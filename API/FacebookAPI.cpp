#include "FacebookAPI.h"

using std::vector, std::string;

vector<url> FacebookAPI::getPhotoUrlsById(const url &url) {
    return {};
}


FacebookAPI::FacebookAPI(const std::string &app_key) {
    login(app_key);
}

vector<url> FacebookAPI::getFriendsUrlsById(const url &url) {
    return {};
}

vector<url> FacebookAPI::getGroupParticipants(const url &url) {
    return {};
}

void FacebookAPI::login(std::string app_key) {

}
