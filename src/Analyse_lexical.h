#ifndef ANALYSE_LEXICAL_H_
#define ANALYSE_LEXICAL_H_

#include <string>
#include <string.h>
#include <vector>
#include "lexeur.h"
#include "Dictionnaire.h"
#include "Analyse_lexical.h"

void Analyse_lexical (vector < lexem* > Lx_vector);
bool test_orthographe(lexem lex);
bool test_alphanumeric_et_underscore(string m);



#endif
