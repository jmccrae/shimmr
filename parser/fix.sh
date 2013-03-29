#!/bin/bash

mv Absyn.C Absyn.cpp
mv Printer.C Printer.cpp
mv Skeleton.C Skeleton.cpp
flex -o lexer.cpp shimmr.l
bison -o parser.cpp shimmr.y
perl -pi -e 's/_STRING_/__STRING_/g' *.cpp *.H
perl -pi -e 's/yyin = inp; BEGIN YYINITIAL;/yyin = inp; BEGIN YYINITIAL; return 0;/' lexer.cpp
