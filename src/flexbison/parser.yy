%skeleton "lalr1.cc" 
%require "3.8"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  class driver;
}

%param { driver& drv }

%code {
  #include "driver.h"
  #include <string>
  #include <iostream>
  #include <memory>
}

%locations

%token
MINUS "-"
PLUS "+"
SEMI ";"
EQUL "="
COMMA ","
;

%start unit
%token <int> NUMBER
%nterm <int> exp

%%














%%
void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}