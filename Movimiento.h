#pragma once
#include <iostream>
#include "Monigote.h"
#include "Mapa.h"
using namespace std;
using namespace System::Drawing;
class Movimiento
{
private:
	Mapa** mapa;
	int* ce;
	Monigote* obj_monigote;
	int num_vidas;
	int puntaje;
public:
	Movimiento();
	Movimiento(Bitmap^ bmp);
	~Movimiento();
	//NUEVO
	void Init(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa);
	void Run(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa);
	void Mover_Monigote(Graphics^ g);
	void Cambiar_Direccion_Monigote(direccion dir);
	void Dibujar_Monigote(Graphics^ g, Bitmap^ bmp_monigote);
	void Dibujar_Mapa(Graphics^ g, Bitmap^ bmp_mapa);
	bool Colision(Punto* obj1, Punto* obj2);
};
