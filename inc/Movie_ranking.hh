#ifndef MOVIERANKING_HH
#define MOVIERANKING_HH

using namespace std;

/*!
 * \brief Klasa modeluje pojęcie filmu w rankingu
 *
 * Klasa zawiera tytuł opisywanego filmu oraz jego ocene z rankingu
 * 
 * W klasie zostal zdefiniowany konstruktor nieparametryczny i parametryczny
 * Klasa zawiera również metody dostępowe do pól prywatnych klasy
 */
class movie_review
{
private:
    double review;
    string title;
public:
    movie_review(){review = 0; title = "none";};
    movie_review(double i, string j){review = i; title = j;};
    double get_review(){return review;};
    string get_title(){return title;};
};


#endif
