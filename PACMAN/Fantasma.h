#pragma once
#include "Entidad.h"

class Fantasma : public Entidad
{
private:
	time_t t_direccion;

public:
	Fantasma(int x, int y, int col, int fila, int maxCol, int maxfila) :Entidad(x, y, col, fila, maxCol, maxfila)
	{
		t_direccion = time(0);
		dx = 0;
		dy = 0;
		this->fila = fila;
		switch (fila)
		{
		case 0:
			this->col = col;
			fila = 0;
			dx = 10;
			dy = 0;
			break;
		case 1:
			this->col = col;
			fila = 1;
			dx = 0;
			dy = 10;
			break;
		case 2:
			this->col = col;
			fila = 2;
			dx = -10;
			dy = 0;
			break;
		case 3:
			this->col = col;
			fila = 3;
			dx = 0;
			dy = -10;
			break;
		}
	}
	~Fantasma() {}

	void mostrar(Graphics^ g, Bitmap^ bmp) {
		ancho = bmp->Width / maxCol;
		alto = bmp->Height / maxfila;
		Rectangle porcion = Rectangle(col * ancho, fila * alto, ancho, alto);
		g->DrawImage(bmp, x,y, porcion, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, getArea());
		g->DrawString("*", gcnew Font("Algerian", 15, FontStyle::Bold), Brushes::White, 315, 235);
		col++;
		if (col % 2 == 0) col = col - 2;
		//g->DrawRectangle(Pens::White, getNextArea());
	}
	void Direccionalterno() {

		int n = rand() % 6;/*int aux = n;
		if (n == aux)
		{
			n += 1;
		}*/
		switch (n)
		{
		case 0:
			fila = 0;
			dx = 10;
			dy = 0;
			break;
		case 1:
			fila = 1;
			dx = 0;
			dy = 10;
			break;
		case 2:
			fila = 2;
			dx = -10;
			dy = 0;
			break;
		case 3: case 4: case 5:
			fila = 3;
			dx = 0;
			dy = -10;
			break;

		}
	}

	void CambioDireccion()
	{
		if (difftime(time(0),t_direccion) > 4)
		{		
			Direccionalterno();
			t_direccion = time(0);
		}
	}

	bool ColisionEscenario(Rectangle rec1, Rectangle rec2, Rectangle rec3, Rectangle rec4, Rectangle rec5, Rectangle rec6, Rectangle rec7, Rectangle rec8, Rectangle rec9, Rectangle rec10, Rectangle rec11, Rectangle rec12, Rectangle rec13, Rectangle rec14, Rectangle rec15,
		Rectangle rec16, Rectangle rec17, Rectangle rec18, Rectangle rec19, Rectangle rec20, Rectangle rec21, Rectangle rec22, Rectangle rec23) {
		if (getNextArea().IntersectsWith(rec1) || getNextArea().IntersectsWith(rec2) || getNextArea().IntersectsWith(rec3) || getNextArea().IntersectsWith(rec4) ||
			getNextArea().IntersectsWith(rec5) || getNextArea().IntersectsWith(rec6) || getNextArea().IntersectsWith(rec7) || getNextArea().IntersectsWith(rec8) ||
			getNextArea().IntersectsWith(rec9) || getNextArea().IntersectsWith(rec10) || getNextArea().IntersectsWith(rec11) || getNextArea().IntersectsWith(rec12) ||
			getNextArea().IntersectsWith(rec13) || getNextArea().IntersectsWith(rec14) || getNextArea().IntersectsWith(rec15) || getNextArea().IntersectsWith(rec16) ||
			getNextArea().IntersectsWith(rec17) || getNextArea().IntersectsWith(rec18) || getNextArea().IntersectsWith(rec19) || getNextArea().IntersectsWith(rec20) ||
			getNextArea().IntersectsWith(rec21) || getNextArea().IntersectsWith(rec22) || getNextArea().IntersectsWith(rec23)) // || getNext ---- rec2 .... getNext ---- rec3
		
		{

			
			if (dx > 0) {
				dy = 10; 
				dx = 0;
			}
			else if (dx < 0) {
				dy = -10;
				dx = 0;
			}  else if (dy > 0) {
				dx = -10; 
				dy = 0;
			}
			else if (dy < 0) {
				dx = 10; 
				dy = 0;
			}
			return true;
		}
		return false;

	}

	void mover(Graphics ^ g, Rectangle rec1, Rectangle rec2, Rectangle rec3, Rectangle rec4, Rectangle rec5, Rectangle rec6, Rectangle rec7, Rectangle rec8, Rectangle rec9, Rectangle rec10, Rectangle rec11, Rectangle rec12, Rectangle rec13, Rectangle rec14, Rectangle rec15,
		Rectangle rec16, Rectangle rec17, Rectangle rec18, Rectangle rec19, Rectangle rec20, Rectangle rec21, Rectangle rec22, Rectangle rec23) {

		CambioDireccion();
		ColisionEscenario(rec1, rec2, rec3, rec4, rec5, rec6, rec7, rec8, rec9, rec10, rec11, rec12, rec13, rec14, rec15, rec16, rec17, rec18, rec19, rec20,rec21, rec22, rec23);
		if (x + dx < 33)
		{
			fila = 0;
			dx = 10;
			dy = 0;
		}

		if (x + ancho + dx > g->VisibleClipBounds.Width - 35)
		{
			fila = 2;
			dx = -10;
			dy = 0;
		}

		if (y + dy < 95)
		{
			fila = 1;
			dy = 10;
			dx = 0;
		}
		if (y + alto + dy > g->VisibleClipBounds.Height - 30)
		{
			fila = 3;
			dy = -10;
			dx = 0;
		}

		x += dx;
		y += dy;
	}
};

