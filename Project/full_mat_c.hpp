#ifndef FULL_MAT_C_H
#define FULL_MAT_C_H
#include "Vector.hpp"
using namespace std;

class FullMtx
{
private:
  int ncols; // Number of columns of a Matrix
	int nrows; // Number of rows of a Matrix
  double** mx; // Entries of the Matrix

public:
  FullMtx(int n, int m, double**); // Constructor 1
  FullMtx(int n, int m, double t = 0); // Constructor 2
  FullMtx(initializer_list<initializer_list<double>> lst); // Constructor 3
  FullMtx(const FullMtx&);            // Copy Constructor
  // Destructor
  ~FullMtx() {
    for (int i = 0; i< nrows; i++) delete[]  mx[i];
    delete[] mx;
  }
  friend FullMtx operator * (const FullMtx&, const FullMtx&); // Matrix Multiplication
  FullMtx& operator=(const FullMtx&); // Overload of the Operator '='
  Vector operator*(const Vector&) const; // Matrix-Vector multiply
  double* operator[](int i) const { return mx[i]; } // Method that Returns the i-th row
  friend ostream& operator<<(ostream&, const FullMtx&);     // Overload of the Operator '<<'
/*
  // FullMtx& operator+=(const FullMtx& FllMtx); // Unary Operator, usage: M += N
  // FullMtx& operator-=(const FullMtx& FllMtx); // Unary Operator, usage: M -= N
  // friend FullMtx operator+(const FullMtx&); // Unary Operator, usage: M = +M
  // friend FullMtx operator-(const FullMtx&); // Unary Operator, usage: M = -M
  // friend FullMtx operator+(const FullMtx&, const FullMtx&);  // Binary Operator, usage: M = A + B
  // friend FullMtx operator-(const FullMtx&, const FullMtx&);  // Binary Operator, usage: M = A - B
  // friend FullMtx operator*(double, const FullMtx&); // Scalar-Matrix Product, usage: M = k * N
  // friend FullMtx operator*(const FullMtx&, double); // Matrix-Scalar Product, usage: M = N * k
  // MATRIX NORMS?
  */
};


#endif
//****** End full_mat_c.hpp  ******//
