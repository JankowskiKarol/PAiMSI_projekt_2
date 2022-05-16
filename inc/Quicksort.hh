#ifndef QUICKSORT_HH
#define QUICKSORT_HH

#include "Movie_ranking.hh"

using namespace std;


/*!
 * \brief Deklaracja funkcji realizującej segregowanie względem wybranej osi
 *
 */
int arrange(movie_review *, int, int );

/*!
 * \brief Deklaracja funkcji realizującej algorytm szybkiego sortowania
 *
 */
void quick_sort(movie_review *, int, int );


#endif


