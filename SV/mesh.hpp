#ifndef MESH_H
#define MESH_H
#include <iostream>
#include <cassert>
#include "Vector.hpp"
#include "error.hpp"
using namespace std;

class Mesh
{
  private:
  double xr; // Right-hand side of the interval I = [xl,xr]
  double xl; // Left-hand side of the interval I = [xl,xr]
  unsigned int n; // Number of intervals
  double L; // Interval Length L = xr - xl
  double h; // Discretized step h = L / n
  //double dx; xmin + i * dx = i.dx
  Vector x; // Vector x of discretized points
  Vector center; // Center of the cell C[i]


  public:
  // MAIN CONSTRUCTOR of a 1D-MESH
  Mesh::Mesh(double a,double b, unsigned int n_interval){
    double L,dx,h;
    //Vector center;
    Vector x(n+1,0.0); // Vector of size S := n+1 initialized to xl
    Vector center(n,0.0); // Vector of size S := n initialized to 0
    if (a > b)
    error("The supremum value b must be greater than the infinimum a; please try again.");
    else
    {
      xr = b;
      xl = a;
      n = n_interval;
      L = b-a;
      h = L/n_interval;
      for (unsigned int i = 0; i < n; ++i) x[i] = a + (i*h);
      for (unsigned int k = 0; k < n; ++k) center[i] = (x[i] + x[i+1]) / 2;
    }
  }

  //double Mesh::dx const {return  a + (i*h); }

  double Mesh::lower() const {return xl;}
  double Mesh::upper() const {return xr;}
};

#endif
