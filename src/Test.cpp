#include "Test.h"

//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c?page=1&tab=votes#tab-top

bool isNbr(std::string &str)
{
  return std::ranges::all_of(str.begin(), str.end(), [](unsigned char c) {return isdigit(c) != 0; });
}

Test::Test() :m_num {1}, m_den {1} {}

long long Test::gcd(const long long &n, const long long &d)
{
  long long r {1}, a, b;
  n < 0 ? a = -n : a = n;
  d < 0 ? b = -d : b = d;
  while (r != 0)
  {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void Test::calcul(std::vector<std::string> sortie)
{
  /*
  if (sortie[3] == "*")
  {
    sortie[0] = std::to_string(std::stoll(sortie[0]) * std::stoll(sortie[4]));
    sortie[2] = std::to_string(std::stoll(sortie[2]) * std::stoll(sortie[6]));
    sortie.erase(std::begin(sortie) + 3, std::begin(sortie) + 7);
  }
  */
  u_int64_t taille {std::size(sortie)};

  for (uint i {0}; i < taille; i++)
  {
    if (sortie[i] == "*")
    {
      sortie[i - 3] = std::to_string(std::stoll(sortie[i - 3]) * std::stoll(sortie[i + 1]));
      sortie[i - 1] = std::to_string(std::stoll(sortie[i - 1]) * std::stoll(sortie[i + 3]));
      sortie.erase(std::begin(sortie) + i, std::begin(sortie) + 4 + i);

      taille = std::size(sortie);
      i = 0;
      std::cout << "--------------------------" << std::endl;
      std::cout << "Multiplication" << std::endl;
      for (std::string k : sortie)
      {
        std::cout << k;
      }
      std::cout << "\n";
      std::cout << "--------------------------" << std::endl;
    }

  }

  m_num = std::stoll(sortie[0]);
  m_den = std::stoll(sortie[2]);
  int pgcd {0};
  pgcd = gcd(m_num, m_den);
  m_num /= pgcd;
  m_den /= pgcd;

  for (u_int8_t i {3}; i < taille; i += 3)
  {
    if (sortie[i] == "+")
    {
      sortie.erase(std::begin(sortie) + i);
      taille = std::size(sortie);
    }
    m_num = m_num * std::stoll(sortie[i + 2]) + m_den * std::stoll(sortie[i]);
    m_den *= std::stoll(sortie[i + 2]);
    pgcd = gcd(m_num, m_den);
    m_num /= pgcd;
    m_den /= pgcd;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Addition - Soustraction" << std::endl;

    std::cout << m_num << "/" << m_den;
    std::string k;
    
    for (uint j = i + 3; j < taille; ++j)
    {
      if (isNbr(k) && isNbr(sortie[j]))
      {
        std::cout << "+";
      }
      std::cout << sortie[j];
      k = sortie[j];
    }
    
    std::cout << "\n";
    //std::cout << m_num << "/" << m_den << "\n";
    std::cout << "--------------------------" << std::endl;
  }
}

std::vector<std::string> Test::extraire(std::string entree)
{
  std::vector<std::string> bloc;
  std::string str;
  u_int64_t taille {entree.size()};
  int j {-1};
  bool isNbr = true;

  for (unsigned int i {0}; i < taille; ++i)
  {
    if (isdigit(entree[i]) && isNbr == false)
    {
      str = entree[i];
      bloc[j] = bloc[j] + str;
    }
    if ((isdigit(entree[i]) && isNbr) || entree[i] == '-')
    {
      str = entree[i];
      bloc.push_back(str);
      isNbr = false;
      ++j;
    }
    if (isdigit(entree[i]) == false)
    {
      str = entree[i];
      if (str != "-")
      {
        bloc.push_back(str);
        ++j;
        isNbr = true;
      }

    }
  }
  /*
  for (std::string k : bloc)
  {
    std::cout << "bloc = " << k << std::endl;
  }
  */
  return bloc;
}
void Test::afficher(std::string entree)
{
  std::cout << "--------------------------" << std::endl;
  std::cout << "Résultat final :" << std::endl;
  std::cout << entree << " est égal à\n";
  std::cout << m_num << "/" << m_den << std::endl;
  std::cout << "--------------------------" << std::endl;
}