#include<iostream>
#include<sstream>
#include<string>
#include"lexem.h"
#include"Dictionnaire.h"

#include <iostream>
#include <string>

using namespace std;

bool test_syntaxe(lexem lex);
bool test_alphanumeric_et_underscore(string m);
//void type_lexem (Lexem lex);

int main(void){
	string mot="abcd_12";
	lexem lex1(mot);
	Dictionnaire Dico("lexem_type.dico");
	
	cout<<"nom: "<<lex1.get_nom()<<endl;
		
	//Dico.affiche_vect();
	if(test_syntaxe(lex1)==true){
		cout <<"test lexical retourne vrai"<<endl;
		cout<<"nom: "<<lex1.get_nom()<<endl;
		cout<<"type: "<< lex1.get_type()<<endl;
		cout<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;
	}
	else {
		cout<<"erreur de syntaxe !!!"<<endl;
	}
	

	/*
	Dico.Type(&lex1);
	
	cout<<"nom: "<<lex1.get_nom()<<endl;
	cout<<"type: "<< lex1.get_type()<<endl;
	cout<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;*/
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

bool test_syntaxe(lexem lex){
	string mot=lex.get_nom();
	bool out = false;
	//regle de syntaxe
	if (mot.find("_")==0 || mot.find("_")==(mot.size()-1)){
		out=false;
	}	
	else if (mot.at(0) <= 'a' && mot.at(0) >= 'z'){
		out=false;
	}
	else if (mot.at((mot.size()-1)) == '_'){
		out=false;
	}
	else if (test_alphanumeric_et_underscore(mot) != true){
		out=false;
	}
	else{
		out = true;
	}
		return out;
}

bool test_alphanumeric_et_underscore(string m){
	bool out;
	int i=0;
	while(/*i<m.size()*/ m.at(i) == '\0' /*|| out!=false*/){
		if ((m.at(i) != '_') || (m.at(i) < 'a' && m.at(i) > 'z') || (m.at(i)<'0' && m.at(i)>'9')){
			out=false;
		}
		i++;	
	}
}
//Fin programme
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

