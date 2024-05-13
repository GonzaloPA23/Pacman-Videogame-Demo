#pragma once
#include "Entidad.h"

class Escenario : public Entidad {

public:
	Escenario():Entidad() {}
	~Escenario(){}

	void mostrar(Graphics^ g, Bitmap^ bmpEscenario) {
		ancho = bmpEscenario->Width;
		alto = bmpEscenario->Height;

		Rectangle porcion = Rectangle(0, 0, ancho, alto);
		Rectangle aumentoMapa = Rectangle(x, y, ancho * 1.8, alto * 1.6);
		g->DrawImage(bmpEscenario, aumentoMapa, porcion, GraphicsUnit::Pixel);
		//Medio - Arriba
		g->FillRectangle(Brushes::DarkBlue, 280, 135, 250 , 35);
		// Medio - Abajo
		g->FillRectangle(Brushes::DarkBlue, 280, 350, 250, 35);
		// Medio - Centro // Horizontales
		g->FillRectangle(Brushes::DarkBlue, 290, 220, 60,20);
		g->FillRectangle(Brushes::DarkBlue, 460, 220, 60, 20);
		g->FillRectangle(Brushes::DarkBlue, 290, 290, 230, 20);

		// Medio - Centro // Verticales
		g->FillRectangle(Brushes::DarkBlue, 290, 220, 20, 80);
		g->FillRectangle(Brushes::DarkBlue, 500, 220, 20, 80);

		// Hotizontales inicio

		g->FillRectangle(Brushes::DarkBlue, 80, 135, 80, 30);
		g->FillRectangle(Brushes::DarkBlue, 80, 350, 80, 30);

		// Verticales inicio 
		g->FillRectangle(Brushes::DarkBlue, 80, 165, 35, 70);
		g->FillRectangle(Brushes::DarkBlue, 80, 280, 35, 70);//g->DrawRectangle(Pens::DarkCyan, 80, 280, 35, 70);

		// Hotizontales final

		g->FillRectangle(Brushes::DarkBlue, 645, 135, 80, 30);
		g->FillRectangle(Brushes::DarkBlue, 645, 350, 80, 30);

		// Verticales final 
		g->FillRectangle(Brushes::DarkBlue, 690, 165, 35, 70);
		g->FillRectangle(Brushes::DarkBlue, 690, 280, 35, 70);

		// las 2 parecidos al  = inicial 
		g->FillRectangle(Brushes::DarkBlue, 170, 215, 70, 25);
		g->FillRectangle(Brushes::DarkBlue, 170, 280, 70, 25);

		// las 2 parecidos al = final 
		g->FillRectangle(Brushes::DarkBlue, 570, 215, 70, 25);
		g->FillRectangle(Brushes::DarkBlue, 570, 280, 70, 25);

		// Los 4 lineas verticales del mapa mismo
		g->FillRectangle(Brushes::DarkBlue, 215, 90, 20, 75);
		g->FillRectangle(Brushes::DarkBlue, 575, 90, 20, 75);

		g->FillRectangle(Brushes::DarkBlue, 215, 360, 20, 75);
		g->FillRectangle(Brushes::DarkBlue, 575, 360, 20, 75);
	}
	
	Rectangle rec1() {
		return Rectangle(280, 135, 250, 35);
	}
	Rectangle rec2() {
		return Rectangle(280, 350, 250, 35);
	}
	Rectangle rec3() {
		return Rectangle(290, 220, 80, 20);
	}
	Rectangle rec4() {
		return Rectangle(440, 220, 80, 20);
	}
	Rectangle rec5() {
		return Rectangle(290, 290, 230, 20);
	}
	Rectangle rec6() {
		return Rectangle(290, 220, 20, 80);
	}
	Rectangle rec7() {
		return Rectangle(500, 220, 20, 80);
	}
	Rectangle rec8() {
		return Rectangle(80, 135, 80, 30);
	}
	Rectangle rec9() {
		return Rectangle(80, 350, 80, 30);
	}
	Rectangle rec10() {
		return Rectangle(80, 165, 35, 70);
	}
	Rectangle rec11() {
		return Rectangle(80, 280, 35, 70);
	}
	Rectangle rec12() {
		return Rectangle(645, 135, 80, 30);
	}
	Rectangle rec13() {
		return Rectangle(645, 350, 80, 30);
	}
	Rectangle rec14() {
		return Rectangle(690, 165, 35, 70);
	}
	Rectangle rec15() {
		return Rectangle(690, 280, 35, 70);
	}
	Rectangle rec16() {
		return Rectangle(170, 215, 70, 25);
	}
	Rectangle rec17() {
		return Rectangle(170, 280, 70, 25);
	}
	Rectangle rec18() {
		return Rectangle(570, 215, 70, 25);
	}
	Rectangle rec19() {
		return Rectangle(570, 280, 70, 25);
	}
	Rectangle rec20() {
		return Rectangle(215, 90, 20, 75);
	}
	Rectangle rec21() {
		return Rectangle(575, 90, 20, 75);
	}
	Rectangle rec22() {
		return Rectangle(215, 360, 20, 75);
	}
	Rectangle rec23() {
		return Rectangle(575, 360, 20, 75);
	}
};