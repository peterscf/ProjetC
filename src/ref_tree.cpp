#include<iostream>
#include<sstream>
#include<string>
#include <iostream>
#include <fstream>
#include"node.h"
#include"ref_tree.h"

using namespace std;

//constructeur : creation de l'arbre de referance
ref_tree::ref_tree(string File){

	node* root=NULL;
	node* courant;
	node* precedant;
	//int level =0;

    ifstream fichier (File.c_str(), ios::in);	// on ouvre en lecture
    if (fichier){
		string line;
		int tab_index=0;
		int nb_line=0;
		while (getline (fichier, line)){
			//cout<<"line"<<nb_line<<endl;
			if(line.find("#") == string::npos){
				int idx_line;
			
				if (line.rfind('\t')== string::npos){
					idx_line=0;			
				}
				else{
					idx_line=line.rfind('\t')+1;
				}
				
				if (root==NULL){
					root = create_node (line.substr(idx_line,line.size()));
					precedant= root;
					my_root=root;
				}
				else{
				
					if(tab_index < idx_line){
					
						courant = create_node (line.substr(idx_line,line.size()));
						precedant->append(courant);
						tab_index = idx_line;
						precedant=precedant->get_child();
						while (precedant->get_bros()!=NULL){
							precedant=precedant->get_bros();
						}
					
					}
					else if (tab_index == idx_line){
						precedant= root;
						for (int i=0; i< idx_line-1; i++){
							precedant=precedant->get_child();
							while (precedant->get_bros()!=NULL){
								precedant=precedant->get_bros();
							}
						}
						courant = create_node (line.substr(idx_line,line.size()));
						precedant->append(courant);
						precedant=courant;
						tab_index = idx_line;
					}
					else if (tab_index > idx_line){
						precedant= root;
						for (int i=0; i< idx_line-1; i++){
							precedant=precedant->get_child();
							while (precedant->get_bros()!=NULL){
								precedant=precedant->get_bros();
							}
						}
						courant = create_node (line.substr(idx_line,line.size()));
						precedant->append(courant);
						precedant=courant;
						tab_index = idx_line;
					}
				}
			}
			nb_line++;
		}
		cout<<"ref_tree ok"<<endl;
	}

    else
      {
	cerr << "Impossible d'ouvrir le fichier !" << endl;
      }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
node* ref_tree::create_node(string str){
	node* new_node;
	if(str.find('\r')!=string::npos){
		str=str.substr(0,str.find('\r'));
	}

	if (str.find("%")!=string::npos){

		str=str.substr(str.find("%")+1,str.size());
		new_node = new node (str);
		
		if(str=="library"){
			if(my_library==NULL) 
			my_library=new_node;
		}
		else if(str=="process"){
			if(my_process==NULL)
			my_process=new_node;
		}
		else if(str=="entity"){
			if(my_entity==NULL)
			my_entity=new_node;
		}
		else if(str=="if"){
			if(my_if==NULL)
			my_if=new_node;
		}
		else if(str=="port"){
			if(my_port==NULL)
			my_port=new_node;
		}
		else if(str=="signal"){
			if(my_signal==NULL)
			my_signal=new_node;
		}
		else if(str=="variable"){
			if(my_variable==NULL)
			my_variable=new_node;
		}
		else if(str=="case"){
			if(my_case==NULL)
			my_case=new_node;
		}
		else if(str=="use"){
			if(my_use==NULL)
			my_use=new_node;
		}
		
		else{
		cerr<<"Impossible de faire le lien !!!!"<<endl
		<<"reconnaissance de root arbre particulier"<<endl;
		}
	}
	else{
		new_node = new node (str);
	}
	return new_node;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ref_tree::affichage_tree(void){
	/*node* root=NULL;
	node* courant;
				while (cournat->get_child()!=NULL){
						precedant=precedant->get_child();
						while (precedant->get_bros()!=NULL){
							precedant=precedant->get_bros();
						}
					}*/
}








