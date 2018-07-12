import numpy as np
import matplotlib.pyplot as plt
N = 10000
datos = np.genfromtxt("datosSIR.dat")

plt.figure()
plt.plot(datos[:,0],datos[:,1],color="r",label='S')
plt.plot(datos[:,0],datos[:,2],color="k",label='R')
plt.plot(datos[:,0],datos[:,3],color="b",label='I')
plt.plot(datos[:,0],datos[:,1]+datos[:,2]+datos[:,3],color="g",label='Suma')
plt.legend(loc="right")
plt.savefig("graficaSIR.pdf")
