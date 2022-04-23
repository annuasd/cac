#include <iostream>
#include <memory>
#include <vector>
#include <string.h>

#include "ast.h"
#include "action.h"
#include "Parser.h"
extern int yyparse();

int main() {
  // std::unique_ptr<DeclStmt> ptr;
  // Actions action;
  // ptr = action.actOnTypeDecl("int", 11);
  // action.actOnVarDecl(ptr, "a", 11);
  // action.actOnVarDecl(ptr, "b", 12);
  // for(auto it = ptr->get_begin(); it != ptr->get_end(); it++) {
    
  //   std::cout <<  (*it)->getName()  << std::endl;
  // } 
  yyparse();
  return 0;
}