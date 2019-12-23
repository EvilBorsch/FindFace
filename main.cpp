#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <sstream>
#include <vector>


std::vector<std::vector<double>> getFacesVector(std::string link) {
    char buffer[128];
    std::string cmd = "source env/bin/activate; python python_magic.py " + link;
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    std::cout << result;
    pclose(pipe);
    std::stringstream output(result);
    int n;
    output >> n;
    std::cout << n;
    std::vector<std::vector<double>> faces;
    std::vector<double> tmp_vector;
    std::string num;
    while(output >> num) {
        if(num[0] == '[') {
            tmp_vector.clear();
            num.erase(num.begin());
        } else if(num.back() == ']'){
            num.pop_back();
            if(!num.empty()) {
                tmp_vector.push_back(std::stod(num));
            }
            faces.push_back(tmp_vector);
            continue;
        }
        tmp_vector.push_back(std::stod(num));
    }
    for (const auto& i: faces) {
        for(auto j: i)
            std::cout << j << ' ';
        std::cout << "\n";
    }

    return faces;
}

int main() {
    auto a = getFacesVector("https://24smi.org/public/media/resize/800x-/2018/10/16/30085313-161676521175028-6270825408061505536-n-768x512.jpg");
    return 0;
}
