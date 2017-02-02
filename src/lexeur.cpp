#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "lexeur.h"
#include "lexem.h"


using namespace std;
bool test_caractere_special (char c);

vector < lexem * > lexeur (string file_name) //description de la fonction lexeur
{
  vector < lexem * > Lx; // on cree un vecteur de lexeme
  ifstream fichier (file_name.c_str (), ios::in);	// on ouvre le fichier en lecture

  if (fichier)			// si l'ouverture a reussi
    {
      char caractere;
      string mot;
      string mot_temp;
      lexem *lex_temp;
      stringstream ss;
      int index_line = 1; //index pour numeroter chaque ligne
      bool caractere_valid = true; //gere la recuperationd es caracteres : ici active
      while (fichier.get (caractere)) // tant que le fichier contient un caractere
	{
	  caractere = tolower (caractere);	//tout en minuscule

	  if ((caractere == ' ') || (caractere == '\t') || (caractere == '\n'))	//identifie separateur  qui ne doivent pas être stockes  : espace, \n et tab
	    {
	      mot = ss.str ();	//met le flux de caractere jusqu'au separateur dans mot
	      if (caractere == '\n') //gere la numerotation des lignes
		{
		  index_line = index_line + 1; // numero de ligne +1 a chaque \n
		}
	      if (mot.find ("--") <= mot.length ())	//recherche commentaires
		{
		  caractere_valid = false; //desactive la recuperation de caractere
		  mot_temp = mot; //mot dans mot temporaire
		  mot_temp.resize ((mot.find ("--"))); //recupere le mot avant la detection de commentaire
		  if (!mot_temp.empty ()) //verifie qu'un mot a bien ete recupere 
		    {
		      lex_temp = new lexem (mot_temp, index_line); //convertit le mot en lexeme en ajoutant son numero de ligne
		      Lx.push_back (lex_temp); //ajoute le lexeme au vecteur
		    }
		  mot_temp.erase (mot_temp.begin (), mot_temp.end ()); //efface le contenu du mot temporaire

		}
	      else if (mot.find ("-") <= mot.length ()) //recherche du tiret qui n'est pas un commentaire
		{
		  mot_temp = mot; 
		  mot_temp.resize ((mot.find ("-"))); //ajuste le mot temporaire du debut jusqu'au tiret
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp); //ajoute le lexeme avant le tiret au vector
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ()); //efface le mot temporaire
		  mot_temp = mot[(mot.find ("-"))]; //met le tiret dans le mot temporaire
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp); //ajout le tiret au vecteur
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("-") + 1), (mot_temp.length () - (mot_temp.find ("-")))); //ajsute le mot pour complet pour ne garder que le mot apres le tiret
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp); //ajoute le lexeme apres tiret au vecteur
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find ("<=") <= mot.length ()) //meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("<=")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("<=")), 2);
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("<=") + 2), (mot_temp.length () -(mot_temp.find ("<="))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (">=") <= mot.length ())//meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (">=")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (">=")), 2);
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (">=") + 2), (mot_temp.length () - (mot_temp.find (">="))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		}
	      else if (mot.find ("=>") <= mot.length ()) //meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("=>")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("=>")), 2);
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("=>") + 2),(mot_temp.length () -(mot_temp.find ("=>"))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		}
	      else if (mot.find ("\\=") <= mot.length ()) //meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("\\=")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("\\=")), 2);
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("\\=") + 2),(mot_temp.length () -(mot_temp.find ("\\="))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (":=") <= mot.length ()) //meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (":=")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (":=")), 2);
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (":=") + 2),(mot_temp.length () - (mot_temp.find (":="))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}

	      else if (mot.find ("<") <= mot.length ())//meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("<")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find ("<"))];
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("<") + 1), (mot_temp.length () -(mot_temp.find ("<"))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (">") <= mot.length ()) //meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (">")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find (">"))];
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (">") + 1),(mot_temp.length () -(mot_temp.find (">"))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find (":") <= mot.length ())//meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find (":")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find (":"))];
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find (":") + 1), (mot_temp.length () -(mot_temp.find (":"))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());

		}
	      else if (mot.find ("=") <= mot.length ()) //meme methode que pour le tiret
		{
		  mot_temp = mot;
		  mot_temp.resize ((mot.find ("=")));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot[(mot.find ("="))];
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		  mot_temp = mot;
		  mot_temp = mot_temp.substr ((mot_temp.find ("=") + 1),(mot_temp.length () -(mot_temp.find ("="))));
		  if (!mot_temp.empty ())
		    {
		      lex_temp = new lexem (mot_temp, index_line);
		      Lx.push_back (lex_temp);
		    }

		  mot_temp.erase (mot_temp.begin (), mot_temp.end ());
		}

	      else
		{
		  if (!mot.empty ()) //dans le cas ou le mot ne contient pas -- ou - ou <= ou >= ou => ou : ou := ou > ou > ou = ou \=
		    {
		      lex_temp = new lexem (mot, index_line);
		      Lx.push_back (lex_temp); //le mot est ajoute tel qu'il est au vecteur
		    }
		}
	      if ((caractere == '\n') && (caractere_valid == false)) //detecte lorsquon change de ligne et que la recuperationd e caractere est active
		{
		  caractere_valid = true; //reactive la recuperation de caractere car on n'est plus en commentaire
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear le flux de caracteres

	    }
	  else if (test_caractere_special (caractere) == true && (caractere_valid == true))	//identifie caracteres speciaux "simples" qui separent et qui doivent etre stockes
	    {
	      mot = ss.str ();	//met le flux dans mot
	      if (!mot.empty ())
		{
		  lex_temp = new lexem (mot, index_line);
		  Lx.push_back (lex_temp); //le mot est ajoute tel qu'il est au vecteur
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear le flux de caracteres

	      ss << caractere;	//mise des caracteres dans le flux
	      mot = ss.str ();	//met le flux dans mot

	      if (!mot.empty ()) 
		{
		  lex_temp = new lexem (mot, index_line);
		  Lx.push_back (lex_temp); //le mot est ajoute tel qu'il est au vecteur
		}		
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear le flux de caracteres

	    }
	  else
	    {
	      if (caractere_valid == true) //traite le cas ou on ne detecte pas de commentaire avec -- lorsquon souhaite recuperer les lexemes
		{
		  ss << caractere;	//mise des caracteres dans le flux
		}
	    }



	}
      fichier.close ();		//ferme le fichier texte lu


    }


  else				// sinon
    cerr << "Impossible d'ouvrir le fichier !" << endl;
  	exit(1); //kill

  return Lx; //fa fonction lexeur retourne un vecteur qui est un arbre a une branche que represente le fichier en entree

}

void
affichage_vector (vector < lexem * >myLx)
{
  vector < lexem * >::iterator itr;
  for (itr = myLx.begin (); itr != myLx.end (); ++itr)	//lit et affiche la liste chainée
    {
      (*itr)->affiche_lexem ();
    }
}

bool
test_caractere_special (char c) //recherche les caracteres speciaux qui ne sont pas dans des combinaisons mais qui serparent et doivent etre stockes
{
  if ((c == '(') || (c == ')') || (c == '[') || (c == ']') || (c == ';')
      || (c == '+') || (c == '&') || (c == '*') || (c == '.') || (c == '\'')
      || (c == ',') || (c == '!') || (c == '\"'))
    {
      return true;
    }
  else
    {
      return false;
    }

}
