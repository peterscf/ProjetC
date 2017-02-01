#include<iostream>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>
#include <vector>
#include <stack>


#include"lexem.h"
#include"node.h"
#include"ref_tree.h"
#include"Analyse_gramaticale.h"

using namespace std;
//variable glabale des fonction
ref_tree library_tree("./ref_tree/library_use.tree");
ref_tree use_tree("./ref_tree/use.tree");
ref_tree entity_tree("./ref_tree/entity.tree");
ref_tree architecture_tree("./ref_tree/architecture.tree");

ref_tree declaration_port_tree("./ref_tree/declaration_port.tree");		
ref_tree declaration_signal_tree("./ref_tree/declaration_signal.tree");
ref_tree type_vector_tree("./ref_tree/type_vector.tree");
ref_tree port_tree("./ref_tree/port.tree");
ref_tree component_tree("./ref_tree/component.tree");
ref_tree affectation_signal_tree("./ref_tree/affectation_signal.tree");
ref_tree affectation_variable_tree("./ref_tree/affectation_variable.tree");
ref_tree assignement_signal_tree("./ref_tree/assignement_signal.tree");
ref_tree case_tree("./ref_tree/case.tree");
ref_tree declaration_variable_tree("./ref_tree/declaration_variable.tree");

ref_tree if_tree("./ref_tree/if.tree");
ref_tree else_tree("./ref_tree/else.tree");
ref_tree elsif_tree("./ref_tree/elsif.tree");

ref_tree port_map_tree("./ref_tree/port_map.tree");

ref_tree process_tree("./ref_tree/process.tree");
ref_tree liste_de_sensib_tree("./ref_tree/liste_de_sensib.tree");

ref_tree test_if_tree("./ref_tree/test_if.tree");
ref_tree test_if_clk_tree("./ref_tree/test_if_clk.tree");
ref_tree test_if_parenthese_tree("./ref_tree/test_if_parenthese.tree");
ref_tree when_tree("./ref_tree/when.tree");
ref_tree when_parenthese_tree_txt("./ref_tree/when_parenthese.tree");
ref_tree when_case_tree("./ref_tree/when_case.tree");

