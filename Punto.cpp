#include "Punto.h"
Punto::Punto() {}
Punto::Punto(int px, int py)
{
	x = px;
	y = py;
	dx = 1 + rand() % 10;
	dy = 1 + rand() % 5;
	eliminar = false;
}
void Punto::Dibujar(Graphics^ g)
{

}
void Punto::Dibujar_R(Graphics^ g)
{

}
void Punto::Mover(Graphics^ g)
{

}
Punto::~Punto()
{}
int Punto::retornar_X() { return x; }
int Punto::retornar_Y() { return y; }
void Punto::cambiar_X(int nuevo) { x = nuevo; }
void Punto::cambiar_Y(int nuevo) { y = nuevo; }
float Punto::retornar_Ancho() { return 0; }
float Punto::retornar_Alto() { return 0; }
bool Punto::retornar_eliminar() { return eliminar; }
void Punto::cambiar_eliminar(bool nuevo) { eliminar = nuevo; }
int Punto::retornar_DX() { return dx; }
int Punto::retornar_DY() { return dy; }
void Punto::cambiar_DX(int nuevo) { dx = nuevo; }
void Punto::cambiar_DY(int nuevo) { dy = nuevo; }
