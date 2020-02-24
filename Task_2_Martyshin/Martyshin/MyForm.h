#pragma once

namespace Martyshin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//�����
	float lines[] =
	{
		//�����
		7.f,29.f,6.f,27.f,
		6.f,27.f,4.f,27.f,
		4.f,27.f,4.f,26.f,
		4.f,26.f,14.f,26.f,
		14.f,26.f,14.f,27.f,
		14.f,27.f,12.f,27.f,
		12.f,27.f,11.f,29.f,
		11.f,29.f,7.f,29.f,
		12.f,27.f,6.f,27,
		//����
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
		//����� ����
		7.f,26.f,6.f,25.f,
		6.f,25.f,6.f,23.f,
		6.f,23.f,8.f,23.f,
		8.f,23.f,8.f,25.f,
		8.f,25.f,7.f,26.f,

		7.f,25.f,6.f,23.f,
		7.f,25.f,8.f,23.f,

		7.f,24.f,6.5f,23.f,
		7.f,24.f,7.5f,23.f,

		//������ ����
		11.f,26.f,10.f,25.f,
		10.f,25.f,10.f,23.f,
		10.f,23.f,12.f,23.f,
		12.f,23.f,12.f,25.f,
		12.f,25.f,11.f,26.f,

		11.f,25.f,10.f,23.f,
		11.f,25.f,12.f,23.f,

		11.f,24.f,10.5f,23.f,
		11.f,24.f,11.5f,23.f,

		//��� ���
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

		//������
		7.f,21.f,8.f,20.f,
		8.f,20.f,10.f,20.f,
		10.f,20.f,11.f,21.f,

		//��������
		8.f,18.f,5.f,17.f,
		5.f,17.f,5.f,9.f,
		5.f,9.f,13.f,9.f,
		13.f,9.f,13.f,17.f,
		13.f,17.f,10.f,18.f,

		//�������
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
		//����� �� �������
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

		//����� ����
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

		//������ ����
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

		//����� ����
		5.f,9.f,6.f,3.f,
		6.f,3.f,9.f,3.f,
		9.f,3.f,9.f,9.f,

		//����� 
		7.f,8.f,6.f,7.f,
		6.f,7.f,7.f,6.f,
		7.f,6.f,8.f,7.f,
		8.f,7.f,7.f,8.f,

		7.f,4.f,6.f,3.f,
		7.f,4.f,8.f,3.f,

		//������ ����
		13.f,9.f,12.f,3.f,
		12.f,3.f,9.f,3.f,

		//�����
		11.f,8.f,10.f,9.f,
		11.f,8.f,12.f,9.f,

		11.f,6.f,10.f,5.f,
		10.f,5.f,11.f,4.f,
		11.f,4.f,12.f,5.f,
		12.f,5.f,11.f,6.f,

		//����)

		9.f,3.f,5.f,3.f,
		5.f,3.f,2.f,1.f,
		2.f,1.f,17.f,1.f,
		17.f,1.f,14.f,3.f,
		14.f,3.f,9.f,3.f,
		9.f,3.f,9.f,1.f,
	};

	


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
	private: bool keepAspectRatio; // �������� - ��������� �� ����������� ������ �������?
	private: bool Swap = true;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // ��������� ��������: ��������� ����������� ������ �������
	}



	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width; // ������ ���� �� �����������
		float Wy = ClientRectangle.Height; // ������ ���� �� ���������

		float aspectForm = Wx / Wy; // ����������� ������ ���� ���������

		//����������� �����
		if (Swap)
		{

			float Vx = 17.f; // ������ ������� �� �����������
			float Vy = 31.f; // ������ ������� �� ���������
			float aspectFig = Vx / Vy; // ����������� ������ �������
			float Sx, Sy;
			if (keepAspectRatio) {
				// �����������s ���������� ��� ���������� ��������� ����������� ������
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
				Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
			}
			unsigned int arrayLength = sizeof(lines) / sizeof(float); // ����� �������
			float Ty = Sy * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����

			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1],
					Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}

		}
		//���� ������� N �� ���� 
		else
		{
			float lines[] = {
				// ������
				0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
				1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
				0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
				0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
				1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
				1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
				2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
				1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
				1.5f,4.5f,3.f,4.5f, // �������
				3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
				3.f,6.f,2.5f,7.5f, // ������ ��� �����
				2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
				3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
				3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
				4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
				4.f,6.f,3.5f,4.5f, // ������ ��� ������
				3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
				4.f,3.f,3.5f,1.5f, // ������ �����
				3.5f,1.5f,2.5f,1.f, // ���������� ������
				2.5f,1.f,2.f,1.f, // ���������� �����
				2.f,1.f,1.f,1.5f, // ���������� �����
				1.f,1.5f,0.5f,3.f, // ����� �����
				// ��������
				4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
				5.5f,3.5f,7.f,3.5f, // ����� ����
				7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
				7.5f,2.5f,8.f,2.5f, // ����� ������
				8.f,2.5f,8.f,2.f, // ����� ������
				8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
				7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
				7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
				6.5f,0.5f,6.5f,1.f, // ������ ���� �����
				6.5f,1.f,6.f,1.f, // ����� ������ ���
				6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
				6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
				5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
				5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
				4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
				4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
				3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
				3.f,1.f,2.5f,1.f, // ����� �������� ���
				2.5f,1.f,2.5f,0.5f, // �������� ���� ������
				2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
				1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
				// ����� ����
				1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
				1.5f,3.f,2.f,3.f, // ����� ���� ���
				2.f, 3.f,2.f,3.5f, // ����� ���� ������
				2.f,3.5f,1.5f,3.5f, // ����� ���� ����
				// ������ ����
				2.5f,3.5f,2.5f,3.f, // ������ ���� �����
				2.5f,3.f,3.f, 3.f, // ������ ���� �����
				3.f,3.f,3.f,3.5f, // ������ ���� ������
				3.f,3.5f,2.5f,3.5f, // ������ ���� ������
				// ����� ��������
				1.f,5.5f,1.f,7.f, // ����� ����� ��������
				3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
				// ���
				2.f,2.5f,2.5f,2.5f, // ��� ������
				2.5f,2.5f,2.25f,2.f, // ��� ������
				2.25f,2.f,2.f,2.5f // ��� �����
			};

			float Vx = 8.5f; // ������ ������� �� �����������
			float Vy = 8.5f; // ������ ������� �� ���������
			float aspectFig = Vx / Vy; // ����������� ������ �������

			float Sx, Sy;
			if (keepAspectRatio) {
				// �����������s ���������� ��� ���������� ��������� ����������� ������
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
				Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
			}

			float Ty = Sy * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
			unsigned int arrayLength = sizeof(lines) / sizeof(float); // ����� �������
			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1],
					Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}
		}

	}
	//������
	private: System::Void MyForm_Resize_1(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}

//���� ��� ������
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
