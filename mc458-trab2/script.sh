#!/bin/bash
I=1
while [ $I -le 100 ]
do
	NAME="arq$I"
	NAME=$NAME"comb1.in"
	echo $NAME
	./Gerador1 $I*50 > "Experimentos/"$NAME	

	NAME="arq$I"
	NAME=$NAME"comb2.in"
	echo $NAME
	./Gerador2 $I*50 > "Experimentos/"$NAME	

	NAME="arq$I"
	NAME=$NAME"comb3.in"
	echo $NAME
	./Gerador3 $I*50 > "Experimentos/"$NAME	

	I=$((I+1))
done
