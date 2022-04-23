#ifndef SCOPE_H
#define SCOPE_H

#include <map>
#include <memory>
#include <string>
#include "ast.h"
class Scope {
    std::shared_ptr<Scope> Parent;
    std::map<std::string, std::shared_ptr<Decl>> Symbols;
    public:
    Scope(std::shared_ptr<Scope> Parent):Parent(Parent){}

    bool insert(std::shared_ptr<Decl>);
    std::shared_ptr<Decl> lookup(std::string name);

    std::shared_ptr<Scope> getParent() {return Parent;}
};







#endif
