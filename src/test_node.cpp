#include<iostream>
#include<sstream>
#include<string>
#include"node.h"

#include <iostream>
#include <string>

#include <fstream>

using namespace std;


int main(void){

	node* root=NULL;
	node* courant;
	node* precedant;
	int level =0;

    ifstream fichier ("lexem_type.dico", ios::in);	// on ouvre en lecture
    if (fichier)
      {
	string line;
	while (getline (fichier, line))
	  {
	  if (root==NULL){
	  	root = new node (line);
	  	precedant= root;
	  	root->print_node();
	  }			
	  	//operation sur line
	  else if (line.find("%") || line.find ("#")){
	  	//decoupage de la ligne
		do{
			if (line.find("#") < line.find("%")){
				courant = new node (line.substr(0,line.find("#")));
				precedant->append(courant);
		  		courant->print_node();

				precedant = precedant->get_bros();// on prend le frere du precedant !
				line=line.substr(line.find("#")+1,line.size()); //suppression du '#'
			}
			if(line.find("%")!= string::npos){ 			
				courant = new node (line.substr(0,line.find("%")));
				precedant->append(courant);
		  		courant->print_node();
				line=line.substr(line.find("%")+1,line.size()); //supression du '%'
			}
			
		}while(line.find("%") != string::npos || line.find("#")!=string::npos);

		if (line.size()!=0){
			courant = new node (line);
			precedant->append(courant);
		  	courant->print_node();
		}
	  }
	  else{
		//ajouter node a n-1
		  courant = new node (line);
		  precedant->append(courant);
		  courant->print_node();
	      }
		level++;
		precedant =root;
		for(int i=1;i<level;i++){
			precedant = precedant->get_child();
	  	}

		}
      }

    else
      {
	cerr << "Impossible d'ouvrir le fichier !" << endl;
      }



/*
	node A("A entity");
	node B("B Child 1 entity");
	node C("C child 2 entity");
	node D("D child 2 entity");
	node E("E child 2 entity");
	node F("F child 2 entity");
	node G("G child 2 entity");
	node H("H child 2 entity");

	
	A.print_node();
	A.append(&B);
	A.append(&C);
	
	A.print_node();
	

	A.append(&D);
	B.append(&E);
	B.append(&F);
	B.append(&G);
	C.append(&H);
	cout <<"-----------------------------\n";
		
	A.print_node();
	cout <<"-----------------------------\n";
	B.print_node();
	cout <<"-----------------------------\n";
	C.print_node();
	cout <<"-----------------------------\n";
	D.print_node();
	cout <<"-----------------------------\n";
	E.print_node();
	cout <<"-----------------------------\n";
	F.print_node();
	cout <<"-----------------------------\n";
	G.print_node();
	cout <<"-----------------------------\n";
	H.print_node();
	
*/
	
		return 0;
}

//Fin programme
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

