#include "Movimiento.h"
Movimiento::Movimiento() {
	ce = new int;
	*ce = 0;
	ce_2 = new int;
	*ce_2 = 0;
	ce_3 = new int;
	*ce_3 = 0;
}
Movimiento::Movimiento(Bitmap^ bmp) {
	
}
void Movimiento::Insertar_Portal(Graphics^ g, Bitmap^ bmp_portal1,Bitmap^bmp_portal2, int p, int j) {
	Punto** aux = new Punto * [*ce_3];
	for (int i = 0; i < *ce_3; i++)
		aux[i] = poderes[i];
	poderes = new Punto * [*ce_3 + 1];
	for (int i = 0; i < *ce_3; i++)
		poderes[i] = aux[i];
	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	switch (p) {
	case 1: poderes[*ce_3] = new Portal(x, y, bmp_portal1);
	case 2: poderes[*ce_3] = new Portal(x, y, bmp_portal2);
	}
	*ce_3 = *ce_3 + 1;
}
void Movimiento::Insertar_Hielo(Graphics^ g, Bitmap^ bmp_hielo, int j) {
	Punto** aux = new Punto * [*ce_3];
	for (int i = 0; i < *ce_3; i++)
		aux[i] = poderes[i];
	poderes = new Punto * [*ce_3 + 1];
	for (int i = 0; i < *ce_3; i++)
		poderes[i] = aux[i];
	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	poderes[*ce_3] = new Hielo(x, y, bmp_hielo);
	*ce_3 = *ce_3 + 1;
}
void Movimiento::Insertar_Rapidez(Graphics^ g, Bitmap^ bmp_rapidez, int j) {
	Punto** aux = new Punto * [*ce_3];
	for (int i = 0; i < *ce_3; i++)
		aux[i] = poderes[i];
	poderes = new Punto * [*ce_3 + 1];
	for (int i = 0; i < *ce_3; i++)
		poderes[i] = aux[i];
	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	poderes[*ce_3] = new Rapidez(x, y, bmp_rapidez);
	*ce_3 = *ce_3 + 1;
}
void Movimiento::Insertar_Corrupt(Graphics^ g, Bitmap^ bmp_corrupt, int j) { //Inserta enemigos tipo corrupt
	Punto** aux = new Punto * [*ce];
	for (int i=0; i < *ce; i++)
		aux[i] = enemigos[i];
	enemigos = new Punto * [*ce + 1];
	for (int i=0; i < *ce; i++)
		enemigos[i] = aux[i];
	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	enemigos[*ce] = new NPC(x, y, bmp_corrupt);
	int direccion;
	direccion = rand() % 4 + 1;
	switch (direccion) {
	case 1: enemigos[*ce]->cambiar_ult_movimiento(arriba); break;
	case 2: enemigos[*ce]->cambiar_ult_movimiento(abajo); break;
	case 3: enemigos[*ce]->cambiar_ult_movimiento(izquierda); break;
	case 4: enemigos[*ce]->cambiar_ult_movimiento(derecha);
	}
	*ce = *ce + 1;
}
void Movimiento::Insertar_Assasin(Graphics^ g, Bitmap^ bmp_assasin, int j) { //Inserta enemigos tipo assasin
	Punto** aux = new Punto * [*ce];
	for (int i = 0; i < *ce; i++)
		aux[i] = enemigos[i];
	enemigos = new Punto * [*ce + 1];
	for (int i = 0; i < *ce; i++)
		enemigos[i] = aux[i];
	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	enemigos[*ce] = new AssasinNPC(x, y, bmp_assasin);
	int direccion;
	direccion = rand() % 4 + 1;
	switch (direccion) {
	case 1: enemigos[*ce]->cambiar_ult_movimiento(arriba); break;
	case 2: enemigos[*ce]->cambiar_ult_movimiento(abajo); break;
	case 3: enemigos[*ce]->cambiar_ult_movimiento(izquierda); break;
	case 4: enemigos[*ce]->cambiar_ult_movimiento(derecha);
	}
	*ce = *ce + 1;
}
void Movimiento::Insertar_Aliado(Graphics^ g, Bitmap^ bmp_aliado, int j, int animal) { //Inserta aliados
	Aliado** aux = new Aliado * [*ce_2];
	for (int i=0; i < *ce_2; i++)
		aux[i] = aliados[i];
	aliados = new Aliado * [*ce_2 + 1];
	for (int i=0; i < *ce_2; i++)
		aliados[i] = aux[i];
	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	aliados[*ce_2] = new Aliado(x, y, animal, bmp_aliado);
	int direccion;
	direccion = rand() % 4 + 1;
	switch (direccion) {
	case 1: aliados[*ce_2]->cambiar_ult_movimiento(arriba); break;
	case 2: aliados[*ce_2]->cambiar_ult_movimiento(abajo); break;
	case 3: aliados[*ce_2]->cambiar_ult_movimiento(izquierda); break;
	case 4: aliados[*ce_2]->cambiar_ult_movimiento(derecha);
	}
	*ce_2 = *ce_2 + 1;
}
void Movimiento::Init(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa, Bitmap^ bmp_corrupt, Bitmap^ bmp_pajaro, Bitmap^ bmp_conejo , Bitmap^ bmp_hielo, Bitmap^ bmp_rapidez, Bitmap^ bmp_portal1, Bitmap^ bmp_portal2)
{
	int aux_x = 0;
	int aux_y = 0;
	
	
	 
	mapa = new Mapa * [850];
	for (int i = 0; i < 850; i++) {
		int x = aux_x;
		int y = aux_y;
		mapa[i] = new Mapa(x, y, bmp_mapa);
		if ((i + 1) % 34 == 0) {
			aux_x = 0;
			aux_y = aux_y + mapa[i]->retornar_Alto();
		}
		else
			aux_x = aux_x + mapa[i]->retornar_Ancho();
	}
	
	obj_monigote = new Monigote(mapa[784]->retornar_X(), mapa[784]->retornar_Y(), bmp_monigote);
	obj_monigote->cambiar_ult_movimiento(direccion::derecha);
	Insertar_Corrupt(g, bmp_corrupt, 307);
	Insertar_Corrupt(g, bmp_corrupt, 28);
	
	Insertar_Aliado(g, bmp_pajaro, 5, 1);
	Insertar_Aliado(g, bmp_pajaro, 315, 1);
	Insertar_Aliado(g, bmp_conejo, 42, 2);
	Insertar_Aliado(g, bmp_conejo, 43, 2);

	Insertar_Hielo(g, bmp_hielo,10);
	Insertar_Portal(g, bmp_portal1, bmp_portal2, 2, 56);
	Insertar_Rapidez(g, bmp_rapidez, 33);

	num_vidas = 3;
	puntaje = 0;
	num_aliados = *ce_2;
	num_poderes = *ce_3;
	num_salvados = 0;
	x_poder = y_poder = 0;
}
void Movimiento::Run(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa, Bitmap^ bmp_corrupt, Bitmap^ bmp_pajaro, Bitmap^ bmp_conejo, Bitmap^ bmp_assasin,Bitmap^ bmp_hielo, Bitmap^ bmp_rapidez, Bitmap^ bmp_portal1, Bitmap^ bmp_portal2)
{
	Dibujar_Mapa(g, bmp_mapa);
	Font^ f = gcnew Font("Arial", 10);
	SolidBrush^ b = gcnew SolidBrush(Color::White);

	g->DrawString("Nro Vidas : " + num_vidas.ToString(), f, b, 1, 1);
	g->DrawString("Puntaje : " + puntaje.ToString(), f, b, 1, 15);
	g->DrawString("Aliados restantes : " + num_aliados.ToString(), f, b, 1, 25);
	g->DrawString("Aliados salvados : " + num_salvados.ToString(), f, b, 1, 35);
	g->DrawString("Poderes : " + num_poderes.ToString(), f, b, 1, 45);
	g->DrawString("X : " + x_poder.ToString(), f, b, 1, 55);
	g->DrawString("Y : " + y_poder.ToString(), f, b, 1, 65);
	int x = 0;
	int y = 0;
	for (int i = 0; i < *ce_2; i++) {
		if (aliados[i]->retornar_primer_salvado()) {
			x = aliados[i]->retornar_X();
			y = aliados[i]->retornar_Y();
		}
	}

	Mover_Monigote(g, obj_monigote->retornar_X(), obj_monigote->retornar_Y(), x, y);
	for (int i = 0; i < 850; i++)
	{

		if (Colision_Mapa(obj_monigote, mapa[i]) && (mapa[i]->retornar_limite()))
		{
			obj_monigote->cambiar_X(obj_monigote->retornar_X() - obj_monigote->retornar_DX());
			obj_monigote->cambiar_Y(obj_monigote->retornar_Y() - obj_monigote->retornar_DY());
			obj_monigote->cambiar_ult_movimiento(ninguno);
		}
		for (int j = 0; j < *ce; j++) {
			if (Colision_Mapa(enemigos[j], mapa[i]) && (mapa[i]->retornar_limite())) //Colision con bordes para NPCs. Automaticamente cambia a una direccion aleatoria
			{
				int direccion;
				enemigos[j]->cambiar_X(enemigos[j]->retornar_X() - enemigos[j]->retornar_DX());
				enemigos[j]->cambiar_Y(enemigos[j]->retornar_Y() - enemigos[j]->retornar_DY());
				direccion = rand() % 4 + 1;
				switch (direccion) {
				case 1: enemigos[j]->cambiar_ult_movimiento(arriba); break;
				case 2: enemigos[j]->cambiar_ult_movimiento(abajo); break;
				case 3: enemigos[j]->cambiar_ult_movimiento(izquierda); break;
				case 4: enemigos[j]->cambiar_ult_movimiento(derecha);
				}

			}
		}
		for (int j = 0; j < *ce_2; j++) {
			if (Colision_Mapa(aliados[j], mapa[i]) && (!aliados[j]->retornar_seguimiento())&& (mapa[i]->retornar_limite())) //Colision con bordes para NPCs. Automaticamente cambia a una direccion aleatoria
			{
				int direccion;
				aliados[j]->cambiar_X(aliados[j]->retornar_X() - aliados[j]->retornar_DX());
				aliados[j]->cambiar_Y(aliados[j]->retornar_Y() - aliados[j]->retornar_DY());
				direccion = rand() % 4 + 1;
				switch (direccion) {
				case 1: aliados[j]->cambiar_ult_movimiento(arriba); break;
				case 2: aliados[j]->cambiar_ult_movimiento(abajo); break;
				case 3: aliados[j]->cambiar_ult_movimiento(izquierda); break;
				case 4: aliados[j]->cambiar_ult_movimiento(derecha);
				}

			}
		}
	}
	for (int j = 0; j < *ce; j++) {
		if (Colision_NPC(obj_monigote, enemigos[j])) //Colision del monigote con un enemigo
		{
			num_vidas = num_vidas - 1;
			enemigos[j]->cambiar_eliminar(true);
		}
		for (int i = 0; i < *ce_2; i++) { //Colision de un aliado con un enemigo
			if (Colision_NPC(aliados[i], enemigos[j]) && !aliados[i]->retornar_salvado())
			{
				enemigos[j]->cambiar_disfraz(true);
				enemigos[j]->cambiar_animal(aliados[i]->retornar_animal());
				if (enemigos[j]->retornar_animal() == 1) {
					enemigos[j]->cambiar_w(bmp_pajaro);
					enemigos[j]->cambiar_h(bmp_pajaro);
				}
				if (enemigos[j]->retornar_animal() == 2) {
					enemigos[j]->cambiar_w(bmp_conejo);
					enemigos[j]->cambiar_h(bmp_conejo);
				}
				aliados[i]->cambiar_eliminar(true);
			}
		}
	}
	for (int j = 0; j < *ce_2; j++) {
		if (Colision_NPC(obj_monigote, aliados[j])) //Colision del monigote con un aliado
		{
			if (!aliados[j]->retornar_salvado()) {
				num_salvados = num_salvados + 1;
				aliados[j]->cambiar_salvado(true);
				if (num_salvados <= 2) { //primer salvado
					if (num_salvados == 1) {
						aliados[j]->cambiar_seguimiento(true);
						aliados[j]->cambiar_primer_salvado(true);
						direccion dir = obj_monigote->retornar_dir();
						switch (dir) {
						case arriba: aliados[j]->cambiar_X(obj_monigote->retornar_X());
							aliados[j]->cambiar_Y(obj_monigote->retornar_Y() + aliados[j]->retornar_Alto()); break;
						case abajo: aliados[j]->cambiar_X(obj_monigote->retornar_X());
							aliados[j]->cambiar_Y(obj_monigote->retornar_Y() - aliados[j]->retornar_Alto()); break;
						case derecha: aliados[j]->cambiar_X(obj_monigote->retornar_X() - aliados[j]->retornar_Ancho());
							aliados[j]->cambiar_Y(obj_monigote->retornar_Y()); break;
						case izquierda: aliados[j]->cambiar_X(obj_monigote->retornar_X() + aliados[j]->retornar_Ancho());
							aliados[j]->cambiar_Y(obj_monigote->retornar_Y());
						}
					}
					if (num_salvados == 2) { //segundo salvado
						aliados[j]->cambiar_seguimiento(true);
						direccion dir;
						for (int i = 0; i < *ce_2; i++) {
							if (aliados[j]->retornar_seguimiento()) {
								dir = aliados[i]->retornar_dir();
								switch (dir) {
								case arriba: aliados[j]->cambiar_X(aliados[i]->retornar_X());
									aliados[j]->cambiar_Y(aliados[i]->retornar_Y() + aliados[j]->retornar_Alto()); break;
								case abajo: aliados[j]->cambiar_X(aliados[i]->retornar_X());
									aliados[j]->cambiar_Y(aliados[i]->retornar_Y() - aliados[j]->retornar_Alto()); break;
								case derecha: aliados[j]->cambiar_X(aliados[i]->retornar_X() - aliados[j]->retornar_Ancho());
									aliados[j]->cambiar_Y(aliados[i]->retornar_Y()); break;
								case izquierda: aliados[j]->cambiar_X(aliados[i]->retornar_X() + aliados[j]->retornar_Ancho());
									aliados[j]->cambiar_Y(aliados[i]->retornar_Y());
								}
								break;
							}
						}
					}
				}
			}
		}
	}
	Borrar_enemigos();
	Borrar_aliados();
	if (*ce == 0) {
		Insertar_Assasin(g, bmp_assasin, 15);
		Insertar_Assasin(g, bmp_assasin, 28);
	}
 
	Dibujar_Monigote(g, bmp_monigote, bmp_corrupt, bmp_pajaro, bmp_conejo, bmp_assasin,bmp_hielo,bmp_portal1,bmp_portal2,bmp_rapidez);
	num_aliados = *ce_2;
	num_poderes = *ce_3;
	x_poder = poderes[0]->retornar_X();
	y_poder = poderes[0]->retornar_Y();
	//Si hay colision aqui modificar
	
	
}
void Movimiento::Mover_Monigote(Graphics^ g, int x_prota, int y_prota, int x_salvado, int y_salvado)
{
	obj_monigote->Movimiento(g);
	for (int i = 0; i < *ce; i++)
		enemigos[i]->Movimiento(g);
	for (int i = 0; i < *ce_2; i++) {
		if (aliados[i]->retornar_seguimiento())
			aliados[i]->Movimiento_seguimiento(g, x_prota, y_prota, x_salvado, y_salvado);
		else
			aliados[i]->Movimiento(g);
	}
}
void Movimiento::Cambiar_Direccion_Monigote(direccion dir) {
	obj_monigote->cambiar_ult_movimiento(dir);
}
void Movimiento::Dibujar_Monigote(Graphics^ g, Bitmap^ bmp_monigote, Bitmap^ bmp_corrupt, Bitmap^ bmp_pajaro, Bitmap^ bmp_conejo, Bitmap^ bmp_assasin, Bitmap^ bmp_hielo, Bitmap^ bmp_rapidez, Bitmap^ bmp_portal1, Bitmap^ bmp_portal2)
{
	obj_monigote->Dibujar(g, bmp_monigote);
	for (int i = 0; i < *ce; i++) {
		if (enemigos[i]->retornar_disfraz()) {
			if (enemigos[i]->retornar_animal() == 1)
				enemigos[i]->Dibujar(g, bmp_pajaro);
			if (enemigos[i]->retornar_animal() == 2)
				enemigos[i]->Dibujar(g, bmp_conejo);
		}
		else {
			if (dynamic_cast<NPC*>(enemigos[i]))
				enemigos[i]->Dibujar(g, bmp_corrupt);
			else
				enemigos[i]->Dibujar(g, bmp_assasin);
		}
	}
	for (int i = 0; i < *ce_2; i++) {
		if ((!aliados[i]->retornar_salvado()) || (aliados[i]->retornar_salvado() && aliados[i]->retornar_seguimiento())) {
			if (aliados[i]->retornar_animal() == 1)
				aliados[i]->Dibujar(g, bmp_pajaro);
			else
				aliados[i]->Dibujar(g, bmp_conejo);
		}
	}


 
}
Movimiento::~Movimiento() {
	if (*ce > 0 && *ce_2 > 0 && *ce_3 > 0) {
		for (int i = 0; i < *ce; i++)
			delete enemigos[i];
		delete[]enemigos;
		for (int i = 0; i < *ce_2; i++)
			delete aliados[i];
		for (int i = 0; i < *ce_3; i++)
			delete poderes[i];
		delete[]poderes;

		delete[]aliados;
		delete ce;
		delete ce_2;
		delete ce_3;
	}
}
void Movimiento::Dibujar_Mapa(Graphics^ g, Bitmap^ bmp_mapa) {
	//1
	mapa[0]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[1]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[2]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[3]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[4]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[5]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[6]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[7]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[8]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[9]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[10]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[11]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[12]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[13]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[14]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[15]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[16]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[17]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[18]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[19]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[20]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[21]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[22]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[23]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[24]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[25]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[26]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[27]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[28]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[29]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[30]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[31]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[32]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[33]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//2
	mapa[34]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[35]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[36]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[37]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[38]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[39]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[40]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[41]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[42]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[43]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[44]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[45]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[46]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[47]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[48]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[49]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);//
	mapa[50]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[51]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[52]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[53]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[54]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[55]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[56]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[57]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[58]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[59]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[60]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[61]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[62]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[63]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[64]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[65]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[66]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[67]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//3
	mapa[68]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[69]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[70]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[71]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[72]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[73]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[74]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[75]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[76]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[77]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[78]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[79]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[80]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[81]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[82]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[83]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);//
	mapa[84]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[85]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[86]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[87]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[88]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[89]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[90]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[91]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[92]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[93]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[94]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[95]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[96]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[97]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[98]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[99]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[100]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[101]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//4
	mapa[102]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[103]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[104]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[105]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[106]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[107]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[108]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[109]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[110]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[111]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[112]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[113]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[114]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[115]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[116]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[117]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);//
	mapa[118]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[119]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[120]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[121]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[122]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[123]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[124]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[125]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[126]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[127]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[128]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[129]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[130]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[131]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[132]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[133]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[134]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[135]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//5
	mapa[136]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[137]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[138]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[139]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[140]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[141]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[142]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[143]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[144]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[145]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[146]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[147]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[148]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[149]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[150]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[151]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[152]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[153]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[154]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[155]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[156]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[157]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[158]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[159]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[160]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[161]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[162]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[163]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[164]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[165]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[166]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[167]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[168]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[169]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//6
	mapa[170]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[171]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[172]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[173]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[174]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[175]->Dibujar_Imagen(g, bmp_mapa, 0, 2,false);
	mapa[176]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[177]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[178]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[179]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[180]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[181]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[182]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[183]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[184]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[185]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[186]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[187]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[188]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[189]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[190]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[191]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[192]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[193]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[194]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[195]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[196]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[197]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[198]->Dibujar_Imagen(g, bmp_mapa, 0, 5, true);
	mapa[199]->Dibujar_Imagen(g, bmp_mapa, 0, 6, false);
	mapa[200]->Dibujar_Imagen(g, bmp_mapa, 0, 5, true);
	mapa[201]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[202]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[203]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//7
	mapa[204]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[205]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[206]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[207]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[208]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[209]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[210]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[211]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[212]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[213]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[214]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[215]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[216]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[217]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[218]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[219]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[220]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[221]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[222]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[223]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[224]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[225]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[226]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[227]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[228]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[229]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[230]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[231]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[232]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[233]->Dibujar_Imagen(g, bmp_mapa, 5, 3, false);
	mapa[234]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[235]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[236]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[237]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//8
	mapa[238]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[239]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[240]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[241]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[242]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[243]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[244]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[245]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[246]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[247]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[248]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[249]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[250]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[251]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[252]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[253]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[254]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[255]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[256]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[257]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[258]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[259]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[260]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[261]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[262]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[263]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[264]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[265]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[266]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[267]->Dibujar_Imagen(g, bmp_mapa, 5, 3, false);
	mapa[268]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[269]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[270]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[271]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//9
	mapa[272]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[273]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[274]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[275]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[276]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[277]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[278]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[279]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[280]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[281]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[282]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[283]->Dibujar_Imagen(g, bmp_mapa, 0, 2,false);
	mapa[284]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[285]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[286]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[287]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);//
	mapa[288]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[289]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[290]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[291]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[292]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[293]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[294]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[295]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[296]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[297]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[298]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[299]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[300]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[301]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[302]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[303]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[304]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[305]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//10
	mapa[306]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[307]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[308]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[309]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[310]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[311]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[312]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[313]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[314]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[315]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[316]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[317]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[318]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[319]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[320]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[321]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[322]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[323]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[324]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[325]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[326]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[327]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[328]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[329]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[330]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[331]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[332]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[333]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[334]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[335]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[336]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[337]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[338]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[339]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//11
	mapa[340]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[341]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[342]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[343]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[344]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[345]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[346]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[347]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[348]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[349]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[350]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[351]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[352]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[353]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[354]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[355]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[356]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[357]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[358]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[359]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[360]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[361]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[362]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[363]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[364]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[365]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[366]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[367]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[368]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[369]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[370]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[371]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[372]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[373]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//12
	mapa[374]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[375]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[376]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[377]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[378]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[379]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[380]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[381]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[382]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[383]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[384]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[385]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[386]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[387]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[388]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[389]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[390]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[391]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[392]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[393]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[394]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[395]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[396]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[397]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[398]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[399]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[400]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[401]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[402]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[403]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[404]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[405]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[406]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[407]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//13
	mapa[408]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[409]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[410]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[411]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[412]->Dibujar_Imagen(g, bmp_mapa, 0, 2,false);
	mapa[413]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[414]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[415]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[416]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[417]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[418]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[419]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[420]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[421]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[422]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[423]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[424]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[425]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[426]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[427]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[428]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[429]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[430]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[431]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[432]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[433]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[434]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[435]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[436]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[437]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[438]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[439]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[440]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[441]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//14
	mapa[442]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[443]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[444]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[445]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[446]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[447]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[448]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[449]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[450]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[451]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[452]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[453]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[454]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[455]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[456]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[457]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[458]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[459]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[460]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[461]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[462]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[463]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[464]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[465]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[466]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[467]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[468]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[469]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[470]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[471]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[472]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[473]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[474]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[475]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//15
	mapa[476]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[477]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[478]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[479]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[480]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[481]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[482]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[483]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[484]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[485]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[486]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[487]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[488]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[489]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[490]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[491]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);//
	mapa[492]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[493]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[494]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[495]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[496]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[497]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[498]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[499]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[500]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[501]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[502]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[503]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[504]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[505]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[506]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[507]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[508]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[509]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//16
	mapa[510]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[511]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[512]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[513]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[514]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[515]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[516]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[517]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[518]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[519]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[520]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[521]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[522]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[523]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[524]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[525]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[526]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[527]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[528]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[529]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[530]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[531]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[532]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[533]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[534]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[535]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[536]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[537]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[538]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[539]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[540]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[541]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[542]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[543]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//17
	mapa[544]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[545]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[546]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[547]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[548]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[549]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[550]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[551]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[552]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[553]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[554]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[555]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[556]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[557]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[558]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[559]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);//
	mapa[560]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[561]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[562]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[563]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[564]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[565]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[566]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[567]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[568]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[569]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[570]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[571]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[572]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[573]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[574]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[575]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[576]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[577]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//18
	mapa[578]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[579]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[580]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[581]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[582]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[583]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[584]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[585]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[586]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[587]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[588]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[589]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[590]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[591]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[592]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[593]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[594]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[595]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[596]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[597]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[598]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[599]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[600]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[601]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[602]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[603]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[604]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[605]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[606]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[607]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[608]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[609]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[610]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[611]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//19
	mapa[612]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[613]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[614]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[615]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[616]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[617]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[618]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[619]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[620]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[621]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[622]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[623]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[624]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[625]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);/////
	mapa[626]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[627]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[628]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[629]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[630]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[631]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[632]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[633]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[634]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[635]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[636]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[637]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[638]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[639]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[640]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[641]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[642]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[643]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[644]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[645]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//20
	mapa[646]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[647]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[648]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[649]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[650]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[651]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[652]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[653]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[654]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[655]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[656]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[657]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[658]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[659]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);/////
	mapa[660]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[661]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);//
	mapa[662]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[663]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[664]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[665]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[666]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[667]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[668]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[669]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[670]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[671]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[672]->Dibujar_Imagen(g, bmp_mapa, 0, 2,false);
	mapa[673]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[674]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[675]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[676]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[677]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[678]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[679]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//21
	mapa[680]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[681]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[682]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[683]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[684]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[685]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[686]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[687]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[688]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[689]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[690]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[691]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[692]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[693]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);/////
	mapa[694]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[695]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);//
	mapa[696]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[697]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[698]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[699]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[700]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[701]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[702]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[703]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[704]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[705]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[706]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[707]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[708]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[709]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[710]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[711]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[712]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[713]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//22
	mapa[714]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[715]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[716]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[717]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[718]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[719]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[720]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[721]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[722]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[723]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[724]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[725]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[726]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[727]->Dibujar_Imagen(g, bmp_mapa, 1, 10, false);/////
	mapa[728]->Dibujar_Imagen(g, bmp_mapa, 1, 10, false);
	mapa[729]->Dibujar_Imagen(g, bmp_mapa, 1, 10, false);//
	mapa[730]->Dibujar_Imagen(g, bmp_mapa, 1, 10, false);
	mapa[731]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[732]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[733]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[734]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[735]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[736]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[737]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[738]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[739]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[740]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[741]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[742]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[743]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[744]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[745]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[746]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[747]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//23
	mapa[748]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[749]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[750]->Dibujar_Imagen(g, bmp_mapa, 1, 11, false);
	mapa[751]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[752]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[753]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[754]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[755]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[756]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[757]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[758]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[759]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[760]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[761]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);/////
	mapa[762]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[763]->Dibujar_Imagen(g, bmp_mapa, 5, 8, false);//
	mapa[764]->Dibujar_Imagen(g, bmp_mapa, 5, 8, true);
	mapa[765]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[766]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[767]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[768]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[769]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[770]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[771]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[772]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[773]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[774]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[775]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[776]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[777]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[778]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[779]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[780]->Dibujar_Imagen(g, bmp_mapa, 0, 2, false);
	mapa[781]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//24
	mapa[782]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[783]->Dibujar_Imagen(g, bmp_mapa, 1, 11, false);
	mapa[784]->Dibujar_Imagen(g, bmp_mapa, 1, 11, false);
	mapa[785]->Dibujar_Imagen(g, bmp_mapa, 1, 11, false);
	mapa[786]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[787]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[788]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[789]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[790]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[791]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[792]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[793]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[794]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[795]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);/////
	mapa[796]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[797]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[798]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[799]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[800]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[801]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[802]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[803]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[804]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[805]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[806]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[807]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[808]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[809]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[810]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[811]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[812]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[813]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[814]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[815]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	//25
	mapa[816]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[817]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[818]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[819]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[820]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[821]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[822]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[823]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[824]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[825]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[826]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[827]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[828]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[829]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);/////
	mapa[830]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[831]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);//
	mapa[832]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[833]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[834]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[835]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[836]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[837]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[838]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[839]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[840]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[841]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[842]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[843]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[844]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[845]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[846]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[847]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[848]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);
	mapa[849]->Dibujar_Imagen(g, bmp_mapa, 0, 4, true);

}

