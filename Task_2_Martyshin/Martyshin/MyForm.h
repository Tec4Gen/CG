#pragma once

namespace Martyshin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Клоун
	float lines[] =
	{
		//шляпа
		7.f,29.f,6.f,27.f,
		6.f,27.f,4.f,27.f,
		4.f,27.f,4.f,26.f,
		4.f,26.f,14.f,26.f,
		14.f,26.f,14.f,27.f,
		14.f,27.f,12.f,27.f,
		12.f,27.f,11.f,29.f,
		11.f,29.f,7.f,29.f,
		12.f,27.f,6.f,27,
		//лицо
		4.f,26.f,2.f,24.f,
		2.f,24.f,3.f,24.f,
		3.f,24.f,1.f,22.f,
		1.f,22.f, 3.f,22.f,
		3.f,22.f,2.f,20.f,
		2.f,20.f,4.f,21.f,
		4.f,21.f,4.f,19.f,
		4.f,19.f,5.f,20.f,
		5.f,20.f,8.f,18.f,
		8.f,18.f,10.f,18.f,
		10.f,18.f,13.f,20.f,
		13.f,20.f,14.f,19.f,
		14.f,19.f,14.f,21.f,
		14.f,21.f,16.f,20.f,
		16.f,20.f,15.f,22.f,
		15.f,22.f,17.f,22.f,
		17.f,22.f,15.f,24.f,
		15.f,24.f,16.f,24.f,
		16.f,24.f,14.f,26.f,
		5.f,20.f,5.f,26.f,
		13.f,20.f,13.f,26.f,
		//левый глаз
		7.f,26.f,6.f,25.f,
		6.f,25.f,6.f,23.f,
		6.f,23.f,8.f,23.f,
		8.f,23.f,8.f,25.f,
		8.f,25.f,7.f,26.f,

		7.f,25.f,6.f,23.f,
		7.f,25.f,8.f,23.f,

		7.f,24.f,6.5f,23.f,
		7.f,24.f,7.5f,23.f,

		//правый глаз
		11.f,26.f,10.f,25.f,
		10.f,25.f,10.f,23.f,
		10.f,23.f,12.f,23.f,
		12.f,23.f,12.f,25.f,
		12.f,25.f,11.f,26.f,

		11.f,25.f,10.f,23.f,
		11.f,25.f,12.f,23.f,

		11.f,24.f,10.5f,23.f,
		11.f,24.f,11.5f,23.f,

		//нос рот
		8.f,23.f,7.f,22.5f,
		7.f,22.5f,7.f,21.5f,
		7.f,21.5f,6.f,22.f,
		6.f,22.f,6.f,20.f,
		6.f,20.f,9.f,19.f,
		9.f,19.f,12.f,20.f,
		12.f,20.f,12.f,22.f,
		12.f,22.f,11.f,21.5f,
		11.f,21.5f,11.f,22.5f,
		11.f,22.5f,10.f,23.f,
		10.f,23.f,8.f,23.f,

		7.f,21.5f,8.f,21.f,
		8.f,21.f,10.f,21.f,
		10.f,21.f,11.f,21.5f,

		//улыбка
		7.f,21.f,8.f,20.f,
		8.f,20.f,10.f,20.f,
		10.f,20.f,11.f,21.f,

		//туловище
		8.f,18.f,5.f,17.f,
		5.f,17.f,5.f,9.f,
		5.f,9.f,13.f,9.f,
		13.f,9.f,13.f,17.f,
		13.f,17.f,10.f,18.f,

		//галстук
		8.f,18.f,7.f,17.f,
		7.f,17.f,8.f,16.f,
		8.f,16.f,7.f,12.f,
		7.f,12.f,9.f,10.f,
		9.f,10.f,11.f,12.f,
		11.f,12.f,10.f,16.f,
		10.f,16.f,11.f,17.f,
		11.f,17.f,10.f,18.f,

		9.f,18.f,8.f,17.f,
		8.f,17.f,9.f,16.f,
		9.f,16.f,10.f,17.f,
		10.f,17.f,9.f,18.f,

		8.f,16.f,10.f,16.f,

		9.f,10.f,9.f,9.f,
		//Узоры на рубашке
		6.f,16.f,6.f,15.f,
		6.f,15.f,5.f,15.f,
		5.f,15.f,5.f,16.f,
		5.f,14.f,6.f,14.f,
		6.f,14.f,6.f,13.f,
		6.f,13.f,7.f,13.f,
		7.f,13.f,7.f,14.f,
		7.f,14.f,7.5f,14.f,
		7.8f,15.f,7.f,15.f,
		7.f,15.f,7.f,16.f,
		7.f,16.f,6.f,16.f,

		11.f,13.f,11.f,12.f,
		10.1f,11.f,11.f,11.f,
		11.f,11.f,11.f,10.f,
		11.f,10.f,12.f,10.f,
		12.f,10.f,12.f,11.f,
		12.f,11.f,13.f,11.f,
		13.f,12.f,12.f,12.f,
		12.f,12.f,12.f,13.f,
		12.f,13.f,11.f,13.f,

		//левая рука
		5.f,17.f,2.f,9.f,
		2.f,9.f,2.f,7.f,
		2.f,7.f,4.f,7.f,
		4.f,7.f,4.f,8.f,
		4.f,8.f,5.f,8.f,
		5.f,8.f,5.f,9.f,
		5.f,9.f,2.f,9.f,

		2.4f, 10.f,3.f,10.f,
		3.f,10.f,3.f,11.f,
		3.f,11.f,4.f,11.f,
		4.f,11.f,4.f,10.f,
		4.f,10.f,5.f,10.f,

		//правая рука
		13.f,17.f,16.f,9.f,
		16.f,9.f,16.f,7.f,
		16.f,7.f,14.f,7.f,
		14.f,7.f,14.f,8.f,
		14.f,8.f,13.f,8.f,
		13.f,8.f,13.f,9.f,
		13.f,9.f,16.f,9.f,

		13.f,10.f,14.f,10.f,
		14.f,10.f,14.f,11.f,
		14.f,11.f,15.f,11.f,
		15.f,11.f,15.f,10.f,
		15.f,10.f,15.6f,10.f,

		//левая нога
		5.f,9.f,6.f,3.f,
		6.f,3.f,9.f,3.f,
		9.f,3.f,9.f,9.f,

		//узоры 
		7.f,8.f,6.f,7.f,
		6.f,7.f,7.f,6.f,
		7.f,6.f,8.f,7.f,
		8.f,7.f,7.f,8.f,

		7.f,4.f,6.f,3.f,
		7.f,4.f,8.f,3.f,

		//правая нога
		13.f,9.f,12.f,3.f,
		12.f,3.f,9.f,3.f,

		//узоры
		11.f,8.f,10.f,9.f,
		11.f,8.f,12.f,9.f,

		11.f,6.f,10.f,5.f,
		10.f,5.f,11.f,4.f,
		11.f,4.f,12.f,5.f,
		12.f,5.f,11.f,6.f,

		//лапы)

		9.f,3.f,5.f,3.f,
		5.f,3.f,2.f,1.f,
		2.f,1.f,17.f,1.f,
		17.f,1.f,14.f,3.f,
		14.f,3.f,9.f,3.f,
		9.f,3.f,9.f,1.f,
	};

	


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio; // значение - сохранять ли соотношение сторон рисунка?
	private: bool Swap = true;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // начальное значение: сохранять соотношение сторон рисунка
	}



	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width; // размер окна по горизонтали
		float Wy = ClientRectangle.Height; // размер окна по вертикали

		float aspectForm = Wx / Wy; // соотношение сторон окна рисования

		//Поумолчанию клоун
		if (Swap)
		{

			float Vx = 17.f; // размер рисунка по горизонтали
			float Vy = 31.f; // размер рисунка по вертикали
			float aspectFig = Vx / Vy; // соотношение сторон рисунка
			float Sx, Sy;
			if (keepAspectRatio) {
				// коэффициентs увеличения при сохранении исходного соотношения сторон
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // коэффициент увеличения по оси Ox
				Sy = Wy / Vy; // коэффициент увеличения по оси Oy
			}
			unsigned int arrayLength = sizeof(lines) / sizeof(float); // длина массива
			float Ty = Sy * Vy; // смещение в положительную сторону по оси Oy после смены знака

			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1],
					Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}

		}
		//Если тыкнули N то заяц 
		else
		{
			float lines[] = {
				// голова
				0.5f,3.f,1.f,4.5f, // от левой щеки вверх до уха
				1.f,4.5f,0.5f,6.f, // левое ухо слева снизу вверх
				0.5f,6.f,0.5f, 7.5f, // левое ухо слева
				0.5f, 7.5f,1.f,8.f, // левое ухо верх слева
				1.f,8.f,1.5f,8.f, // левое ухо верх середина
				1.5f,8.f,2.f,7.5f, // левое ухо верх справа
				2.f,7.5f,1.5f, 6.f, // левое ухо справа сверху вниз
				1.5f, 6.f,1.5f,4.5f, // левое ухо справа до макушки
				1.5f,4.5f,3.f,4.5f, // макушка
				3.f,4.5f,3.f,6.f, // правое ухо слева снизу вверх
				3.f,6.f,2.5f,7.5f, // правое ухо слева
				2.5f,7.5f,3.f,8.f, // правое ухо верх слева
				3.f,8.f,3.5f,8.f, // правое ухо верх середина
				3.5f,8.f,4.f,7.5f, // правое ухо верх справа
				4.f,7.5f,4.f,6.f, // правое ухо сверху вниз
				4.f,6.f,3.5f,4.5f, // правое ухо справа
				3.5f,4.5f,4.f,3.f, // от правого уха вниз до щеки
				4.f,3.f,3.5f,1.5f, // правая скула
				3.5f,1.5f,2.5f,1.f, // подбородок справа
				2.5f,1.f,2.f,1.f, // подбородок снизу
				2.f,1.f,1.f,1.5f, // подбородок слева
				1.f,1.5f,0.5f,3.f, // левая скула
				// туловище
				4.f,3.f,5.5f,3.5f, // спина от головы вправо
				5.5f,3.5f,7.f,3.5f, // спина верх
				7.f,3.5f,7.5f,2.5f, // спина сверху до хвоста
				7.5f,2.5f,8.f,2.5f, // хвост сверху
				8.f,2.5f,8.f,2.f, // хвост справа
				8.f,2.f,7.5f,2.f, // хвост низ справа налево
				7.5f,2.f,7.5f,0.5f, // задняя нога справа сверху вниз
				7.5f,0.5f,6.5f,0.5f, // задняя нога низ
				6.5f,0.5f,6.5f,1.f, // задняя нога слева
				6.5f,1.f,6.f,1.f, // между задних ног
				6.f,1.f,6.f,0.5f, // левая задняя нога справа
				6.f,0.5f,5.f,0.5f, // левая задняя нога низ
				5.f,0.5f,5.f,1.f, // левая задняя нога слева
				5.f,1.f,4.f,1.f, // между задними и передними ногами
				4.f,1.f,4.f,0.5f, // правая передняя нога справа
				4.f,0.5f,3.f,0.5f, // правая передняя нога низ
				3.f,0.5f,3.f,1.f, // правая передняя нога слева
				3.f,1.f,2.5f,1.f, // между передних ног
				2.5f,1.f,2.5f,0.5f, // передняя нога справа
				2.5f,0.5f,1.5f,0.5f, // передняя нога низ
				1.5f,0.5f,1.5f,1.25f, // передняя нога слева
				// левый глаз
				1.5f,3.5f,1.5f,3.f, // левый глаз слева сверху вниз
				1.5f,3.f,2.f,3.f, // левый глаз низ
				2.f, 3.f,2.f,3.5f, // левый глаз справа
				2.f,3.5f,1.5f,3.5f, // левый глаз верх
				// правый глаз
				2.5f,3.5f,2.5f,3.f, // правый глаз слева
				2.5f,3.f,3.f, 3.f, // правый глаз снизу
				3.f,3.f,3.f,3.5f, // правый глаз справа
				3.f,3.5f,2.5f,3.5f, // правый глаз сверху
				// ушные раковины
				1.f,5.5f,1.f,7.f, // левая ушная раковина
				3.5f,5.5f,3.5f,7.f, // правая ушная раковина
				// нос
				2.f,2.5f,2.5f,2.5f, // нос сверху
				2.5f,2.5f,2.25f,2.f, // нос справа
				2.25f,2.f,2.f,2.5f // нос слева
			};

			float Vx = 8.5f; // размер рисунка по горизонтали
			float Vy = 8.5f; // размер рисунка по вертикали
			float aspectFig = Vx / Vy; // соотношение сторон рисунка

			float Sx, Sy;
			if (keepAspectRatio) {
				// коэффициентs увеличения при сохранении исходного соотношения сторон
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // коэффициент увеличения по оси Ox
				Sy = Wy / Vy; // коэффициент увеличения по оси Oy
			}

			float Ty = Sy * Vy; // смещение в положительную сторону по оси Oy после смены знака
			unsigned int arrayLength = sizeof(lines) / sizeof(float); // длина массива
			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1],
					Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}
		}

	}
	//ресайз
	private: System::Void MyForm_Resize_1(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}

//Свич для кнопок
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {

		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N:
			Swap = !Swap;
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}
