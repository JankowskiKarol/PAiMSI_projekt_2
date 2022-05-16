#ifndef FILEHANDLING_HH
#define FILEHANDLING_HH

#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "Movie_ranking.hh"

using namespace std;


/*!
 * \brief Deklaracja funkcji otwierajacej plik i sprawdzajacej poprawność danych w nim zawartych
 *
 */
bool work_with_file(ifstream &, const char *, unsigned int &, movie_review *);

/*!
 * \brief Deklaracja funkcji realizującej liczenie średniej arytmetycznej
 *
 */
double average_value(unsigned int, movie_review *);

/*!
 * \brief Deklaracja funkcji realizującej wyliczanie mediany
 *
 */
double median(unsigned int, movie_review *);

/*!
 * \brief Deklaracja funkcji realizującej zapis do pliku
 *
 */
bool savetofile(movie_review *, unsigned int);




#endif
