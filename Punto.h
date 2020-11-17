#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

public enum direccion { arriba, abajo, izquierda, derecha, ninguno };

class Punto
{
protected:
	int x, y, dx, dy;
	bool eliminar;
public:
	Punto();
	Punto(int px, int py);
	virtual void Dibujar(Graphics^ g);
	virtual void Dibujar_R(Graphics^ g);
	virtual void Dibujar_Imagen(Graphics^ g, Bitmap^ bmp, int pf, int pc);
	virtual void Mover(Graphics^ g);
	int retornar_X();
	int retornar_Y();
	void cambiar_X(int nuevo);
	void cambiar_Y(int nuevo);
	virtual int retornar_Ancho();
	virtual int retornar_Alto();
	bool retornar_eliminar();
	void cambiar_eliminar(bool nuevo);
	int retornar_DX();
	int retornar_DY();
	void cambiar_DX(int nuevo);
	void cambiar_DY(int nuevo);
	~Punto();
};
