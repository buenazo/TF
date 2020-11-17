#pragma once
#include "Punto.h"
class Mapa :
	public Punto
{
private:
	float w, h, f, c;
public:
	Mapa();
	Mapa(int px, int py, Bitmap^ bmp);
	void Dibujar_Imagen(Graphics^ g, Bitmap^ bmp, int pf, int pc);
	float Mapa::retornar_Ancho();
	float Mapa::retornar_Alto();
	~Mapa();
};
