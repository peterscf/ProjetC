
CFLAGS=-g



all :test_lexeur test_node test_orthographe test_ref_tree

test_orthographe :  lexem.o Dictionnaire.o  Analyse_lexical.o test_orthographe.o
	g++  -o $@ $^ $(LDFLAGS)

test_node :  node.o Dictionnaire.o test_node.o
	#g++ -o test_node -g $^ $(LDFLAGS)
	g++ -o $@    $^ $(LDFLAGS)

test_lexeur :  lexeur.o  Dictionnaire.o Analyse_lexical.o test_lexeur.o
	g++ -o $@  $^ $(LDFLAGS)

test_ref_tree :  ref_tree.o node.o test_ref_tree.o
	g++ -o $@  $^ $(LDFLAGS)
	
comp :  ref_tree.o node.o lexeur.o  Dictionnaire.o Analyse_lexical.o Analyse_gramaticale.o comp.o
	g++ -o $@  $^ $(LDFLAGS)

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)


clean:
	rm -f *.o *~ test_lexeur test_node test_orthographe test_ref_tree

