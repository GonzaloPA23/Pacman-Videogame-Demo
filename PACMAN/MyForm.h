#pragma once
#include "Controladora.h"
#include "File.h"

namespace PACMAN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ bf;
		//Bitmaps
		Bitmap^ bmppacman;
		Bitmap^ bmpescenario;
		Bitmap^ bmpvidas;
		Bitmap^ bmppacdots;
		Bitmap^ bmpbonus;
		// Punteros
		Controladora* control;
		//File
		File* file;

	public:
		MyForm(void)
		{
			srand(time(NULL));
			//File
			file = new File();
			InitializeComponent();
			//INSTANCIAR LOS ATRIBUTOS

			//Buffer
			g = CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			bf = espacio->Allocate(g, ClientRectangle);
			// Bitmaps
			bmppacman = gcnew Bitmap("Pacman2.png");
			bmpescenario = gcnew Bitmap("escenario2.jpg");
			bmpvidas = gcnew Bitmap("Vidas.png");
			bmppacdots = gcnew Bitmap("Pac-Dot.png");
			bmpbonus = gcnew Bitmap("bonus.png");
			// Instanciar
			control = new Controladora(file->getVidas(),file->getFantasmas());
		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete g, espacio, bf, bmpescenario, bmppacman, bmppacdots,control;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		SoundPlayer^ musica = gcnew SoundPlayer("PacmanMusic.wav");

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 570);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		musica->PlayLooping();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//bf->Graphics->Clear(Color::White);
		control->MoverTodo(bf->Graphics);
		control->MostrarTodo(bf->Graphics,bmppacman,bmpescenario,bmppacdots, bmpvidas, bmpbonus);
		bf->Render(g);

		if (control->Ganaste() || control->Perdiste())
		{
			this->timer1->Enabled = false;
			MessageBox::Show("ACABO EL JUEGO :) :(");
			this->Close();
			return;
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			control->Desplazamiento(direccion::up);
			break;
		case Keys::Down:
			control->Desplazamiento(direccion::down);
			break;
		case Keys::Left:
			control->Desplazamiento(direccion::left);
			break;
		case Keys::Right:
			control->Desplazamiento(direccion::right);
			break;
		case Keys::P:
			musica->Stop();
		default:
			break;
		}
	}
	};
}
