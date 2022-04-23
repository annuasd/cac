#ifndef AST_H
#define AST_H
#include <memory>
#include <string>
#include <vector>
class Ast {
    public:
    virtual ~Ast() {}
};

class Decl: public Ast {
    public:
    enum Declkind {
        DK_Var,
        DK_Type
    };
    private:
    const Declkind Kind;

    protected:
    std::string Name;
    int Loc;

    public:
    Decl(Declkind Kind, std::string Name, int Loc):Kind(Kind), Name(Name), Loc(Loc){}
    Declkind getKind() const {return Kind;}
    std::string getName() {return Name;}
    int getLoc() {return Loc;}
};

class TypeDecl: public Decl {
    public:
    TypeDecl(std::string Name, int Loc): Decl(DK_Type, Name, Loc) {}
    static bool classof  (const Decl *D) { return D->getKind() == DK_Type;}
};

class VarDecl: public Decl {
    std::unique_ptr<Ast> Value;
    public:
    VarDecl(std::string Name, int Loc):
    Decl(DK_Var, Name, Loc){}
    VarDecl(std::string Name, int Loc,  std::unique_ptr<Ast> Value):
    Decl(DK_Var, Name, Loc), Value(std::move(Value)){}
};

class Stmt: public Ast {
  public: 
  enum StmtKind {
      SK_Decl
  };
  
  private:
  const StmtKind Kind;

  public:
  Stmt(StmtKind Kind): Kind(Kind) {}
  StmtKind getKind() const {return Kind;}
}; 

class DeclStmt: public Stmt {
    std::shared_ptr<TypeDecl> Ty;
    public:
    std::vector< std::unique_ptr<VarDecl> > VarList;
    public:
    DeclStmt(std::shared_ptr<TypeDecl> Ty): Stmt(SK_Decl), Ty(Ty){}
    void push_back(std::unique_ptr<VarDecl> Var) {
        VarList.push_back(std::move(Var));
        return;
    }
    std::vector< std::unique_ptr<VarDecl>> ::iterator get_begin() {
        return VarList.begin();
    }
    std::vector< std::unique_ptr<VarDecl>> ::iterator get_end() {
        return VarList.end();
    }
};

#endif






