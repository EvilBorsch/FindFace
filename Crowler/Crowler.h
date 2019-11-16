#include "../AbstractClasses/AbstractAPI.h"
#include "../AbstractClasses/Abstract_id_list_generator_strategy.h"

class Container {

};


class Crowler {
    const int stop_state = 2;
    AbstractIdListGeneratorStrategy *lg;
    std::vector<url> id_list;

    Container get_container_from_urls(const std::vector<url> &urls);
    int *fd;
    AbstractAPI *api;
public:
    void startCrowl();

    void stopCrowlAndSaveIdList();

    Crowler(AbstractAPI *m_api, AbstractIdListGeneratorStrategy *m_lg, int *fd);


};