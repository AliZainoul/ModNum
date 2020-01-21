#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#include "Vector.hpp"
int main ()

{
  int size = 10;
  Vector v(size);
  cout << v;
  for (unsigned int k=0; k<size;++k) v[k] = k;
  double lambda=10;
  v = lambda*v;
  cout << v;
  return 0;
}
