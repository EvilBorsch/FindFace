//
// Created by Dmitry Boldin on 08/11/2019.
//

#include <vector>
#include "HttpRequest.h"
#include <sstream>
#include <iostream>
#include <map>


int HttpRequest::addHeaders(const char* buffer) {
//  PARSE FIRST FILE AND URL
    std::vector<std::string> headers_vector = split(buffer, '\n');;
    int headers_size = headers_vector[0].length();

    headers_vector[0].pop_back();
    std::vector<std::string> first_line = split(headers_vector[0], ' ');
    if(first_line.size() < 2) {
        noErrors = false;
        return -1;
    }

    method = first_line[0];
    url.raw = first_line[1];
    url.protocol = first_line[2];

    if (method == "GET") {
        parseGetParams(first_line[1]);
    } else if(method == "POST") {
        url.protocol = first_line[2];
        url.path = first_line[1];
        url.query_string = "";
    }

    return parseAllHeaders(headers_vector, headers_size);
}

void HttpParser::parsePostParams() {

}

void HttpParser::parseGetParams(const std::string& get_params) {
    std::vector<std::string> separated_url = split(
            get_params, '?');

    if(separated_url.size() == 2) {
        url.path = separated_url[0];
        url.query_string = separated_url[1];
    } else {
        url.path = separated_url[0];
        url.query_string = "";
    }
    parseArgs(url.query_string, get);
}

void HttpParser::parseRequest() {

}

std::vector<std::string>
HttpParser::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;

}

int HttpParser::isNumber(const std::string &s) {
    /**
     * Return values:
     * 0 - is not a number
     * 1 - is double
     * 2 - is int
     */
    auto result_double = double();

    auto i = std::istringstream(s);

    i >> result_double;

    auto is_num = !i.fail() && i.eof();
    if(!is_num) {
        return is_num;
    }
    return (result_double == (int) result_double) + 1;
}

void HttpParser::parseArgs(std::string const & query_string,
                            std::map<std::string, Any>& params_map) {

    std::vector<std::string> params_vector = split(query_string, '&');
    for(auto param: params_vector) {
        auto delimiter_pos = param.find('=');
        std::string token = param.substr(0, delimiter_pos);
        param.erase(0, delimiter_pos + 1);
        switch (isNumber(param)){
            case 0:
                params_map.insert(std::pair<std::string, Any> (
                        token, Any(param)
                        ));
                break;
            case 1:
                params_map.insert(std::pair<std::string, Any> (
                        token, Any(std::stod(param))
                        ));
                break;
            case 2:
                params_map.insert(std::pair<std::string, Any> (
                        token, Any(std::stoi(param))
                        ));
        }
    }

}

Any HttpRequest::GET_search(const std::string& key) {
    auto it = get.find(key);
    if (it != get.end()) {
        return it->second;
    }
    throw NoValueFoundException("Value with key'" + key + "' not found");
}

int HttpRequest::parseAllHeaders(std::vector<std::string> headers_vector,
        int headers_size) {
    int last_header_line = 0;
    for(int i = 1; i < headers_vector.size(); ++i) {
        headers_size += headers_vector[i].length();

        headers_vector[i].pop_back();

        std::vector<std::string> key_value_pair = split(headers_vector[i], ':');
        if(key_value_pair.size() < 2) {
            last_header_line = i;
            break;
        }
        key_value_pair[1].erase(0, 1);
        std::transform(
                key_value_pair[0].begin(), key_value_pair[0].end(),
                key_value_pair[0].begin(),
                [](unsigned char c){ return std::tolower(c); }
        );
        headers.insert(std::pair<std::string,std::string>(
                key_value_pair[0], key_value_pair[1]));
    }
    return headers_size;
}
