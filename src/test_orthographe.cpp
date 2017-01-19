#include<iostream>
#include<sstream>
#include<string>
#include"lexem.h"
#include"Analyse_lexical.h"


using namespace std;
void affiche_resultat_test_lexical(lexem lex);
//void type_lexem (Lexem lex);

int main(void){
	lexem lex1("az_09");
	lexem lex2("ab*d_12");
	lexem lex3("____ADC999'");
	lexem lex4("ABC_");
	
	cout<<"nom: "<<lex1.get_nom()<<endl;
	cout<<"nom: "<<lex2.get_nom()<<endl;
	cout<<"nom: "<<lex3.get_nom()<<endl;
	cout<<"nom: "<<lex4.get_nom()<<endl;
	
	cout << endl <<endl;
	
	affiche_resultat_test_lexical(lex1);
	affiche_resultat_test_lexical(lex2);
	affiche_resultat_test_lexical(lex3);
	affiche_resultat_test_lexical(lex4);
		return 0;
}
void affiche_resultat_test_lexical(lexem lex){
	if(test_orthographe(lex)){
		cout <<"test lexical retourne vrai"<<endl;
		lex.affiche_lexem();
	}
	else {
		cout<<"erreur lexical !!!"<< endl << lex.get_nom()<<endl<<endl;
	}

}

//Fin programme
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

