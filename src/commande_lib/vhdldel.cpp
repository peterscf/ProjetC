//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*Author: Floriant PETERSCHMITT
/*Project: synthetiseur VHDL
/*Date: 14/10/2016
/*
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////*/
#include<iostream>
#include<string>
#include<sstream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]){

	string rmdir ="rm -rf ";

//test présence nom de la library
if (argc==1){
	cout<<"Error: too few arguments !" << endl
		<<"example:\t\"vhdllib <$path/name of physical library>\""
		<< endl;
		
else if(argc>2){
	cout<<"Error: too much arguments !" << endl
		<<"example:\t\"vhdllib <$path/name of physical library>"
		<< endl;
}
else { //ajouter la verification du path (existe ou pas dans .ini)
	rmdir=rmdir + argv[1];
	
	system((char*)rmdir.c_str()); 
}

}
