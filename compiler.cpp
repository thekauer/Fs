#include "compiler.h"


void Compiler::compile(const std::string& path) {
    sm.open(path);
    SourceLocation sl(sm.sources[0]);
    //HashedString hs;
    //while(sl.can_iter())std::cout << (int)advance_token(sl,hs) << " ";
    parse(sl);
    /*
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
    llvm::LLVMContext context{};
    auto module = std::make_unique<llvm::Module>("test",context);
    llvm::FunctionPassManager fpm;
    */


     
    
}