bool Movimiento::Colision_Mapa(Punto* obj1, Punto* obj2) {
	Rectangle rect1 = Rectangle(obj1->retornar_X(),
		obj1->retornar_Y(),
		obj1->retornar_Ancho(),
		obj1->retornar_Alto());
	Rectangle rect2 = Rectangle(obj2->retornar_X(),
		obj2->retornar_Y(),
		obj2->retornar_Ancho()/1.5,
		obj2->retornar_Alto()/2);
	return rect1.IntersectsWith(rect2);
}
bool Movimiento::Colision_NPC(Punto* obj1, Punto* obj2) {
	Rectangle rect1 = Rectangle(obj1->retornar_X(),
		obj1->retornar_Y(),
		obj1->retornar_Ancho(),
		obj1->retornar_Alto());
	Rectangle rect2 = Rectangle(obj2->retornar_X(),
		obj2->retornar_Y(),
		obj2->retornar_Ancho(),
		obj2->retornar_Alto());
	return rect1.IntersectsWith(rect2);
}
void Movimiento::Borrar_enemigos() {
	int contador = 0;
	for (int i = 0; i < *ce; i++)
		contador += enemigos[i]->retornar_eliminar() ? 1 : 0; //if (arreglo[i]-> retornar_eliminar()) contador=contador +1; else contador=contador+0;
	Punto** auxiliar = new Punto * [*ce - contador];
	int j = 0;
	for (int i = 0; i < *ce; i++) {
		if (!enemigos[i]->retornar_eliminar()) {
			auxiliar[j] = enemigos[i];//Guardar en el arreglo
			j++;
		}
	}
	enemigos = auxiliar;
	*ce = *ce - contador;
}
void Movimiento::Borrar_aliados() {
	int contador = 0;
	for (int i = 0; i < *ce_2; i++)
		contador += aliados[i]->retornar_eliminar() ? 1 : 0; //if (arreglo[i]-> retornar_eliminar()) contador=contador +1; else contador=contador+0;
	Aliado** auxiliar = new Aliado * [*ce_2 - contador];
	int j = 0;
	for (int i = 0; i < *ce_2; i++) {
		if (!aliados[i]->retornar_eliminar()) {
			auxiliar[j] = aliados[i];//Guardar en el arreglo
			j++;
		}
	}
	aliados = auxiliar;
	*ce_2 = *ce_2 - contador;
}
//System::DateTime::Now.Ticks : srand para Random() -> Random(System::DateTime::Now.Ticks)
