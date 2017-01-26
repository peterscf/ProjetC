#include <string>
#include <string.h>
#include <vector>
#include "lexeur.h"
#include "Dictionnaire.h"
#include "Analyse_lexical.h"

//using namespace std;




////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//Fonction Analyse lexical

void Analyse_lexical (vector < lexem* > Lx_vector){
Dictionnaire vhd_dico("VHDL.dico");
vector < lexem* >::iterator itr;


	for (itr = Lx_vector.begin(); itr != Lx_vector.end(); ++itr){		//lit la liste chainée		
		if(test_orthographe){
			vhd_dico.Type((*itr));
			
			//traitement des chiffres
			string test_lex=(*(*itr)).get_nom();
			if(test_lex.at(0) >= '0' && test_lex.at(0) <= '9'){
				(*(*itr)).set_type("valeur_numerique");
			}
			
			//Typage des etiquette !!!		
			/*if ((*(*itr)).get_type()=="etiquette"){
				string type_prec = (*(*(itr-1))).get_type();
			
				if(type_prec == "signal"){ //signal
						(*(*itr)).set_type("etiquette_signal");
				}
				else if(type_prec == "variable"){ //variable
						(*(*itr)).set_type("etiquette_variable");
				}
				else if(type_prec == 	"entity" ) {//entity
						(*(*itr)).set_type("etiquette_entity");
				}
				else if(type_prec == "architecture" ) {//Architecture
						(*(*itr)).set_type("etiquette_architecture");
				}
				else if(type_prec == "architecture" ) {//Architecture
						(*(*itr)).set_type("etiquette_architecture");
				}
				else{
					for (vector < lexem* >::iterator itr2 = Lx_vector.begin(); itr2 != itr; ++itr2){
						if((*(*itr)).get_nom()==(*(*itr2)).get_nom() && (*(*itr2)).get_type() != "etiquette"){
								(*(*itr)).set_type((*(*itr2)).get_type());
								break;
						}	
					}
				} 
			}//if etiquette */
		}//if test orthographe
	}//for
}//fonction



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

bool test_orthographe(lexem lex){
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
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
