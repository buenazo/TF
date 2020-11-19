#pragma once
#include "Punto.h"
using namespace System::Drawing;
class Aliado : public Punto
{
private:
	int w, h, f, c, animal;
	direccion ult_movimiento;
public:
	Aliado();
	Aliado(int px, int py, int panimal, Bitmap^ bmp);
	void Movimiento(Graphics^ g);
	void cambiar_ult_movimiento(direccion dir);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	float retornar_Ancho();
	float retornar_Alto();
	int retornar_animal();
	~Aliado();
};

