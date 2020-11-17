#include "Movimiento.h"
Movimiento::Movimiento() {}
Movimiento::Movimiento(Bitmap^ bmp) {
	ce = new int;
	*ce = 0;
}
void Movimiento::Init(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa)
{
	int aux_x = 0;
	int aux_y = 0;
	obj_monigote = new Monigote(10, 10, bmp_monigote);
	obj_monigote->cambiar_ult_movimiento(direccion::abajo);
	num_vidas = 3;
	puntaje = 0;
	mapa = new Mapa * [50];
	for (int i = 0; i < 50; i++) {
		int x = aux_x;
		int y = aux_y;
		mapa[i] = new Mapa(x, y, bmp_mapa);
		if ((i + 1) % 10 == 0) {
			aux_x = 0;
			aux_y = aux_y + mapa[i]->retornar_Alto();
		}
		else
			aux_x = aux_x + mapa[i]->retornar_Ancho();
	}
}
void Movimiento::Run(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa)
{
	Dibujar_Mapa(g, bmp_mapa);
	Font^ f = gcnew Font("Arial", 10);
	SolidBrush^ b = gcnew SolidBrush(Color::Red);

	g->DrawString("Nro Vidas : " + num_vidas.ToString(), f, b, 1, 1);
	g->DrawString("Puntaje : " + puntaje.ToString(), f, b, 1, 15);

	Mover_Monigote(g);
	for (int i = 0; i < 50; i++)
	{

		if (Colision(obj_monigote, mapa[i]) && (i == 1 || i == 2 || i == 3 || i == 4 || i == 11 || i == 21 || i == 22 || i == 24 || i == 31 || i == 32 || i == 34 || i == 44))
		{
			obj_monigote->cambiar_X(obj_monigote->retornar_X() - obj_monigote->retornar_DX());
			obj_monigote->cambiar_Y(obj_monigote->retornar_Y() - obj_monigote->retornar_DY());
			obj_monigote->cambiar_ult_movimiento(ninguno);
		}

	}
	Dibujar_Monigote(g, bmp_monigote);

	//Si hay colision aqui modificar
	
}
void Movimiento::Mover_Monigote(Graphics^ g)
{
	obj_monigote->Movimiento(g);
}
void Movimiento::Cambiar_Direccion_Monigote(direccion dir) {
	obj_monigote->cambiar_ult_movimiento(dir);
}
void Movimiento::Dibujar_Monigote(Graphics^ g, Bitmap^ bmp_monigote)
{
	obj_monigote->Dibujar(g, bmp_monigote);
}
Movimiento::~Movimiento() {
	
}
void Movimiento::Dibujar_Mapa(Graphics^ g, Bitmap^ bmp_mapa) {
	mapa[0]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[1]->Dibujar_Imagen(g, bmp_mapa, 0, 7);
	mapa[2]->Dibujar_Imagen(g, bmp_mapa, 2, 8);
	mapa[3]->Dibujar_Imagen(g, bmp_mapa, 2, 8);
	mapa[4]->Dibujar_Imagen(g, bmp_mapa, 1, 9);
	mapa[5]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[6]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[7]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[8]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[9]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[10]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[11]->Dibujar_Imagen(g, bmp_mapa, 1, 7);
	mapa[12]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[13]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[14]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[15]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[16]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[17]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[18]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[19]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[20]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[21]->Dibujar_Imagen(g, bmp_mapa, 1, 7);
	mapa[22]->Dibujar_Imagen(g, bmp_mapa, 1, 7);
	mapa[23]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[24]->Dibujar_Imagen(g, bmp_mapa, 1, 7);
	mapa[25]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[26]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[27]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[28]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[29]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[30]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[31]->Dibujar_Imagen(g, bmp_mapa, 2, 7);
	mapa[32]->Dibujar_Imagen(g, bmp_mapa, 2, 9);
	mapa[33]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[34]->Dibujar_Imagen(g, bmp_mapa, 1, 7);
	mapa[35]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[36]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[37]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[38]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[39]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[40]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[41]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[42]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[43]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[44]->Dibujar_Imagen(g, bmp_mapa, 1, 7);
	mapa[45]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[46]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[47]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[48]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
	mapa[49]->Dibujar_Imagen(g, bmp_mapa, 0, 0);
}
bool Movimiento::Colision(Punto* obj1, Punto* obj2) {
	Rectangle rect1 = Rectangle(obj1->retornar_X(),
		obj1->retornar_Y(),
		obj1->retornar_Ancho(),
		obj1->retornar_Alto());
	Rectangle rect2 = Rectangle(obj2->retornar_X(),
		obj2->retornar_Y(),
		obj2->retornar_Ancho()/2,
		obj2->retornar_Alto()/2);
	return rect1.IntersectsWith(rect2);
}
