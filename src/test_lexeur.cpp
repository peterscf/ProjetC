#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "lexeur.h"
#include "Dictionnaire.h"
#include "Analyse_lexical.h"

using namespace std;


int main ()
{
vector < lexem* > Lx ; //CREATION DU VECTEUR

Lx = lexeur("arbiter.vhd");//Lexeur

Analyse_lexical (Lx);

affichage_vector(Lx);//affichage de chaque lexems du lexeur
}
