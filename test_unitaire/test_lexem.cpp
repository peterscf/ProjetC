#include <string>
#include <sstream>
#include<iostream>

#include"Lexem.h"

using namespace std;

int main(void){
	
	Lexem lex1("HELLO", "mot", 1, 2);
	
	cout 	<<"nom: "<< lex1.get_nom << endl
		<<"type: "<< lex1.get_type<<endl
		<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;
		return 0;
		
}
