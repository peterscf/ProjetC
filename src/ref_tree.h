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
#ifndef REF_TREE_H_
#define REF_TREE_H_

#include<iostream>
#include<sstream>
#include<string>
#include <iostream>
#include <fstream>
#include"node.h"

using namespace std;

class ref_tree{
private:
// declaration des attributs
	node* my_root=NULL;
	node* my_architecture=NULL;
	node* my_process=NULL;
	node* my_entity=NULL;
	node* my_if=NULL;
	node* my_library=NULL;
	node* my_port=NULL;
	node* my_signal=NULL;
	node* my_variable=NULL;
	node* my_case=NULL;
	node* my_use=NULL;
	

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
public:
//Conctructeur
	ref_tree(string File);
//Destructeur
	~ref_tree(){};
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Accesseurs et modifieurs
	node* get_root(){
		return my_root;	
	}
	node* get_process_tree(){
		return my_process;	
	}
	node* get_entity_tree(){
		return my_entity;	
	}
	node* get_if_tree(){
		return my_if;	
	}
	node* get_library_tree(){
		return my_library;	
	}
	node* get_port_tree(){
		return my_port;	
	}
	node* get_signal_tree(){
		return my_signal;	
	}
	node* get_case_tree(){
		return my_case;	
	}
	node* get_variable_tree(){
		return my_variable;	
	}
	node* get_architecture_tree(){
		return my_architecture;	
	}
	node* get_use_tree(){
		return my_use;	
	}

		
	void affichage_tree(void);
	node* create_node(string str);
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

};

#endif
