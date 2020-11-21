#include "AssasinNPC.h"
AssasinNPC::AssasinNPC() {}
AssasinNPC::AssasinNPC(int px, int py, Bitmap^ bmp) : Punto(px, py)
{
	w = bmp->Width / 4; //ANCHO DE 1 MONIGOTE
	h = bmp->Height / 4; //ALTURA DE 1 MONIGOTE
	dx = dy = 1;
	f = c = 0;
}
void AssasinNPC::Movimiento(Graphics^ g)
{
	if (ult_movimiento == arriba && y + dy > g->VisibleClipBounds.Top)
		y += dy;
	if (ult_movimiento == abajo && y + dy + h / 2 < g->VisibleClipBounds.Bottom)
		y += dy;
	if (ult_movimiento == izquierda && x + dx > g->VisibleClipBounds.Left)
		x += dx;
	if (ult_movimiento == derecha && x + dx + w / 2 < g->VisibleClipBounds.Right)
		x += dx;
	c++;
	if (disfraz) {
		if (c > 2)
			c = 0;
	}
	else {
		if (c > 3)
			c = 0;
	}
}
void AssasinNPC::cambiar_ult_movimiento(direccion dir) {
	ult_movimiento = dir;
	switch (ult_movimiento) {
	case arriba: f = 3; dx = 0; dy = (-1 * (1 + rand() % 5))*2; break;
	case abajo: f = 0; dx = 0; dy = (1 + rand() % 5)*2; break;
	case izquierda: f = 1; dy = 0; dx = (-1 * (1 + rand() % 5))*2; break;
	case derecha: f = 2; dy = 0; dx = (1 + rand() % 5)*2; break;
	case ninguno: dx = dy = 0; break;
	}
}
void AssasinNPC::Dibujar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle porcion = Rectangle(c * w, f * h, w, h);
	Rectangle zoom = Rectangle(x, y, w / 2, h / 2);
	g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
}
AssasinNPC::~AssasinNPC() {}
float AssasinNPC::retornar_Ancho() { return w / 2; }
float AssasinNPC::retornar_Alto() { return h / 2; }
void AssasinNPC::cambiar_w(Bitmap^ bmp) { w = bmp->Width / 3; }
void AssasinNPC::cambiar_h(Bitmap^ bmp) { h = bmp->Height / 4; }
