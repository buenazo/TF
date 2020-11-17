#include "Mapa.h"
Mapa::Mapa() {}
Mapa::Mapa(int px, int py, Bitmap^ bmp) : Punto(px, py) {
	w = 32.92307692;
	h = 32.625;
	dx = dy = 0;
	f = 0;
	c = 0;
}
void Mapa::Dibujar_Imagen(Graphics^ g, Bitmap^ bmp, int pf, int pc)
{
	f = pf;
	c = pc;
	Rectangle porcion = Rectangle(c * w, f * h, w, h);
	Rectangle zoom = Rectangle(x, y, w, h);
	g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
}
float Mapa::retornar_Ancho() { return w; }
float Mapa::retornar_Alto() { return h; }
Mapa::~Mapa() {}
