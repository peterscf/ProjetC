#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
        ifstream fichier("test.txt", ios::in);  // on ouvre le fichier en lecture
 
        if(fichier)  // si l'ouverture a réussi
        {       
  		char caractere;
		string mot;
		while(fichier.get(caractere)){
			if((caractere == ' ')||( caractere == '\t')||( caractere == '\n')){ //identifie separateur
			//std::vector<std::string> words;
			mot.erase(mot.begin(), mot.end());
			}
			else if (( caractere == '(')||( caractere == ')')||( caractere == '[')||( caractere == ']')||( caractere == ':')||( caractere == ';')){ //identifie caracteres specieux qui separent
				//cout << '\n'<< caractere<< '\n';
				mot.erase(mot.begin(), mot.end());
			}
			else {
				stringstream ss;
				//string mot;
				ss << caractere;
				ss >> mot;
				//cout<< caractere;
				cout<< mot;
			}
		}          	
		fichier.close();
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;

	
}

