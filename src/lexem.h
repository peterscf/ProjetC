//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*Author : Floriant PETERSCHMITT
/*release : 17/11/2016
/*
/*
/*
/*
/*
/*
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////*/
#ifndef LEXEM_H_
#define LEXEM_H_

#include <string>
#include <sstream>
#include<iostream>
using namespace std;
class lexem{
private:
// declaration des attributs
	string my_type;
	string my_nom;
	
	int my_l_pos;
	int my_c_pos;

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
public:
//Conctructeur
	lexem(string nom, string type="unknow", int l_pos=0, int c_pos=0){
		my_nom=nom;
		my_type=type;
		my_l_pos=l_pos;
		my_c_pos=c_pos;
	
	}
//Destructeur
	~lexem(){};
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Accesseurs et modifieurs
	const string & get_type() const{
		return my_type;	
	}
	
	const string & get_nom()const{
		return my_nom;
	}
	const int get_line_pos() const{
		return my_l_pos;
	}
	const int get_col_pos() const{
		return my_c_pos;
	}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
	void set_name(string nom){
		my_nom=nom;
	}
	void set_type(string type){
		my_type=type;
	}
	void set_pos(int l_pos, int c_pos){
		my_l_pos=l_pos;
		my_c_pos=c_pos;
	}



};

#endif
