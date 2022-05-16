#include <iostream>
#include <cstdlib>
#include <cstring>
#include "FileHandling.hh"


using namespace std;


/*!
 * \brief realizuje odczyt danych z pliku oraz analize poprawnosci danych w 
 *        nim zawartych
 * 
 * \param[in] Inputfile - rekurencja do uchwytu do pliku
 * \param[in] nameoffile - wskaznik na nazwe pliku
 * \param[in] number_of_movie - rekurencja na liczbe danych
 * \param[in] array - tablica z danymi
 * 
 * \return true jezeli plik zostal otworzony poprawnie
 * \return false jezeli plik nie zostal otworzony poprawnie
 */
bool work_with_file(ifstream &Inputfile, const char *nameoffile, unsigned int &number_of_movie, movie_review *array)
{
  if (!strcmp(nameoffile,"projekt2_dane"))
  {
    Inputfile.open("projekt2_dane.csv");
    if (!Inputfile.is_open())
    {
      cerr << "Plik z rankingiem filmów nie zostal otwarty" << endl;
      return false;
    }
  }

  unsigned int number = 1;
  string ordinal, movie, review;
  double mark;
  int i = 0;
  char symbol;

  while (number <= number_of_movie)
  {
    if (Inputfile.eof())
    {
      cerr << "W pliku nie ma tylu poprawnych danych" << endl;
      return false;
    }
    getline(Inputfile,ordinal,',');
    if(Inputfile.peek() == '"')
    {
      Inputfile >> symbol;
      getline(Inputfile,movie,'"');
        if(Inputfile.peek() == '"')
        {
          Inputfile >> symbol;
          getline(Inputfile,movie,'"');
        }
        if(Inputfile.peek() == '"')
        {
          Inputfile >> symbol;
          getline(Inputfile,movie,'"');
        }
      Inputfile >> symbol;
      
    }
    else
    {
      getline(Inputfile,movie,',');
    }
    if(Inputfile.peek() != '\n')
    {
      getline(Inputfile,review);
      mark = atof(review.c_str());
      movie_review position(mark,movie);
      array[i] = position;
      i++;
      number++;
    }
  }
  return true;
 }


/*!
 * \brief realizuje operacje matematyczna - średnia arytmetyczna
 * 
 * \param[in] array - tablica z danymi
 * \param[in] number_of_movie - rozmiar danych
 * 
 * \return wartość średniej arytmetycznej zestawu danych
 *
 */
  double average_value(unsigned int number_of_movie, movie_review *array)
  {
    double sum = 0;
    for(unsigned int i=0; i<number_of_movie; i++)
    {
      sum = sum + array[i].get_review();
    }
    sum = sum / number_of_movie;
    return sum;
  }


/*!
 * \brief realizuje operacje matematyczna - mediana
 * 
 * \param[in] array - tablica z danymi
 * \param[in] number_of_movie - rozmiar danych
 * 
 * \return wartość mediany zestawu danych
 *
 */
  double median(unsigned int number_of_movie, movie_review *array)
  {
    double median;
    median = (array[number_of_movie / 2 -1].get_review() + array[number_of_movie / 2].get_review())/2;
    return median;
  }


 /*!
 * \brief realizuje zapis do pliku
 * 
 * \param[in] array - tablica z danymi
 * \param[in] size - rozmiar danych
 *
 */
  bool savetofile(movie_review *array, unsigned int size)
  {
    ofstream save("wynik.txt");

    for(unsigned int i=0; i<size; i++)
    {
      save << array[i].get_title() << '\n' << array[i].get_review() << endl;
    }
    save.close();
    return true;
  }




