#pragma once
#include <iostream>
#include <vector>
#include "compatibility.h"
#include <fstream>

void error(int code,const std::string& msg);
struct FSFile {
    const std::string path;
    const std::string code;
    FSFile(const std::string path,const std::string code) :path(path),code(code){};
};
class SourceManager {
public:
    std::vector<FSFile> sources;
    SourceManager()=default;
    void open(const std::string& path);
    //void open_(std::experimental::filesystem::path path);
};

