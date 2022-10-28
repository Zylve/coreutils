#include <cstdio>
#include <cstring>
#include <exception>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    std::vector<std::string> args;
    std::vector<std::string> paths;
    bool verbose = false;
    bool parents = false;

    if(argc == 1) {
        printf("Please pass a name!\n");
        return 1;
    }

    for(int i = 1; i < argc; i++) {
        args.emplace_back(argv[i]);
    }

    for(uint i = 0; i < args.size(); i++) {
        if(args[i] == "-h" || args[i] == "--help") {
            printf("mkdir help\n");
            printf("show this menu\n");
            printf("  -h [ --help ]         Show this menu\n");
            printf("  -v [ --verbose ]      Print each directory being created\n");
            printf("  -p [ --parents ]      Create any parent directories if they do not exist\n");
            printf("  -m <int> [ --mode ]   Specify CHMOD mode (e.g. 644)\n");
            return 1;
        }

        if(args[i] == "-v" || args[i] == "--verbose") {
            verbose = true;
        } else if(args[i] == "-p" || args[i] == "--parents") {
            parents = true;
        } else {
            paths.push_back(args[i]);
        }
    }

    for(uint i = 0; i < paths.size(); i++) {
        if(parents) {
            fs::create_directories(paths[i]);
            if(verbose) { printf("Created directory %s\n", paths[i].c_str()); }
        } else {
            fs::create_directory(paths[i]);
            if(verbose) { printf("Created directory %s\n", paths[i].c_str()); }
        }
    }
}