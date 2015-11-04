#pragma once

namespace CLRSketcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PenDialog
	/// </summary>
	public ref class PenDialog : public System::Windows::Forms::Form
	{
	public:
		PenDialog(void)
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
		~PenDialog()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::GroupBox^  groupBox1;
  protected: 
  private: System::Windows::Forms::RadioButton^  penWidthButton6;
  private: System::Windows::Forms::RadioButton^  penWidthButton5;
  private: System::Windows::Forms::RadioButton^  penWidthButton4;
  private: System::Windows::Forms::RadioButton^  penWidthButton3;
  private: System::Windows::Forms::RadioButton^  penWidthButton2;
  private: System::Windows::Forms::RadioButton^  penWidthButton1;
  private: System::Windows::Forms::Button^  penWidthOK;
  private: System::Windows::Forms::Button^  penWidthCancel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

public:
    property float PenWidth
    {
      float get()
      {
        if(penWidthButton1->Checked)
          return 1.0f;
        if(penWidthButton2->Checked)
          return 2.0f;
        if(penWidthButton3->Checked)
          return 3.0f;
        if(penWidthButton4->Checked)
          return 4.0f;
        if(penWidthButton5->Checked)
          return 5.0f;
        return 6.0f;
      }
    }


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
      this->penWidthButton1 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton2 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton3 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton4 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton5 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthButton6 = (gcnew System::Windows::Forms::RadioButton());
      this->penWidthOK = (gcnew System::Windows::Forms::Button());
      this->penWidthCancel = (gcnew System::Windows::Forms::Button());
      this->groupBox1->SuspendLayout();
      this->SuspendLayout();
      // 
      // groupBox1
      // 
      this->groupBox1->Controls->Add(this->penWidthButton6);
      this->groupBox1->Controls->Add(this->penWidthButton5);
      this->groupBox1->Controls->Add(this->penWidthButton4);
      this->groupBox1->Controls->Add(this->penWidthButton3);
      this->groupBox1->Controls->Add(this->penWidthButton2);
      this->groupBox1->Controls->Add(this->penWidthButton1);
      this->groupBox1->Location = System::Drawing::Point(27, 12);
      this->groupBox1->Name = L"groupBox1";
      this->groupBox1->Size = System::Drawing::Size(265, 162);
      this->groupBox1->TabIndex = 0;
      this->groupBox1->TabStop = false;
      this->groupBox1->Text = L"Select Pen Width";
      // 
      // penWidthButton1
      // 
      this->penWidthButton1->AutoSize = true;
      this->penWidthButton1->Checked = true;
      this->penWidthButton1->Location = System::Drawing::Point(20, 31);
      this->penWidthButton1->Name = L"penWidthButton1";
      this->penWidthButton1->Size = System::Drawing::Size(84, 17);
      this->penWidthButton1->TabIndex = 0;
      this->penWidthButton1->TabStop = true;
      this->penWidthButton1->Text = L"Pen Width 1";
      this->penWidthButton1->UseVisualStyleBackColor = true;
      // 
      // penWidthButton2
      // 
      this->penWidthButton2->AutoSize = true;
      this->penWidthButton2->Location = System::Drawing::Point(20, 81);
      this->penWidthButton2->Name = L"penWidthButton2";
      this->penWidthButton2->Size = System::Drawing::Size(84, 17);
      this->penWidthButton2->TabIndex = 1;
      this->penWidthButton2->Text = L"Pen Width 2";
      this->penWidthButton2->UseVisualStyleBackColor = true;
      // 
      // penWidthButton3
      // 
      this->penWidthButton3->AutoSize = true;
      this->penWidthButton3->Location = System::Drawing::Point(20, 131);
      this->penWidthButton3->Name = L"penWidthButton3";
      this->penWidthButton3->Size = System::Drawing::Size(84, 17);
      this->penWidthButton3->TabIndex = 2;
      this->penWidthButton3->Text = L"Pen Width 3";
      this->penWidthButton3->UseVisualStyleBackColor = true;
      // 
      // penWidthButton4
      // 
      this->penWidthButton4->AutoSize = true;
      this->penWidthButton4->Location = System::Drawing::Point(145, 31);
      this->penWidthButton4->Name = L"penWidthButton4";
      this->penWidthButton4->Size = System::Drawing::Size(84, 17);
      this->penWidthButton4->TabIndex = 3;
      this->penWidthButton4->Text = L"Pen Width 4";
      this->penWidthButton4->UseVisualStyleBackColor = true;
      // 
      // penWidthButton5
      // 
      this->penWidthButton5->AutoSize = true;
      this->penWidthButton5->Location = System::Drawing::Point(145, 81);
      this->penWidthButton5->Name = L"penWidthButton5";
      this->penWidthButton5->Size = System::Drawing::Size(84, 17);
      this->penWidthButton5->TabIndex = 4;
      this->penWidthButton5->Text = L"Pen Width 5";
      this->penWidthButton5->UseVisualStyleBackColor = true;
      // 
      // penWidthButton6
      // 
      this->penWidthButton6->AutoSize = true;
      this->penWidthButton6->Location = System::Drawing::Point(145, 131);
      this->penWidthButton6->Name = L"penWidthButton6";
      this->penWidthButton6->Size = System::Drawing::Size(84, 17);
      this->penWidthButton6->TabIndex = 5;
      this->penWidthButton6->Text = L"Pen Width 6";
      this->penWidthButton6->UseVisualStyleBackColor = true;
      // 
      // penWidthOK
      // 
      this->penWidthOK->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->penWidthOK->Location = System::Drawing::Point(47, 190);
      this->penWidthOK->Name = L"penWidthOK";
      this->penWidthOK->Size = System::Drawing::Size(75, 23);
      this->penWidthOK->TabIndex = 1;
      this->penWidthOK->Text = L"OK";
      this->penWidthOK->UseVisualStyleBackColor = true;
      // 
      // penWidthCancel
      // 
      this->penWidthCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->penWidthCancel->Location = System::Drawing::Point(181, 190);
      this->penWidthCancel->Name = L"penWidthCancel";
      this->penWidthCancel->Size = System::Drawing::Size(75, 23);
      this->penWidthCancel->TabIndex = 2;
      this->penWidthCancel->Text = L"Cancel";
      this->penWidthCancel->UseVisualStyleBackColor = true;
      // 
      // PenDialog
      // 
      this->AcceptButton = this->penWidthOK;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->CancelButton = this->penWidthCancel;
      this->ClientSize = System::Drawing::Size(319, 239);
      this->ControlBox = false;
      this->Controls->Add(this->penWidthCancel);
      this->Controls->Add(this->penWidthOK);
      this->Controls->Add(this->groupBox1);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"PenDialog";
      this->Text = L"Set Pen Width";
      this->groupBox1->ResumeLayout(false);
      this->groupBox1->PerformLayout();
      this->ResumeLayout(false);

    }
#pragma endregion
	};
}
