#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class Controleur
{
public:
  Controleur(int valeur_initiale) : train_counter(valeur_initiale)
  {
  }

  bool controlinEnB(int numero)
  {
    if (train_counter >= 0)
    {
      train_counter++;
      return true;
    }
    return false;
  }

  bool controlinEnA(int numero)
  {
    if (train_counter <= 0)
    {
      train_counter--;
      return true;
    }
    return false;
  }

  bool controloutEnB(int numero)
  {
    train_counter++;
    return true;
  }

  bool controloutEnA(int numero)
  {
    train_counter--;
    return true;
  }

private:
  /**
   * @brief Compteur de trains
   * @details Négatif = trains circulant de A à B
   *          Positif = trains circulant de B à A
   *          0 = Aucun train ne circule
   */
  int train_counter;
};

#endif // CONTROLEUR_HPP
