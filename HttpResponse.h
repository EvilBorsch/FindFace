//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_HTTPRESPONSE_H
#define BACKEND_HTTPRESPONSE_H

class HttpResponseBase {
public:
    int status_code = 200;
    std::map<std::string, std::string> headers;

    std::string get_content_type();
    HttpResponseBase(int status);

    void _set_header(std::string key, std::string value);

protected:
    std::string serialize_headers();
};

class HttpResponse: private HttpResponseBase {
public:
    HttpResponse(int status);
    HttpResponse( std::string contentType);
    std::string serialize();
    void set_header(std::string key, std::string value);
};


#endif //BACKEND_HTTPRESPONSE_H
