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

	//�����
	//float lines[] =
	//{
	//	//�����
	//	7.f,29.f,6.f,27.f,
	//	6.f,27.f,4.f,27.f,
	//	4.f,27.f,4.f,26.f,
	//	4.f,26.f,14.f,26.f,
	//	14.f,26.f,14.f,27.f,
	//	14.f,27.f,12.f,27.f,
	//	12.f,27.f,11.f,29.f,
	//	11.f,29.f,7.f,29.f,
	//	12.f,27.f,6.f,27,
	//	//����
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
	//	//����� ����
	//	7.f,26.f,6.f,25.f,
	//	6.f,25.f,6.f,23.f,
	//	6.f,23.f,8.f,23.f,
	//	8.f,23.f,8.f,25.f,
	//	8.f,25.f,7.f,26.f,


	mat3 T;
	mat3 initT;			// ������� ���������� ��������������
	vec2 Vc; // ���������� ������ ������� ����
	vec2 V; // ������� �������������� � ������������ �������
	vec2 Vc_work, V_work; // ������� ��������� ��������������
	float Ty;
	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->openFileDialog->Title = L"������� ����";
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
	private: float left = 30, right = 100, top = 20, bottom = 50; // ���������� �� ������ ����
		   float minX = left, maxX; // �������� ��������� ��������� x
		   float minY = top, maxY; // �������� ��������� ��������� y
		   float Wcx = left, Wcy; // ���������� ������ ������� ���� ��������������
		   float Wx, Wy; // ������ � ������ ��������������
		   int numXsect = 5, numYsect = 5;
	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // �������� ��������� ��������� x
		maxY = ClientRectangle.Height - bottom; // �������� ��������� ��������� y
		Wcy = maxY; // ���������� ������ ������� ���� ��������������
		Wx = maxX - left; // ������ ��������������
		Wy = maxY - top; // ������ � ������ ��������������
	}
	private: System::Void worldRectCalc() {
		Vc_work = normalize(T * vec3(Vc, 1.f));
		V_work = mat2(T) * V;
	}
	private: float f(float x) {
		return tan(x);
	}
	private: bool f_exists(float x, float delta) {
		return fabs(2.f * acos(cos(x)) - Math::PI) > delta;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Vc = vec2(-2.f, -2.f);
		V = vec2(4.f, 4.f);

		initT = mat3(1.f);
		T = initT;
		rectCalc();
		worldRectCalc();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		Pen^ pen = gcnew Pen(Color::Blue, 1);
		float deltaX = V_work.x / Wx; // ��� �� x � ������� �����������
		bool hasStart;
		vec2 start; // ����� ������ ������� � ����������� ������
		float x, y; // ���������� ��� ��������� ����� � ������� ��
		start.x = Wcx; // ��� ��������� ����� ������� ������� ������������� ���������� x
		x = Vc_work.x; // ���������� x ��������� ����� ������� ������� � ������� �����������

		hasStart = f_exists(x,deltaX);
		if (hasStart) {
			y = f(x); // ���������� y ��������� ����� � ������� �����������
			// ��������� ��������������� �������� � ����������� ������
			start.y = Wcy - (y - Vc_work.y) / V_work.y * Wy;
		}
		//����� �� x
        Pen^ gridPen = gcnew Pen(Color::Black, 1);
        SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
        System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
 
        float gridStep_x = Wx / numXsect; // ���������� ����� ������� ����� �� x
        float grid_dX = V_work.x / numXsect; // ���������� ����� ������� ����� �� x � ������� �����������
        float tick_x = Vc_work.x; // �������� ��������������� ������ ����� �����
        for (int i = 0; i <= numXsect; i++) { // ���� �� ���������� �����
            float tmpXCoord_v = Wcx + i * gridStep_x; // ���������� x i-� ������������ �����

            g->DrawLine(gridPen, tmpXCoord_v, Wy + top, tmpXCoord_v, minY);
            if (i > 0 && i < numXsect) // ���� ����� �� �������
            // ������� ����� � ������ ����� ������������ �����
                g->DrawString(tick_x.ToString("F4"), drawFont, drawBrush, tmpXCoord_v, Wcy);
 
            tick_x += grid_dX; // ��������� ��������, ��������������� ��������� �����
        }
		//����� �� y
        float gridStep_y = Wy / numYsect; // ���������� ����� ������� ����� �� y
        float grid_dY = V_work.y / numYsect; // ���������� ����� ������� ����� �� y � ������� �����������
        float tick_y = Vc_work.y; // �������� ��������������� ������ ����� �����
        for (int i = 0; i <= numYsect; i++) { // ���� �� ���������� �����
            float tmpYCoord_g = Wcy - i * gridStep_y; // ���������� y i-� ������������ �����
            g->DrawLine(gridPen, Wx + left, tmpYCoord_g, minX, tmpYCoord_g);
            if (i > 0 && i < numYsect) // ���� ����� �� �������
                g->DrawString(tick_y.ToString("F4"), drawFont, drawBrush, Wx + left, tmpYCoord_g);
 
            tick_y += grid_dY; // ��������� ��������, ��������������� ��������� �����
        }

		float deltaY; // ������ ����� � �������������� (���� ����� ������)
		float red, green, blue; // ���������� ����� �������
		while (start.x < maxX) {

			vec2 end;// ����� ����� ������� � ����������� ������
			bool hasEnd;
			end.x = start.x + 1.f; // ���������� x ���������� �� �������
			x += deltaX; // ���������� x �������� ����� ������� � ������� �����������

			hasEnd = f_exists(x, deltaX);
			if (hasEnd) {
				y = f(x); // ���������� y ��������� ����� � ������� �����������
				// ��������� ��������������� �������� � ����������� ������
				// ��������� ��������������� �������� � ����������� ������
				deltaY = (y - Vc_work.y) / V_work.y;
				end.y = Wcy - deltaY * Wy;
			}
			vec2 tmpEnd = end;
			bool visible = hasStart && hasEnd && clip(start, end, minX, minY, maxX, maxY);
			hasStart = hasEnd;
			if (visible) { // ���� ������� �����
			// ����� ���������, start � end - ����� ������� ����� �������
				if (deltaY > 1.f) deltaY = 1.f; // ����������� �������� ������ �����
				if (deltaY < 0.f) deltaY = 0.f; // �� ������, ���� ������� ���������
				green = 510.f * deltaY; // ��������������� ���������� ������������
				if (deltaY < 0.5) { // ���� ����� ���� �������� ������� ���������
				// ���������� �������� ��� ���������
					blue = 255.f - green; // ����� ��������� �������
					red = 0.f; // ������� ����� ����
				}
				else { // ���� ����� �� ���� ��������
					blue = 0.f; // ����� ����� ����
					red = green - 255.f; // ��������� ������� � �������
					green = 510.f - green; // � �������������� ������������ ������������
				}
				pen->Color = Color::FromArgb(red, green, blue); // ������ ���� ����
				g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� ������
			}
			// �������� ����� ������������� ������� ���������� ��������� ������ ����������
			start = tmpEnd;
		}
	}
		   //������
	private: System::Void MyForm_Resize_1(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}

		   //���� ��� ������
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = Wx / 2.f; // ���������� ������
		float Wcy = Wy / 2.f; // �������� ����
		float centerX = Vc_work.x + V_work.x / 2; // ���������� ������ ��������������
		float centerY = Vc_work.y + V_work.y / 2; // � ������� ������� ���������
		switch (e->KeyCode) {
			//�����
		case Keys::Escape:
			T = initT;
			break;
			//////////////WASDRF///////////////////
		case Keys::W:
			T = translate(0.f, V_work.x / Wx) * T; // ����� ������� ������ �� ���� ������
			break;
		case Keys::A:
			T = translate(-V_work.x / Wx, 0.f) * T; // ����� ������� ������ �� ���� ������
			break;
		case Keys::S:
			T = translate(0.f, -V_work.x / Wx) * T; // ����� ������� ������ �� ���� ������
			break;
		case Keys::D:
			T = translate(V_work.x / Wx, 0.f) * T; // ����� ������� ������ �� ���� ������
			break;
			//////////////XZ///////////////////
		case Keys::Z:
			T = translate(-centerX, -centerY) * T; // ������� ������ ��������� � �����
			T = scale(1.1) * T; // ��������������� ������������ ������ ���������
			T = translate(centerX, centerY) * T; // ������� ������� ������ ���������
			break;
		case Keys::X:
			T = translate(-centerX, -centerY) * T; // ������� ������ ��������� � �����
			T = scale(0.9) * T; // ��������������� ������������ ������ ���������
			T = translate(centerX, centerY) * T; // ������� ������� ������ ���������
			break;

			//////////////1234///////////////////
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
		default:
			break;
		}
		worldRectCalc();
		Refresh();
	}
	};
}
