#pragma once
#include "lex.h"
#include "parser.h"
#include "source.h"
//#include "llvm/IR/IRBuilder.h"
class Compiler {
 std::vector<std::string> Warnings,Lints;
 SourceManager sm;
 struct CompilerOptions {
     
 };
 public:
  Compiler() : sm(SourceManager()){};
  void compile(const std::string& path);
};
