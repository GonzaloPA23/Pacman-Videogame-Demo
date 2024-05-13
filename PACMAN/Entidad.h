#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;

public enum direccion { up, down, left, right, none };

class Entidad
{
protected:
	int x, y, dx, dy, ancho, alto;
	int fila, col, maxfila, maxCol;
	direccion orientacion;
	bool activo;

public:
	Entidad() {
		x = 0;
		y = 0;
		dx = 0;
		dy = 0;
		activo = true;
		orientacion = direccion::none;
	
	}
	Entidad(int x, int y, int col, int fila, int maxCol, int maxfila) {
		this->x = x;
		this->y = y;
		this->col = col;
		this->fila = fila;
		this->maxCol = maxCol;
		this->maxfila = maxfila;

		dx = 0;
		dy = 0;
		activo = true;
		orientacion = direccion::none;
	}

	Entidad(int x, int y, int col, int fila, int maxCol, int maxfila, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->col = col;
		this->fila = fila;
		this->maxCol = maxCol;
		this->maxfila = maxfila;
		this->dx = dx;
		this->dy = dy;

		activo = true;
		orientacion = direccion::none;
	}

	Entidad(int col, int fila, int maxCol, int maxfila) {
		this->col = col;
		this->fila = fila;
		this->maxCol = maxCol;
		this->maxfila = maxfila;

		dx = 0;
		dy = 0;
		activo = true;
		orientacion = direccion::none;

	}
	~Entidad() {}

	virtual void mostrar(Graphics^ g, Bitmap^ bmp) {
		/*ancho = bmp->Width / maxCol;
		alto = bmp->Height / maxfila;
		Rectangle porcion = Rectangle(col * ancho, fila * alto, ancho, alto);
		Rectangle aumentoMapa = Rectangle(x, y, ancho * 0.8, alto * 0.8);
		g->DrawImage(bmp, aumentoMapa, porcion, GraphicsUnit::Pixel);

		col++;
		if (col == maxCol) col = 0;*/
	}
	virtual void mover(Graphics^ g) {

		if (x + dx < 0 || x + ancho + dx > g->VisibleClipBounds.Width) dx = 0;
		if (y + dy < 0 || y + alto + dy > g->VisibleClipBounds.Height) dy = 0;

		x += dx;
		y += dy;

	}

	virtual void desplazamiento(direccion d) {
		dx = 0;
		dy = 0;
		orientacion = d;

		switch (d)
		{
		case direccion::up:
			dy = -10;
			fila = 3;
			break;
		case direccion::down:
			dy = 10;
			fila = 1;
			break;
		case direccion::left:
			dx = -10;
			fila = 2;
			break;
		case direccion::right:
			dx = 10;
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

	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setDX(int dx) {
		this->dx = dx;
	}
	void setDY(int dy) {
		this->dy = dy;
	}

	void setW(int ancho) {
		this->ancho = ancho;
	}
	void setH(int alto) {
		this->alto = alto;
	}
	void setfila(int r) {
		this->fila = r;
	}
	void setCol(int c) {
		this->col = c;
	}
	void setMaxfila(int r) {
		this->maxfila = r;
	}
	void setMaxCol(int c) {
		this->maxCol = c;
	}
	void setActive(bool value) {
		this->activo = value;
	}
	void setOrientacion(direccion d) {
		this->orientacion = d;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getDx() {
		return dx;
	}
	int getDy() {
		return dy;
	}
	int getW() {
		return ancho;
	}
	int getH() {
		return alto;
	}
	int getfila() {
		return fila;
	}
	int getCol() {
		return col;
	}
	int getMaxfila() {
		return maxfila;
	}
	int getMaxCol() {
		return maxCol;
	}
	int getActive() {
		return activo;
	}

	direccion getOrientacion() {
		return orientacion;
	}
	Rectangle getArea() {
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle getNextArea() {
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

};

