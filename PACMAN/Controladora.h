#pragma once
#include "Fantasma.h"
#include "Pacman.h"
#include "PacDot.h"
#include "Escenario.h"
#include <fstream>
#include <vector>
//#include <time.h>

class Controladora
{
	// Clases
	Pacman* pacman;
	Escenario* escenario;
	Bonus* bonus;
	// Vectores
	vector<Fantasma*> fantasmas;
	vector<PacDot*> pacdots;
	// Variables
	int columnafantasma;
	int columna;
	int fila;
	int xf;
	int yf;
	int puntos;
	// Time
	time_t spawBonus;
	time_t tiempoVeloc;

	ofstream output;

public:
	Controladora(int vidas, int cntFantasmas){
		xf = 70;
		yf = 130;
		columna = 0;
		fila = 0;
		puntos = 0;
		spawBonus = 0;
		tiempoVeloc = 0;
		output.open("output.txt", ios::out);
		pacman = new Pacman(40, 100, 10, 0, 12, 4, vidas);
		escenario = new Escenario();
		columnafantasma = 0;
		for (int i = 0; i < cntFantasmas; i++)
		{
			fantasmas.push_back(new Fantasma(rand()% 150 + 310 , 235, columnafantasma, 0, 12, 4)); // 310 a 460
			columnafantasma += 2;
		}
		// Horizontal arriba
		for (int i = 0; i < 6; i++)
		{
			pacdots.push_back(new PacDot( xf, 100));
			pacdots.push_back(new PacDot(xf, 400));
			xf += 20;

		}
		xf += 50;
		for (int i = 0; i < 16; i++)
		{
			pacdots.push_back(new PacDot(xf, 100));
			pacdots.push_back(new PacDot(xf, 400));
			xf += 20;
		}
		xf += 45; //+  // 
		//bonus = new Bonus(40 + rand() % xf + 20, 90 + rand() % yf + 20);
		
		
		for (int i = 0; i < 8; i++)
		{
			pacdots.push_back(new PacDot(xf, 100));
			pacdots.push_back(new PacDot(xf, 400));
			xf += 20;
		}
		// Vertical izquierda
		for (int i = 0; i < 14; i++)
		{
			pacdots.push_back(new PacDot(40, yf));
			yf += 20;
		}
		
		// Vertical derecha
		yf = 130;
		for (int i = 0; i < 13; i++)
		{
			pacdots.push_back(new PacDot(745, yf));
			yf += 20;
		}

		// Los 2 Horizontales del medio 

		xf = 130;
		for (int i = 0; i < 27; i++)
		{
			pacdots.push_back(new PacDot(xf, 180));
			pacdots.push_back(new PacDot(xf, 315));
			xf += 20;
		}

		// Horizontal del medio 
			// IZQUIERDA
		xf = 70;
		for (int i = 0; i < 10; i++)
		{
			pacdots.push_back(new PacDot(xf, 245));
			xf += 20;

		}
			// DERECHA
		xf = 530;
		for (int i = 0; i < 10; i++)
		{
			pacdots.push_back(new PacDot(xf, 245));
			xf += 20;

		}

		//  VERTICALES INICIALES RESTANTES
		yf = 120;
		for (int i = 0; i < 3; i++)
		{
			pacdots.push_back(new PacDot(170, yf));
			pacdots.push_back(new PacDot(240, yf));
			pacdots.push_back(new PacDot(540, yf));
			pacdots.push_back(new PacDot(605, yf));
			yf += 20;
		}

		// VERTICALES FINALES RESTANTES
		yf = 340;
		for (int i = 0; i < 3; i++)
		{
			pacdots.push_back(new PacDot(170, yf));
			pacdots.push_back(new PacDot(240, yf));
			pacdots.push_back(new PacDot(540, yf));
			pacdots.push_back(new PacDot(605, yf));
			yf += 20;
		}

		// VERTICALES SOBRANTES FIN
		yf = 200;
		for (int i = 0; i < 2; i++)
		{
			pacdots.push_back(new PacDot(130, yf));
			pacdots.push_back(new PacDot(240, yf));
			pacdots.push_back(new PacDot(540, yf));
			pacdots.push_back(new PacDot(650, yf));
			yf += 20;
		}
		AgregarBonus();
		yf = 270;
		for (int i = 0; i < 2; i++)
		{
			pacdots.push_back(new PacDot(130, yf));
			pacdots.push_back(new PacDot(240, yf));
			pacdots.push_back(new PacDot(540, yf));
			pacdots.push_back(new PacDot(650, yf));
			yf += 20;
		}
	}
	~Controladora(){
		delete pacman;
		for ( Fantasma* fan : fantasmas)
		{
			delete fan;
		}
		for (PacDot* pac : pacdots)
		{
			delete pac;
		}
		fantasmas.clear();
		pacdots.clear();
	}
	
	void AgregarBonus() {
		xf = 500;
		yf = 150;
		bonus = new Bonus(40 + rand() % xf + 65, 90 + rand() % yf + 50);	//+ rand() % xf + rand() % yf
		spawBonus = time(0);
		bonus->setActive(true);
	}

	void Desplazamiento(direccion dir) {
		pacman->desplazamiento(dir);
	}

