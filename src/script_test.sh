#!/bin/bash


if [ -e "./vhdlcomp" ]
then
	echo vhdlcomp test_arbre_4_if.vhd
	result_1 = $(vhdlcomp -d test_arbre_4_if.vhd)
	echo $result_1
else
	make all
fi
