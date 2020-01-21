#include <cmath>
#include <iostream>
#include "Vector.hpp"
#include "full_mat_c.hpp"

using namespace std;
int g=10; // Gravity Constant

// Saint Venant Main Function
void SV(int n,int itermax)
{
  // Mesh Generating [-2,2]
  double xg=-10;
  double xd=10;
  double L=xd-xg;
  double deltax=L/n;
  // int ne=n-1; Number of Elements
  // Mesh Elements
  Vector x(n+1);
  for (int j=0;j<n+1;j++) x[j]=xg+j*deltax;
  // Center of Mesh Elements
  Vector center(n);
  for (unsigned int k=0; k<n; ++k)  center[k] = (x[k] + x[k+1]) / 2;


  //double* h0=new double[n+1];
  Vector h0(n+1);
  for (int j=0;j<n+1;j++) if (x[j]>0) h0[j]=1; else h0[j]=2;
  Vector q0(n+1,0.0);



  //u_0(i)
  double** u0;
  u0=new double*[n+1];
  for (int i=0;i<n+1;i++)
  {
    double init=0;
    u0[i]=new double[2];
    // Approximation de l'integral
    for (int j=0;j<n;j++) init += deltax*(h0[j+1]-h0[j]);
    u0[i][0]=init;
    u0[i][1]=0;
  }

  //3 Condition CFL
  Vector lambda(n+1,0.0);
  for (int j=0;j<n+1;j++)
  {
    double h=u0[j][1];
    double q=u0[j][0];
    lambda[j]=sqrt(h*h+q*q)+sqrt(g*h);
  }


  // 4 Boucle en temps
  double deltaT=deltax*0.9/(lambda.maxnorm());

  Vector U(2);
  for (int iter=0;iter<itermax;iter++)
  {
    //calcul du flux
  }
    //return 1;
}

Vector F(Vector u){
  Vector F(2);
  double h=u[0];
  double q=u[1];
  F[0]=q;
  F[1]=q*q/h+g*h*h/2;
  return F;
}

Vector flux(Vector u1,Vector u2){
  Vector flux(2);
  //calcul de lambda j+1/2
  double lambda;
  double h1=u1[0];
  double q1=u1[1];
  double v1=sqrt(h1*h1+q1*q1);
  double h2=u2[0];
  double q2=u2[1];
  double v2=sqrt(h2*h2+q2*q2);
  lambda=max(v1+sqrt(g*h1),v2+sqrt(g*h2));
  Vector F1(2);
  Vector F2(2);
  F1=F(u1);
  F2=F(u2);
  flux[0]=(1/2)*(F1[0]+F2[0])-(lambda/2)*(h2-h1);
  flux[1]=(1/2)*(F2[1]+F2[1])-(lambda/2)*(q2-q1);
  return flux;
}
