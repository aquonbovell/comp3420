//  GUIForm.h
//  Project-02
//
//  Created by Aquon Bovell on 04/02/2024.
//  Student ID: 417002174
#pragma once
#include <msclr/marshal_cppstd.h>

namespace GUIpng {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for GUIForm
	/// </summary>
	public ref class GUIForm : public System::Windows::Forms::Form
	{
	public:
		GUIForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUIForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ filePath;
	private: System::Windows::Forms::PictureBox^ getImageBox;
	protected:

	protected:



	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ flipHorizontallyBox;
	private: System::Windows::Forms::PictureBox^ flipVerticallyBox;
	private: System::Windows::Forms::PictureBox^ removeGreenAndBlueBox;
	private: System::Windows::Forms::Button^ getImageBtn;
	private: System::Windows::Forms::Button^ flipHorizontallyBtn;
	private: System::Windows::Forms::Button^ flipVerticallyBtn;






	private: System::Windows::Forms::Button^ removeGreenAndBlueBtn;
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ flipHorizontallyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ flipVerticallyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeGreenAndBlueColoursToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quitToolStripMenuItem;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->filePath = (gcnew System::Windows::Forms::TextBox());
			this->getImageBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipHorizontallyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipVerticallyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeGreenAndBlueColoursToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipHorizontallyBox = (gcnew System::Windows::Forms::PictureBox());
			this->flipVerticallyBox = (gcnew System::Windows::Forms::PictureBox());
			this->removeGreenAndBlueBox = (gcnew System::Windows::Forms::PictureBox());
			this->getImageBtn = (gcnew System::Windows::Forms::Button());
			this->flipHorizontallyBtn = (gcnew System::Windows::Forms::Button());
			this->flipVerticallyBtn = (gcnew System::Windows::Forms::Button());
			this->removeGreenAndBlueBtn = (gcnew System::Windows::Forms::Button());
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->getImageBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flipHorizontallyBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flipVerticallyBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->removeGreenAndBlueBox))->BeginInit();
			this->SuspendLayout();
			// 
			// filePath
			// 
			this->filePath->Location = System::Drawing::Point(97, 0);
			this->filePath->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->filePath->Name = L"filePath";
			this->filePath->Size = System::Drawing::Size(662, 25);
			this->filePath->TabIndex = 0;
			// 
			// getImageBox
			// 
			this->getImageBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->getImageBox->Location = System::Drawing::Point(14, 35);
			this->getImageBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->getImageBox->Name = L"getImageBox";
			this->getImageBox->Size = System::Drawing::Size(300, 300);
			this->getImageBox->TabIndex = 1;
			this->getImageBox->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(772, 25);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->saveToolStripMenuItem,
					this->flipHorizontallyToolStripMenuItem, this->flipVerticallyToolStripMenuItem, this->removeGreenAndBlueColoursToolStripMenuItem,
					this->quitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 19);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->saveToolStripMenuItem->Text = L"Get Image";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIForm::getImageBtn_Click);
			// 
			// flipHorizontallyToolStripMenuItem
			// 
			this->flipHorizontallyToolStripMenuItem->Name = L"flipHorizontallyToolStripMenuItem";
			this->flipHorizontallyToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->flipHorizontallyToolStripMenuItem->Text = L"Flip Horizontally";
			this->flipHorizontallyToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIForm::flipHorizontallyBtn_Click);
			// 
			// flipVerticallyToolStripMenuItem
			// 
			this->flipVerticallyToolStripMenuItem->Name = L"flipVerticallyToolStripMenuItem";
			this->flipVerticallyToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->flipVerticallyToolStripMenuItem->Text = L"Flip Vertically";
			this->flipVerticallyToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIForm::flipVerticallyBtn_Click);
			// 
			// removeGreenAndBlueColoursToolStripMenuItem
			// 
			this->removeGreenAndBlueColoursToolStripMenuItem->Name = L"removeGreenAndBlueColoursToolStripMenuItem";
			this->removeGreenAndBlueColoursToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->removeGreenAndBlueColoursToolStripMenuItem->Text = L"Remove Green and Blue Colours";
			this->removeGreenAndBlueColoursToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIForm::removeGreenAndBlueBtn_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(244, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIForm::quitBtn_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 19);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIForm::aboutToolStripMenuItem_Click);
			// 
			// flipHorizontallyBox
			// 
			this->flipHorizontallyBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flipHorizontallyBox->Location = System::Drawing::Point(459, 35);
			this->flipHorizontallyBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->flipHorizontallyBox->Name = L"flipHorizontallyBox";
			this->flipHorizontallyBox->Size = System::Drawing::Size(300, 300);
			this->flipHorizontallyBox->TabIndex = 5;
			this->flipHorizontallyBox->TabStop = false;
			// 
			// flipVerticallyBox
			// 
			this->flipVerticallyBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flipVerticallyBox->Location = System::Drawing::Point(13, 384);
			this->flipVerticallyBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->flipVerticallyBox->Name = L"flipVerticallyBox";
			this->flipVerticallyBox->Size = System::Drawing::Size(300, 300);
			this->flipVerticallyBox->TabIndex = 6;
			this->flipVerticallyBox->TabStop = false;
			// 
			// removeGreenAndBlueBox
			// 
			this->removeGreenAndBlueBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->removeGreenAndBlueBox->Location = System::Drawing::Point(459, 384);
			this->removeGreenAndBlueBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->removeGreenAndBlueBox->Name = L"removeGreenAndBlueBox";
			this->removeGreenAndBlueBox->Size = System::Drawing::Size(300, 300);
			this->removeGreenAndBlueBox->TabIndex = 7;
			this->removeGreenAndBlueBox->TabStop = false;
			// 
			// getImageBtn
			// 
			this->getImageBtn->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->getImageBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->getImageBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->getImageBtn->Location = System::Drawing::Point(14, 345);
			this->getImageBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->getImageBtn->Name = L"getImageBtn";
			this->getImageBtn->Size = System::Drawing::Size(300, 29);
			this->getImageBtn->TabIndex = 8;
			this->getImageBtn->Text = L"Get Image";
			this->getImageBtn->UseVisualStyleBackColor = false;
			this->getImageBtn->Click += gcnew System::EventHandler(this, &GUIForm::getImageBtn_Click);
			// 
			// flipHorizontallyBtn
			// 
			this->flipHorizontallyBtn->Location = System::Drawing::Point(459, 345);
			this->flipHorizontallyBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->flipHorizontallyBtn->Name = L"flipHorizontallyBtn";
			this->flipHorizontallyBtn->Size = System::Drawing::Size(300, 29);
			this->flipHorizontallyBtn->TabIndex = 9;
			this->flipHorizontallyBtn->Text = L"Flip Horizontally";
			this->flipHorizontallyBtn->UseVisualStyleBackColor = true;
			this->flipHorizontallyBtn->Click += gcnew System::EventHandler(this, &GUIForm::flipHorizontallyBtn_Click);
			// 
			// flipVerticallyBtn
			// 
			this->flipVerticallyBtn->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->flipVerticallyBtn->ForeColor = System::Drawing::Color::White;
			this->flipVerticallyBtn->Location = System::Drawing::Point(14, 694);
			this->flipVerticallyBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->flipVerticallyBtn->Name = L"flipVerticallyBtn";
			this->flipVerticallyBtn->Size = System::Drawing::Size(299, 29);
			this->flipVerticallyBtn->TabIndex = 10;
			this->flipVerticallyBtn->Text = L"Flip Vertically";
			this->flipVerticallyBtn->UseVisualStyleBackColor = false;
			this->flipVerticallyBtn->Click += gcnew System::EventHandler(this, &GUIForm::flipVerticallyBtn_Click);
			// 
			// removeGreenAndBlueBtn
			// 
			this->removeGreenAndBlueBtn->BackColor = System::Drawing::Color::LightCoral;
			this->removeGreenAndBlueBtn->ForeColor = System::Drawing::Color::DimGray;
			this->removeGreenAndBlueBtn->Location = System::Drawing::Point(459, 694);
			this->removeGreenAndBlueBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->removeGreenAndBlueBtn->Name = L"removeGreenAndBlueBtn";
			this->removeGreenAndBlueBtn->Size = System::Drawing::Size(300, 29);
			this->removeGreenAndBlueBtn->TabIndex = 11;
			this->removeGreenAndBlueBtn->Text = L"Remove Green And Blue Color";
			this->removeGreenAndBlueBtn->UseVisualStyleBackColor = false;
			this->removeGreenAndBlueBtn->Click += gcnew System::EventHandler(this, &GUIForm::removeGreenAndBlueBtn_Click);
			// 
			// quitBtn
			// 
			this->quitBtn->BackColor = System::Drawing::Color::Red;
			this->quitBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->quitBtn->Location = System::Drawing::Point(344, 694);
			this->quitBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(88, 29);
			this->quitBtn->TabIndex = 12;
			this->quitBtn->Text = L"Quit";
			this->quitBtn->UseVisualStyleBackColor = false;
			this->quitBtn->Click += gcnew System::EventHandler(this, &GUIForm::quitBtn_Click);
			// 
			// GUIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 749);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->removeGreenAndBlueBtn);
			this->Controls->Add(this->flipVerticallyBtn);
			this->Controls->Add(this->flipHorizontallyBtn);
			this->Controls->Add(this->getImageBtn);
			this->Controls->Add(this->removeGreenAndBlueBox);
			this->Controls->Add(this->flipVerticallyBox);
			this->Controls->Add(this->flipHorizontallyBox);
			this->Controls->Add(this->getImageBox);
			this->Controls->Add(this->filePath);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"GUIForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GUIForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->getImageBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flipHorizontallyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flipVerticallyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->removeGreenAndBlueBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void getImageBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
	openFileDialog->Filter = "PNG Files|*.png|All Files|*.*";
	openFileDialog->Title = "Select a PNG Image File";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->filePath->Clear();
		this->filePath->Text = openFileDialog->FileName;
		this->getImageBox->Load(openFileDialog->FileName);
		this->getImageBox->SizeMode = PictureBoxSizeMode::StretchImage;

		pngwriter* point = new pngwriter(1, 1, 0.7, "pixel.png");
		point->plot(1, 1, 240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
		point->close();

		if (this->flipHorizontallyBox->Image != nullptr) {
			delete this->flipHorizontallyBox->Image;
			this->flipHorizontallyBox->Load("pixel.png");
		}
		if (this->flipVerticallyBox->Image != nullptr) {
			delete this->flipVerticallyBox->Image;
			flipVerticallyBox->Load("pixel.png");
		}
		if (this->removeGreenAndBlueBox->Image != nullptr) {
			delete this->removeGreenAndBlueBox->Image;
			removeGreenAndBlueBox->Load("pixel.png");
		}
	}
}
private: System::Void flipHorizontallyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Release resources of the previous image
	if (flipHorizontallyBox->Image != nullptr) {
		delete flipHorizontallyBox->Image;
	}
	pngwriter* source = new pngwriter();
	
	std::string nativeString = marshal_as<std::string>(filePath->Text);
	char* imgPath = new char[nativeString.size() + 1];
	std::strcpy(imgPath, nativeString.c_str());

	source->readfromfile(imgPath);
	int width = source->getwidth();
	int height = source->getheight();
	pngwriter* dest = new pngwriter(width, height, 0.7, "flippedH.png");
	 int red, green, blue;

	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
		{
			red = source->read(i, j, 1);
			green = source->read(i, j, 2);
			blue = source->read(i, j, 3);

			dest->plot(width - i + 1, j ,red, green , blue);
		}
	}
	dest->close();

	flipHorizontallyBox->Image = Image::FromFile("flippedH.png");
	flipHorizontallyBox->SizeMode = PictureBoxSizeMode::StretchImage;
}
private: System::Void flipVerticallyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Release resources of the previous image
	if (flipVerticallyBox->Image != nullptr) {
		delete flipVerticallyBox->Image;
	}
	pngwriter* source = new pngwriter();

	std::string nativeString = marshal_as<std::string>(filePath->Text);
	char* imgPath = new char[nativeString.size() + 1];
	std::strcpy(imgPath, nativeString.c_str());

	source->readfromfile(imgPath);
	int width = source->getwidth();
	int height = source->getheight();
	pngwriter* dest = new pngwriter(width, height, 0.7, "flippedV.png");
	int red, green, blue;

	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
		{
			red = source->read(i, j, 1);
			green = source->read(i, j, 2);
			blue = source->read(i, j, 3);

			dest->plot(i, height - j + 1, red, green, blue);
		}
	}
	dest->close();

	flipVerticallyBox->Image = Image::FromFile("flippedV.png");
	flipVerticallyBox->SizeMode = PictureBoxSizeMode::StretchImage;	
}
private: System::Void removeGreenAndBlueBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Release resources of the previous image
	if (removeGreenAndBlueBox->Image != nullptr) {
		delete removeGreenAndBlueBox->Image;	
	}
	pngwriter* source = new pngwriter();

	std::string nativeString = marshal_as<std::string>(filePath->Text);
	char* imgPath = new char[nativeString.size() + 1];
	std::strcpy(imgPath, nativeString.c_str());

	source->readfromfile(imgPath);
	int width = source->getwidth();
	int height = source->getheight();
	pngwriter* dest = new pngwriter(width, height, 0.7, "grayScaleWRed.png");
	double hue, sat, val , gray;

	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
		{
			hue = source->dreadHSV(i, j, 1);
			sat = source->dreadHSV(i, j, 2);
			val = source->dreadHSV(i, j, 3);
			if (hue > 25.0 / 360.0 && hue < 330.0 / 360.0) {
				gray = source->dread(i, j);
				dest->plot(i, j, gray, gray, gray);
			}	
			else {
			dest->plotHSV(i, j, hue, sat, val);
			}
		}
	}
	dest->close();

	removeGreenAndBlueBox->Image = Image::FromFile("grayScaleWRed.png");
	removeGreenAndBlueBox->SizeMode = PictureBoxSizeMode::StretchImage;
}
private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Meet Aquon Bovell (ID: 417002174) – a computer science and mathematics student mastering the realms of Java, Python, C++, HTML, CSS, and JavaScript. I've navigated successful projects, from boosting local businesses with sleek websites to developing a savvy mobile app for a non-profit organization.\n\nAs the lead programmer, I'm behind a cutting-edge tool for Windows 10 (v10.0.226210) and Visual Studio 2015 (v140) that lets users flexibly manipulate PNG files. Load, display, flip – it's all at your fingertips.What sets it apart ? The power to surgically remove green and blue channels, leaving the red untouched – a game - changer in image editing.\n\nThis program doesn't just talk tech; it walks the user-friendly walk. C++, WindowsForm, pngwriter, freetype, and PNG form the tech orchestra ensuring a seamless experience.\n\nMy journey isn't just about code – it's about impact.Crafting digital footprints for local businesses and steering non - profits towards their goals is my forte.\n\nEager for the next challenge, my commitment to clean code and user - centric design propels me forward.Ready for excellence ? Let's code the future, innovatively and impactfully.","About", MessageBoxButtons::OK,
		MessageBoxIcon::Information);
}
};
}
