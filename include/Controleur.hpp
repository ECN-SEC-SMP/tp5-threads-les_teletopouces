#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class TomyLeControleur
{
public:
  TomyLeControleur(int valeur_initiale) : compteur_de_dinotrains(valeur_initiale)
  {
  }

  bool controlinEnB(int numero)
  {
    if (compteur_de_dinotrains >= 0)
    {
      compteur_de_dinotrains++;
      return true;
    }
    return false;
  }

  bool controlinEnA(int numero)
  {
    if (compteur_de_dinotrains <= 0)
    {
      compteur_de_dinotrains--;
      return true;
    }
    return false;
  }

  bool controloutEnB(int numero)
  {
    compteur_de_dinotrains++;
    return true;
  }

  bool controloutEnA(int numero)
  {
    compteur_de_dinotrains--;
    return true;
  }

private:
  /**
   * @brief Compteur de dinotrains
   * @details Négatif = trains circulant de A à B
   *          Positif = trains circulant de B à A
   *          0 = Aucun train ne circule
   */
  int compteur_de_dinotrains;
};

#endif // CONTROLEUR_HPP
