#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    std::vector<std::string> input;

    if(argc == 1) {
        char* in = nullptr;

        while(true) {
            scanf("%s", in);
            printf("%s", in);
        }
    }

    for(int i = 1; i < argc; i++) {
        if(fs::exists(argv[i])) {
            if(fs::is_directory(argv[i])) {
                printf("%s is a directory!\n", argv[i]);
            } else {
                input.emplace_back(argv[i]);
            }
        }
    }

    std::ifstream file;
    std::string str;

    for(uint i = 0; i < input.size(); i++) {
        file.open(input[i]);

        while(file.good()) {
            std::getline(file, str);
            printf("%s\n", str.c_str());
        }

        file.close();
    }

    return 0;
}