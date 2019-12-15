#include "FacebookAPI.h"


bool isDefault(const std::string &photoUrl) {
    std::string type;
    const int lastBackSlashPositionPlusOne = 8;
    const int lastBackSlashPositionPlusLengthOfStaticPlusOne = 14;
    std::copy(photoUrl.begin() + lastBackSlashPositionPlusOne,
              photoUrl.begin() + lastBackSlashPositionPlusLengthOfStaticPlusOne, std::back_inserter(type));
    return type == "static";
}

std::vector<url> findPhotoUrlInResponse(boost::property_tree::ptree pt) {
    auto photoUrl = pt.begin()->second.get<std::string>("url");
    std::vector<url> vec;
    if (!isDefault(photoUrl)) vec.emplace_back(url(photoUrl));
    return vec;
}


bool isCorrect(response resp) {
    return (resp.getData().begin()->first != "error");

}

std::vector<url> FacebookAPI::getPhotoUrlsById(const url &mUrl) {
    NetService net;
    url requestUrl;
    std::vector<url> vec;
    std::string id = mUrl.getFacebookId();
    const std::string maxSizeOfPicture = "1000";
    requestUrl.getFacebookPictureRequest(id, maxSizeOfPicture);
    response resp = net.request(requestUrl);
    if (isCorrect(resp)) vec = findPhotoUrlInResponse(resp.getData());
    return vec;
}


FacebookAPI::FacebookAPI(const std::string &mapp_key, const std::string &msecret_key) {
    secret_key = msecret_key;
    app_key = mapp_key;
}

std::string findTokenInResponse(boost::property_tree::ptree pt) {
    const int firstTokenCharPosition = 16;
    std::string token;
    using boost::property_tree::ptree;
    auto appKeyAndToken = pt.begin()->second.get<std::string>("");

    std::copy(appKeyAndToken.begin() + firstTokenCharPosition, appKeyAndToken.end(), std::back_inserter(token));

    return token;

}

void FacebookAPI::login() {
    NetService net;
    url mUrl;
    mUrl.getFacebookLoginRequest(app_key, secret_key);
    response resp = net.request(mUrl);
    std::string mToken = findTokenInResponse(resp.getData());
    token = mToken;


}



