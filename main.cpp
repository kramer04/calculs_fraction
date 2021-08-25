#include "Test.h"

int main()
{
  Test fm;

  std::string entree;
  std::cout << "Entrer fractions" << "\n";
  std::cin >> entree;

  fm.calcul(fm.extraire(entree));

  fm.afficher(entree);

  return EXIT_SUCCESS;
}