//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*Author: Floriant PETERSCHMITT
/*Project: synthetiseur VHDL
/*Date: 13/10/2016
/*
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////*/
#include<iostream>
#include<string>
#include<sstream>
#include <stdlib.h>
using namespace std;

int main (int argc, char *argv[]){

	string mkdir ="mkdir ";
	char *cmd;

//test présence nom de la library
if (argc==1){
	cout<<"Error: too few arguments !" << endl
		<<"example:\t\"vhdllib <name of physical library>\""
		<< endl;
}
else if(argc>2){
	cout<<"Error: too much arguments !" << endl
		<<"example:\t\"vhdllib <name of physical library>"
		<< endl;
}
else { //ajouter le path
	mkdir=mkdir + argv[1];
	//cout<<mkdir<<endl;
	system((char*)mkdir.c_str()); 
}

}
