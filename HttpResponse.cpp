//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "HttpResponse.h"

std::string HttpResponseBase::get_content_type() {
    return nullptr;
}

HttpResponseBase::HttpResponseBase(int status) {

}

std::string HttpResponseBase::serialize_headers() {
    return nullptr;
}

void HttpResponseBase::_set_header(std::string key, std::string value) {

}

std::string HttpResponse::serialize() {
    return "Some data";
}

HttpResponse::HttpResponse(int status)
        : HttpResponseBase(status) {

}

HttpResponse::HttpResponse(std::string data)
        : HttpResponseBase(200) {

}

void HttpResponse::set_header(std::string key, std::string value) {
    HttpResponseBase::_set_header(std::move(key), std::move(value));
}
