#include <cstdio>
#include <exception>
#include <sstream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if(argc == 1) {
        printf("Missing options, use %s --help for information\n", argv[0]);
        return 1;
    }

    if(!strcmp(argv[1], "--help")) {
        printf("sleep help\n");
        printf("Usage: sleep <options>\n");
        printf("Options by default are in seconds, but you can change it by suffixing m, h, or d\n");
        printf("--help    Display this menu\n");
        return 1;
    }

    int total = 0;
    float mTotal = 0;

    for(int i = 1; i < argc; i++) {
        int num = 0;
        float mNum = 0;
        int mult = 1;
        int len = strlen(argv[i]);
        bool suf = false;

        std::string arg = argv[i];
        // arg[(ulong)len - 1]

        if(arg[(ulong)len - 1] == 's') {
            mult = 1;
            suf = true;
        } else if(arg[(ulong)len - 1] == 'm') {
            mult = 60;
            suf = true;
        } else if(arg[(ulong)len - 1] == 'h') {
            mult = 3600;
            suf = true;
        } else if(arg[(ulong)len - 1] == 'd') {
            mult = 86400;
            suf = true;
        } else if(arg[(ulong)len - 1] == '0' || arg[(ulong)len - 1] == '1' || arg[(ulong)len - 1] == '2' || arg[(ulong)len - 1] == '3' ||
                  arg[(ulong)len - 1] == '4' || arg[(ulong)len - 1] == '5' || arg[(ulong)len - 1] == '6' || arg[(ulong)len - 1] == '7' ||
                  arg[(ulong)len - 1] == '8' || arg[(ulong)len - 1] == '9') {

            mult = 1;

        } else {
            printf("Not a valid time, use %s --help for information\n", argv[0]);
            return 1;
        }

        if(suf) { arg.pop_back(); }

        try {
            mNum = std::stof(arg);
        } catch(std::exception &e) {
            &e;

            num = std::stoi(arg);
        }

        num *= mult;
        mNum *= (float)mult;
        total += num;
        mTotal += mNum;
    }

    sleep((uint)total);
    usleep((uint)(mTotal * 1000000));
    return 0;
}