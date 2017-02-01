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
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//fonction 
void Analyse_gramaticale(vector <lexem*> Lx_vector){

	node* node_courant=NULL;
	stack<node*> node_precedant;
	vector < lexem* >::iterator itr_lex;
	string path="./ref_tree/";
	
	ref_tree library_tree("./ref_tree/library_use.tree");
	ref_tree use_tree("./ref_tree/use.tree");
	ref_tree entity_tree("./ref_tree/entity.tree");
	//ref_tree architecture_tree("./ref_tree/architecture.tree");
	ref_tree component_tree("./ref_tree/component.tree");
	ref_tree expression_tree("./ref_tree/expression.tree");
	ref_tree type_vector_tree("./ref_tree/type_vector.tree");
	//ref_tree if_tree("./ref_tree/if.tree");
	
	string position_lex;
	
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
				//(*(*itr_lex)).affiche_lexem();		
			}
			
			
		//traitement du pointeur quand il ya un lien dans l'arbre de ref
		
		
		if((*(*itr_lex)).get_type() == "architecture"){
			//pointer sur architecture_tree
			//node_courant = architecture_tree.get_root();
			node_precedant.push(node_courant);
			position_lex="architecture";
		}
		else if((*(*itr_lex)).get_type() == "entity"){
			//pointer sur port_tree
			node_courant = entity_tree.get_root();
			node_precedant.push(node_courant);
			position_lex="entity";
		}
		else if((*(*itr_lex)).get_type() == "use"){
			//pointer sur port_tree
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
			node_courant = lien_vers_sous_arbre(node_courant,node_precedant);
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
				
				if (node_courant->get_value() == "%fin"){
						node_courant = (node_precedant.top())->get_child();
						node_precedant.pop();
						cout<<"/!\\node precedant dans while: "<< node_courant->get_value()<<endl;
				}
				
				if ((*(*itr_lex)).get_type() == node_courant->get_value()){
					cout<<"node comparaison : "<< node_courant->get_value()<<endl;
					node_courant = node_courant->get_child();
					break;
				}
				
				else if((node_courant->get_value()).find(".")!=string::npos){
					node_precedant.push(node_courant);
					node_courant = lien_vers_sous_arbre(node_courant,node_precedant);
					
				
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
//lien vers sous arbre
node * lien_vers_sous_arbre(node* link, stack<node*> stck){

ref_tree declaration_port_tree("./ref_tree/declaration_port.tree");		
ref_tree port_tree("./ref_tree/port.tree");

			if(link->get_value() =="port.tree" ){
				stck.push(link);
				link = port_tree.get_root();
			}
			else if(link->get_value() =="declaration_port.tree" ){
				stck.push(link);
				link = declaration_port_tree.get_root();
			}
/*			else if (link->get_value() ==" "){
				//position_lex == "decl_port";			
				node_courant = declaration_port_tree.get_root();
			
			}
			else if(link->get_value() ==" " ){
				//pointer sur signal_tree

			}
			else if(link->get_value() ==" " ){
				//pointer sur veriable_tree
			}
			else if(link->get_value() ==" " ){
				//pointer sur if_tree

			}
			else if(link->get_value() ==" " ){
				//pointer sur case_tree

			}*/
			else{
				link =NULL;
			}
			return link;
		}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//Fin du programme
