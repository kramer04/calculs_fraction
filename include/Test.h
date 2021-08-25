#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Test {
  public:
  Test();
  std::vector<std::string> extraire(std::string entree);
  void calcul(std::vector<std::string> sortie);
  void afficher(std::string entree);
  
  private:
  long long gcd(const long long &n, const long long &d);
  long long m_num, m_den;
};

#endif