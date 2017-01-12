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

    ifstream fichier ("lexem_type.dico", ios::in);	// on ouvre en lecture
    if (fichier)
      {
	string line;
	while (getline (fichier, line))
	  {
	  if (root==NULL){
	  	root = new node (line);
	  	precedant= root;
	  	cout <<"-----------------------------\n";
	  	root->print_node();
	  }			
	  	//operation sur line
	  else if (line.find (",") == 0){
	  	//decoupage de la ligne
	  	   
	  }
	  else{
		//ajouter node a n-1
		  courant = new node (line);
		  precedant->append(courant);
		  cout <<"-----------------------------\n";
		  courant->print_node();
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

