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
	vector<path> figure;
	float Vx;
	float Vy;
	float aspectFig;
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
	private: System::Windows::Forms::Button^ btnOpen;

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
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"(*.txt)|*.txt";
			this->openFileDialog->Title = L"������� ����";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(197, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"�������";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize_1);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);


		for (int i = 0; i < figure.size(); i++) {

			path lines = figure[i]; // lines - ��������� ������� �����
			Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
			pen->Width = lines.thickness;

			vec2 start = normalize(T * vec3(lines.vertices[0], 1.0)); // ��������� ����� ������� �������
			for (int j = 1; j < lines.vertices.size(); j++) { // ���� �� �������� ������ (�� �������)
				vec2 end = normalize(T * vec3(lines.vertices[j], 1.0)); // �������� �����
				g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� �������
				start = end; // �������� ����� �������� ������� ���������� ��������� ������ ����������
			}
		}
	}
		   //������
	private: System::Void MyForm_Resize_1(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}

		   //���� ��� ������

	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// ���������� ����� ����� �� openFileDialog->FileName � fileName
			wchar_t fileName[1024]; // ����������, � ������� ����������� �������� ��� �����
			for (int i = 0; i < openFileDialog->FileName->Length; i++)
				fileName[i] = openFileDialog->FileName[i];
			fileName[openFileDialog->FileName->Length] = '\0';
			// ���������� � �������� �����
			ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				figure.clear(); // ������� ��������� ������ �������			// ��������� ���������� ��� ������ �� �����
				float thickness = 2; // ������� �� ��������� �� ��������� 2
				float r, g, b; // ������������ �����
				r = g = b = 0; // �������� ������������ ����� �� ��������� (������)
				// ��������������� ������ � ������
				string cmd;
				string str; // ������, � ������� ��������� ������ �����
				getline(in, str); // ��������� �� �������� ����� ������ ������
				while (in) { // ���� ��������� ������ ������� �������
				// ������������ // ��������� ��������� ������
					if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
						// ����������� ������ �� ����� � �� �����������
						stringstream s(str); // ��������� ����� �� ������ str
						// ���������� ��� ����� �������
						s >> cmd; // ��������� ��� �������
						if (cmd == "frame") { // ������� �����������
							s >> Vx >> Vy; // ��������� ���������� �������� Vx � Vy
							aspectFig = Vx / Vy; // ���������� ����������� ������
							float Wx = ClientRectangle.Width; // ������ ���� �� �����������
							float Wy = ClientRectangle.Height; // ������ ���� �� ���������
							float aspectForm = Wx / Wy; // ����������� ������ ���� ���������
							// ����������� ���������� ��� ���������� ��������� ����������� ������
							float S = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
							float Ty = S * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
							initT = translate(0.f, Ty) * scale(S, -S); // �������������� ����������� ������ ������
							T = initT;

						}
						else if (cmd == "color") { // ���� �����
							s >> r >> g >> b; // ��������� ��� ������������ �����
						}
						else if (cmd == "thickness") { // ������� �����
							s >> thickness; // ��������� �������� �������
						}
						else if (cmd == "path") { // ����� �����
							vector<vec2> vertices; // ������ ����� �������
							int N; // ���������� �����
							s >> N;
							string str1; // �������������� ������ ��� ������ �� �����
							while (N > 0) { // ���� �� ��� ����� �������
								getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������

								if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
									float x, y; // ���������� ��� ����������

									stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
									s1 >> x >> y;
									vertices.push_back(vec2(x, y)); // ��������� ����� � ������
									N--; // ��������� ������� ����� ��������� ���������� �����
								}
							}
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
						}
					}
					getline(in, str);
				}
				Refresh();
			}
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f; // ���������� ������
		float Wcy = ClientRectangle.Height / 2.f; // �������� ����
		switch (e->KeyCode) {
			//�����
		case Keys::Escape:
			T = initT;
			break;
//QE///////////////////////////////////
			//������� ������ ������� 
		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(0.01f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������m
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
			//������� �� �������

		case Keys::E:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(-0.01f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������m
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;

//RY///////////////////////////////////
			//������� ������ �������
		case Keys::R:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(0.05f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������m
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
			//������� �� �������
		case Keys::Y:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(-0.05f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������m
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;

//WASD///////////////////////////////////
		case Keys::W:
			T = translate(0.f, -1.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::A:
			T = translate(-1.f, 0.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::D:
			T = translate(1.f, 0.f) * T; // ����� ������ �� ���� ������
			break;
		case Keys::S:
			T = translate(0.f, 1.f) * T; // ����� ���� �� ���� ������
			break;
//UJ///////////////////////////////////
		case Keys::U:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = MirroxX() * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
		case Keys::J:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = MirroxY() * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;

//TGFH/////////////////////////////////
		case Keys::T:
			T = translate(0.f, -10.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::G:
			T = translate(0.f, 10.f) * T; // ����� ���� �� ���� ������
			break;
		case Keys::F:
			T = translate(-10.f, 0.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::H:
			T = translate(10.f, 0.f) * T; // ����� ������ �� ���� ������
			break;
//ZX/////////////////////////////////
		case Keys::Z:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.1f, 1.1f) * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
		case Keys::X:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(0.9f, 0.9f) * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
//IK/////////////////////////////////
		case Keys::I:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.1f, 1.f) * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
		case Keys::K:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(0.9f, 1.f) * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
//OL/////////////////////////////////
		case Keys::O:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.f, 1.1f) * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
		case Keys::L:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.f, 0.9f) * T;
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}
