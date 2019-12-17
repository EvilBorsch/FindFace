#include <vector>
#include <string>
#include <sstream>
#include "HttpRequest/HttpRequest.h"
#include "HttpResponse/HttpResponse.h"
#include "Server/Server.h"

HttpResponse not_found_view(HttpRequest request) {
    HttpResponse response;
    std::stringstream response_body;
    response_body << "<title>Ничего не найдено</title>\n"
                  << "<h1>Зачем спросил, чего не знаю?</h1>\n";

    response.setContentType("text/html; charset=utf-8");
    response.setResponseBody(response_body.str());

    response.setStatus("404", "Not Found");

    return response;
}

HttpResponse api_method(HttpRequest request) {
    HttpResponse response;

    if(request.METHOD() == "GET") {
        std::map<std::string, Any> get = request.GET();

        try {

            Any test_value = request.GET_search("test");
            std::stringstream response_body;
            response_body << "<title>Test</title>\n"
                          << "<h1>Test</h1>\n"
                          << "<p>This is body of the test page...</p>\n"
                          << "<h2>Request headers</h2>\n"
                          << "<pre>" << test_value.s << "</pre>\n"
                          << "<em><small>Test C++ Http Server</small></em>\n";


//        response.setOKStatus();
            response.setContentType("text/html; charset=utf-8");
            response.setResponseBody(response_body.str());

            return response;
        } catch (NoValueFoundException) {
            return not_found_view(request);
        }



    }
    response.setStatus("405", "Method Not Allowed");
    response.setResponseBody("Only GET method allowed");

    return response;
}


int main() {
    Server server(8080);

    server.set_not_found_view(not_found_view);
    server.add_view(api_method, "/some_api_method/");

    server.run();
    return 0;
}
