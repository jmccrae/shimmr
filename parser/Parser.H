#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>

class Program;
class StatementBlock;
class ListStatement;
class Statement;
class Decl;
class ElseBlock;
class Exp;
class Argument;
class ListArgument;
class ListExp;
class Type;
class SetTypeElem;
class ListSetTypeElem;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  StatementBlock* statementblock_;
  ListStatement* liststatement_;
  Statement* statement_;
  Decl* decl_;
  ElseBlock* elseblock_;
  Exp* exp_;
  Argument* argument_;
  ListArgument* listargument_;
  ListExp* listexp_;
  Type* type_;
  SetTypeElem* settypeelem_;
  ListSetTypeElem* listsettypeelem_;
} YYSTYPE;

#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define __STRING_ 290
#define _INTEGER_ 291
#define _DOUBLE_ 292
#define _IDENT_ 293

extern YYSTYPE yylval;
Program* pProgram(FILE *inp);
StatementBlock* pStatementBlock(FILE *inp);
ListStatement* pListStatement(FILE *inp);
Statement* pStatement(FILE *inp);
Decl* pDecl(FILE *inp);
ElseBlock* pElseBlock(FILE *inp);
Exp* pExp(FILE *inp);
Argument* pArgument(FILE *inp);
ListArgument* pListArgument(FILE *inp);
ListExp* pListExp(FILE *inp);
Type* pType(FILE *inp);
SetTypeElem* pSetTypeElem(FILE *inp);
ListSetTypeElem* pListSetTypeElem(FILE *inp);


#endif
