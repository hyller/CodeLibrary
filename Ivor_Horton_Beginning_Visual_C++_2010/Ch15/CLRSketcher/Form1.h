#pragma once

namespace CLRSketcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

  enum class ElementType {LINE, RECTANGLE, CIRCLE, CURVE};

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
    Form1(void) : elementType(ElementType::LINE), color(Color::Black)
    {
			InitializeComponent();
			//
			SetElementTypeButtonsState();
      SetColorButtonsState();
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::MenuStrip^  menuStrip1;
  protected: 
  private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
  private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
  private: System::Windows::Forms::ToolStripMenuItem^  printToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  printPreviewToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
  private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
  private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
  private: System::Windows::Forms::ToolStripMenuItem^  selectAllToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  customizeToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  elementToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  lineToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  rectangleToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  curveToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  colorToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blackToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  redToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  greenToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blueToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  contentsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  indexToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
  private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
  private: System::Windows::Forms::ToolStrip^  toolStrip1;
  private: System::Windows::Forms::ToolStripButton^  newToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  openToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  printToolStripButton;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
  private: System::Windows::Forms::ToolStripButton^  toolStripLineButton;
  private: System::Windows::Forms::ToolStripButton^  toolStripRectangleButton;
  private: System::Windows::Forms::ToolStripButton^  toolStripCircleButton;
  private: System::Windows::Forms::ToolStripButton^  toolStripCurveButton;


  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
  private: System::Windows::Forms::ToolStripButton^  toolStripBlackButton;
  private: System::Windows::Forms::ToolStripButton^  toolStripRedButton;
  private: System::Windows::Forms::ToolStripButton^  toolStripGreenButton;
  private: System::Windows::Forms::ToolStripButton^  toolStripBlueButton;







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
      System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
      this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
      this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->printPreviewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->selectAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->customizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->elementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->lineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->curveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->redToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->greenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->contentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->indexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
      this->newToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->openToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->printToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripLineButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripRectangleButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripCircleButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripCurveButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripBlackButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripRedButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripGreenButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripBlueButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->menuStrip1->SuspendLayout();
      this->toolStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fileToolStripMenuItem, 
        this->editToolStripMenuItem, this->toolsToolStripMenuItem, this->elementToolStripMenuItem, this->colorToolStripMenuItem, this->helpToolStripMenuItem});
      this->menuStrip1->Location = System::Drawing::Point(0, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(484, 24);
      this->menuStrip1->TabIndex = 0;
      this->menuStrip1->Text = L"menuStrip1";
      // 
      // fileToolStripMenuItem
      // 
      this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->newToolStripMenuItem, 
        this->openToolStripMenuItem, this->toolStripSeparator, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator1, 
        this->printToolStripMenuItem, this->printPreviewToolStripMenuItem, this->toolStripSeparator2, this->exitToolStripMenuItem});
      this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
      this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
      this->fileToolStripMenuItem->Text = L"&File";
      // 
      // newToolStripMenuItem
      // 
      this->newToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripMenuItem.Image")));
      this->newToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
      this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
      this->newToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->newToolStripMenuItem->Text = L"&New";
      // 
      // openToolStripMenuItem
      // 
      this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripMenuItem.Image")));
      this->openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
      this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
      this->openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->openToolStripMenuItem->Text = L"&Open";
      // 
      // toolStripSeparator
      // 
      this->toolStripSeparator->Name = L"toolStripSeparator";
      this->toolStripSeparator->Size = System::Drawing::Size(143, 6);
      // 
      // saveToolStripMenuItem
      // 
      this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripMenuItem.Image")));
      this->saveToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
      this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
      this->saveToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->saveToolStripMenuItem->Text = L"&Save";
      // 
      // saveAsToolStripMenuItem
      // 
      this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
      this->saveAsToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->saveAsToolStripMenuItem->Text = L"Save &As";
      // 
      // toolStripSeparator1
      // 
      this->toolStripSeparator1->Name = L"toolStripSeparator1";
      this->toolStripSeparator1->Size = System::Drawing::Size(143, 6);
      // 
      // printToolStripMenuItem
      // 
      this->printToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printToolStripMenuItem.Image")));
      this->printToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
      this->printToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
      this->printToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->printToolStripMenuItem->Text = L"&Print";
      // 
      // printPreviewToolStripMenuItem
      // 
      this->printPreviewToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printPreviewToolStripMenuItem.Image")));
      this->printPreviewToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->printPreviewToolStripMenuItem->Name = L"printPreviewToolStripMenuItem";
      this->printPreviewToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->printPreviewToolStripMenuItem->Text = L"Print Pre&view";
      // 
      // toolStripSeparator2
      // 
      this->toolStripSeparator2->Name = L"toolStripSeparator2";
      this->toolStripSeparator2->Size = System::Drawing::Size(143, 6);
      // 
      // exitToolStripMenuItem
      // 
      this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
      this->exitToolStripMenuItem->Size = System::Drawing::Size(146, 22);
      this->exitToolStripMenuItem->Text = L"E&xit";
      // 
      // editToolStripMenuItem
      // 
      this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->undoToolStripMenuItem, 
        this->redoToolStripMenuItem, this->toolStripSeparator3, this->cutToolStripMenuItem, this->copyToolStripMenuItem, this->pasteToolStripMenuItem, 
        this->toolStripSeparator4, this->selectAllToolStripMenuItem});
      this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
      this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
      this->editToolStripMenuItem->Text = L"&Edit";
      // 
      // undoToolStripMenuItem
      // 
      this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
      this->undoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
      this->undoToolStripMenuItem->Size = System::Drawing::Size(144, 22);
      this->undoToolStripMenuItem->Text = L"&Undo";
      // 
      // redoToolStripMenuItem
      // 
      this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
      this->redoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
      this->redoToolStripMenuItem->Size = System::Drawing::Size(144, 22);
      this->redoToolStripMenuItem->Text = L"&Redo";
      // 
      // toolStripSeparator3
      // 
      this->toolStripSeparator3->Name = L"toolStripSeparator3";
      this->toolStripSeparator3->Size = System::Drawing::Size(141, 6);
      // 
      // cutToolStripMenuItem
      // 
      this->cutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cutToolStripMenuItem.Image")));
      this->cutToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
      this->cutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
      this->cutToolStripMenuItem->Size = System::Drawing::Size(144, 22);
      this->cutToolStripMenuItem->Text = L"Cu&t";
      // 
      // copyToolStripMenuItem
      // 
      this->copyToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copyToolStripMenuItem.Image")));
      this->copyToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
      this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
      this->copyToolStripMenuItem->Size = System::Drawing::Size(144, 22);
      this->copyToolStripMenuItem->Text = L"&Copy";
      // 
      // pasteToolStripMenuItem
      // 
      this->pasteToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pasteToolStripMenuItem.Image")));
      this->pasteToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
      this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
      this->pasteToolStripMenuItem->Size = System::Drawing::Size(144, 22);
      this->pasteToolStripMenuItem->Text = L"&Paste";
      // 
      // toolStripSeparator4
      // 
      this->toolStripSeparator4->Name = L"toolStripSeparator4";
      this->toolStripSeparator4->Size = System::Drawing::Size(141, 6);
      // 
      // selectAllToolStripMenuItem
      // 
      this->selectAllToolStripMenuItem->Name = L"selectAllToolStripMenuItem";
      this->selectAllToolStripMenuItem->Size = System::Drawing::Size(144, 22);
      this->selectAllToolStripMenuItem->Text = L"Select &All";
      // 
      // toolsToolStripMenuItem
      // 
      this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->customizeToolStripMenuItem, 
        this->optionsToolStripMenuItem});
      this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
      this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
      this->toolsToolStripMenuItem->Text = L"&Tools";
      // 
      // customizeToolStripMenuItem
      // 
      this->customizeToolStripMenuItem->Name = L"customizeToolStripMenuItem";
      this->customizeToolStripMenuItem->Size = System::Drawing::Size(130, 22);
      this->customizeToolStripMenuItem->Text = L"&Customize";
      // 
      // optionsToolStripMenuItem
      // 
      this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
      this->optionsToolStripMenuItem->Size = System::Drawing::Size(130, 22);
      this->optionsToolStripMenuItem->Text = L"&Options";
      // 
      // elementToolStripMenuItem
      // 
      this->elementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->lineToolStripMenuItem, 
        this->rectangleToolStripMenuItem, this->circleToolStripMenuItem, this->curveToolStripMenuItem});
      this->elementToolStripMenuItem->Name = L"elementToolStripMenuItem";
      this->elementToolStripMenuItem->Size = System::Drawing::Size(62, 20);
      this->elementToolStripMenuItem->Text = L"E&lement";
      this->elementToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &Form1::elementToolStripMenuItem_DropDownOpening);
      // 
      // lineToolStripMenuItem
      // 
      this->lineToolStripMenuItem->Name = L"lineToolStripMenuItem";
      this->lineToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
        | System::Windows::Forms::Keys::L));
      this->lineToolStripMenuItem->Size = System::Drawing::Size(199, 22);
      this->lineToolStripMenuItem->Text = L"Line";
      this->lineToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lineToolStripMenuItem_Click);
      // 
      // rectangleToolStripMenuItem
      // 
      this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
      this->rectangleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
        | System::Windows::Forms::Keys::R));
      this->rectangleToolStripMenuItem->Size = System::Drawing::Size(199, 22);
      this->rectangleToolStripMenuItem->Text = L"Rectangle";
      this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rectangleToolStripMenuItem_Click);
      // 
      // circleToolStripMenuItem
      // 
      this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
      this->circleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
        | System::Windows::Forms::Keys::C));
      this->circleToolStripMenuItem->Size = System::Drawing::Size(199, 22);
      this->circleToolStripMenuItem->Text = L"Circle";
      this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::circleToolStripMenuItem_Click);
      // 
      // curveToolStripMenuItem
      // 
      this->curveToolStripMenuItem->Name = L"curveToolStripMenuItem";
      this->curveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
        | System::Windows::Forms::Keys::U));
      this->curveToolStripMenuItem->Size = System::Drawing::Size(199, 22);
      this->curveToolStripMenuItem->Text = L"Curve";
      this->curveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::curveToolStripMenuItem_Click);
      // 
      // colorToolStripMenuItem
      // 
      this->colorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->blackToolStripMenuItem, 
        this->redToolStripMenuItem, this->greenToolStripMenuItem, this->blueToolStripMenuItem});
      this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
      this->colorToolStripMenuItem->Size = System::Drawing::Size(48, 20);
      this->colorToolStripMenuItem->Text = L"&Color";
      this->colorToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &Form1::colorToolStripMenuItem_DropDownOpening);
      // 
      // blackToolStripMenuItem
      // 
      this->blackToolStripMenuItem->Name = L"blackToolStripMenuItem";
      this->blackToolStripMenuItem->Size = System::Drawing::Size(105, 22);
      this->blackToolStripMenuItem->Text = L"Black";
      this->blackToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blackToolStripMenuItem_Click);
      // 
      // redToolStripMenuItem
      // 
      this->redToolStripMenuItem->Name = L"redToolStripMenuItem";
      this->redToolStripMenuItem->Size = System::Drawing::Size(105, 22);
      this->redToolStripMenuItem->Text = L"Red";
      this->redToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::redToolStripMenuItem_Click);
      // 
      // greenToolStripMenuItem
      // 
      this->greenToolStripMenuItem->Name = L"greenToolStripMenuItem";
      this->greenToolStripMenuItem->Size = System::Drawing::Size(105, 22);
      this->greenToolStripMenuItem->Text = L"Green";
      this->greenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::greenToolStripMenuItem_Click);
      // 
      // blueToolStripMenuItem
      // 
      this->blueToolStripMenuItem->Name = L"blueToolStripMenuItem";
      this->blueToolStripMenuItem->Size = System::Drawing::Size(105, 22);
      this->blueToolStripMenuItem->Text = L"Blue";
      this->blueToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blueToolStripMenuItem_Click);
      // 
      // helpToolStripMenuItem
      // 
      this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->contentsToolStripMenuItem, 
        this->indexToolStripMenuItem, this->searchToolStripMenuItem, this->toolStripSeparator5, this->aboutToolStripMenuItem});
      this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
      this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
      this->helpToolStripMenuItem->Text = L"&Help";
      // 
      // contentsToolStripMenuItem
      // 
      this->contentsToolStripMenuItem->Name = L"contentsToolStripMenuItem";
      this->contentsToolStripMenuItem->Size = System::Drawing::Size(122, 22);
      this->contentsToolStripMenuItem->Text = L"&Contents";
      // 
      // indexToolStripMenuItem
      // 
      this->indexToolStripMenuItem->Name = L"indexToolStripMenuItem";
      this->indexToolStripMenuItem->Size = System::Drawing::Size(122, 22);
      this->indexToolStripMenuItem->Text = L"&Index";
      // 
      // searchToolStripMenuItem
      // 
      this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
      this->searchToolStripMenuItem->Size = System::Drawing::Size(122, 22);
      this->searchToolStripMenuItem->Text = L"&Search";
      // 
      // toolStripSeparator5
      // 
      this->toolStripSeparator5->Name = L"toolStripSeparator5";
      this->toolStripSeparator5->Size = System::Drawing::Size(119, 6);
      // 
      // aboutToolStripMenuItem
      // 
      this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
      this->aboutToolStripMenuItem->Size = System::Drawing::Size(122, 22);
      this->aboutToolStripMenuItem->Text = L"&About...";
      // 
      // toolStrip1
      // 
      this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {this->newToolStripButton, 
        this->openToolStripButton, this->saveToolStripButton, this->printToolStripButton, this->toolStripSeparator6, this->toolStripLineButton, 
        this->toolStripRectangleButton, this->toolStripCircleButton, this->toolStripCurveButton, this->toolStripSeparator7, this->toolStripBlackButton, 
        this->toolStripRedButton, this->toolStripGreenButton, this->toolStripBlueButton});
      this->toolStrip1->Location = System::Drawing::Point(0, 24);
      this->toolStrip1->Name = L"toolStrip1";
      this->toolStrip1->Size = System::Drawing::Size(484, 25);
      this->toolStrip1->TabIndex = 1;
      this->toolStrip1->Text = L"toolStrip1";
      // 
      // newToolStripButton
      // 
      this->newToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->newToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripButton.Image")));
      this->newToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->newToolStripButton->Name = L"newToolStripButton";
      this->newToolStripButton->Size = System::Drawing::Size(23, 22);
      this->newToolStripButton->Text = L"&New";
      // 
      // openToolStripButton
      // 
      this->openToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->openToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripButton.Image")));
      this->openToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->openToolStripButton->Name = L"openToolStripButton";
      this->openToolStripButton->Size = System::Drawing::Size(23, 22);
      this->openToolStripButton->Text = L"&Open";
      // 
      // saveToolStripButton
      // 
      this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
      this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->saveToolStripButton->Name = L"saveToolStripButton";
      this->saveToolStripButton->Size = System::Drawing::Size(23, 22);
      this->saveToolStripButton->Text = L"&Save";
      // 
      // printToolStripButton
      // 
      this->printToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->printToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printToolStripButton.Image")));
      this->printToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->printToolStripButton->Name = L"printToolStripButton";
      this->printToolStripButton->Size = System::Drawing::Size(23, 22);
      this->printToolStripButton->Text = L"&Print";
      // 
      // toolStripSeparator6
      // 
      this->toolStripSeparator6->Name = L"toolStripSeparator6";
      this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripLineButton
      // 
      this->toolStripLineButton->BackColor = System::Drawing::SystemColors::Control;
      this->toolStripLineButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripLineButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripLineButton.Image")));
      this->toolStripLineButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripLineButton->Name = L"toolStripLineButton";
      this->toolStripLineButton->Size = System::Drawing::Size(23, 22);
      this->toolStripLineButton->Text = L"Lines";
      this->toolStripLineButton->ToolTipText = L"Draw lines";
      this->toolStripLineButton->Click += gcnew System::EventHandler(this, &Form1::lineToolStripMenuItem_Click);
      // 
      // toolStripRectangleButton
      // 
      this->toolStripRectangleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripRectangleButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripRectangleButton.Image")));
      this->toolStripRectangleButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripRectangleButton->Name = L"toolStripRectangleButton";
      this->toolStripRectangleButton->Size = System::Drawing::Size(23, 22);
      this->toolStripRectangleButton->Text = L"Rectangles";
      this->toolStripRectangleButton->ToolTipText = L"Draw rectangles";
      this->toolStripRectangleButton->Click += gcnew System::EventHandler(this, &Form1::rectangleToolStripMenuItem_Click);
      // 
      // toolStripCircleButton
      // 
      this->toolStripCircleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripCircleButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripCircleButton.Image")));
      this->toolStripCircleButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripCircleButton->Name = L"toolStripCircleButton";
      this->toolStripCircleButton->Size = System::Drawing::Size(23, 22);
      this->toolStripCircleButton->Text = L"Circles";
      this->toolStripCircleButton->ToolTipText = L"Draw circles";
      this->toolStripCircleButton->Click += gcnew System::EventHandler(this, &Form1::circleToolStripMenuItem_Click);
      // 
      // toolStripCurveButton
      // 
      this->toolStripCurveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripCurveButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripCurveButton.Image")));
      this->toolStripCurveButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripCurveButton->Name = L"toolStripCurveButton";
      this->toolStripCurveButton->Size = System::Drawing::Size(23, 22);
      this->toolStripCurveButton->Text = L"Curves";
      this->toolStripCurveButton->ToolTipText = L"Draw curves";
      this->toolStripCurveButton->Click += gcnew System::EventHandler(this, &Form1::curveToolStripMenuItem_Click);
      // 
      // toolStripSeparator7
      // 
      this->toolStripSeparator7->Name = L"toolStripSeparator7";
      this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripBlackButton
      // 
      this->toolStripBlackButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripBlackButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripBlackButton.Image")));
      this->toolStripBlackButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripBlackButton->Name = L"toolStripBlackButton";
      this->toolStripBlackButton->Size = System::Drawing::Size(23, 22);
      this->toolStripBlackButton->Text = L"Black";
      this->toolStripBlackButton->ToolTipText = L"Draw in black";
      this->toolStripBlackButton->Click += gcnew System::EventHandler(this, &Form1::blackToolStripMenuItem_Click);
      // 
      // toolStripRedButton
      // 
      this->toolStripRedButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripRedButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripRedButton.Image")));
      this->toolStripRedButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripRedButton->Name = L"toolStripRedButton";
      this->toolStripRedButton->Size = System::Drawing::Size(23, 22);
      this->toolStripRedButton->Text = L"Red";
      this->toolStripRedButton->ToolTipText = L"Draw in red";
      this->toolStripRedButton->Click += gcnew System::EventHandler(this, &Form1::redToolStripMenuItem_Click);
      // 
      // toolStripGreenButton
      // 
      this->toolStripGreenButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripGreenButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripGreenButton.Image")));
      this->toolStripGreenButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripGreenButton->Name = L"toolStripGreenButton";
      this->toolStripGreenButton->Size = System::Drawing::Size(23, 22);
      this->toolStripGreenButton->Text = L"Green";
      this->toolStripGreenButton->ToolTipText = L"Draw in green";
      this->toolStripGreenButton->Click += gcnew System::EventHandler(this, &Form1::greenToolStripMenuItem_Click);
      // 
      // toolStripBlueButton
      // 
      this->toolStripBlueButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripBlueButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripBlueButton.Image")));
      this->toolStripBlueButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripBlueButton->Name = L"toolStripBlueButton";
      this->toolStripBlueButton->Size = System::Drawing::Size(23, 22);
      this->toolStripBlueButton->Text = L"Blue";
      this->toolStripBlueButton->ToolTipText = L"Draw in blue";
      this->toolStripBlueButton->Click += gcnew System::EventHandler(this, &Form1::blueToolStripMenuItem_Click);
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(484, 312);
      this->Controls->Add(this->toolStrip1);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->Name = L"Form1";
      this->Text = L"CLR Sketcher";
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->toolStrip1->ResumeLayout(false);
      this->toolStrip1->PerformLayout();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void lineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
               elementType = ElementType::LINE;
               SetElementTypeButtonsState();
           }
