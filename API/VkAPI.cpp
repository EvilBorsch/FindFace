#include "VkAPI.h"


void getPhotosBySizeInResponseData(boost::property_tree::ptree const &pt, std::vector<url> &vec,
                                   const std::string &size = "z") {
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();


    for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
        if (it->first == "type" && it->second.get_value<std::string>() == size) {
            it++;
            vec.emplace_back(url(it->second.get_value<std::string>()));
            continue;
        }
        getPhotosBySizeInResponseData(it->second, vec, size);

    }
}


bool isError(response resp) {

    boost::property_tree::ptree pt = resp.getData();
    return (pt.begin()->first == "error");

}


std::vector<url> VkAPI::getPhotoUrlsById(const url &m_url) {

    NetService net;
    url requestUrl;
    requestUrl.getVkPhotosRequestUrl(token, m_url.getVkId());
    response resp = net.request(requestUrl);
    std::vector<url> vec;
    if (!isError(resp)) getPhotosBySizeInResponseData(resp.getData(), vec);

    return vec;

}


VkAPI::VkAPI(const std::string &m_app_key) {
    app_key = m_app_key;
}

void VkAPI::login() {
    //url mUrl;
    //mUrl.getVkLoginRequestUrl(app_key);
    //response resp=net.request(mUrl);
    token = "af2d806eaf2d806eaf2d806e66af40fd7daaf2daf2d806ef28431079864b75a45b322d9";

}

