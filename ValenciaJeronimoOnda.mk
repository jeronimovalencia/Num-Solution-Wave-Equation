grafica.pdf : plotOnda.py datosOnda.dat
	python plotOnda.py
	xdg-open grafica.pdf


datosOnda.dat : datosOnda.exe
	./datosOnda.exe > datosOnda.dat
	rm datosOnda.exe

datosOnda.exe : ValenciaJeronimoOnda.cpp
	g++ ValenciaJeronimoOnda.cpp -o datosOnda.exe
