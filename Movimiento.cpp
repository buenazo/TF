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

		if (Colision(obj_monigote, mapa[i]) && (mapa[i]->retornar_limite()))
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
	mapa[0]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1]->Dibujar_Imagen(g, bmp_mapa, 0, 7, true);
	mapa[2]->Dibujar_Imagen(g, bmp_mapa, 2, 8, true);
	mapa[3]->Dibujar_Imagen(g, bmp_mapa, 2, 8, true);
	mapa[4]->Dibujar_Imagen(g, bmp_mapa, 1, 9, true);
	mapa[5]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[6]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[7]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[8]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[9]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[10]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[11]->Dibujar_Imagen(g, bmp_mapa, 1, 7, true);
	mapa[12]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[13]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[14]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[15]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[16]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[17]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[18]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[19]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[20]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[21]->Dibujar_Imagen(g, bmp_mapa, 1, 7, true);
	mapa[22]->Dibujar_Imagen(g, bmp_mapa, 1, 7, true);
	mapa[23]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[24]->Dibujar_Imagen(g, bmp_mapa, 1, 7, true);
	mapa[25]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[26]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[27]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[28]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[29]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[30]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[31]->Dibujar_Imagen(g, bmp_mapa, 2, 7, true);
	mapa[32]->Dibujar_Imagen(g, bmp_mapa, 2, 9, true);
	mapa[33]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[34]->Dibujar_Imagen(g, bmp_mapa, 1, 7, true);
	mapa[35]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[36]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[37]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[38]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[39]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[40]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[41]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[42]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[43]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[44]->Dibujar_Imagen(g, bmp_mapa, 1, 7, true);
	mapa[45]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[46]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[47]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[48]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[49]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
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
//System::DateTime::Now.Ticks : srand para Random() -> Random(System::DateTime::Now.Ticks)
