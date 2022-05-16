#ifndef PRZEZSCALANIE_HH
#define PRZEZSCALANIE_HH

#include "Movie_ranking.hh"

using namespace std;


/*!
 * \brief Deklaracja funkcji realizującej łączenie posortowanych tablic
 *
 */
void connect(movie_review *, movie_review *, int , int , int );

/*!
 * \brief Deklaracja funkcji realizującej algorytm sortowania przez scalanie
 *
 */
void merge_sort(movie_review *, movie_review *, int , int );



#endif
