#include<iostream>
#include<sstream>
#include<string>
#include"lexem.h"
#include"Dictionnaire.h"

using namespace std;

bool test_syntaxe(lexem lex);
//void type_lexem (Lexem lex);

int main(void){
	lexem lex1(">=");
	Dictionnaire Dico("file");
	
	Dico.affiche_vect();
	
	cout<<"nom: "<<lex1.get_nom()<<endl;
	cout<<"type: "<< lex1.get_type()<<endl;
	cout<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;
	Dico.Type(&lex1);
	cout<<"nom: "<<lex1.get_nom()<<endl;
	cout<<"type: "<< lex1.get_type()<<endl;
	cout<<"position: "<< lex1.get_line_pos()<<","<< lex1.get_col_pos()<<endl;
		return 0;
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/*bool test_syntaxe(lexem lex){
	//regle de syntaxe
	if (lex.get_nom()){
		 
	}
	else if
		
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void type_lexem(lexem lex){

}

*/
