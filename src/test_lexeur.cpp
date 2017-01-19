#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "lexeur.h"
#include "lexem.cpp"
#include "Dictionnaire.h"


using namespace std;

int main ()
{
Dictionnaire vhd_dico("DICO.dico");
vector < lexem* > Lx ;
Lx = lexeur("arbiter.vhd");
//affichage_vector(Lx);
vector < lexem* >::iterator itr;
for (itr = Lx.begin(); itr != Lx.end(); ++itr)	//lit la liste chainée
      {
	vhd_dico.Type((*itr));
}
affichage_vector(Lx);
}
