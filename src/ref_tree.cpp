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
	int level =0;

    ifstream fichier (file, ios::in);	// on ouvre en lecture
    if (fichier){
		string line;
		int tab_index=0;
		while (getline (fichier, line)){
			int idx_line;
			if (line.rfind('\t')== string::npos);
				idx_line=0;			
			else{
				idx_line=line.rfind('\t');
			}

			if (root==NULL){
				root = new node (line);
				precedant= root;
				my_ref_tree=root;
				root->print_node();
			}

			if(tab_index < idx_line){
				courant = new node (line.substr(idx_line,line.size();
				precedant->append(courant);
				tab_index = idx_line;
			}
			else if (tab_index > idx_line){
				precedant= root;
				for (int i=0; i< tab_index; i++){
					precedant=precedant->get_child();
				}
				courant = new node (line.substr(idx_line,line.size();
				precedant->append(courant);
				tab_index = idx_line;
			}
		}
	}

    else
      {
	cerr << "Impossible d'ouvrir le fichier !" << endl;
      }



void ref_tree::affichage_tree(){
	bool fin_arbre=FALSE;
	node* courant=get_root();	
	while(fin_arbre==TRUE){
		courant->affiche_node();
		if ()		
		courant->courant->get_child();
	}
}