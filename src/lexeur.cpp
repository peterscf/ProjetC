#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>


using namespace std;

int
main ()
{
  ifstream fichier ("filtre.vhd", ios::in);	// on ouvre le fichier en lecture

  if (fichier)			// si l'ouverture a réussi
    {
      char caractere;
      string mot;
      vector < string > Lx;
      vector < string >::iterator itr;
      stringstream ss;
      bool caractere_valid = true;
      while (fichier.get (caractere))
	{
	  if ((caractere == ' ') || (caractere == '\t') || (caractere == '\n'))	//identifie separateur
	    {
	      mot = ss.str ();	//met le flux dans mot
	      if (mot.find ("--") <= mot.length())
		{
		  caractere_valid = false;
		}
	      else
		{
		  for (int i = 0; i < mot.size (); i++)
		    {
		      mot[i] = tolower (mot[i]);
		    }
		  Lx.push_back (mot);	//met "mot" dans la liste
		}
	      if ((caractere == '\n') && (caractere_valid == false))
		{
		  caractere_valid = true;
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear ss

	    }
	  else if ((caractere == '(') || (caractere == ')') || (caractere == '[') || (caractere == ']') || (caractere == ':') || (caractere == ';'))	//identifie caracteres specieux qui separent
	    {
	      mot = ss.str ();	//met le flux dans mot
	      Lx.push_back (mot);
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear ss

	      ss << caractere;	//mise des caractere dans le flux
	      mot = ss.str ();	//met le flux dans mot

	      if (mot.find ("--") <= mot.length ())
		{
		  caractere_valid = false;
		}
	      else
		{
		  for (int i = 0; i < mot.size (); i++)
		    {
		      mot[i] = tolower (mot[i]);
		    }
		  Lx.push_back (mot);	//met "mot" dans la liste
		}
	      if ((caractere == '\n') && (caractere_valid == false))
		{
		  caractere_valid = true;
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear ss

	    }
	  else
	    {
	      if (caractere_valid == true)
		{
		  ss << caractere;	//mise des caractere dans le flux
		}
	    }



	}
      fichier.close ();		//ferme le fichier texte lu

      for (itr = Lx.begin (); itr != Lx.end (); ++itr)	//lit et affiche la liste chainée
	{
	  cout << *itr << endl;
	}
    }

  else				// sinon
    cerr << "Impossible d'ouvrir le fichier !" << endl;

  return 0;


}
