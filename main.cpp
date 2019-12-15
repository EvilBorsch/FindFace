#include "NetService/NetService.h"
#include "API/VkAPI.h"
#include "Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "Crowler/Crowler.h"
#include "API/FacebookAPI.h"
#include "Id_list_generator_strategy/Facebook_id_list_generator_strategy.h"

int main(int argc, char *argv[]) {


    std::shared_ptr<VkAPI> vk = std::make_shared<VkAPI>("asd");
    vk->login();

    std::shared_ptr<VkIdListGeneratorStrategy> vkId = std::make_shared<VkIdListGeneratorStrategy>(6,
                                                                                                  "/Users/dmitrijgulacenkov/CrowlerDump/vkId.txt"
    );


    std::shared_ptr<FacebookAPI> facebook = std::make_shared<FacebookAPI>("579642939271889",
                                                                          "54350e9fd703fa4510992914b7907d31");
    facebook->login();

    std::shared_ptr<FacebookIdListGeneratorStrategy> facebook_lg = std::make_shared<FacebookIdListGeneratorStrategy>(6,
                                                                                                                     "/Users/dmitrijgulacenkov/CrowlerDump/facebookId.txt"
    );

    Crowler crFace(facebook, facebook_lg);
    Crowler cr(vk, vkId);
    Crowler cr2(vk, vkId);
    cr.startCrowl();
    cr2.startCrowl();
    crFace.startCrowl();
    sleep(4);
    cr.stopCrowl();
    sleep(4);

    cr2.stopCrowl();
    sleep(10);

    crFace.stopCrowl();


}