#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>


using namespace std;
bool test_caractere_special (char c);
int
main ()
{
  ifstream fichier ("test.txt", ios::in);	// on ouvre le fichier en lecture

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
	 caractere = tolower(caractere); //tout en minuscule
	  if ((caractere == ' ') || (caractere == '\t') || (caractere == '\n'))	//identifie separateur
	    {
	      mot = ss.str ();	//met le flux dans mot
	      if (mot.find ("--") <= mot.length())
		{
		  caractere_valid = false;
			cout << mot.find("--");
		}
		else if (mot.find ("-") <= mot.length()){
		
		}
	      else
		{
		  Lx.push_back (mot);	//met "mot" dans la liste
		}
	      if ((caractere == '\n') && (caractere_valid == false))
		{
		  caractere_valid = true;
		}
	      mot.erase (mot.begin (), mot.end ());	//clot le lexeme et passe a un nouveau
	      ss.str ("");	//clear ss

	    }
	  else if (test_caractere_special(caractere) == true)	//identifie caracteres speciaux qui separent
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


bool test_caractere_special (char c){
if ((c == '(') || (c == ')') || (c == '[') || (c == ']') || (c == ':') || (c == ';')|| (c == '+')|| (c == '&')||(c == '&')){
		return true;
}
else{
		return false;
	}

}
