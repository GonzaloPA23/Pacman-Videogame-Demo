#pragma once
#include "Entidad.h"

class PacDot : public Entidad
{
public:
	PacDot(int x, int y){
		this->x = x;
		this->y = y;
		
	}
	~PacDot(){}

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		Rectangle porcion = Rectangle(0,0, ancho, alto);
		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, getArea());

	}
};

class Bonus : public Entidad
{
	int ancho2, alto2;

public:
	Bonus(int x, int y) {
		this->x = x;
		this->y = y;
		activo = true;
	}
	~Bonus() {}

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		ancho2 = bmp->Width / 4;
		alto2 = bmp->Height;

		Rectangle porcion = Rectangle(0, 0, ancho2, alto2);
		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::White, getAreaBonus());
		
	}

	Rectangle getAreaBonus() {
		return Rectangle(x, y, ancho2, alto2);
	}
};