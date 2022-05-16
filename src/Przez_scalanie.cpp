#include <iostream>
#include "Przez_scalanie.hh"

using namespace std;


/*!
 * \brief Realizuje scalanie posortowanych tablic
 * 
 * \param[in] array - tablica z danymi
 * \param[in] help_tab - tablica pomocnicza do wykonania scalania
 * \param[in] left - zakres lewy indeksu tablicy
 * \param[in] right - zakres prawy indeksu tablicy
 * \param[in] middle - wartość srodkowa
 */
void connect(movie_review *array, movie_review *help_tab, int left, int middle, int right)
{
    int i;
    int j;
    int sort;
	
	for (i=middle+1; i>left; i--) 
    {
        help_tab[i-1] = array[i-1];
    }

    for (j=middle; j<right; j++) 
    {
        help_tab[middle+right-j] = array[j+1];
    }

	for (sort=left; sort<=right; sort++)
    {
        if (help_tab[j].get_review()<help_tab[i].get_review())
        {
            array[sort] = help_tab[j--];
        }
        else
        {
            array[sort] = help_tab[i++];
        }
    }
}


/*!
 * \brief Realizuje algorytm sortowania przez scalanie
 * 
 * \param[in] array - tablica z danymi
 * \param[in] help_tab - tablica pomocnicza do wykonania sortowań
 * \param[in] left - zakres lewy indeksu tablicy
 * \param[in] right - zakres prawy indeksu tablicy
 * 
 */
void merge_sort(movie_review *array, movie_review *help_tab, int left, int right)
{
	if (left < right) /* W przypadku jednego elementu zbiór jest posortowany */
	{
		int middle = (right + left)/2;

		merge_sort(array, help_tab, left, middle); 
		merge_sort(array, help_tab, middle+1, right);

		connect(array, help_tab, left, middle, right);
	}
}
