#pragma once

#include <msclr\marshal_cppstd.h>	//to convert system::string to std::string

namespace PicMan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;  //to convert system::string to std::string

	/// <summary>
	/// Summary for PicForm
	/// </summary>
	public ref class PicForm : public System::Windows::Forms::Form
	{
	public:
		PicForm(void)
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
		~PicForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ sourcePictureBox;
	private: System::Windows::Forms::TextBox^ fileTextBox;
	private: System::Windows::Forms::Button^ GetImageButton;
	private: System::Windows::Forms::PictureBox^ ResultPictureBox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:


	protected:

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
			this->sourcePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->fileTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GetImageButton = (gcnew System::Windows::Forms::Button());
			this->ResultPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sourcePictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// sourcePictureBox
			// 
			this->sourcePictureBox->Location = System::Drawing::Point(22, 60);
			this->sourcePictureBox->Name = L"sourcePictureBox";
			this->sourcePictureBox->Size = System::Drawing::Size(294, 209);
			this->sourcePictureBox->TabIndex = 0;
			this->sourcePictureBox->TabStop = false;
			// 
			// fileTextBox
			// 
			this->fileTextBox->Location = System::Drawing::Point(22, 13);
			this->fileTextBox->Name = L"fileTextBox";
			this->fileTextBox->Size = System::Drawing::Size(750, 20);
			this->fileTextBox->TabIndex = 1;
			// 
			// GetImageButton
			// 
			this->GetImageButton->Location = System::Drawing::Point(340, 96);
			this->GetImageButton->Name = L"GetImageButton";
			this->GetImageButton->Size = System::Drawing::Size(75, 23);
			this->GetImageButton->TabIndex = 2;
			this->GetImageButton->Text = L"Get Image";
			this->GetImageButton->UseVisualStyleBackColor = true;
			this->GetImageButton->Click += gcnew System::EventHandler(this, &PicForm::GetImageButton_Click);
			// 
			// ResultPictureBox
			// 
			this->ResultPictureBox->Location = System::Drawing::Point(478, 60);
			this->ResultPictureBox->Name = L"ResultPictureBox";
			this->ResultPictureBox->Size = System::Drawing::Size(294, 209);
			this->ResultPictureBox->TabIndex = 3;
			this->ResultPictureBox->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(363, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Process";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PicForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(382, 151);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Quit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PicForm::button2_Click);
			// 
			// PicForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 462);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ResultPictureBox);
			this->Controls->Add(this->GetImageButton);
			this->Controls->Add(this->fileTextBox);
			this->Controls->Add(this->sourcePictureBox);
			this->Name = L"PicForm";
			this->Text = L"PicForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sourcePictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GetImageButton_Click(System::Object^ sender, System::EventArgs^ e) {
		//Define an object to store the filename's characteristics
		OpenFileDialog^ ofd;
		ofd = gcnew OpenFileDialog;

		// Define file types to be displayed in the dialog
		ofd->Filter = "PNG Files(*.png)|*.png|""All Files (*.*)|*.*";

		//Identfy the default file type to be displayed
		ofd->FilterIndex = 1;

		// Display the caption for the Open File Dialog box
		ofd->Title = "Select the PNG Image file";

		// Display the Open File Dialog
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// Clear the the fileNameBox
			this->fileTextBox->Clear();

			// Copy the file name in the fileNameBox
			this->fileTextBox->Text = ofd->FileName;

			// Lod the selected image into the originalPictureBox
			sourcePictureBox->Load(ofd->FileName);

			//Stretch the image selected in ofd
			sourcePictureBox->SizeMode = PictureBoxSizeMode::StretchImage;

			// Hide the picture from the ResultPictureBox
			ResultPictureBox->Hide();


			// We'll create a tiny png file to put into the ResultPictureBox
			// so it could release NewImage.png to edit the file when a 
			// new image is loaded into the sourcePictureBox
			pngwriter* point = new pngwriter(2, 2, 0.7, "pixel.png");
			point->plot(1, 1, .7, .7, .7);
			point->close();

			// Hide the ResultPictureBox when a new image has been selected
			// for sourcePictureBox
			ResultPictureBox->Load("pixel.png");
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// If NewImage.png exists, delete it
	delete this->ResultPictureBox->Image;
	ResultPictureBox->Refresh();

	// Get the file name from the TextBox
	char* imageFile = (char*)(void*)Marshal::StringToHGlobalAnsi(fileTextBox->Text);

	pngwriter* sourceImage = new pngwriter();

	sourceImage->readfromfile(imageFile);
	int width, height, red, green, blue;
	width = sourceImage->getwidth();
	height = sourceImage->getheight();

	pngwriter* processImage = new pngwriter(width, height, 1.0, "NewImage.png");
	processImage->clear();

	for (int x = 1; x <= width; x++)
	{
		for (int y = 1; y <= height; y++)
		{
			red = sourceImage->read(x, y, 1);
			green = sourceImage->read(x, y, 2);
			blue = sourceImage->read(x, y, 3);

			processImage->plot(x, y, blue, green, red);
		}
	}

	processImage->close();
	sourceImage->close();

	ResultPictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
	ResultPictureBox->Load("NewImage.png");

	// Show the ResultPictureBox again
	ResultPictureBox->Show();

}
};
}
