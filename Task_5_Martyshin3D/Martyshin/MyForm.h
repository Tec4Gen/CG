#pragma once
#include "Matrix.h"
#include <math.h>
#include "Transform.h"


namespace Martyshin {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	//Клоун
	//float lines[] =
	//{
	//	//шляпа
	//	7.f,29.f,6.f,27.f,
	//	6.f,27.f,4.f,27.f,
	//	4.f,27.f,4.f,26.f,
	//	4.f,26.f,14.f,26.f,
	//	14.f,26.f,14.f,27.f,
	//	14.f,27.f,12.f,27.f,
	//	12.f,27.f,11.f,29.f,
	//	11.f,29.f,7.f,29.f,
	//	12.f,27.f,6.f,27,
	//	//лицо
	//	4.f,26.f,2.f,24.f,
	//	2.f,24.f,3.f,24.f,
	//	3.f,24.f,1.f,22.f,
	//	1.f,22.f, 3.f,22.f,
	//	3.f,22.f,2.f,20.f,
	//	2.f,20.f,4.f,21.f,
	//	4.f,21.f,4.f,19.f,
	//	4.f,19.f,5.f,20.f,
	//	5.f,20.f,8.f,18.f,
	//	8.f,18.f,10.f,18.f,
	//	10.f,18.f,13.f,20.f,
	//	13.f,20.f,14.f,19.f,
	//	14.f,19.f,14.f,21.f,
	//	14.f,21.f,16.f,20.f,
	//	16.f,20.f,15.f,22.f,
	//	15.f,22.f,17.f,22.f,
	//	17.f,22.f,15.f,24.f,
	//	15.f,24.f,16.f,24.f,
	//	16.f,24.f,14.f,26.f,
	//	5.f,20.f,5.f,26.f,
	//	13.f,20.f,13.f,26.f,
	//	//левый глаз
	//	7.f,26.f,6.f,25.f,
	//	6.f,25.f,6.f,23.f,
	//	6.f,23.f,8.f,23.f,
	//	8.f,23.f,8.f,25.f,
	//	8.f,25.f,7.f,26.f,


	mat4 T; // матрица, в которой накапливаются все преобразования
	mat4 initT; // матрица начального преобразования
	vec3 Vc; // координаты дальнего левого нижнего угла
	vec3 V; // размеры параллелепипеда в пространстве графика
	vec3 Vc_work, V_work; // рабочие параметры параллелепипеда
	float Ty;
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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;


	protected:

	protected:

	protected:


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
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"(*.txt)|*.txt";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(155, 120);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: float left = 30, right = 100, top = 20, bottom = 50; // расстояния до границ окна
		   float minX = left, maxX; // диапазон изменения координат x
		   float minY = top, maxY; // диапазон изменения координат y
		   float Wcx = left, Wcy; // координаты левого нижнего угла прямоугольника
		   float Wx, Wy; // ширина и высота прямоугольника
		   float Wx_work, Wy_work; // ширина и высота области вывода одной линии графика
		   float Wx_part = 0.6, Wy_part = 0.6; // доля Wx_work, Wy_work от Wx, Wy соответственно
		   float Wcx_work, Wcy_work; // координаты левого нижнего угла самого дальнего прямоугольника
		   float Wz_work; // количество рабочих прямоугольников
		   int numXsect = 5, numYsect = 5, numZsect = 5; // количество секций координатной сетки по осям

	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y
		Wcy = maxY; // координаты левого нижнего угла прямоугольника
		Wx = maxX - left; // ширина прямоугольника
		Wy = maxY - top; // ширина и высота прямоугольника

