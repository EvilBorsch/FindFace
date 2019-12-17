//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_SERVER_H
#define BACKEND_SERVER_H

#include "../HttpRequest/HttpRequest.h"
#include "../HttpResponse/HttpResponse.h"

#include <netinet/in.h>
#include <sys/socket.h>
#include <map>

class ViewNotFoundError : public std::exception {
public:
    explicit ViewNotFoundError(std::string msg) : m_message(std::move(msg)) {}
    const char * what () const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

class ServerError : public std::exception
{
public:
    explicit ServerError(std::string msg) : m_message(std::move(msg)) {}
    const char * what () const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

class RequestsManager {
public:
    RequestsManager() = default;
    HttpRequest readRequest(int connection);
    int sendResponse(const HttpResponse &response, int connection);
    int port = 8080;
    std::string host="127.0.0.1";


protected:
    int listen_fd{};
};

class APIManger {
public:
    typedef HttpResponse (*api_method)(HttpRequest);

    APIManger() = default;
    void add_view(HttpResponse (*api_method)(HttpRequest), const std::string &url);

    api_method get_view(const std::string& url);
private:
    std::map<std::string, api_method> views;
};

class Server: private RequestsManager, public APIManger{
public:
    explicit Server(int port);
    void run();

    void set_not_found_view(api_method view);
private:
    void runThread(int _new_socket);
    std::mutex mtx;

    int server_fd{}, new_socket{}, PORT{};
    struct sockaddr_in address{};
    int addrlen = sizeof(address);
    static std::vector<std::string> get_from_cache(const std::vector<double>&);
    static std::vector<std::string> put_to_cache(const std::vector<double>&);

    api_method not_found_view = nullptr;
    void checks_before_start();
};

#endif //BACKEND_SERVER_H
