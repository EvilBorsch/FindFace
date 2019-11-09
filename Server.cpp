//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "Server.h"

HttpRequest RequestsManager::read_request(int connection) {
    return HttpRequest();
}

int RequestsManager::send_response(HttpResponse response, int connection) {
    return 0;
}

void APIManger::registrate(HttpResponse (*api_method)(HttpRequest),
                           std::string url) {

}
