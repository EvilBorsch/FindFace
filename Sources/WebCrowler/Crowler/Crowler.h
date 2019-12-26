#include "WebCrowler/AbstractClasses/AbstractAPI.h"
#include "WebCrowler/AbstractClasses/Abstract_id_list_generator_strategy.h"
#include <thread>
#include "DataBase/KD/DB.h"
class Crowler {
    std::shared_ptr<AbstractIdListGeneratorStrategy> lg;
    std::thread *t;
    std::shared_ptr<AbstractAPI> api;
    bool thread_must_end = false;
    DB *db;
public:
    void startCrowl();
    void crowl();
    void stopCrowl();
    Crowler(std::shared_ptr<AbstractAPI> m_api, std::shared_ptr<AbstractIdListGeneratorStrategy> m_lg, DB* m_db);



    std::vector<std::vector<double>> getFacesVector(std::string link);


};