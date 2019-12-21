#include <iostream>

#ifndef KURSACH_FINAL_URL_H
#define KURSACH_FINAL_URL_H

class url {

public:

    std::string base_url = "";
    std::string protocol = "";
    std::string host = "";

    void parse(const std::string &mUrl) {

        const size_t firstNotSlashChar = 5;
        std::copy(mUrl.begin(), mUrl.begin() + firstNotSlashChar, std::back_inserter(protocol));

        std::string temp_data;
        size_t baseUrlIndex = 0;
        for (size_t i = firstNotSlashChar + 3; i < mUrl.length(); i++) {
            baseUrlIndex = i;
            char ch = mUrl[i];
            if (ch == '/') {
                host = temp_data;
                break;
            }
            temp_data += ch;
        }
        for (size_t i = baseUrlIndex + 1; i < mUrl.length(); i++) {
            base_url += mUrl[i];
        }

    };


public:

    explicit url(const std::string &st, const std::string &type = "default") {
        if (type == "vk") {
            protocol = "https";
            host = "vk.com";
            base_url = st;
        } else if (type == "ok") {
            protocol = "https";
            host = "ok.ru";
            base_url = st;
        } else if (type == "facebook") {
            protocol = "https";
            host = "facebook.com";
            base_url = "profile.php?" + st;
        } else {
            parse(st);
        }
    }


    std::string toStr() {
        return protocol + "://" + host + "/" + base_url;
    }


    void vkStyleId(std::string id) {
        protocol = "https";
        host = "vk.com";
        base_url = "id" + id;
    }


    [[nodiscard]] std::string getVkId() const {
        std::string id;
        const size_t firstDigit = 2;
        if (base_url!="")std::copy(base_url.begin() + firstDigit, base_url.end(), std::back_inserter(id));
        return id;
    }

    void getVkPhotosRequestUrl(std::string &token, std::string id) {
        protocol = "https";
        host = "api.vk.com";

        base_url = "method/photos.get?owner_id=" + id + "&album_id=profile&access_token=" + token +
                   "&v=5.103";
    }


    friend bool operator==(const url &m_url1, const url &m_url2) {
        return (m_url1.base_url == m_url2.base_url);
    }


    url() = default;

    void getFacebookLoginRequest(const std::string &app_key, const std::string &secret_key) {
        protocol = "https";
        host = "graph.facebook.com";
        base_url = "oauth/access_token?client_id=" + app_key + "&client_secret=" + secret_key +
                   "&grant_type=client_credentials";
    }


    [[nodiscard]] std::string getFacebookId() const {
        const int firstDigitPosition = 15;
        std::string id;
        std::copy(base_url.begin() + firstDigitPosition, base_url.end(), std::back_inserter(id));
        return id;
    }


    void getFacebookPictureRequest(const std::string &id, const std::string &sizeOfPicture) {
        protocol = "https";
        host = "graph.facebook.com";
        base_url = "v5.0/" + id + "/picture?height=" + sizeOfPicture + "&redirect=false";
    }

    void facebookStyleId(const std::string &id) {
        protocol = "https";
        host = "facebook.com";
        base_url = "profile.php?id=" + id;
    }
};

#endif //KURSACH_FINAL_URL_H
