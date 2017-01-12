#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "lexeur.cpp"


using namespace std;

int main ()
{

ifstream fichier ("test.txt", ios::in);
vector < string > Lx =lexeur(ifstream fichier);
affichage_vector(Lx);
}
