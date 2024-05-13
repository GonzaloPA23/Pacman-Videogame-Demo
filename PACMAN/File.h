#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ifstream fileRead;
	string text;

	int vidas, fantasmas;

public:
	File() {
		readData();
	}

	~File() {}

	void readData() {
		fileRead.open("imput.txt", ios::in);


		getline(fileRead, text);
		vidas = stoi(text);
		getline(fileRead, text);
		fantasmas = stoi(text);
		getline(fileRead, text);
	}

	//void setPuntos(int puntos) {
	//	this->PacdotsCap = puntos;
	//}

	int getVidas() { return vidas; }
	int getFantasmas() { return fantasmas; }
	/*int getPuntos() { return PacdotsCap; }*/
};