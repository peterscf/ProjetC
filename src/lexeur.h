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

bool test_caractere_special (char c); //fonction qui gere cherche la presence des caractere spéciaux simples (;()[]+-*.\",!&)
void affichage_vector(vector < lexem* > myLx); //fonction qui permet l'affiche du vector dans lequel sont places tous les lexemes
vector <lexem* > lexeur(string file_name); //fonction lexeur

#endif
