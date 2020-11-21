#pragma once
#include "Punto.h"
using namespace System::Drawing;
class AssasinNPC : public Punto
{
private:
	int w, h, f, c;
	direccion ult_movimiento;
public:
	AssasinNPC();
	AssasinNPC(int px, int py, Bitmap^ bmp);
	void Movimiento(Graphics^ g);
	void cambiar_ult_movimiento(direccion dir);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	float retornar_Ancho();
	float retornar_Alto();
	void cambiar_w(Bitmap^ bmp);
	void cambiar_h(Bitmap^ bmp);
	~AssasinNPC();
};
