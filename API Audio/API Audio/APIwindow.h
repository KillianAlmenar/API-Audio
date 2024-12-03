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
	using namespace System::IO;
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
	private: System::Windows::Forms::Button^ ExportPlaylistButton;
	private: System::Windows::Forms::Button^ ImportPlaylistButton;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(APIwindow::typeid));
			this->PlayBtn = (gcnew System::Windows::Forms::Button());
			this->PauseBtn = (gcnew System::Windows::Forms::Button());
			this->StopBtn = (gcnew System::Windows::Forms::Button());
			this->ResumeBtn = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->OpenButton = (gcnew System::Windows::Forms::Button());
			this->VolumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->previousButton = (gcnew System::Windows::Forms::Button());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->ExportPlaylistButton = (gcnew System::Windows::Forms::Button());
			this->ImportPlaylistButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VolumeBar))->BeginInit();
			this->SuspendLayout();
			// 
			// PlayBtn
			// 
			this->PlayBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PlayBtn.BackgroundImage")));
			this->PlayBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PlayBtn->Location = System::Drawing::Point(12, 235);
			this->PlayBtn->Name = L"PlayBtn";
			this->PlayBtn->Size = System::Drawing::Size(45, 36);
			this->PlayBtn->TabIndex = 0;
			this->PlayBtn->UseVisualStyleBackColor = true;
			this->PlayBtn->Click += gcnew System::EventHandler(this, &APIwindow::Play_Click);
			// 
			// PauseBtn
			// 
			this->PauseBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PauseBtn.BackgroundImage")));
			this->PauseBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PauseBtn->Location = System::Drawing::Point(63, 235);
			this->PauseBtn->Name = L"PauseBtn";
			this->PauseBtn->Size = System::Drawing::Size(43, 36);
			this->PauseBtn->TabIndex = 1;
			this->PauseBtn->UseVisualStyleBackColor = true;
			this->PauseBtn->Click += gcnew System::EventHandler(this, &APIwindow::PauseBtn_Click);
			// 
			// StopBtn
			// 
			this->StopBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StopBtn.BackgroundImage")));
			this->StopBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->StopBtn->Location = System::Drawing::Point(193, 235);
			this->StopBtn->Name = L"StopBtn";
			this->StopBtn->Size = System::Drawing::Size(41, 36);
			this->StopBtn->TabIndex = 2;
			this->StopBtn->UseVisualStyleBackColor = true;
			this->StopBtn->Click += gcnew System::EventHandler(this, &APIwindow::Stop_Click);
			// 
			// ResumeBtn
			// 
			this->ResumeBtn->Location = System::Drawing::Point(112, 242);
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
			// label1
			// 
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(109, 142);
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
			this->previousButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"previousButton.BackgroundImage")));
			this->previousButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->previousButton->Location = System::Drawing::Point(335, 13);
			this->previousButton->Name = L"previousButton";
			this->previousButton->Size = System::Drawing::Size(41, 38);
			this->previousButton->TabIndex = 11;
			this->previousButton->UseVisualStyleBackColor = true;
			this->previousButton->Click += gcnew System::EventHandler(this, &APIwindow::previousButton_Click);
			// 
			// nextButton
			// 
			this->nextButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextButton.BackgroundImage")));
			this->nextButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->nextButton->Location = System::Drawing::Point(382, 13);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(41, 38);
			this->nextButton->TabIndex = 12;
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &APIwindow::nextButton_Click);
			// 
			// ExportPlaylistButton
			// 
			this->ExportPlaylistButton->Location = System::Drawing::Point(93, 13);
			this->ExportPlaylistButton->Name = L"ExportPlaylistButton";
			this->ExportPlaylistButton->Size = System::Drawing::Size(82, 29);
			this->ExportPlaylistButton->TabIndex = 13;
			this->ExportPlaylistButton->Text = L"Export Playlist";
			this->ExportPlaylistButton->UseVisualStyleBackColor = true;
			this->ExportPlaylistButton->Click += gcnew System::EventHandler(this, &APIwindow::ExportPlaylistButton_Click);
			// 
			// ImportPlaylistButton
			// 
			this->ImportPlaylistButton->Location = System::Drawing::Point(181, 13);
			this->ImportPlaylistButton->Name = L"ImportPlaylistButton";
			this->ImportPlaylistButton->Size = System::Drawing::Size(82, 29);
			this->ImportPlaylistButton->TabIndex = 14;
			this->ImportPlaylistButton->Text = L"Import Playlist";
			this->ImportPlaylistButton->UseVisualStyleBackColor = true;
			this->ImportPlaylistButton->Click += gcnew System::EventHandler(this, &APIwindow::ImportPlaylistButton_Click);
			// 
			// APIwindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(512, 303);
			this->Controls->Add(this->ImportPlaylistButton);
			this->Controls->Add(this->ExportPlaylistButton);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->previousButton);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
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
		openFileDialog->Filter = "Fichiers WAV (*.wav)|*.wav";

		openFileDialog->ShowDialog();

		String^ filePath = openFileDialog->FileName;

		int splitSize = filePath->Split('\\')->Length;

		Playlist->Add(filePath);

		label1->Text = filePath->Split('\\')[splitSize - 1];

		richTextBox1->AppendText(label1->Text + "\n");
	}
	private: System::Void nextButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (Playlist->Count <= 0)
		{
			return;
		}
		currentSong++;

		if (currentSong >= Playlist->Count)
		{
			currentSong = Playlist->Count - 1;
		}

		String^ managedString = Playlist[currentSong];
		std::string stdString = msclr::interop::marshal_as<std::string>(managedString);
		const char* word = stdString.c_str();

		Play(word);

		SetVolume(VolumeBar->Value);
		int splitSize = Playlist[currentSong]->Split('\\')->Length;
		label1->Text = Playlist[currentSong]->Split('\\')[splitSize - 1];
	}
	private: System::Void previousButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (Playlist->Count <= 0)
		{
			return;
		}
		currentSong--;

		if (currentSong < 0) currentSong = 0;

		String^ managedString = Playlist[currentSong];
		std::string stdString = msclr::interop::marshal_as<std::string>(managedString);
		const char* word = stdString.c_str();

		Play(word);
		SetVolume(VolumeBar->Value);
		int splitSize = Playlist[currentSong]->Split('\\')->Length;
		label1->Text = Playlist[currentSong]->Split('\\')[splitSize - 1];
	}

	private: System::Void ExportPlaylistButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Créer une instance de SaveFileDialog
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

		// Configuration du SaveFileDialog
		saveFileDialog->Filter = "Fichiers texte (*.txt)|*.txt"; // Types de fichiers pris en charge
		saveFileDialog->Title = "Enregistrer la playlist";
		saveFileDialog->FileName = "playlist.txt"; // Nom de fichier par défaut


		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = saveFileDialog->FileName; // Récupère le chemin choisi

			StreamWriter^ writer = nullptr; // Déclare le StreamWriter en dehors du try
			try {
				// Initialisation du StreamWriter
				writer = gcnew StreamWriter(filePath);

				// Écrit chaque ligne de la liste dans le fichier
				for each (String ^ song in Playlist) {
					writer->WriteLine(song);
				}

				// Message de confirmation
				MessageBox::Show("Playlist exportée avec succès dans : " + filePath,
					"Exportation réussie", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				// Gestion des erreurs
				MessageBox::Show("Erreur lors de l'exportation : " + ex->Message,
					"Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				// Fermeture explicite du StreamWriter
				if (writer != nullptr) {
					writer->Close();
				}
			}
		}
	}


	private: System::Void ImportPlaylistButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Créer une instance de OpenFileDialog
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

		// Configuration de l'OpenFileDialog
		openFileDialog->Filter = "Fichiers texte (*.txt)|*.txt"; // Types de fichiers pris en charge
		openFileDialog->Title = "Importer une playlist";

		// Afficher le dialogue et vérifier si l'utilisateur a sélectionné un fichier
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = openFileDialog->FileName; // Récupère le chemin complet du fichier sélectionné

			StreamReader^ reader = nullptr; // Déclare le StreamReader en dehors du try
			try {
				// Initialisation du StreamReader
				reader = gcnew StreamReader(filePath);

				// Nettoyer la liste avant d'importer les nouvelles lignes
				Playlist->Clear();

				// Lire chaque ligne du fichier et l'ajouter à la liste
				String^ line;
				while ((line = reader->ReadLine()) != nullptr) {
					Playlist->Add(line);
					int splitSize = line->Split('\\')->Length;
					richTextBox1->AppendText(line->Split('\\')[splitSize - 1] + "\n");
				}

				// Message de confirmation
				MessageBox::Show("Playlist importée avec succès depuis : " + filePath,
					"Importation réussie", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				// Gestion des erreurs
				MessageBox::Show("Erreur lors de l'importation : " + ex->Message,
					"Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				// Fermeture explicite du StreamReader
				if (reader != nullptr) {
					reader->Close();
				}
			}
		}

		int splitSize = Playlist[currentSong]->Split('\\')->Length;
		label1->Text = Playlist[currentSong]->Split('\\')[splitSize - 1];

	}

	};
}
