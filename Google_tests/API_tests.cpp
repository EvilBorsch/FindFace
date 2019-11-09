#include "../API/VkAPI.h"
#include "../API/OkAPI.h"
#include "../API/FacebookAPI.h"
#include "../Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "../Id_list_generator_strategy/Ok_id_list_generator_strategy.h"
#include "../Id_list_generator_strategy/Facebook_id_list_generator_strategy.h"
#include "../Crowler/Crowler.h"
#include "../Id_list_generator_strategy/Ok_id_list_generator_strategy_friends_method.h"
#include <iostream>



#include "gtest/gtest.h"
#include <fstream>

class TestAPI : public ::testing::Test {
protected:

    void SetUp() override {
        vk = new VkAPI("7175443");
        ok=new OkAPI("512000155176");
        facebook=new FacebookAPI("424256728258093");
    }

    void TearDown() override{
        delete vk;
        delete ok;
        delete facebook;
    }

    VkAPI *vk;
    OkAPI * ok;
    FacebookAPI* facebook;


};


TEST_F(TestAPI, testvk) {
    vector<string> vk_get_photo_ans = {"https://vk.com/cchhiill?z=photo184059480_456241996%2Falbum184059480_0%2Frev",
                             "https://vk.com/cchhiill?z=photo184059480_457242377%2Falbum184059480_0%2Frev",
                             "https://vk.com/cchhiill?z=photo184059480_456240854%2Falbum184059480_0%2Frev",
                             "https://vk.com/cchhiill?z=photo184059480_456240763%2Falbum184059480_0%2Frev"};
    vector<string> vk_get_friends_ans={"https://vk.com/sergeiptrnk"};
    vector<string> vk_get_group_ans={"https://vk.com/id358547266","https://vk.com/nukenova2016"
                                     ,"https://vk.com/id399688365","https://vk.com/id418671513"};

    EXPECT_EQ(vk->get_photo_urls_by_id("https://vk.com/id184059480"), vk_get_photo_ans);
    EXPECT_EQ(vk->get_friends_urls_by_id("https://vk.com/id289472284"),vk_get_friends_ans);
    EXPECT_EQ(vk->get_group_participants("https://vk.com/club143457610"),vk_get_group_ans);

    EXPECT_EQ(vk->get_friends_urls_by_id("https://vk.com/id12313"),vector<string>());
    EXPECT_EQ(vk->get_group_participants("https://vk.com/a_4_autism"),vector<string>());
    EXPECT_EQ(vk->get_photo_urls_by_id("https://vk.com/id289472284"),vector<string>());


    EXPECT_EQ(vk->get_friends_urls_by_id("https://vk.com/id1askdhjaskljh2313"),vector<string>());
    EXPECT_EQ(vk->get_group_participants("https://vk.com/a_asdjkhaskjdh4_autism"),vector<string>());
    EXPECT_EQ(vk->get_photo_urls_by_id("https://vk.com/id2894asjdhgaskjdh72284"),vector<string>());

}


TEST_F(TestAPI, testok) {
    //str
    //gruppa https://ok.ru/group/61557801746474
    vector<string> ok_get_photo_ans = {"https://ok.ru/profile/575941399764/pphotos/879711732436",
                                       "https://ok.ru/profile/593221215274/pphotos/889758673450",
                                       };
    vector<string> ok_get_friends_ans={"https://ok.ru/profile/593221211482"};
    vector<string> ok_get_group_ans={"https://ok.ru/profile/593221215274"};

    EXPECT_EQ(ok->get_photo_urls_by_id("https://ok.ru/profile/593221215274"), ok_get_photo_ans);
    EXPECT_EQ(ok->get_friends_urls_by_id("https://ok.ru/profile/593221215274"),ok_get_friends_ans);
    EXPECT_EQ(ok->get_group_participants("https://ok.ru/group/61557801746474"),ok_get_group_ans);

    EXPECT_EQ(ok->get_friends_urls_by_id("https://ok.ru/profile/59322121521231232112312"),vector<string>());
    EXPECT_EQ(ok->get_group_participants("dkfhkajshf"),vector<string>());
    EXPECT_EQ(ok->get_photo_urls_by_id("xncvmncxmvnxcm"),vector<string>());


}

TEST_F(TestAPI,test_facebook){
    vector<string> facebook_get_photo_ans = {"https://www.facebook.com/photo.php?fbid=113498916761448&set=a.113453566765983&type=3&theater",
                                       "https://www.facebook.com/photo.php?fbid=113453540099319&set=a.113453566765983&type=3&theater",
    };

    vector<string> facebook_get_friends_ans={"https://www.facebook.com/profile.php?id=100026228050639"};
    vector<string> facebook_get_group_ans={"https://www.facebook.com/profile.php?id=100026228050639"};

    EXPECT_EQ(facebook->get_photo_urls_by_id("https://www.facebook.com/profile.php?id=100043040207420"), facebook_get_photo_ans);
    EXPECT_EQ(facebook->get_friends_urls_by_id("https://www.facebook.com/profile.php?id=100043040207420"),facebook_get_friends_ans);
    EXPECT_EQ(facebook->get_group_participants("https://www.facebook.com/groups/2558160454233543"),facebook_get_group_ans);

    EXPECT_EQ(facebook->get_friends_urls_by_id("https://www.facebook.com/profile.php?id=100043040207420ahsjdhja"),vector<string>());
    EXPECT_EQ(facebook->get_group_participants("https://www.facebook.com/groups/551899082309567"),vector<string>());
    EXPECT_EQ(facebook->get_group_participants("https://www.facebook.com/groups/55189908230956asdjhasjdhj7"),vector<string>());
    EXPECT_EQ(facebook->get_photo_urls_by_id("xncvmncxmvnxcm"),vector<string>());

}










