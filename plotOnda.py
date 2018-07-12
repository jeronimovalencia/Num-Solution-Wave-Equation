import numpy as np
import matplotlib.pyplot as plt

nt = 600
nx = 1000
datos = np.genfromtxt("datosOnda.dat")

import matplotlib.animation as animation
from matplotlib import rc

fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(-2, 2))
line, = ax.plot([], [], lw=2)

def init():
	line.set_data([],[])
	return line,

def animate(i):
	datos = np.genfromtxt("datosOnda.dat")
	line.set_data(datos[i*nx:(i+1)*nx,0],datos[i*nx:(i+1)*nx,1])
	return line,


anim = animation.FuncAnimation(fig, animate, init_func=init,frames=100, interval=200, blit=True)
anim.save('cuerda.mp4', fps=30, extra_args=['-vcodec', 'libx264'])

plt.show()
