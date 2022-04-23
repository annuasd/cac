%{
#include <string.h>
#include "driver.h"
#include "parser.tab.hh"
%}
%option noyywrap nodefault nounput noinput batch 

%{
    # define YY_USER_ACTION  loc.columns (yyleng);
%}

blank [ \t\r]

%%

%{
    yy::location &loc = drv.location;   
    loc.step();
%}

{blank}+                loc.step();
\n+                     loc.lines(yyleng);loc.step();
[1-9]+[0-9]*            return yy::parser::make_NUMBER (atol(yytext), loc);
"+"                     return yy::parser::make_PLUS(loc);
"-"                     return yy::parser::make_MINUS(loc);
";"                     return yy::parser::make_SEMI(loc);
"="                     return yy::parser::make_EQUL(loc);
","                     return yy::parser::make_COMMA(loc);
<<EOF>>                 return yy::parser::make_YYEOF(loc);

%%
void driver::scan_begin() {
    yyin = stdin;
}
void driver::scan_end() {
    fclose(yyin);
}