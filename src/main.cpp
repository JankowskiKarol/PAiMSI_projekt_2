#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>


#include "Movie_ranking.hh"
#include "FileHandling.hh"
#include "Quicksort.hh"
#include "Przez_scalanie.hh"
#include "Kubelkowe.hh"


using namespace std;



int main()
{
   ifstream File;
   unsigned int size;
   unsigned int best_mark = 10;

   cout << endl << "Podaj ilość danych do analizy:" << endl;
   cin >> size;
   movie_review *array;
   movie_review *help_tab;
   array = new movie_review[size];
   help_tab = new movie_review[size];

   if(!work_with_file(File, "projekt2_dane", size, array)) return 1;

   /* Zawiera kod służacy do pomiaru złożoności obliczeniowej zaimplementowanych sortowań */
   
    double r;
    cout.setf(ios::fixed);
    cout.precision(10);
    clock_t start, end;
    start = clock();

     merge_sort(array, help_tab, 0, size-1);
    // quick_sort(array, 0, size-1);
    // bucket_sort(array, size, best_mark);

    end = clock();
    r = (end - start)/(double)CLOCKS_PER_SEC;

   double srednia = average_value(size,array);
   double mediana = median(size,array);

   if(!savetofile(array, size)) return 1;

   cout << endl << "Wartość średnia: \t" << srednia;
   cout << endl << "Mediana: \t" << mediana << endl;
   cout << "Czas wykonania: \t" << r << endl;

}