		Wx_work = Wx_part * Wx; // вычисление ширины и высоты
		Wy_work = Wy_part * Wy; // рабочего прямоугольника
		Wcx_work = maxX - Wx_work; // вычисление координат нижнего левого
		Wcy_work = minY + Wy_work; // угла самого дальнего рабочего прямоугольника
		Wz_work = Wcy - Wcy_work; // количество рабочих прямоугольников

	}
	private: System::Void worldRectCalc() {
		Vc_work = normalize(T * vec4(Vc, 1.f));
		V_work = mat3(T) * V;
	}
	private: float f(float x, float z) {
		return x * sin(sqrtf(x * x + z * z));
	}
	private: bool f_exists(float x, float z, float delta) {
		return true;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Vc = vec3(-2.f, -2.f, -2.f);
		V = vec3(4.f, 4.f, 4.f);
		initT = mat4(1.f);

		T = initT;
		rectCalc();
		worldRectCalc();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		Pen^ gridPen = gcnew Pen(Color::Black, 1);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
		//сетка по Z
		float gridStep_x = Wx_work / numXsect; // расстояние между линиями сетки по x
		float grid_dX = V_work.x / numXsect; // расстояние между линиями сетки по x в мировых координатах
		float tmpXCoord_v;
		float tick_x = Vc_work.x; // значение соответствующее первой линии сетки
		for (int i = 0; i <= numXsect; i++) { // цикл по количеству линий
			tick_x += grid_dX; // вычисляем значение, соответствующее следующей линии

			float tmpXCoord_d = Wcx + i * gridStep_x; // нижняя координата x i-й диагональной линии
			 tmpXCoord_v = Wcx_work + i * gridStep_x; // координата x i-й вертикальной линии
			// i-я диагональная линия
			g->DrawLine(gridPen, tmpXCoord_d, Wcy, tmpXCoord_v, Wcy_work);
			// i-я вертикальная линия
			g->DrawLine(gridPen, tmpXCoord_v, Wcy_work, tmpXCoord_v, minY);

			if (i > 0 && i < numXsect) // если линия не крайняя	// выводим текст в нижней точке диагональной линии
				g->DrawString(tick_x.ToString("F4"), drawFont, drawBrush, tmpXCoord_d, Wcy);
		}
		//сетка по X
		gridStep_x = (Wx - Wx_work) / numZsect; // между  вертикальными линиями сетки по горизонтали
		float gridStep_y = Wz_work / numZsect; //между между горизонтальными линиями сетки по вертикали
		float grid_dZ = V_work.z / numZsect; // между линиями сетки по $z$ в мировых координатах

		float tick_z = Vc_work.z; // значение, соответствующее первой линии сетки
		for (int i = 0; i <= numZsect; i++) { // цикл по количеству линий
			tick_z += grid_dZ; // вычисляем значение, соответствующее следующей линии
			float tmpXCoord_v = Wcx_work - i * gridStep_x; // x вертикальных линий
			float tmpYCoord_g = Wcy_work + i * gridStep_y; // yгоризонтальных линий
			float tmpXCoord_g = tmpXCoord_v + Wx_work; // вторая x горизонтальных линий
			// i-я вертикальная линия
			g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_v, tmpYCoord_g - Wy_work);
			// i-я горизонтальная линия
			g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_g, tmpYCoord_g);
			if (i > 0 && i < numZsect) // если линия не крайняя
				// выводим текст в правой точке горизонтальной линии
				g->DrawString(tick_z.ToString("F4"), drawFont, drawBrush, tmpXCoord_g, tmpYCoord_g);
		}
		///////////////********Task 2(a)********////////////////////
		//сетка по y
		gridStep_y = Wy_work / numYsect;
		float grid_dY = V_work.y / numYsect; // расстояние между линиями сетки по $y$ в мировых координатах
		float tick_y = Vc_work.y; // значение, соответствующее первой линии сетки
		for (int i = 0; i <= numYsect; i++) {  // цикл по количеству линий
			float tmpYCoord_d = Wcy - i * gridStep_y;
			float tmpYCoord_v = Wcy_work - i * gridStep_y;
			g->DrawLine(gridPen, Wcx, tmpYCoord_d, Wcx_work, tmpYCoord_v);
			g->DrawLine(gridPen, Wcx_work, tmpYCoord_v, Wcx_work + Wx_work, tmpYCoord_v);
			if (i > 0 && i < numYsect)// Если линия не крайняя
			// выводим текст в правой точке горизонтальной линии
				g->DrawString(tick_y.ToString("F4"), drawFont, drawBrush, Wcx_work + Wx_work, tmpYCoord_v);
			tick_y += grid_dY; // Вычисляем значение, соответствующее следующей линии
		}
		///////////////****************////////////////////

		Pen^ pen = gcnew Pen(Color::Blue, 1);
		float deltaX = V_work.x / Wx_work; // шаг по x в мировых координатах
		float deltaZ = V_work.z / Wz_work; // шаг по z в мировых координатах
		float deltaWcx = (Wcx_work - Wcx) / Wz_work; // шаг прямоугольников по x в координатах экрана
		bool hasStart;
		float z = Vc_work.z; // координата z наиболее удаленных точек графика
		float Wcx_w = Wcx_work, Wcy_w = Wcy_work;
		while (Wcy_w <= Wcy) { // пока не перебрали все прямоугольники

			vec2 start, end; // точка начала отрезка в координатах экрана
			float x, y; // переменные для координат точки в мировой СК
			start.x = Wcx_w; // для начальной точки первого отрезка устанавливаем координату x
			x = Vc_work.x; // координата x начальной точки первого отрезка в мировых координатах

			hasStart = f_exists(x, z, deltaX);
			if (hasStart) {
				y = f(x, z); // координата y начальной точки в мировых координатах
				// вычисляем соответствующее значение в координатах экрана
				start.y = Wcy_w - (y - Vc_work.y) / V_work.y * Wy_work;
			}
			// координаты левого нижнего угла рабочего прямоугольника (инициализация)
			float maxX = Wcx_w + Wx_work;
			while (start.x < maxX) {
				bool hasEnd;
				float deltaY; // высота точки в прямоугольнике (доля общей высоты)
				float red, green, blue; // компоненты цвета отрезка
				end.x = start.x + 1.f; // координата x отличается на единицу
				x += deltaX; // координата x конечной точки отрезка в мировых координатах

				hasEnd = f_exists(x, z, deltaX);
				if (hasEnd) {
					y = f(x, z); // координата y начальной точки в мировых координатах
					// вычисляем соответствующее значение в координатах экрана
					// вычисляем соответствующее значение в координатах экрана
					deltaY = (y - Vc_work.y) / V_work.y;
					end.y = Wcy_w - deltaY * Wy_work;
				}
				vec2 tmpEnd = end;
				bool visible = hasStart && hasEnd && clip(start, end, Wcx, Wcy_w - Wy_work , maxX, Wcy_w);
				hasStart = hasEnd;
				if (visible) { // если отрезок видим
				// после отсечения, start и end - концы видимой части отрезка
					if (deltaY > 1.f) deltaY = 1.f; // нормализуем значение высоты точки
					if (deltaY < 0.f) deltaY = 0.f; // на случай, если отрезок отсекался
					green = 510.f * deltaY; // предварительное вычисление произведения
					if (deltaY < 0.5) { // если точка ниже середины области видимости
					// компонента зеленого уже вычислена
						blue = 255.f - green; // синий дополняет зеленый
						red = 0.f; // красный равен нулю
					}
					else { // если точка не ниже середины
						blue = 0.f; // синий равен нулю
						red = green - 255.f; // вычисляем красный и зеленый
						green = 510.f - green; // с использованием вычисленного произведения
					}
					pen->Color = Color::FromArgb(red, green, blue); // меняем цвет пера
					g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей
				}
				// конечная точка неотсеченного отрезка становится начальной точкой следующего
				start = tmpEnd;
			}
			Wcy_w += 1.f; // переходим к следующему прямоугольнику, он будет ниже на один пиксел
			Wcx_w -= deltaWcx; // и левее на некоторое значение
			z += deltaZ; // вычисляем соответствующее значение z для очередного прямоугольника
		}
	}
		   //ресайз
	private: System::Void MyForm_Resize_1(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}

		   //Свич для кнопок
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = Wx / 2.f; // координаты центра
		float Wcy = Wy / 2.f; // текущего окна
		float centerX = Vc_work.x + V_work.x / 2; // координаты центра прямоугольника
		float centerY = Vc_work.y + V_work.y / 2; // в мировой системе координат
		float centerZ = Vc_work.z + V_work.z / 2;
		switch (e->KeyCode) {
			//сброс
		case Keys::Escape:
			T = initT;
			Wx_part = 0.6;
			Wy_part = 0.6;
			rectCalc();
			break;

			//////////////WASDRF///////////////////
		case Keys::W:
			T = translate(0.f, 0.f, V_work.x / Wx) * T; // сдвиг вперед от наблюдателя
			break;
		case Keys::A:
			T = translate(-V_work.x / Wx, 0.f, 0.f) * T; // сдвиг графика вправо на один
			break;
		case Keys::S:
			T = translate(0.f, 0.f, -V_work.x / Wx) * T; // сдвиг вперед от наблюдателя
			break;
		case Keys::D:
			T = translate(V_work.x / Wx, 0.f, 0.f) * T; // сдвиг графика вправо на один
			break;
		case Keys::R:
			T = translate(0.f, V_work.x / Wx, 0.f) * T; // сдвиг графика вправо на один
			break;
		case Keys::F:
			T = translate(0.f, -V_work.x / Wx, 0.f) * T; // сдвиг графика вправо на один
			break;
			//////////////XZ///////////////////
		case Keys::X:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(0.9, 0.9, 0.9) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::Z:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1.1, 1.1, 1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
			//////////////QECV///////////////////
		case Keys::Q:
			if (Wx_part <= 0.9)
			{
				Wx_part *= 1.1;
				rectCalc();
			}
			break;
		case Keys::E:
			if (Wx_part >= 0.2)
			{
				Wx_part *= 0.9;
				rectCalc();
			}
			break;
		case Keys::C:
			if (Wy_part <= 0.9)
			{
				Wy_part *= 1.1;
				rectCalc();
			}
			break;
		case Keys::V:
			if (Wy_part >= 0.2)
			{
				Wy_part *= 0.9;
				rectCalc();
			}
			break;
			////////////////////////////////////
			//////////////TGYHUJ///////////////////
		case Keys::T:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1.1, 1, 1) * T; // масштабирование относительно начала координат		
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::G:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(0.9, 1, 1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::Y:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 1.1, 1) * T; // масштабирование относительно начала координат		
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::H:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 0.9, 1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::U:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 1, 1.1) * T; // масштабирование относительно начала координат		
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::J:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 1, 0.9) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
			//////////////123456///////////////////
		case Keys::D1:
			numXsect += 1;
			break;
		case Keys::D2:
			if (numXsect > 2)
			{
				numXsect -= 1;
			}
			break;
		case Keys::D3:
			numYsect += 1;
			break;
		case Keys::D4:
			if (numYsect > 2)
			{
				numYsect -= 1;
			}
			break;
		case Keys::D5:
			numZsect += 1;
			break;
		case Keys::D6:
			if (numZsect > 2)
			{
				numZsect -= 1;
			}
			break;
			/////////////////////////////////////
		default:
			break;
		}
		worldRectCalc();
		Refresh();
	}
	};
}
