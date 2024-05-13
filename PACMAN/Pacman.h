#pragma once
#include "Entidad.h"

class Pacman : public Entidad
{
private:
	int vidas;
	bool Chocobonus;
public:
	Pacman(int x, int y, int col, int row, int maxCol, int maxRow, int vidas) : Entidad(x, y, col, row, maxCol, maxRow)
	{
		Chocobonus = false;
		this->vidas = vidas;
		
	};
	~Pacman() {}

	void mostrar(Graphics^ g, Bitmap^ bmpnormal) {
		ancho = bmpnormal->Width / maxCol;
		alto = bmpnormal->Height / maxfila;
		Rectangle porcion = Rectangle(col * ancho, fila * alto, ancho, alto);

		g->DrawImage(bmpnormal,x,y, porcion, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, x, y, 30, 30);
		//g->DrawRectangle(Pens::White, Areapequenia());

		col++;
		if (col == maxCol) col = 10;
	}

	//, Rectangle rec2, Rectangle rec3, Rectangle rec4, Rectangle rec5, 
	//Rectangle rec6, Rectangle rec7, Rectangle rec8, Rectangle rec9, Rectangle rec10, Rectangle rec11, Rectangle rec12, Rectangle rec13, Rectangle rec14, Rectangle, rec15
	bool ColisionEscenario(Rectangle rec1, Rectangle rec2, Rectangle rec3, Rectangle rec4, Rectangle rec5, Rectangle rec6, Rectangle rec7, Rectangle rec8, Rectangle rec9, Rectangle rec10, Rectangle rec11, Rectangle rec12, Rectangle rec13, Rectangle rec14, Rectangle rec15,
		Rectangle rec16, Rectangle rec17, Rectangle rec18, Rectangle rec19, Rectangle rec20, Rectangle rec21, Rectangle rec22, Rectangle rec23) {
		if (getNextArea().IntersectsWith(rec1) || getNextArea().IntersectsWith(rec2) || getNextArea().IntersectsWith(rec3) || getNextArea().IntersectsWith(rec4) || 
			getNextArea().IntersectsWith(rec5) || getNextArea().IntersectsWith(rec6) || getNextArea().IntersectsWith(rec7) || getNextArea().IntersectsWith(rec8) || 
			getNextArea().IntersectsWith(rec9) || getNextArea().IntersectsWith(rec10) || getNextArea().IntersectsWith(rec11) || getNextArea().IntersectsWith(rec12) ||
			getNextArea().IntersectsWith(rec13) || getNextArea().IntersectsWith(rec14) || getNextArea().IntersectsWith(rec15) || getNextArea().IntersectsWith(rec16) || 
			getNextArea().IntersectsWith(rec17) || getNextArea().IntersectsWith(rec18) || getNextArea().IntersectsWith(rec19) || getNextArea().IntersectsWith(rec20) || 
			getNextArea().IntersectsWith(rec21) || getNextArea().IntersectsWith(rec22) || getNextArea().IntersectsWith(rec23)) // || getNext ---- rec2 .... getNext ---- rec3
		{
			dx = 0;
			dy = 0;
			return true;
		}
		return false;

	}
	void mover(Graphics^ g, Rectangle rec1, Rectangle rec2, Rectangle rec3, Rectangle rec4, Rectangle rec5, Rectangle rec6, Rectangle rec7, Rectangle rec8, Rectangle rec9, Rectangle rec10, Rectangle rec11, Rectangle rec12, Rectangle rec13, Rectangle rec14, Rectangle rec15,
		Rectangle rec16, Rectangle rec17, Rectangle rec18, Rectangle rec19, Rectangle rec20, Rectangle rec21, Rectangle rec22, Rectangle rec23) {
		ColisionEscenario(rec1,rec2,rec3,rec4,rec5,rec6, rec7, rec8, rec9, rec10, rec11, rec12, rec13, rec14, rec15, rec16, rec17, rec18, rec19, rec20,rec21,rec22,rec23);
		if (x + dx >= 33 && x + ancho + dx <= g->VisibleClipBounds.Width-35) x += dx;
		if (y + dy >= 95 && y + alto + dy <= g->VisibleClipBounds.Height-30) y += dy;
	}
	
	void setVidas(int vidas) {
		this->vidas += vidas;
	}

	int getVidas() {
		return vidas;
	}
	
	void desplazamiento(direccion d) {
		dx = 0;
		dy = 0;
		orientacion = d;

		switch (d)
		{
		case direccion::up:
			if (Chocobonus == true)
			{
				dy = -20;
			}
			else
			{
				dy = -10;
			}
			
			fila = 3;
			break;
		case direccion::down:
			if (Chocobonus == true)
			{
				dy = 20;
			}
			else
			{
				dy = 10;
			}
			fila = 1;
			break;
		case direccion::left:
			if (Chocobonus == true)
			{
				dx = -20;
			}
			else
			{
				dx = -10;
			}
			fila = 2;
			break;
		case direccion::right:
			if (Chocobonus == true)
			{
				dx = 20;
			}
			else
			{
				dx = 10;
			}
			fila = 0;
			break;
		case direccion::none:
			dx = 0;
			dy = 0;
			break;
		default:
			break;
		}
	}

	void setChocoBonus(bool value) {
		this->Chocobonus = value;
	}

	bool getChocoBonus() {
		return Chocobonus;
	}

	Rectangle Areapequenia() {
		return Rectangle(x + 10, y + 5, ancho / 2, alto / 2);
	}
};	