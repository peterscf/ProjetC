#include<iostream>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>

#include "Analyse_lexical.h"
#include "Analyse_gramaticale.h"


int main (int argc, char *argv[])
{

//string file ="./test_file_vhd/arbiter.vhd";
//string file ="./test_file_vhd/test_lexeur.txt";
//string file ="./test_file_vhd/filtre.vhd";
//string file ="./test_file_vhd/arbiter.vhd";


vector < lexem* > Lx ; //CREATION DU VECTEUR
//string file = argv[1];

string file ="./test_file_vhd/arbiter.vhd";

//test présence nom de la library
	/*if (argc==1){
		cout<<"Error: too few arguments !" << endl
			<<"example:\t\"vhdllib <$path/name of physical library>\""
			<< endl;
	}
	else if(argc>2){
		cout<<"Error: too much arguments !" << endl
			<<"example:\t\"vhdllib <$path/name of physical library>"
			<< endl;
	}
	else { */
		Lx = lexeur(file);//Lexeur
		Analyse_lexical (Lx);
		Analyse_gramaticale(Lx);
	//}
//création de l'arbre pré-synthèse


}
