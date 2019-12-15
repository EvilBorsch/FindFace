#include "AbstractClasses/Abstract_id_list_generator_strategy.h"
#include "url/url.h"

class VkIdListGeneratorStrategy : public AbstractIdListGeneratorStrategy {
private:
    int size;
    std::string path;
    size_t currentId = 0;

    size_t getCurrentId();

public:
    VkIdListGeneratorStrategy(int m_size, const std::string &m_path) {
        size = m_size;
        path = m_path;
        currentId = getCurrentId();

    }

    std::vector<url> generate() override;


    void save() override;


};
