#include<iostream>
#include<sstream>
#include<string>
#include"lexem.h"
#include"Dictionnaire.h"

#include <iostream>
#include <string>

using namespace std;

bool test_syntaxe(lexem lex);
//void type_lexem (Lexem lex);

int main(void){
	string mot="ABC";
	lexem lex1(">=");
	Dictionnaire Dico("lexem_type.dico");
		
	Dico.affiche_vect();
	
	cout<< (mot.front()) <<endl;
	
	cout<<"nom: "<<lex1.get_nom()<<endl;
	cout<<"type: "<< lex1.get_type()<<endl;
	cout<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;
	
	Dico.Type(&lex1);
	
	cout<<"nom: "<<lex1.get_nom()<<endl;
	cout<<"type: "<< lex1.get_type()<<endl;
	cout<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;
		return 0;
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/*Règles d’orthographe des lexèmes en VHDL :
Un lexème peut être composé de caractères alphanumériques et d’underscore(s)
Les underscore(s) peuvent être utilisés dans un lexème à condition qu’ils ne soient 
ni le premier, ni le dernier caractère de celui-ci
Le premier caractère du lexème doit être une lettre
Un caractère spécial est un lexème
Un lexème ne peut contenir un autre lexème
*/
/*
bool test_syntaxe(lexem lex){
	string mot=lex.get_nom();
	bool out = true;

	//regle de syntaxe
	if (mot.find("_")==0 || mot.find("_")==mot.length()){
		out=false;
	}	
	else if (mot.front() < 'a' && mot.front() > 'z'){
		out=false;
	}
		return out;
}*/
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/*void type_lexem(lexem lex){

}

*/
