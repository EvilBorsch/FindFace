#include "AbstractClasses/AbstractAPI.h"
#include "AbstractClasses/Abstract_id_list_generator_strategy.h"
#include <thread>
#include <atomic>
#include <chrono>



class Crowler {
    std::shared_ptr<AbstractIdListGeneratorStrategy> lg;
    std::thread *t;
    std::shared_ptr<AbstractAPI> api;
public:
    void startCrowl();

    void crowl();

    void stopCrowl();

    Crowler(std::shared_ptr<AbstractAPI> m_api, std::shared_ptr<AbstractIdListGeneratorStrategy> m_lg);


};