	void MostrarTodo(Graphics^ g, Bitmap^ bmpacman, Bitmap^ bmpescenario,Bitmap^ bmppacdots, Bitmap^ bmpvidas, Bitmap^ bmpbonus) {
		escenario->mostrar(g,bmpescenario);
		MostrarVidas(g,bmpvidas);
			
		for (int i = 0; i < pacdots.size(); i++)
		{
			pacdots[i]->mostrar(g, bmppacdots);
		}
		pacman->mostrar(g, bmpacman);
		for (int i = 0; i < fantasmas.size(); i++)
		{
			fantasmas[i]->mostrar(g, bmpacman);
		}
		if (bonus->getActive())
		{
			bonus->mostrar(g, bmpbonus);
		}
		//g->DrawString(" Creditos: \n Gwyneth Segura \n Deyvid Guevara " , gcnew Font("Algerian", 10, FontStyle::Bold), Brushes::White, 350, 20);
		g->DrawString(" Score: " + puntos, gcnew Font("Algerian", 15, FontStyle::Bold), Brushes::White, 585, 40);
	}

	void MostrarVidas(Graphics^ g, Bitmap^ bmpvidas) {
		int ancho = bmpvidas->Width;
		int alto = bmpvidas->Height / 5;
		Rectangle porcion = Rectangle(columna * ancho, fila * alto, ancho, alto);

		g->DrawImage(bmpvidas, 20, 20, porcion, GraphicsUnit::Pixel);

		switch (pacman->getVidas())
		{
		case 0:
			fila = 5; break;
		case 1:
			fila = 4; break;
		case 2:
			fila = 3; break;
		case 3:
			fila = 2; break;
		case 4:
			fila = 1; break;
		case 5:
			fila = 0; break;
		default:
			break;
		}
	}

	void MoverTodo(Graphics^ g) {
		pacman->mover(g,escenario->rec1(),escenario->rec2(), escenario->rec3(), escenario->rec4(), escenario->rec5(), escenario->rec6(),
			escenario->rec7(), escenario->rec8(), escenario->rec9(), escenario->rec10(), escenario->rec11(), escenario->rec12(),
			escenario->rec13(), escenario->rec14(), escenario->rec15(), escenario->rec16(), escenario->rec17(), escenario->rec18(), escenario->rec19(),
			escenario->rec20(), escenario->rec21(), escenario->rec22(), escenario->rec23());
		for (int i = 0; i < fantasmas.size(); i++)
		{
			fantasmas[i]->mover(g, escenario->rec1(), escenario->rec2(), escenario->rec3(), escenario->rec4(), escenario->rec5(), escenario->rec6(),
				escenario->rec7(), escenario->rec8(), escenario->rec9(), escenario->rec10(), escenario->rec11(), escenario->rec12(),
				escenario->rec13(), escenario->rec14(), escenario->rec15(), escenario->rec16(), escenario->rec17(), escenario->rec18(), escenario->rec19(),
				escenario->rec20(), escenario->rec21(), escenario->rec22(), escenario->rec23());
			
		}
		ColisionP_F();
		ColisionP_Pac();
		ColisionP_B();
		spawn();
	}
	
	void ColisionP_F() {

		for (int i = 0; i < fantasmas.size(); i++)
		{
			if (pacman->getArea().IntersectsWith(fantasmas.at(i)->getArea()))
			{
				pacman->setVidas(-1);
				pacman->setX(40);
				pacman->setY(100);
				pacman->setDX(0);
				pacman->setDY(0);
				pacman->setfila(0);
			}
		}
	}

	void ColisionP_B() {
		if (pacman->getArea().IntersectsWith(bonus->getAreaBonus()))
		{
			tiempoVeloc = time(0);
			pacman->setChocoBonus(true);
			bonus->setActive(false);		
		}

		RegresarVelocidad();
		
	}

	void RegresarVelocidad() {
		if (difftime(time(0), tiempoVeloc) > 10 && pacman->getChocoBonus())
		{
			pacman->setChocoBonus(false);
		}
	}

	void ColisionP_Pac() {
		for (int i = 0; i < pacdots.size(); i++)
		{
			if (pacman->Areapequenia().IntersectsWith(pacdots.at(i)->getArea())) {
				pacdots.erase(pacdots.begin() +i);
				puntos += 10;
				output.open("output.txt", ios::out);
				if (output.is_open())
				{
					output << "Cantidad de pac-dots que comió Pacman: " << puntos / 10 << endl;
					output.close();
				}
			}
		}
	}

	bool Perdiste() {
		if (pacman->getVidas() < 0)
		{
			/*output.open("output.txt", ios::out);*/
			/*if (output.is_open())
			{
				output << "Bueno no sé que paso pero si da :v : " << puntos/10 << endl;
				output.close();
			}*/
			return true;
		}
	}

	bool Ganaste() {
		if (pacdots.size() <= 0)
		{
			/*output.open("output.txt", ios::out);
			if (output.is_open())
			{
				output << "Bueno no sé que paso pero si da :v : " << puntos/10 << endl;
				output.close();
			}*/
			return true;
		}
	}

	void spawn() {
		if (difftime(time(0), spawBonus) > 15)
		{
			AgregarBonus();
		}

	}

	int getPuntos() {
		return puntos;
	}
};
