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
	protected:

	private: System::Windows::Forms::Button^ Pause;
	private: System::Windows::Forms::Button^ Stop;
	private: System::Windows::Forms::Button^ Resume;
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
			this->Pause = (gcnew System::Windows::Forms::Button());
			this->Stop = (gcnew System::Windows::Forms::Button());
			this->Resume = (gcnew System::Windows::Forms::Button());
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
			// Pause
			// 
			this->Pause->Location = System::Drawing::Point(219, 140);
			this->Pause->Name = L"Pause";
			this->Pause->Size = System::Drawing::Size(75, 23);
			this->Pause->TabIndex = 1;
			this->Pause->Text = L"Pause";
			this->Pause->UseVisualStyleBackColor = true;
			// 
			// Stop
			// 
			this->Stop->Location = System::Drawing::Point(343, 213);
			this->Stop->Name = L"Stop";
			this->Stop->Size = System::Drawing::Size(75, 23);
			this->Stop->TabIndex = 2;
			this->Stop->Text = L"Stop";
			this->Stop->UseVisualStyleBackColor = true;
			// 
			// Resume
			// 
			this->Resume->Location = System::Drawing::Point(343, 140);
			this->Resume->Name = L"Resume";
			this->Resume->Size = System::Drawing::Size(75, 23);
			this->Resume->TabIndex = 3;
			this->Resume->Text = L"Resume";
			this->Resume->UseVisualStyleBackColor = true;
			// 
			// APIwindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(512, 303);
			this->Controls->Add(this->Resume);
			this->Controls->Add(this->Stop);
			this->Controls->Add(this->Pause);
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
	};
}
