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

string file ="./test_file_vhd/arbiter.vhd";
//string file ="./test_file_vhd/test_lexeur.txt";
//string file ="./test_file_vhd/filtre.vhd";
//string file ="./test_file_vhd/arbiter.vhd";

vector < lexem* > Lx ; //CREATION DU VECTEUR

Lx = lexeur(file);//Lexeur

Analyse_lexical (Lx);

affichage_vector(Lx);//affichage de chaque lexems du lexeur
}
