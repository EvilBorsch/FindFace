#include "API/VkAPI.h"
#include "API/OkAPI.h"
#include "API/FacebookAPI.h"
#include "Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "Id_list_generator_strategy/Ok_id_list_generator_strategy.h"
#include "Id_list_generator_strategy/Facebook_id_list_generator_strategy.h"
#include "Crowler/Crowler.h"
#include <iostream>
#include "url/url.h"
#include "gtest/gtest.h"

using std::vector, std::string;

class TestAPI : public ::testing::Test {
protected:

    void SetUp() override {

        vk = std::make_shared<VkAPI>("7175443");
        vk->login();
        ok = std::make_shared<OkAPI>("512000155176");
        ok->login();
        facebook = std::make_shared<FacebookAPI>("579642939271889", "54350e9fd703fa4510992914b7907d31");
        facebook->login();

    }


    std::shared_ptr<VkAPI> vk;
    std::shared_ptr<OkAPI> ok;
    std::shared_ptr<FacebookAPI> facebook;


};


TEST_F(TestAPI, testvk) {
    url m_url("id184059480", "vk");

    url temp1("https://sun9-52.userapi.com/c840232/v840232112/8561d/Y-q_hZJtpDk.jpg");
    url temp2("https://sun9-35.userapi.com/c847122/v847122689/2137f/pdHUHTavt1U.jpg");
    url temp3("https://sun1-29.userapi.com/c850224/v850224350/186544/v6ooSacR0r0.jpg");
    url temp4("https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg");
    vector<url> vk_get_photo_ans = {temp1, temp2, temp3, temp4};

    std::vector<url> vec = vk->getPhotoUrlsById(m_url);

    EXPECT_EQ(vec, vk_get_photo_ans);


    url photoId2("id289472284", "vk");


    EXPECT_EQ(vk->getPhotoUrlsById(photoId2), vector<url>());


    url photoId3("id1askdhjaskljh2313");


    EXPECT_EQ(vk->getPhotoUrlsById(photoId3), vector<url>());

}


TEST_F(TestAPI, testok) {
    url temp1("575941399764/pphotos/879711732436");
    url temp2("593221215274/pphotos/889758673450");


    vector<url> ok_get_photo_ans = {temp1, temp2};


    url photoId("593221215274");


    EXPECT_EQ(ok->getPhotoUrlsById(photoId), ok_get_photo_ans);


    url photoId2("593221215274");


    EXPECT_EQ(ok->getPhotoUrlsById(photoId2), vector<url>());


}

TEST_F(TestAPI, test_facebook) {
    //url temp1("113498916761448&set=a.113453566765983&type=3&theater");
    //url temp2("113453540099319&set=a.113453566765983&type=3&theater");
    //vector<url> facebook_get_photo_ans = {temp1, temp2};

    url mUrl("id=100043040207420", "facebook");
    std::vector<url> vec = facebook->getPhotoUrlsById(mUrl);
    EXPECT_EQ(vec[0].toStr(),
              "https://scontent.xx.fbcdn.net/v/t1.0-1/74394721_113498920094781_7916501690130366464_n.jpg?_nc_cat=106&_nc_ohc=1Hq29VKwkEUAQnBJKFtmCztLho7_fP4mWJ6nFO6UBhBKDB0fnCUFJ29LQ&_nc_ht=scontent.xx&oh=9d6a74eda6a04e48bb7ccf27d2759b27&oe=5E7AFA4E");
    url mUrl2("id=100043askdklasj040207420", "facebook");
    std::vector<url> vec2 = facebook->getPhotoUrlsById(mUrl2);
    EXPECT_EQ(vec2, vector<url>());


    //url photoId("100043040207420");


    //EXPECT_EQ(facebook->getPhotoUrlsById(photoId),
    //         facebook_get_photo_ans);


    //url photoId2("100043040207420ahsjdhja");


    //EXPECT_EQ(facebook->getPhotoUrlsById(photoId2), vector<url>());

}


class TestListGenerator : public ::testing::Test {
protected:

    void SetUp() override {

        vk_lg = std::make_shared<VkIdListGeneratorStrategy>(5, pathvk);
        ok_lg = std::make_shared<OkIdListGeneratorStrategy>(5, pathok);
        facebook_lg = std::make_shared<FacebookIdListGeneratorStrategy>(5, pathfacebook);
    }


    string pathvk = "../../Google_tests/TestsData/CrowlerTest/vkId.txt";

    string pathok = "../../test_ok.txt";

    string pathfacebook = "../../Google_tests/TestsData/CrowlerTest/facebookId.txt";


    std::shared_ptr<VkIdListGeneratorStrategy> vk_lg;
    std::shared_ptr<OkIdListGeneratorStrategy> ok_lg;
    std::shared_ptr<FacebookIdListGeneratorStrategy> facebook_lg;

};


TEST_F(TestListGenerator, test_vk_lg) {


    std::vector<url> vec = vk_lg->generate();

    std::vector<url> res = {url("id1235", "vk"),
                            url("id1236", "vk"),
                            url("id1237", "vk"),
                            url("id1238", "vk"),
                            url("id1239", "vk")};


    EXPECT_EQ(vec, res);


}

TEST_F(TestListGenerator, test_ok_lg) {
    vector<url> vec = {url("593221211482"), url("593221211483"), url("593221211484"), url("593221211485"),
                       url("593221211486")};

    std::ofstream fout(pathok, std::ios_base::out);

    for (auto &el:vec) {
        fout << el.toStr();
    }
    fout.close();


    vector<url> generate_data = {url("593221211487"), url("593221211482"), url("493221211482"), url("593221211490"),
                                 url("123221211482")};

    EXPECT_EQ(ok_lg->generate(), generate_data);
}

TEST_F(TestListGenerator, test_facebook_lg) {
    vector<url> ans = {url("id=1235", "facebook"), url("id=1236", "facebook"), url("id=1237", "facebook"),
                       url("id=1238", "facebook"),
                       url("id=1239", "facebook")};
    std::vector<url> vec = facebook_lg->generate();


    EXPECT_EQ(vec, ans);
}


TEST(CurlTests, Curltest) {
    NetService curler;
    response m_response = curler.request(
            url("https://api.vk.com/method/users.get?user_ids=210700286&fields=bdate&access_token=533bacf01e11f55b536a565b57531ac114461ae8736d6506a3&v=5.103"));


    response m_response2 = curler.request(
            url("https://api.vk.com/method/users.get?user_ids=210700286&fields=bdate&access_token=ajshdkjashdkjhaskjdh533bacf01e11f55b536a565b57531ac114461ae8736d6506a3&v=5.103"));


    EXPECT_EQ(m_response.getData(), m_response2.getData());


}







