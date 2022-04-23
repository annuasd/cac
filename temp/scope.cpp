#include "scope.h"
#include <map>

bool Scope::insert(std::shared_ptr<Decl> ptr) {
    return Symbols.insert(std::pair{ptr->getName(), ptr}).second;
}

