/*** Compiler Front-End Test automatically generated by the BNF Converter ***/
/*                                                                          */
/* This test will parse a file, print the abstract syntax tree, and then    */
/* pretty-print the result.                                                 */
/*                                                                          */
/****************************************************************************/
#include <stdio.h>
#include "Parser.H"
#include "Printer.H"
#include "Absyn.H"

int main(int argc, char ** argv)
{
  FILE *input;
  if (argc > 1) 
  {
    input = fopen(argv[1], "r");
    if (!input)
    {
      fprintf(stderr, "Error opening input file.\n");
      exit(1);
    }
  }
  else input = stdin;
  /* The default entry point is used. For other options see Parser.H */
  Program *parse_tree = pProgram(input);
  if (parse_tree)
  {
    printf("\nParse Succesful!\n");
    printf("\n[Abstract Syntax]\n");
    ShowAbsyn *s = new ShowAbsyn();
    printf("%s\n\n", s->show(parse_tree));
    printf("[Linearized Tree]\n");
    PrintAbsyn *p = new PrintAbsyn();
    printf("%s\n\n", p->print(parse_tree));
    return 0;
  }
  return 1;
}

