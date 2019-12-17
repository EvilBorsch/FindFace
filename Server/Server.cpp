//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "Server.h"
#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

HttpRequest RequestsManager::readRequest(int connection) {
    return HttpRequest();
}

int RequestsManager::sendResponse(const HttpResponse &response, int connection) {
    return 0;
}

void APIManger::add_view(HttpResponse (*api_method)(HttpRequest),
                         const std::string &url) {
    views[url] = api_method;
}

APIManger::api_method APIManger::get_view(const std::string& url) {
    auto it = views.find(url);
    if (it == views.end())
        throw ViewNotFoundError("No view for this path");
    return it->second;
}

std::vector<std::string> Server::get_from_cache(const std::vector<double>&) {
    return std::vector<std::string>();
}

std::vector<std::string> Server::put_to_cache(const std::vector<double>&) {
    return {};
}

void Server::runThread(int _new_socket) {
    int status;
    char buffer[1024];
    status = read(_new_socket, buffer, sizeof(buffer));

    if ( status < 0 ) {
        fprintf(stderr,"Error reading from socket.");
        exit(0);
    }

    HttpRequest request;

    int headers_size = request.addHeaders(buffer);
    URL url = request.URL();
    api_method view;
    try {
        view = get_view(url.path);
    } catch (ViewNotFoundError) {
        view = not_found_view;
    }
    HttpResponse response = view(request);

    std::string serialized_response = response.getSerializedResponse();

    write(_new_socket , serialized_response.c_str(),
          serialized_response.length());
    close(_new_socket);
    pthread_exit(nullptr);
}

void Server::run() {
    checks_before_start();
    while(true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0) {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        std::thread thr(&Server::runThread, this, new_socket);
        thr.detach();
    }
}

Server::Server(int port) {
    PORT = port;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
}

void Server::set_not_found_view(APIManger::api_method view) {
    not_found_view = view;
}

void Server::checks_before_start() {
    if(not_found_view == nullptr) {
        throw ServerError("Set not 404 view before start. "
                    "Use 'set_not_found_view' method");
    }
}
