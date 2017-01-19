#ifndef _LEXEUR_H__
#define _LEXEUR_H__

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "lexem.h"



using namespace std;

bool test_caractere_special (char c);
void affichage_vector(vector < lexem* > myLx);
vector <lexem* > lexeur(string file_name);

#endif
