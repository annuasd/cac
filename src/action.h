#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <string>
#include "ast.h"


class Actions {
    public:
    std::unique_ptr<DeclStmt> actOnTypeDecl(std::string Name, int Loc) {
        std::unique_ptr<TypeDecl> tdptr = std::make_unique<TypeDecl>(Name, Loc);
        std::unique_ptr<DeclStmt> dsptr = std::make_unique<DeclStmt> (std::move(tdptr));
        return dsptr;
    }

    void actOnVarDecl(std::unique_ptr<DeclStmt> &dsptr ,std::string name, int loc) {
        std::unique_ptr<VarDecl> ptr = std::make_unique<VarDecl>(name ,loc);
        dsptr->push_back(std::move(ptr));
    }
    virtual ~Actions() {}
};






#endif