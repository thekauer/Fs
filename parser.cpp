#include "parser.h"



std::unique_ptr<AstExpr> Parser::parse_kw() {
    auto kw =it.peek<Kw>()->kw;
    switch(kw) {
        case Kw::Fn:
            return parse_fn();
        default:
            return nullptr;
    }
}


std::unique_ptr<FnCall> Parser::parse_fn_call() {
    return nullptr;
}


std::unique_ptr<AstExpr> Parser::parse_fn_body(){}

std::unique_ptr<AstExpr> Parser::parse_id() {

    switch (it.peek(1)->type)
    {
    case Lexem::Op: {
        auto op = it.peek<Op>()->op;
        switch (op)
        {
        //fn call , if it is a < it migh as well be fncall
        case Op::Lp:
            return parse_fn_call();
            
        
        default:
            nullptr;
        }
    }
    default:
        return nullptr;
       
    }
}

std::unique_ptr<AstExpr> Parser::parse() {
    switch (it.peek()->type)
    {
    case Lexem::Kw:
        return parse_kw();
        break;
    case Lexem::Id:
        return parse_id();
    default:
        break;
    }
}


std::unique_ptr<FnDecl> Parser::parse_fn() {
    it.pop();//pop the fn keyword
    auto pname = it.pop();
    if(pname->type!=Lexem::Id) {
        //erro function name must follow the fn keyword
    }
    auto pfname = icast<Id>(pname);
    //warn function name case
    auto name = pfname->id;

    auto pop = it.pop(); // either < or (
    if(pop->type!=Lexem::Op) {
        //error expected < or (
    }
    auto op = icast<Op>(pop)->op;
    if(op==Op::Lt) {//<
        //parse generic args
    }
    //Put the ( after the generics into op
    if(op!=Op::Lp) {
        //error expected (
    }

    //Parse args

    //put the ) after args into op
    
    op=icast<Op>(pop)->op;
    if(op!=Op::Rp) {
        //error expected )
    }
    op=icast<Op>(pop)->op;
    if(op!=Op::Gi) {
        //error empty fn body
    }
    auto body = parse_fn_body();

    auto ret = std::make_unique<FnDecl>(name);
    ret->body=std::move(parse_fn_body());
    return ret;

}