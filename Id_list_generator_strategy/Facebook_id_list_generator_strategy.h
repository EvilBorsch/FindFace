#include "../AbstractClasses/Abstract_id_list_generator_strategy.h"
#include "../url/url.h"


class FacebookIdListGeneratorStrategy : public AbstractIdListGeneratorStrategy {
private:
    int size;
    std::string path;
public:

    explicit FacebookIdListGeneratorStrategy(int m_size, const std::string &m_path) {
        size = m_size;
        path = m_path;
    }

    std::vector<url> generate() override;
};
