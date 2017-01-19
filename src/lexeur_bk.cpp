#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "lexeur.h"
#include "lexem.h"


using namespace std;
bool test_caractere_special (char c);

vector <string > lexeur( string file_name) 
{
  vector < string > Lx;
  ifstream fichier (file_name.c_str(), ios::in);	// on ouvre le fichier en lecture

  if (fichier)			// si l'ouverture a réussi
    {
      char caractere;
      string mot;
      string mot_temp;
      stringstream ss;
      bool caractere_valid = true;
      while (fichier.get (caractere))
	{
	  caractere = tolower (caractere);	//tout en minuscule
	  if ((caractere == ' ') || (caractere == '\t') || (caractere == '\n'))	//identifie separateur
	    {
	      mot = ss.str ();	//met le flux dans mot
	      if (mot.find ("--") <= mot.length ()) //recerche commentaires
		{
		  caractere_valid = false;
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("--")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }
		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find ("-") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("-")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find ("-"))];
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find ("-") + 1),
				     (mot_temp.length () -
				      (mot_temp.find ("-"))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find ("<=") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("<=")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("<=")), 2);
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find ("<=") + 2),
				     (mot_temp.length () -
				      (mot_temp.find ("<="))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (">=") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (">=")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (">=")), 2);
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find (">=") + 2),
				     (mot_temp.length () -
				      (mot_temp.find (">="))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		}
	      else if (mot.find ("=>") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("=>")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("=>")), 2);
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find ("=>") + 2),
				     (mot_temp.length () -
				      (mot_temp.find ("=>"))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		}
	      else if (mot.find ("\\=") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("\\=")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("\\=")), 2);
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find ("\\=") + 2),
				     (mot_temp.length () -
				      (mot_temp.find ("\\="))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (":=") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (":=")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (":=")), 2);
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find (":=") + 2),
				     (mot_temp.length () -
				      (mot_temp.find (":="))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}

	      else if (mot.find ("<") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("<")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find ("<"))];
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find ("<") + 1),
				     (mot_temp.length () -
				      (mot_temp.find ("<"))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (">") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (">")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find (">"))];
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find (">") + 1),
				     (mot_temp.length () -
				      (mot_temp.find (">"))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (":") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (":")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find (":"))];
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find (":") + 1),
				     (mot_temp.length () -
				      (mot_temp.find (":"))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find ("=") <= mot.length ())
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("=")));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find ("="))];
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp =
		    mot_temp.substr ((mot_temp.find ("=") + 1),
				     (mot_temp.length () -
				      (mot_temp.find ("="))));
		  if (!mot_temp.empty ())
		    {
		      Lx.push_back (mot_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		}

	      else
		{
		  if (!mot.empty ())
		    {
		      Lx.push_back (mot);
		    }
		  //met "mot" dans la liste
		}
	      if ((caractere == '\n') && (caractere_valid == false))
		{
		  caractere_valid = true;
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear ss

	    }
	  else if (test_caractere_special (caractere) == true && (caractere_valid == true))	//identifie caracteres speciaux qui separent
	    {
	      mot = ss.str ();	//met le flux dans mot
	      if (!mot.empty ())
		{
		  Lx.push_back (mot);
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear ss

	      ss << caractere;	//mise des caractere dans le flux
	      mot = ss.str ();	//met le flux dans mot

	      if (!mot.empty ())
		{
		  Lx.push_back (mot);
		}		//met "mot" dans la liste

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


    }

  else				// sinon
    cerr << "Impossible d'ouvrir le fichier !" << endl;

	return Lx;

}

void affichage_vector(vector < string > myLx)
{
  vector < string >::iterator itr;
for (itr = myLx.begin (); itr != myLx.end (); ++itr)	//lit et affiche la liste chainée
    {
      cout << *itr << endl;
    }
}

bool test_caractere_special (char c)
{
  if ((c == '(') || (c == ')') || (c == '[') || (c == ']') || (c == ';')
      || (c == '+') || (c == '&') || (c == '*') || (c == '.') || (c == '\'')
      || (c == ',') || (c == '!'))
    {
      return true;
    }
  else
    {
      return false;
    }

}

