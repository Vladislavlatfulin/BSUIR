#include "Flags.hpp"
Flags _flags;

void printDirOrFile(std::string path, std::vector<std::string> &files);
std::string getCurrentDirectory(int argc, char **argv);
Flags flagsHandler(int argc, char* argv[]);
void printVectorFile(const std::vector<std::string> &vec);


int main(int argc, char* argv[]) {
    auto path = getCurrentDirectory(argc, argv);
    std::vector<std::string> files;
    
    _flags = flagsHandler(argc, argv);
    printDirOrFile(path, files);
    
    _flags.printFlags();
    
    return 0;
}



std::string getCurrentDirectory(int argc, char **argv) {
    if (argc == 1 || argv[1][0] == '-') { return "./"; }
    return argv[1];
}

Flags flagsHandler(int argc, char* argv[]) {
    Flags flags;
    
    string options;
    bool is_any_flags = false;
    
    if(argv[2]) { options = argv[2]; }
    
    if(options == "TERM_PROGRAM=Apple_Terminal") { options = ""; }
    else if(argc == 1) { options = ""; }
    else if(argv[1][0] == '-') { options = argv[1]; }
    
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
    
    if(is_any_flags == false) { flags.l = flags.d = flags.f = true; }
    
    return flags;
}

void printVectorFile(const std::vector<std::string> &vec) {
    for (const auto& item : vec)
        std::cout << item << std::endl;
}


void printDirOrFile(std::string path, std::vector<std::string> &files) {
    DIR *dir;
    struct dirent *entry;
    
    if (path.back() == '/') { path.pop_back(); }
    
    dir = opendir(path.c_str());
    
    while ((entry = readdir(dir))) {
        const std::string dirName = entry->d_name;
        std::string temp;
        
        if (entry->d_type == DT_DIR && (dirName == "." || dirName == "..")) { continue; }
        
        bool show_dir_only = false;
        if (_flags.d && !_flags.l && !_flags.f) { show_dir_only = true; }
        
        if (!show_dir_only && _flags.l && entry->d_type == DT_LNK) {
            temp = path + '/' + entry->d_name;
            files.push_back(temp);
            printDirOrFile(temp, files);
        }
        
        if (!show_dir_only && _flags.f && entry->d_type == DT_REG) {
            temp = path + '/' + entry->d_name;
            files.push_back(temp);
        }
        
        if (_flags.d && entry->d_type == DT_DIR) {
            temp = path + '/' + entry->d_name;
            files.push_back(temp);
            printDirOrFile(temp, files);
        }
    }
    
    if (_flags.s) { std::sort(files.begin(), files.end()); }
    
    printVectorFile(files);
    files.clear();
    closedir(dir);
    
}


