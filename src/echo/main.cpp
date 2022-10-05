#include <iostream>

// not sure if this works or not
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const int win = 1;
#else
    const int win = 0;
#endif

int main(int argc, const char* argv[]) {
    int backslashEscapes;
    int args;
    int newline;

    if(argv[1] == std::string("--help")) {
        // TODO write/copy help?
        std::cout << "helpful help text that is supposed to help you";
        return 0;
    }

    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            args++;
            switch(argv[i][1]) {
                case 'E':
                    backslashEscapes = 0;
                    break;
                case 'e':
                    backslashEscapes = 1;
                    break;
                case 'n':
                case 'N':
                    newline = 1;
                    break;
                default:
                    std::cout << "Invalid argument: \"" << argv[i] << "\"";
                    return 1;
            }
        } else {
            while (argc > 0) {
                argc--;
                argv++;
                if (argc > 0) {
                    fputs(argv[0 + args], stdout);
                    putchar(' ');
                }
            }
        }
    }

    // TODO find potential fix for windows?
    if(newline != 1 && win == 0) {
        putchar('\n');
    }
    
    if(backslashEscapes == 1) {
        // TODO implement backslash escape interpretation

        /*  
            \\ backslash
            \a alert (BEL)
            \b backspace
            \c produce no further output
            \e escape
            \f form feed
            \n new line
            \r carriage return
            \t horizontal tab
            \v vertical tab
            \0NNN byte with octal value NNN (1 to 3 digits)
            \xHH byte with hexadecimal value HH (1 to 2 digits)
        */
    }

    return 0;
}