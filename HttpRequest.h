//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_HTTPREQUEST_H
#define BACKEND_HTTPREQUEST_H


class HttpRequest {
public:
    HttpRequest() = default;

    void add_data(std::string);

    std::map<std::string, std::string> GET() { return get;};
    std::map<std::string, std::string> POST() { return post;};
    std::map<std::string, std::string> FILES() { return files;};
    std::string METHOD() { return method;};
    std::string URL() { return url;};
    std::string get_content_type() { return content_type;};

private:
    void parse_post_params();
    void parse_get_params();
    void parse_request();

    std::map<std::string, std::string> get;
    std::map<std::string, std::string> post;
    std::map<std::string, std::string> files;
    std::string method;
    std::string url;
    std::string content_type;
};


#endif //BACKEND_HTTPREQUEST_H
