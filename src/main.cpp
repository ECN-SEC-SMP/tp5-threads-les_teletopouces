#include <iostream>
#include <thread>
#include "Semaphore.hpp"

int ressourcePartagee;
Semaphore sem(1);

void lecteur(int numLecteur)
{
  for (int i = 0; i < 4; i++)
  {
    std::cout << "Lecteur n° " << numLecteur << " en cours " << endl;
    this_thread::sleep_for(chrono::milliseconds(rand() % 2000));

    // protect shared resource
    sem.P();
    // use shared resource
    std::cout << "        Valeur lue = " << ressourcePartagee << "  " << endl;
    // release shared resource
    sem.V();
  }
}

void ecrivain(int numEcrivain)
{
  int x;
  for (int i = 0; i < 4; i++)
  {
    std::cout << "Ecrivain n° " << numEcrivain << " en cours " << endl;

    // protect shared resource
    sem.P();

    // use shared resource
    x = ressourcePartagee;
    this_thread::sleep_for(chrono::milliseconds(rand() % 2000));
    std::cout << "Ecrivain n° " << numEcrivain << " : " << "valeur à incrémenter de la ressourcePartagee = " << x << "  " << endl;
    ressourcePartagee = x + 1;

    // release shared resource
    sem.V();
  }
}

int main()
{
  const int nbr = 8;
  std::thread r[nbr];
  std::thread w[nbr];
  int ressourcePartagee = 0;

  for (int i = 1; i < nbr; i++)
  {
    r[i] = std::thread(lecteur, -i);
    w[i] = std::thread(ecrivain, i);
  }
  // Join des threads
  for (int i = 1; i < nbr; i++)
  {
    r[i].join();
    w[i].join();
  }
  return 0;
}
