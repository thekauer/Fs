#include "source.h"




void error(int code,const std::string& msg) {
    std::cout << "Error: " + std::to_string(code) + " " + msg;
    std::exit(code);
}

void SourceManager::open(const std::string& path) {
    std::ifstream in(path);
    std::string code((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>());
    in.close();
    sources.push_back(FSFile(path,code+"\0\0\0"));
}
/*
void SourceManager::open_(std::experimental::filesystem::path path) {
    using namespace std::experimental::filesystem;
    if(!exists(path)) {
        error(ERR_FILE_NOT_EXISTS,path.concat(" does not exists."));
    }
    if(path.extension()!="fs") {
        error(ERR_ONLY_FS_FILES,"Only files with .fs extension are allowed!");
    }
    std::ifstream in(path);
    std::string code((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>());
    in.close();
    sources.push_back(FSFile(path,code));
}
*/
