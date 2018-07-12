#include <iostream>
#include <math.h>

//Discretización de las variables
const int nx=200;
double x[nx];

int nt = 600;

double L = 100;
double rho = 10;
double T = 40;


double c=sqrt(T/rho);
double A = 1/(c*c);
double x_min = 0;
double x_max = L;
double delta_x = 1.0*(x_max-x_min)/nx;
double delta_t = 1.0*sqrt(A)*delta_x;
double t_final = nt*delta_t;

int main()
{
	double u_futuro[nx];
	double u_presente[nx];
	double u_pasado[nx];
	
	//Condicion inicial
	double u_inicial[nx];

	for(int i=0; i<nx;i++)
	{
		if(i< 160)
		{
			u_inicial[i] = 1.25*(delta_x)*i/L;
		}	
		else
		{
			u_inicial[i] = 5.0-5.0*i*delta_x/L;	
		}
	}


	//Condicion de frontera
	u_futuro[0]=0;
	u_futuro[nx-1]=0;

	for(int m=0;m<nx;m++)
	{
		u_pasado[m] = u_inicial[m];
	}

	for(int m=1;m<nx-1;m++)
	{
		u_presente[m] = pow((delta_t/delta_x),2)*(1/A)*(u_pasado[m+1]-2*u_pasado[m]+u_pasado[m-1]) + 2*u_pasado[m] - u_pasado[m];
	}

	for(int j=0;j<nt;j++)
	{
		for(int k=1;k<nx-1;k++)
		{
			u_futuro[k] = pow((delta_t/delta_x),2)*(1.0/A)*(u_presente[k+1]-2.0*u_presente[k]+u_presente[k-1]) + 2.0*u_presente[k] - u_pasado[k];
		}

		for(int l=0;l<nx;l++)
		{
			u_pasado[l] = u_presente[l];
			u_presente[l] = u_futuro[l];
			
			std::cout << l*delta_x << " " << u_presente[l] << std::endl;
		}
		
	}

	std::cout << "Tiempo=" << " " << t_final << std::endl;	
	
	return 0;
}


















