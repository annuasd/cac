#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex(driver &drv)
YY_DECL;
class driver {
    public:
    int res;
    void scan_begin();
    void scan_end();
    yy::location location;
    void parse() {
        scan_begin();
        yy::parser parse(*this);
        parse();
        scan_end();
    }
};

#endif