#include <iostream>
#include "Kubelkowe.hh"
#include "Quicksort.hh"

using namespace std;


/*!
 * \brief Realizuje algorytm sortowania kubełkowego
 * 
 * \param[in] array - tablica z danymi
 * \param[in] range - rozmiar danych
 * \param[in] best_mark - zakres recencji filmu
 * 
 */
void bucket_sort(movie_review *array, unsigned int range, unsigned int best_mark)
{
	movie_review **bucket = new movie_review*[best_mark];

	for (int i =0; i<10; i++)
	{
		bucket[i] = new movie_review[range];
	}

    int *j = new int[best_mark];
 	int help_ind;
	int p = 1;
	int save_ind;
  
    for(unsigned int i=0; i<best_mark; i++)
    {
        for(unsigned int z=0; z<best_mark; z++)
		{
			j[z]=0;
		}
            
        for(unsigned int r=0; r<range; r++)
        {
            help_ind = ((int)array[r].get_review()/p) % 10;
            bucket[help_ind][j[help_ind]] = array[r];
            j[help_ind]++;
        }
     
        save_ind = 0;
        for(unsigned int y=0; y<10; y++)
        {
            for(help_ind=0; help_ind<j[y]; help_ind++)
            {
                array[save_ind] = bucket[y][help_ind];
                save_ind++;
            }
        }
        p*=10;
    }
}


