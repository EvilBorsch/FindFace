#include "NetService/NetService.h"
#include "API/VkAPI.h"
#include "Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "Crowler/Crowler.h"
#include "Api/FacebookAPI.h"
#include "Id_list_generator_strategy/Facebook_id_list_generator_strategy.h"

int main(int argc, char *argv[]) {


    std::shared_ptr<VkAPI> vk = std::make_shared<VkAPI>("asd");
    vk->login();

    std::shared_ptr<VkIdListGeneratorStrategy> vkId = std::make_shared<VkIdListGeneratorStrategy>(6,
                                                                                                  "/Users/dmitrijgulacenkov/CrowlerDump/vkId.txt"
    );

    Crowler cr(vk, vkId);
    cr.startCrowl();
    sleep(6);
    cr.stopCrowl();


}