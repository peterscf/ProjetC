//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*Author : Floriant PETERSCHMITT
/*release : 12/01/2017
/*
/*
/*
/*
/*
/*
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////*/
#ifndef TREE_H_
#define TREE_H_

#include <string>
#include <sstream>
#include<iostream>

using namespace std;

class ref_tree{
private:
// declaration des attributs
	node* my_ref_tree;
	

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
public:
//Conctructeur
	ref_tree(string File);
//Destructeur
	~tree(){};
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Accesseurs et modifieurs
	string & get_root(){
		return my_my_ref_tree;	
	}

	void affichage_tree();
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

};

#endif
