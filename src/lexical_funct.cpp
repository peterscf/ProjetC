
#include<iostream>
#include<sstream>
#include<string>

#include"lexem.h"
#include"lexical_funct.h"

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

bool test_lexical(lexem lex){
	string mot=lex.get_nom();
	bool out=true;
	//regle de lexical
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
		return out;
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool test_alphanumeric_et_underscore(string m){
	bool out=true;
	int i=0;
	while(i <= m.size()-1){
		if ((m.at(i) != '_') && (m.at(i) < 'a' || m.at(i) > 'z') && (m.at(i)<'0' || m.at(i)>'9')){
			out= false;
		}
		//cout<<"i="<<i<<"\t"<<m.at(i)<<endl;
		//cout<<out<<endl;
		i++;	
	}
	return out;
}
//Fin programme
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
