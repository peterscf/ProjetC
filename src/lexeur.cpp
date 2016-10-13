#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
        ifstream fichier("test.txt", ios::in);  // on ouvre le fichier en lecture
 
        if(fichier)  // si l'ouverture a réussi
        {       
  		char caractere;
		while(fichier.get(caractere)){
		cout<<caractere;
		}          	
		fichier.close();
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;

	
}

