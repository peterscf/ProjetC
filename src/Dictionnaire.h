#ifndef DICTIONNAIRE_H_
#define DICTIONNAIRE_H_

#include<iostream>
#include<sstream>
#include<string>
#include"lexem.h"
#include <fstream>
#include <vector>
#include<stdio.h>
#include <string.h>

using namespace std;

class Dictionnaire
{
private:
  string my_file;

  vector < string > my_dico;	//vector qui contient les lexems partivulier du VHDL contenu dans le fichier <name>.dico
  vector < string >::iterator itr;

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
public:
//Conctructeur
  Dictionnaire(string file);

//Destructeur
  ~Dictionnaire ()
  {
  };
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Accesseurs et modifieurs
  const string & get_file () const
  {
    return my_file;
  }
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
  void affiche_vect(void);

  void Type(lexem* lex);

};
#endif
