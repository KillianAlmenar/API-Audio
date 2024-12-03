#include "Player.h"
#include <vector>
#include <array>
#include <msclr/marshal_cppstd.h>
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
	/// 

	public ref class APIwindow : public System::Windows::Forms::Form
	{
	private:
		System::Collections::Generic::List<String^>^ Playlist = gcnew System::Collections::Generic::List<String^>();
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ previousButton;
	private: System::Windows::Forms::Button^ nextButton;

		   int currentSong = 0;

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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ OpenButton;
	private: System::Windows::Forms::TrackBar^ VolumeBar;


	private: System::Windows::Forms::ProgressBar^ ProgressBar;
	private: System::Windows::Forms::Label^ label1;

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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->OpenButton = (gcnew System::Windows::Forms::Button());
			this->VolumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->ProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->previousButton = (gcnew System::Windows::Forms::Button());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VolumeBar))->BeginInit();
			this->SuspendLayout();
			// 
			// PlayBtn
			// 
			this->PlayBtn->Location = System::Drawing::Point(12, 248);
			this->PlayBtn->Name = L"PlayBtn";
			this->PlayBtn->Size = System::Drawing::Size(75, 23);
			this->PlayBtn->TabIndex = 0;
			this->PlayBtn->Text = L"Play";
			this->PlayBtn->UseVisualStyleBackColor = true;
			this->PlayBtn->Click += gcnew System::EventHandler(this, &APIwindow::Play_Click);
			// 
			// PauseBtn
			// 
			this->PauseBtn->Location = System::Drawing::Point(93, 248);
			this->PauseBtn->Name = L"PauseBtn";
			this->PauseBtn->Size = System::Drawing::Size(75, 23);
			this->PauseBtn->TabIndex = 1;
			this->PauseBtn->Text = L"Pause";
			this->PauseBtn->UseVisualStyleBackColor = true;
			this->PauseBtn->Click += gcnew System::EventHandler(this, &APIwindow::PauseBtn_Click);
			// 
			// StopBtn
			// 
			this->StopBtn->Location = System::Drawing::Point(255, 248);
			this->StopBtn->Name = L"StopBtn";
			this->StopBtn->Size = System::Drawing::Size(75, 23);
			this->StopBtn->TabIndex = 2;
			this->StopBtn->Text = L"Stop";
			this->StopBtn->UseVisualStyleBackColor = true;
			this->StopBtn->Click += gcnew System::EventHandler(this, &APIwindow::Stop_Click);
			// 
			// ResumeBtn
			// 
			this->ResumeBtn->Location = System::Drawing::Point(174, 248);
			this->ResumeBtn->Name = L"ResumeBtn";
			this->ResumeBtn->Size = System::Drawing::Size(75, 23);
			this->ResumeBtn->TabIndex = 3;
			this->ResumeBtn->Text = L"Resume";
			this->ResumeBtn->UseVisualStyleBackColor = true;
			this->ResumeBtn->Click += gcnew System::EventHandler(this, &APIwindow::ResumeBtn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// OpenButton
			// 
			this->OpenButton->Location = System::Drawing::Point(12, 12);
			this->OpenButton->Name = L"OpenButton";
			this->OpenButton->Size = System::Drawing::Size(75, 30);
			this->OpenButton->TabIndex = 4;
			this->OpenButton->Text = L"Open";
			this->OpenButton->UseVisualStyleBackColor = true;
			this->OpenButton->Click += gcnew System::EventHandler(this, &APIwindow::OpenButton_Click);
			// 
			// VolumeBar
			// 
			this->VolumeBar->Location = System::Drawing::Point(12, 60);
			this->VolumeBar->Maximum = 100;
			this->VolumeBar->Name = L"VolumeBar";
			this->VolumeBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->VolumeBar->Size = System::Drawing::Size(45, 169);
			this->VolumeBar->TabIndex = 5;
			this->VolumeBar->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->VolumeBar->Value = 100;
			this->VolumeBar->Scroll += gcnew System::EventHandler(this, &APIwindow::VolumeBar_Scroll);
			// 
			// ProgressBar
			// 
			this->ProgressBar->Location = System::Drawing::Point(83, 205);
			this->ProgressBar->Name = L"ProgressBar";
			this->ProgressBar->Size = System::Drawing::Size(149, 14);
			this->ProgressBar->Step = 1;
			this->ProgressBar->TabIndex = 8;
			this->ProgressBar->Value = 50;
			// 
			// label1
			// 
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(85, 60);
			this->label1->MaximumSize = System::Drawing::Size(150, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"song name";
			this->label1->Click += gcnew System::EventHandler(this, &APIwindow::label1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(255, 57);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(245, 172);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"";
			// 
			// previousButton
			// 
			this->previousButton->Location = System::Drawing::Point(292, 28);
			this->previousButton->Name = L"previousButton";
			this->previousButton->Size = System::Drawing::Size(75, 23);
			this->previousButton->TabIndex = 11;
			this->previousButton->Text = L"previous";
			this->previousButton->UseVisualStyleBackColor = true;
			this->previousButton->Click += gcnew System::EventHandler(this, &APIwindow::previousButton_Click);
			// 
			// nextButton
			// 
			this->nextButton->Location = System::Drawing::Point(383, 28);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(75, 23);
			this->nextButton->TabIndex = 12;
			this->nextButton->Text = L"next";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &APIwindow::nextButton_Click);
			// 
			// APIwindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(512, 303);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->previousButton);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ProgressBar);
			this->Controls->Add(this->VolumeBar);
			this->Controls->Add(this->OpenButton);
			this->Controls->Add(this->ResumeBtn);
			this->Controls->Add(this->StopBtn);
			this->Controls->Add(this->PauseBtn);
			this->Controls->Add(this->PlayBtn);
			this->Name = L"APIwindow";
			this->Text = L"API OpenAL";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VolumeBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Play_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ managedString = Playlist[currentSong];
		std::string stdString = msclr::interop::marshal_as<std::string>(managedString);
		const char* word = stdString.c_str();

		Play(word);
	}

	private: System::Void Stop_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Stop();
	}

	private: System::Void PauseBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Pause();
	}

	private: System::Void ResumeBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Resume();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}

	private: System::Void VolumeBar_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		SetVolume(VolumeBar->Value);
	}
	private: System::Void OpenButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Tous les fichiers (*.*)|*.*|Fichiers WAV (*.wav)|*.wav";

		openFileDialog->ShowDialog();

		String^ filePath = openFileDialog->FileName;

		int splitSize = filePath->Split('\\')->Length;

		Playlist->Add(filePath);

		label1->Text = filePath->Split('\\')[splitSize - 1];

		richTextBox1->AppendText(filePath);
	}
	private: System::Void nextButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		currentSong++;

		String^ managedString = Playlist[currentSong];
		std::string stdString = msclr::interop::marshal_as<std::string>(managedString);
		const char* word = stdString.c_str();

		Play(word);
	}
	private: System::Void previousButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		currentSong--;

		String^ managedString = Playlist[currentSong];
		std::string stdString = msclr::interop::marshal_as<std::string>(managedString);
		const char* word = stdString.c_str();

		Play(word);
	}
	};
}
