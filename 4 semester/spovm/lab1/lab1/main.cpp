#include "Flags.hpp"
Flags flags;

string get_initial_directory(int argc, char* argv[]);
void print_vector(const vector<string> &vec);
void get_flags(int argc, char* argv[]);
Flags flagsHandler(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    auto path = get_initial_directory(argc, argv);
    vector<string> files;

    get_flags(argc, argv);
    flags.print_flags();
    flags = flagsHandler(argc, argv);

    return 0;
}

string get_initial_directory(int argc, char* argv[]) {
    if (argc == 1 || argv[1][0] == '-')
        return "./";

    return argv[1];
}

void print_vector(const vector<string> &vec) {
    for (const auto& item : vec)
        cout << item << endl;
}

void get_flags(int argc, char* argv[]) {
    bool has_any_flags = false;

    int c = 0;
    while ( (c = getopt(argc, argv, "ldfs")) != -1) {
        if (c == 'l' || c == 'd' || c == 'f' || c == 's')
            has_any_flags = true;

        switch (c) {
            case 'l':
                flags.l = true;
                break;
            case 'd':
                flags.d = true;
                break;
            case 'f':
                flags.f = true;
                break;
            case 's':
                flags.s = true;
                break;

            default:
                throw runtime_error("Wrong options!");
        }
    }
    if (!has_any_flags)
        flags.d = flags.f = flags.l = true;
}

Flags flagsHandler(int argc, char* argv[]) {
    Flags flags;

    //int option;
    string options;
    bool is_any_flags = false;
    
    if(argv[2])
        options = argv[2];


    if(options == "TERM_PROGRAM=Apple_Terminal")
        options = "";
    else if(argc == 1)
        options = "";
    else if(argv[1][0] == '-')
        options = argv[1];
    
    for(int i = 0; i < options.length(); i++) {
        switch (options[i]) {
            case 'l':
                flags.l = true;
                is_any_flags = true;
                break;
            case 'd':
                flags.d = true;
                is_any_flags = true;
                break;
            case 'f':
                flags.f = true;
                is_any_flags = true;
                break;
            case 's':
                flags.s = true;
                break;
            case '-':
                break;
            default:
                throw std::domain_error("Unexpected flags");
        }
    }

    if(is_any_flags == false)
        flags.l = flags.d = flags.f = true;
    
    return flags;
}
