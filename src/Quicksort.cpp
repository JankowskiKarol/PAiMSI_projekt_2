#include <iostream>
#include "Quicksort.hh"



/*!
 * \brief Realizuje algorytm ułożenia względem wartości pivot'a
 * 
 * \param[in] array - tablica z danymi
 * \param[in] left - zakres lewy indeksu tablicy
 * \param[in] right - zakres prawy indeksu tablicy
 */
int arrange(movie_review *array, int left, int right)
{
    int i = left;
    int j = right;
    double pivot = array[(left+right)/2].get_review();  //wybieramy pivot jako środkową wartość 

    while (true)
    {
        while (array[j].get_review() > pivot) j--;

        while (array[i].get_review() < pivot) i++;

        if (i < j)
        {
            swap(array[i++], array[j--]);
        }  
        else return j;
    }
}


/*!
 * \brief Realizuje algorytm szybkiego sortowania
 * 
 * \param[in] array - tablica z danymi
 * \param[in] left - zakres lewy indeksu tablicy
 * \param[in] right - zakres prawy indeksu tablicy
 */
void quick_sort(movie_review *array, int left, int right)
{
    
    if (left < right) /* W przypadku jednego elementu zbiór jest posortowany */
    {
        int split_point;

        split_point = arrange(array, left, right);
        quick_sort(array, left, split_point);
        quick_sort(array, split_point+1, right);
    }
}