class TestListGenerator : public ::testing::Test {
protected:

    void SetUp() override {

        vk_lg = new Vk_id_list_generator_strategy(5, pathvk);
        ok_lg = new Ok_id_list_generator_strategy(5, pathok);
        facebook_lg = new Facebook_id_list_generator_strategy(5, pathfacebook);
        ok_lg_friends = new Ok_id_list_generator_strategy_friends_method(3, pathokfriends);
    }

    void TearDown() override{
        delete vk_lg;
        delete ok_lg;
        delete facebook_lg;
    }

    string pathvk = "../../test_vk.txt";

    string pathok = "../../test_ok.txt";

    string pathfacebook = "../../test_facebook.txt";


    string pathokfriends = "../../test_ok_friends.txt";
    Vk_id_list_generator_strategy *vk_lg;
    Ok_id_list_generator_strategy *ok_lg;
    Facebook_id_list_generator_strategy* facebook_lg;
    Ok_id_list_generator_strategy_friends_method *ok_lg_friends;
};


TEST_F(TestListGenerator,test_vk_lg){

    vector<string> vec={"vk.com/id123","vk.com/id124","vk.com/id125","vk.com/id126","vk.com/id127"};
    std::ofstream fout(pathvk, std::ios_base::out);

    for (const auto& el:vec){
        fout << el;
    }
    fout.close();

    vector<string> data = vk_lg->load_urls_from_disk(pathvk);
    EXPECT_EQ(data,vec);

    vector<string> generate_data={"vk.com/id128","vk.com/id129","vk.com/id130","vk.com/id131","vk.com/id132"};
    EXPECT_EQ(vk_lg->generate(),generate_data);

}

TEST_F(TestListGenerator,test_ok_lg){
    vector<string> vec={"https://ok.ru/profile/593221211482","https://ok.ru/profile/593221211483"
                        ,"https://ok.ru/profile/593221211484","https://ok.ru/profile/593221211485"
                        ,"https://ok.ru/profile/593221211486"};
    std::ofstream fout(pathok, std::ios_base::out);

    for (const auto& el:vec){
        fout << el;
    }
    fout.close();

    vector<string> data = ok_lg->load_urls_from_disk(pathok);
    EXPECT_EQ(data,vec);

    vector<string> generate_data={"https://ok.ru/profile/593221211487","https://ok.ru/profile/593221211482"
                                  ,"https://ok.ru/profile/493221211482","https://ok.ru/profile/593221211490"
                                  ,"https://ok.ru/profile/123221211482"};
    EXPECT_EQ(ok_lg->generate(),generate_data);
}

TEST_F(TestListGenerator,test_facebook_lg){
    vector<string> vec={"https://www.facebook.com/profile.php?id=100026228050631","https://www.facebook.com/profile.php?id=100026228050632"
            ,"https://www.facebook.com/profile.php?id=100026228050633","https://www.facebook.com/profile.php?id=100026228050634"
            ,"https://www.facebook.com/profile.php?id=100026228050635"};
    std::ofstream fout(pathfacebook, std::ios_base::out);

    for (const auto& el:vec){
        fout << el;
    }
    fout.close();

    vector<string> data = facebook_lg->load_urls_from_disk(pathfacebook);
    EXPECT_EQ(data,vec);

    vector<string> generate_data={"https://www.facebook.com/profile.php?id=100026228050636",
                                  "https://www.facebook.com/profile.php?id=100026228050637"
            ,"https://www.facebook.com/profile.php?id=100026228050638","https://www.facebook.com/profile.php?id=100026228050639"
            ,"https://www.facebook.com/profile.php?id=100026228050640"};
    EXPECT_EQ(facebook_lg->generate(), generate_data);
}


TEST_F(TestListGenerator, test_ok_friends_lg) {
    vector<string> generate_data = {"https://ok.ru/profile/467533400550",
                                    "https://ok.ru/profile/358288531616",
                                    "https://ok.ru/profile/571622183720"};
    EXPECT_EQ(ok_lg_friends->generate(), generate_data);
}


TEST(CurlTests, Curltest) {
    Curl curler;
    string response=curler.request("https://api.vk.com/method/users.get?user_ids=210700286&fields=bdate&access_token=533bacf01e11f55b536a565b57531ac114461ae8736d6506a3&v=5.103");

    string right_answer="{\"error\":{\"error_code\":5,\"error_msg\":\"User authorization failed: invalid access_token (4).\",\"request_params\":[{\"key\":\"user_ids\",\"value\":\"210700286\"},{\"key\":\"fields\",\"value\":\"bdate\"},{\"key\":\"v\",\"value\":\"5.103\"},{\"key\":\"method\",\"value\":\"users.get\"},{\"key\":\"oauth\",\"value\":\"1\"}]}}";

    ASSERT_EQ(right_answer,response);

    ASSERT_EQ("",curler.request("asd"));

}


TEST(CrowlerTest, test) {
    int status = 0;
    int pid = -1;
    int fd[2];
    pipe(fd);
    VkAPI vk("asd");
    Vk_id_list_generator_strategy vk_lg(5, "../../test2.txt");
    Crowler cr(&vk, &vk_lg, fd);

    pid = fork();
    if (pid == 0) {
        EXPECT_ANY_THROW(cr.start_crowl());
    } else {
        sleep(2);
        EXPECT_ANY_THROW(cr.stop_crowl_and_save_id_list());
        close(fd[0]);
        close(fd[1]);
    }
    waitpid(pid, &status, 0);



}





















