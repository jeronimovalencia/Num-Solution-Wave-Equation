grafica.pdf : plotSIR.py datosSIR.dat
	python plotSIR.py
	xdg-open graficaSIR.pdf


datosSIR.dat : datosSIR.exe
	./datosSIR.exe > datosSIR.dat
	rm datosSIR.exe

datosSIR.exe : SIR.cpp
	g++ SIR.cpp -o datosSIR.exe
