//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_SERVER_H
#define BACKEND_SERVER_H

#include "LRU.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

class RequestsManager {
public:
    RequestsManager() = default;
    HttpRequest read_request(int connection);
    int send_response(HttpResponse response, int connection);
    int port = 8080;
protected:
    std::string host="127.0.0.1";
    int listen_fd;
};

class APIManger {
public:
    APIManger() = default;
    void registrate(HttpResponse (*api_method)(HttpRequest), std::string url);
    typedef HttpResponse (*api_method)(HttpRequest, std::string);
    std::map<std::string, api_method> api_methods;
};

class Server: private RequestsManager, public APIManger{
public:
    Server() = default;
    void run();

private:
    LRU cache;
    int listen_fd;
    std::vector<std::string> get_from_cache_or_put(std::vector<double>);
};

#endif //BACKEND_SERVER_H