private: System::Void rectangleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
             elementType = ElementType::RECTANGLE;
             SetElementTypeButtonsState();
         }
private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
             elementType = ElementType::CIRCLE;
             SetElementTypeButtonsState();
         }
private: System::Void curveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
             elementType = ElementType::CURVE;
             SetElementTypeButtonsState();
         }
private: System::Void blackToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
           color = Color::Black;
           SetColorButtonsState();
         }
private: System::Void redToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
           color = Color::Red;
           SetColorButtonsState();
         }
private: System::Void greenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
           color = Color::Green;
           SetColorButtonsState();
         }
private: System::Void blueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            color = Color::Blue;
           SetColorButtonsState();
         }
         // Current element type
         ElementType elementType;
         // Current drawing color
         Color color;
private: System::Void elementToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
  lineToolStripMenuItem->Checked = elementType == ElementType::LINE;
  rectangleToolStripMenuItem->Checked = elementType == ElementType::RECTANGLE;
  circleToolStripMenuItem->Checked = elementType == ElementType::CIRCLE;
  curveToolStripMenuItem->Checked = elementType == ElementType::CURVE;
        }
private: System::Void colorToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
  blackToolStripMenuItem->Checked = color == Color::Black;
  redToolStripMenuItem->Checked = color == Color::Red;
  greenToolStripMenuItem->Checked = color == Color::Green;
  blueToolStripMenuItem->Checked = color == Color::Blue;
         }

         // Set the state of the element type toolbar buttons
         void SetElementTypeButtonsState(void)
         {
     toolStripLineButton->Checked = elementType == ElementType::LINE;
     toolStripRectangleButton->Checked = elementType == ElementType::RECTANGLE;
     toolStripCircleButton->Checked = elementType == ElementType::CIRCLE;
     toolStripCurveButton->Checked = elementType == ElementType::CURVE;
         }

         // Set the state of the color toolbar buttons
         void SetColorButtonsState(void)
         {
     toolStripBlackButton->Checked = color == Color::Black;
     toolStripRedButton->Checked = color == Color::Red;
     toolStripGreenButton->Checked = color == Color::Green;
     toolStripBlueButton->Checked = color == Color::Blue;
         }
};
}

