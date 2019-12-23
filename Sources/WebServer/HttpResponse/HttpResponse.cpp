//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "HttpResponse.h"

#include <utility>
#include <sstream>

void HttpResponseBase::setHeader(std::string const& key, std::string value) {
        if(headers.count(key)) {
            throw HeaderExistedException(
                    "Header with key '" + key + "' already existed");
        }
        headers[key] = std::move(value);
}

std::string HttpResponseBase::serializeHeaders() {
    std::stringstream serialized_headers;
    serialized_headers << "HTTP/1.1 " << status << "\n";

    for(const auto& header: headers) {
        serialized_headers << header.first << ": " << header.second << "\r\n";
    }
    return serialized_headers.str();
}

class NoHeaderException : public std::exception {
public:
    explicit NoHeaderException(std::string msg) : m_message(std::move(msg)) {}
    const char * what () const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

class NoResponseBodyException : public std::exception {
public:
    explicit NoResponseBodyException(std::string msg) : m_message(std::move(msg)) {}
    const char * what () const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

void HttpResponse::setStatus(const std::string &status_code, const std::string &status_text) {
    status = status_code + " " + status_text;
}

void HttpResponse::setOKStatus() {
    setStatus("200", "OK");
}

void HttpResponse::setConnection(std::string connection_type) {
    setHeader("Connection", std::move(connection_type));
}

void HttpResponse::setContentType(std::string content_type) {
    setHeader("Content-Type", std::move(content_type));
}

void HttpResponse::setCustomHeader(std::string key, std::string value) {
    setHeader(std::move(key), std::move(value));
}

std::string HttpResponse::getHeader(const std::string& key) {
    auto it = headers.find(key);
    if (it == headers.end())
        throw NoHeaderException(
                "Header with key '" + key + "' not found");
    return it->second;
}

void HttpResponse::setResponseBody(std::string body) {
    response_body = std::move(body);
}

std::string HttpResponse::getResponseBody() {
    if(response_body.empty()) {
        throw NoResponseBodyException("No body");
    }
    return response_body;
}

std::string HttpResponse::getSerializedResponse() {
    if(!response_body.empty()) {
        std::string content_length = std::to_string(response_body.length());
        setHeader("Content-Length", std::move(content_length));
    }
    return serializeHeaders() + "\r\n\r\n" + response_body;
}
