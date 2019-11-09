//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "HttpRequest.h"


//GET /?var1=1&var2=string&var3=0.1 HTTP/1.1
//Host: 127.0.0.1:5000
//Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
//Upgrade-Insecure-Requests: 1
//Cookie: csrftoken=PiJBMxa1zfWGOVgn92kjZ3zcLJOSywXPqEx2scDBp7kQk93AGZoDYt411YhCMQhM; sessionid=852x1dw8igpg6c29ctitnek1irxcd5ya
//User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/12.1.2 Safari/605.1.15
//Accept-Language: en-us
//Accept-Encoding: gzip, deflate
//Connection: keep-alive

void HttpRequest::add_data(std::string request_data) {
    get["var1"] = "1";
    get["var2"] = "string";
    get["var3"] = "0.1";
}

void HttpRequest::parse_post_params() {

}

void HttpRequest::parse_get_params() {

}

void HttpRequest::parse_request() {

}
