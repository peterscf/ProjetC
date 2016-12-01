#ifndef DICTIONNAIRE_H_
#define DICTIONNAIRE_H_

#include<iostream>
#include<sstream>
#include<string>
#include"lexem.h"
#include <fstream>
 
using namespace std;

 
        if(fichier)  // si l'ouverture a fonctionné
        {
                string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
                getline(fichier, contenu);  // on met dans "contenu" la ligne
                cout << contenu;  // on affiche la ligne
 
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;



class Dictionnaire
{
private:
  string my_file;

  vector < string > my_dico;	//vector qui contient les lexems partivulier du VHDL contenu dans le fichier <name>.dico

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
public:
//Conctructeur
  Dictionnaire (string file = "unknow"){
    my_file = file;
	
	ifstream fichier(my_file, ios::in);  // on ouvre en lecture
	if(fichier){
    	string line;
        while(getline(fichier, line)){  // tant que l'on peut mettre la ligne dans "contenu"
        	//operation sur line
        	if (line.finf("#")<=line.lenght())
        		//ligne comentaire	
        	}
        	else if(){
        		
        	}
        }
	}
	
	else{
      	cerr << "Impossible d'ouvrir le fichier !" << endl;
      }


//Destructeur
    ~Dictionnaire ()
    {
    };
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Accesseurs et modifieurs
    const string & get_type () const
    {
      return my_type;
    }
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
    void set_name (string nom)
    {
      my_nom = nom;
    }
  };
#endif	/* ; */
