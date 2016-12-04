#include"Dictionnaire.h"

 /////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////// 
Dictionnaire::Dictionnaire(string file)
  {
    my_file = file;

    ifstream fichier (my_file.c_str(), ios::in);	// on ouvre en lecture
    if (fichier)
      {
	string line;
	while (getline (fichier, line))
	  {			//operation sur line
	    if (line.find ("#") == 0)
	      {
			//com     
	      }
	    else
	      {
			//push dans vector line
			my_dico.push_back (line);
	      }
	  }
      }

    else
      {
	cerr << "Impossible d'ouvrir le fichier !" << endl;
      }
  }

 /////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////// 

void Dictionnaire::affiche_vect(void)
  {
    for (itr = my_dico.begin(); itr != my_dico.end(); ++itr)	//lit et affiche la liste chainée
      {
	cout << *itr << endl;
      }
  }
 /////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////// 
  void Dictionnaire::Type(lexem* lex)
  {
    for (itr = my_dico.begin(); itr != my_dico.end(); ++itr)	//lit la liste chainée
      {
		if ((*itr).compare((*lex).get_nom()) == 0)
	  	{	
	  		string type = *itr;
	    	(*lex).set_type(type);
	  	}
      }
  }
