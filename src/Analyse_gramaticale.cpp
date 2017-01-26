#include<iostream>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>
#include <vector>

#include"lexem.h"
#include"node.h"
#include"ref_tree.h"

using namespace std;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//fonction 
void Analyse_gramaticale(vector <lexem*> Lx_vector){

	node* node_courant=NULL;
	vector < lexem* >::iterator itr_lex;
	
	ref_tree RefTree("arbre_de_ref.dico");
	string position_lex;
	
	for (itr_lex = Lx_vector.begin(); itr_lex != Lx_vector.end(); ++itr_lex){
		(*(*itr_lex)).affiche_lexem();
		
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
		
		if((*(*itr_lex)).get_type() == "architecture"){
			//pointer sur architecture_tree
			node_courant = RefTree.get_architecture_tree();
			position_lex="architecture";
		}
		else if((*(*itr_lex)).get_type() == "port"){
			//pointer sur port_tree
			node_courant = RefTree.get_port_tree();
			position_lex="port";
		}
		else if ((*(*itr_lex)).get_type() == "etiquette" && position_lex == "port"){
		
			node_courant = RefTree.get_decl_port_tree();
		}
		else if((*(*itr_lex)).get_type() == "entity"){
			//pointer sur port_tree
			node_courant = RefTree.get_entity_tree();
			position_lex="entity";
		}
		else if((*(*itr_lex)).get_type() == "type_signal"){
			//pointer sur signal_tree
			node_courant = RefTree.get_signal_tree();
			position_lex="signal";
		}
		else if((*(*itr_lex)).get_type() == "variable"){
			//pointer sur veriable_tree
			node_courant = RefTree.get_variable_tree();
			position_lex="variable";
		}
		else if((*(*itr_lex)).get_type() == "library"){
			//pointer sur library_tree
			node_courant = RefTree.get_library_tree();
			position_lex="library";
		}
		else if((*(*itr_lex)).get_type() == "use"){
			//pointer sur use_tree
			node_courant = RefTree.get_use_tree();
			position_lex="use";
		}
		else if((*(*itr_lex)).get_type() == "if"){
			//pointer sur if_tree
			node_courant = RefTree.get_if_tree();
			position_lex="if";
		}
		else if((*(*itr_lex)).get_type() == "case"){
			//pointer sur case_tree
			node_courant = RefTree.get_case_tree();
			position_lex="case";
		}
		
		
		/////////////////////////////////////////////////////////
		//test gramaticale
		if ((*(*itr_lex)).get_type() == node_courant->get_value()){
			cout<<"node comparaison : "<< node_courant->get_value()<<endl;
			if((*(*itr_lex)).get_type()=="etiquette"){
				(*(*itr_lex)).set_type("etiquette_"+position_lex);
				(*(*itr_lex)).affiche_lexem();				
			}
			node_courant = node_courant->get_child();
		}
		else{
			while(node_courant != NULL){
				if ((*(*itr_lex)).get_type() == node_courant->get_value()){
					cout<<"node comparaison : "<< node_courant->get_value()<<endl;
					node_courant = node_courant->get_child();
					
					break;
				}
				else{
					node_courant = node_courant->get_bros();
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
//Fin du programme
