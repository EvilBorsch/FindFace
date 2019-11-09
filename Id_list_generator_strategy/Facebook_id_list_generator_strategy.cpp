#include "Facebook_id_list_generator_strategy.h"


vector<string> Facebook_id_list_generator_strategy::generate() {
    vector<string> data = load_urls_from_disk(path);
    return vector<string>();
}

