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
#include <fstream>

using namespace std;

int main (int argc, char *argv[]){

		string mkdir ="mkdir ";
		char *cmd;

	//test présence nom de la library
	if (argc==1){
		cout<<"Error: too few arguments !" << endl
			<<"example:\t\"vhdllib <$path/name of physical library>\""
			<< endl;
	}
	else if(argc>2){
		cout<<"Error: too much arguments !" << endl
			<<"example:\t\"vhdllib <$path/name of physical library>"
			<< endl;
	}
	else { 
			ifstream fichier("./config/synth.ini", ios::in);  // on ouvre le fichier en lecture
	 
		    if(fichier){  // si l'ouverture a réussi       
	  			char caractere;
				while(fichier.get(caractere)){
				cout<<caractere;
				if ()
					system((char*)mkdir.c_str());
				}          	
			fichier.close();
		    }
		    
		    else {
				//cerr << "Impossible d'ouvrir le fichier !" << endl;
				cout << 
		 	}
	}
//system((char*)mkdir.c_str());
}//fin main
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

//fonction
void W_in_file(string file, string line){
		ofstream fichier(file, ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
        
        if(fichier)  // si l'ouverture a réussi
        {
            // instructions
            	flux<<line<<endl;
                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;
}

bool test_in_file(string file, string str_test){
	bool ret_test;
		ifstream fichier(file, ios::in);  // on ouvre le fichier en lecture
		    if(fichier){  // si l'ouverture a réussi       
	  			string line;
				while(get_line(fichier, line){
					//test existe dans line ?
					if(){
						ret_test=TRUE;
					}
					else{
						ret_test=FALSE;
					}
				}          	
			fichier.close();
		    }
		    else {
				cerr << "Impossible d'ouvrir le fichier !" << endl;
		 	}
		 	return ret_test;
}
