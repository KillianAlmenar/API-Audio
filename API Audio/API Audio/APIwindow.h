#include "Player.h"
#define MUSIC_01 "Enemy.wav"
#pragma once
namespace APIAudio {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for APIwindow
	/// </summary>
	public ref class APIwindow : public System::Windows::Forms::Form
	{
	public:
		APIwindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			init();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~APIwindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ PlayBtn;
	private: System::Windows::Forms::Button^ PauseBtn;
	private: System::Windows::Forms::Button^ StopBtn;
	protected:



	private: System::Windows::Forms::Button^ ResumeBtn;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PlayBtn = (gcnew System::Windows::Forms::Button());
			this->PauseBtn = (gcnew System::Windows::Forms::Button());
			this->StopBtn = (gcnew System::Windows::Forms::Button());
			this->ResumeBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PlayBtn
			// 
			this->PlayBtn->Location = System::Drawing::Point(220, 213);
			this->PlayBtn->Name = L"PlayBtn";
			this->PlayBtn->Size = System::Drawing::Size(75, 23);
			this->PlayBtn->TabIndex = 0;
			this->PlayBtn->Text = L"Play";
			this->PlayBtn->UseVisualStyleBackColor = true;
			this->PlayBtn->Click += gcnew System::EventHandler(this, &APIwindow::Play_Click);
			// 
			// PauseBtn
			// 
			this->PauseBtn->Location = System::Drawing::Point(219, 140);
			this->PauseBtn->Name = L"PauseBtn";
			this->PauseBtn->Size = System::Drawing::Size(75, 23);
			this->PauseBtn->TabIndex = 1;
			this->PauseBtn->Text = L"Pause";
			this->PauseBtn->UseVisualStyleBackColor = true;
			// 
			// StopBtn
			// 
			this->StopBtn->Location = System::Drawing::Point(343, 213);
			this->StopBtn->Name = L"StopBtn";
			this->StopBtn->Size = System::Drawing::Size(75, 23);
			this->StopBtn->TabIndex = 2;
			this->StopBtn->Text = L"Stop";
			this->StopBtn->UseVisualStyleBackColor = true;
			this->StopBtn->Click += gcnew System::EventHandler(this, &APIwindow::Stop_Click);
			// 
			// ResumeBtn
			// 
			this->ResumeBtn->Location = System::Drawing::Point(343, 140);
			this->ResumeBtn->Name = L"ResumeBtn";
			this->ResumeBtn->Size = System::Drawing::Size(75, 23);
			this->ResumeBtn->TabIndex = 3;
			this->ResumeBtn->Text = L"Resume";
			this->ResumeBtn->UseVisualStyleBackColor = true;
			// 
			// APIwindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(512, 303);
			this->Controls->Add(this->ResumeBtn);
			this->Controls->Add(this->StopBtn);
			this->Controls->Add(this->PauseBtn);
			this->Controls->Add(this->PlayBtn);
			this->Name = L"APIwindow";
			this->Text = L"APIwindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Play_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Play(MUSIC_01);
	}

	private: System::Void Stop_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}

};
}
