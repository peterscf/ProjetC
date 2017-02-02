#include<iostream>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include "Analyse_lexical.h"
#include "Analyse_gramaticale.h"


int main (int argc, char *argv[])
{


vector < lexem* > Lx ; //CREATION DU VECTEUR
string file=argv[2];
string opt=argv[1];
bool debug=false;

		if(argc == 3){
			if(opt == "-d"){
				debug=true;
			}
		}
		else if(argc == 2){
				file = argv[1];
		}
		else if(argc > 4){
			cout<<"Error: too much arguments !" << endl
				<<"example:\t\"vhdlcomp <option> <$path/name_of_file_.vhd>\""
				<< endl;
		}
		Lx = lexeur(file);//Lexeur
		Analyse_lexical (Lx);
		Analyse_gramaticale(Lx,debug);
//création de l'arbre pré-synthèse


}
