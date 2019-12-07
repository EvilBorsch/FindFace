//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_HTTPRESPONSE_H
#define BACKEND_HTTPRESPONSE_H

#include <map>
#include "iostream"


class HeaderExistedException : public std::exception
{
public:
    explicit HeaderExistedException(std::string msg) : m_message(std::move(msg)) {}
    const char * what () const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};


class HttpResponseBase {
public:
    std::string status = "200 OK";
    std::map<std::string, std::string> headers;
    std::string response_body;

    void setHeader(const std::string& key, std::string value);

protected:
    std::string serializeHeaders();
};

class HttpResponse: private HttpResponseBase {
public:
    void setStatus(const std::string &status_code, const std::string &status_text);
    void setOKStatus();

    void setConnection(std::string connection_type);

    void setContentType(std::string content_type);

    void setCustomHeader(std::string key, std::string value);

    void setResponseBody(std::string body);

    std::string getHeader(const std::string& key);
    std::string getResponseBody();
    std::string getSerializedResponse();
};


#endif //BACKEND_HTTPRESPONSE_H
