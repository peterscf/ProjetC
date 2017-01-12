#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "lexeur.h"

using namespace std;

int main ()
{
vector < string > Lx ;
Lx = lexeur("test_lexeur.txt");
affichage_vector(Lx);
}
