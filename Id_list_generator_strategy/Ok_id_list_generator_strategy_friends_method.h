#include "../AbstractClasses/Abstract_id_list_generator_strategy.h"

class Ok_id_list_generator_strategy_friends_method : public Abstract_id_list_generator_strategy {
private:
    int size;
    string path;
public:
    explicit Ok_id_list_generator_strategy_friends_method(int m_size, const string &m_path) {
        size = m_size;
        path = m_path;
    }

    vector<string> generate() override;

};