string position_lex;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//fonction 
void Analyse_gramaticale(vector <lexem*> Lx_vector){

	node* node_courant=NULL;
	stack<node*> node_precedant;
	vector < lexem* >::iterator itr_lex;
	string path="./ref_tree/";
	

	//string position_lex;
	
	for (itr_lex = Lx_vector.begin(); itr_lex != Lx_vector.end(); ++itr_lex){
		//affichage debug
		(*(*itr_lex)).affiche_lexem();
		
		//test si etiquette existe deja !
		if((*(*itr_lex)).get_type()=="etiquette"){
				//test si le lexem etiquette existe !
				for (vector < lexem* >::iterator itr2 = Lx_vector.begin(); itr2 != itr_lex; ++itr2){
					if((*(*itr_lex)).get_nom()==(*(*itr2)).get_nom() && (*(*itr2)).get_type() != "etiquette"){
						(*(*itr_lex)).set_type((*(*itr2)).get_type());
						break;
					}
					
				}
				(*(*itr_lex)).affiche_lexem();		
			}
			
			
		//traitement du pointeur quand il ya un lien dans l'arbre de ref
		
		
		if((*(*itr_lex)).get_type() == "architecture"){
			//pointer sur architecture_tree
			node_courant = architecture_tree.get_root();
			node_precedant.push(node_courant);
			position_lex="architecture";
		}
		else if((*(*itr_lex)).get_type() == "entity"){
			//pointer sur entity_tree
			node_courant = entity_tree.get_root();
			node_precedant.push(node_courant);
			position_lex="entity";
		}
		else if((*(*itr_lex)).get_type() == "use"){
			//pointer sur use_tree
			node_courant = use_tree.get_root();
			node_precedant.push(node_courant);
			position_lex="use";
		}
		else if((*(*itr_lex)).get_type() == "library"){
			//pointer sur library_tree
			node_courant = library_tree.get_root();
			node_precedant.push(node_courant);
			position_lex="library";
		} 
		
		else if((node_courant->get_value()).find(".")!=string::npos){
			node_precedant.push(node_courant);
			node_courant = lien_vers_sous_arbre(node_courant);
		}
		
		/////////////////////////////////////////////////////////
		//test gramaticale
		if (node_courant->get_value() == "%fin"){
						//node_precedant = node_precedant->get_child();
						node_courant= node_precedant.top()->get_child();
						node_precedant.pop();
						cout<<"/!\\node precedant : "<< node_courant->get_value()<<endl;
		}
		
		
		if ((*(*itr_lex)).get_type() == node_courant->get_value()){
			cout<<"node comparaison : "<< node_courant->get_value()<<endl;
			if((*(*itr_lex)).get_type()=="etiquette"){
				(*(*itr_lex)).set_type("etiquette_"+position_lex);
				(*(*itr_lex)).affiche_lexem();				
			}
			node_courant = node_courant->get_child();
		}
		else{ //node courant ne correspond pas au lexem
			while(node_courant != NULL){ //test si c'est un des frere ?
				
				while (node_courant->get_value() == "%fin"){
						if( (node_precedant.top())->get_child() != NULL){
							node_courant = (node_precedant.top())->get_child();
						}
						else{
							node_courant = (node_precedant.top())->get_bros();
						}
						node_precedant.pop();
						cout<<"/!\\node precedant dans while: "<< node_courant->get_value()<<endl;
				}
				if((node_courant->get_value()).find(".")!=string::npos){
					node_precedant.push(node_courant);
					node_courant = lien_vers_sous_arbre(node_courant);
				}
				
				if ((*(*itr_lex)).get_type() == node_courant->get_value()){
					cout<<"node comparaison : "<< node_courant->get_value()<<endl;
					node_courant = node_courant->get_child();
					break;
				}
				
				
				else{
					if (node_courant->get_bros() == NULL && node_courant->get_value() != "%fin"){
						
						//cout<<"/!\\node precedant.top dans if: "<< (node_precedant.top())->get_value()<<endl;
						//cout<<"/!\\node precedant.top dans if bros: "<< ((node_precedant.top())->get_bros())->get_value()<<endl;
						node_courant = (node_precedant.top())->get_bros();
						node_precedant.pop();
						cout<<"/!\\node precedant dans if: "<< node_courant->get_value()<<endl;
					}
					else{
						node_courant = node_courant->get_bros();
					}
				}
			}
			if (node_courant == NULL){
					cout <<"erreur de syntaxe : "<<(*(*itr_lex)).get_nom()<<endl<< "ligne "<<(*(*itr_lex)).get_line_pos()<<endl;
					//break;//kill programme
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//lien vers sous arbre
node * lien_vers_sous_arbre(node* link){




			if(link->get_value() =="port.tree" ){
				link = port_tree.get_root();
			}
			else if(link->get_value() =="declaration_port.tree" ){
				position_lex="signal";
				link = declaration_port_tree.get_root();
			}
			else if (link->get_value() =="declaration_signal.tree"){
				position_lex="signal";			
				link = declaration_signal_tree.get_root();
			
			}
			else if(link->get_value() =="type_vector.tree" ){
				//pointer sur signal_tree
				link = type_vector_tree.get_root();
			}
			else if(link->get_value() =="component.tree" ){
				//pointer sur veriable_tree
				link = component_tree.get_root();
			}
			else if ( link->get_value() == "affectation_signal.tree" ){
			 link= affectation_signal_tree.get_root();
			}
			else if ( link->get_value() == "affectation_variable.tree" ){
			 link= affectation_variable_tree.get_root();
			}
			else if ( link->get_value() == "assignement_signal.tree" ){
			 link= assignement_signal_tree.get_root();
			}
			else if ( link->get_value() == "case.tree" ){
			 link= case_tree.get_root();
			}
			else if ( link->get_value() == "declaration_variable.tree" ){
			 link= declaration_variable_tree.get_root();
			}
			else if ( link->get_value() == "if.tree" ){
			 link= if_tree.get_root();
			}
			else if ( link->get_value() == "else.tree" ){
			 link= else_tree.get_root();
			}
			else if ( link->get_value() == "elsif.tree" ){
			 link= elsif_tree.get_root();
			}
			else if ( link->get_value() == "port_map.tree" ){
			 link= port_map_tree.get_root();
			}
			else if ( link->get_value() == "process.tree" ){
			 link= process_tree.get_root();
			}
			else if ( link->get_value() == "liste_de_sensib.tree" ){
			 link= liste_de_sensib_tree.get_root();
			}
			else if ( link->get_value() == "test_if.tree" ){
			 link= test_if_tree.get_root();
			}
			else if ( link->get_value() == "test_if_clk.tree" ){
			 link= test_if_clk_tree.get_root();
			}
			else if ( link->get_value() == "test_if_parenthese.tree" ){
			 link= test_if_parenthese_tree.get_root();
			}
			else if ( link->get_value() == " when.tree" ){
			 link= when_tree.get_root();
			}
			else if ( link->get_value() == "when_parenthese.tree" ){
			 link= when_parenthese_tree_txt.get_root();
			}
			else if ( link->get_value() == "when_case.tree" ){
			 link= when_case_tree.get_root();
			}
			else{
				link =NULL;
			}
			return link;
		}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//Fin du programme
