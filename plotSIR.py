import numpy as np
import matplotlib.pyplot as plt
N = 100
datos = np.genfromtxt("datosSIR.dat")

plt.figure()
plt.plot(datos[:N+1,0],datos[:N+1,1],color="r",label='S')
plt.plot(datos[N+1:2*N+1,0],datos[N+1:2*N+1,1],color="k",label='R')
plt.plot(datos[2*N+1:,0],datos[2*N+1:,1],color="b",label='I')
plt.legend()
plt.savefig("graficaSIR.pdf")
