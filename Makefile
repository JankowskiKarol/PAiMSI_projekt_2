
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/sortowania
	${TRGDIR}/sortowania

${TRGDIR}/sortowania: ${OBJ} ${OBJ}/main.o ${OBJ}/FileHandling.o\
                     ${OBJ}/Kubelkowe.o ${OBJ}/Movie_ranking.o ${OBJ}/Przez_scalanie.o\
					 ${OBJ}/Quicksort.o
	g++ -o ${TRGDIR}/sortowania ${OBJ}/main.o ${OBJ}/FileHandling.o\
                     ${OBJ}/Kubelkowe.o ${OBJ}/Movie_ranking.o ${OBJ}/Przez_scalanie.o\
					 ${OBJ}/Quicksort.o
${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Quicksort.hh inc/Przez_scalanie.hh inc/FileHandling.hh inc/Kubelkowe.hh inc/Movie_ranking.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Movie_ranking.o: src/Movie_ranking.cpp inc/Movie_ranking.hh
	g++ -c ${FLAGS} -o ${OBJ}/Movie_ranking.o src/Movie_ranking.cpp

${OBJ}/Quicksort.o: src/Quicksort.cpp inc/Quicksort.hh inc/Movie_ranking.hh
	g++ -c ${FLAGS} -o ${OBJ}/Quicksort.o src/Quicksort.cpp

${OBJ}/FileHandling.o: src/FileHandling.cpp inc/FileHandling.hh inc/Movie_ranking.hh 
	g++ -c ${FLAGS} -o ${OBJ}/FileHandling.o src/FileHandling.cpp

${OBJ}/Przez_scalanie.o: src/Przez_scalanie.cpp inc/Przez_scalanie.hh inc/Movie_ranking.hh
	g++ -c ${FLAGS} -o ${OBJ}/Przez_scalanie.o src/Przez_scalanie.cpp

${OBJ}/Kubelkowe.o: src/Kubelkowe.cpp inc/Kubelkowe.hh inc/Movie_ranking.hh
	g++ -c ${FLAGS} -o ${OBJ}/Kubelkowe.o src/Kubelkowe.cpp


clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
