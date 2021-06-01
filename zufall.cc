#include <fstream>
#include <iostream>
#include <cmath>

double N_in = 0;
double N = 100;

double zufall()
{
  static int I_j;
  int a = 205;
  int c = 29573;
  int m = 139968;
  
  I_j = (a*I_j+c)%m;

  double u_j = (double)I_j/m;

  return u_j;
}

int main()
{
  for(int i=0; i<N; i++)
  {
    double x = zufall();
    double y = zufall();

    double r = sqrt(pow(x,2)+pow(y,2));

    if(r <= 1)
    {
      N_in++;
    }
  }
  double pi = N_in/N * 4;
  double p = N_in/N;
  double E = p*N;
  double V = p*(1-p)*N;
  double sigma = 4*(sqrt(V)/N);

  std::cout << "E[N_in]:" << E << std::endl;
  std::cout << "V[N_in]:" << V << std::endl;
  std::cout << "N_in:" << N_in << std::endl;
  std::cout << "Pi:" << pi << std::endl;
  std::cout << "Sigma:" << sigma << std::endl;
}