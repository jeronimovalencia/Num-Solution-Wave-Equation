#include <iostream>
#include <math.h>

double t_min = 0.0;
double t_max= 50.0;
double N = 10000;
double h = (t_max-t_min)/N;

const double gam = 0.45;
const double beta = 0.0022;

double derivadaS(double t, double i, double s, double r);
double derivadaR(double t, double i, double s, double r);
double derivadaI(double t, double i, double s, double r);

int main()
{	
	double I[int((t_max-t_min)/h)];
	double S[int((t_max-t_min)/h)];
	double R[int((t_max-t_min)/h)];
	
	I[0] = 1;
	S[0] = 770;
	R[0] = 0;
	
	double x = t_min;
	
	for(int i=1;i<N;i++)
	{	
		double k1,k2,k3,k4 = 0;
		k1 = h * derivadaR(x,I[i-1],S[i-1],R[i-1]);
		k2 = h*derivadaR(x+0.5*h,I[i-1]+0.5*k1,S[i-1]+0.5*k1,R[i-1]+0.5*k1);
		k3 = h*derivadaR(x+0.5*h,I[i-1]+0.5*k2,S[i-1]+0.5*k2,R[i-1]+0.5*k2);
		k4 = h*derivadaR(x+h,I[i-1]+k3,S[i-1]+k3,R[i-1]+k3);
		
		R[i] = R[i-1] + (1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		
		k1,k2,k3,k4 = 0;
		k1 = h * derivadaI(x,I[i-1],S[i-1],R[i-1]);
		k2 = h*derivadaI(x+0.5*h,I[i-1]+0.5*k1,S[i-1]+0.5*k1,R[i-1]+0.5*k1);
		k3 = h*derivadaI(x+0.5*h,I[i-1]+0.5*k2,S[i-1]+0.5*k2,R[i-1]+0.5*k2);
		k4 = h*derivadaI(x+h,I[i-1]+k3,S[i-1]+k3,R[i-1]+k3);
		
		I[i] = I[i-1] + (1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);

		k1,k2,k3,k4 = 0;
		k1 = h * derivadaS(x,I[i-1],S[i-1],R[i-1]);
		k2 = h*derivadaS(x+0.5*h,I[i-1]+0.5*k1,S[i-1]+0.5*k1,R[i-1]+0.5*k1);
		k3 = h*derivadaS(x+0.5*h,I[i-1]+0.5*k2,S[i-1]+0.5*k2,R[i-1]+0.5*k2);
		k4 = h*derivadaS(x+h,I[i-1]+k3,S[i-1]+k3,R[i-1]+k3);
		
		S[i] = S[i-1] + (1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
	
		x = x+h;
	}

	for(int j=0; j<N;j++)
	{
		std::cout << j << " " << S[j] << " " << R[j] << " " << I[j] << std::endl;
	}
		
	return 0;
}

double derivadaR(double t, double i, double s, double r)
{
	return gam*i;
}

double derivadaI(double t, double i, double s, double r)
{
	return beta*i*s - gam*i;
}

double derivadaS(double t, double i, double s, double r)
{
	return -beta*i*s;
}





