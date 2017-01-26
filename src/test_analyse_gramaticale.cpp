#include<iostream>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>

#include "Analyse_lexical.h"
#include "Analyse_gramaticale.h"
int main ()
{

//string file ="./test_file_vhd/arbiter.vhd";
//string file ="./test_file_vhd/test_lexeur.txt";
//string file ="./test_file_vhd/filtre.vhd";
//string file ="./test_file_vhd/arbiter.vhd";


vector < lexem* > Lx ; //CREATION DU VECTEUR

string file ="./test_file_vhd/arbiter.vhd";

 
		Lx = lexeur(file);//Lexeur
		Analyse_lexical (Lx);
		Analyse_gramaticale(Lx);



}
