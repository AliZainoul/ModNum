#ifndef VOLFINI_H
#define VOLFINI_H
#include "Vector.hpp"
#include "full_mat_c.hpp"

using namespace std;

void volFini(int i,int itermax);
Vector flux(Vector u1,Vector u2);
Vector F(Vector u);

#endif // VOLFINI_H
