#pragma once
#include "Elements.h"
#include "Sketch.h"
#include "PenDialog.h"
#include "TextDialog.h"

namespace CLRSketcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
  using namespace System::Drawing::Drawing2D;

  enum class ElementType {LINE, RECTANGLE, CIRCLE, CURVE, TEXT};
  enum class Mode {Normal, Move};

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
    Form1(void) : elementType(ElementType::LINE), color(Color::Black)
      , drawing(false)
      , firstPoint(0)
      , tempElement(nullptr)
      , sketch(gcnew Sketch())
      , highlightedElement(nullptr)
      , mode(Mode::Normal)
      , penDialog(gcnew PenDialog())
      , textDialog(gcnew TextDialog())
      , penWidth(1.0f)
    {
			InitializeComponent();
			//
			SetElementTypeButtonsState();
      SetColorButtonsState();
      lineStyleComboBox->SelectedIndex = 0;
      textFont = Font;
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
  private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
  private: System::Windows::Forms::ToolStripMenuItem^  sendToBackContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  deleteContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  moveContextMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  contextSeparator;

  private: System::Windows::Forms::ToolStripMenuItem^  lineContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  rectangleContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  circleContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  curveContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blackContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  redContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  greenContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blueContextMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator9;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
private: System::Windows::Forms::ToolStripButton^  penWidthButton;
private: System::Windows::Forms::ToolStripComboBox^  lineStyleComboBox;
private: System::Windows::Forms::ToolStripMenuItem^  textToolStripMenuItem;
private: System::Windows::Forms::ToolStripButton^  toolStripTextButton;

private: System::Windows::Forms::ToolStripMenuItem^  textContextMenuItem;
private: System::Windows::Forms::ToolStripButton^  toolStripFontButton;

private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator10;
private: System::Windows::Forms::FontDialog^  fontDialog1;






  private: System::ComponentModel::IContainer^  components;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->components = (gcnew System::ComponentModel::Container());
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
      this->textToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
      this->toolStripTextButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripFontButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator10 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripBlackButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripRedButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripGreenButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripBlueButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->penWidthButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->lineStyleComboBox = (gcnew System::Windows::Forms::ToolStripComboBox());
      this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
      this->sendToBackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->deleteContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->moveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->contextSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->lineContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->rectangleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->circleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->curveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->textContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->blackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->redContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->greenContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blueContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
      this->menuStrip1->SuspendLayout();
      this->toolStrip1->SuspendLayout();
      this->contextMenuStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fileToolStripMenuItem, 
        this->editToolStripMenuItem, this->toolsToolStripMenuItem, this->elementToolStripMenuItem, this->colorToolStripMenuItem, this->helpToolStripMenuItem});
      this->menuStrip1->Location = System::Drawing::Point(0, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(559, 24);
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
      this->elementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->lineToolStripMenuItem, 
        this->rectangleToolStripMenuItem, this->circleToolStripMenuItem, this->curveToolStripMenuItem, this->textToolStripMenuItem});
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
      // textToolStripMenuItem
      // 
      this->textToolStripMenuItem->Name = L"textToolStripMenuItem";
      this->textToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
        | System::Windows::Forms::Keys::T));
      this->textToolStripMenuItem->Size = System::Drawing::Size(199, 22);
      this->textToolStripMenuItem->Text = L"Text";
      this->textToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::textToolStripMenuItem_Click);
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
      this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(20) {this->newToolStripButton, 
        this->openToolStripButton, this->saveToolStripButton, this->printToolStripButton, this->toolStripSeparator6, this->toolStripLineButton, 
        this->toolStripRectangleButton, this->toolStripCircleButton, this->toolStripCurveButton, this->toolStripTextButton, this->toolStripSeparator7, 
        this->toolStripFontButton, this->toolStripSeparator10, this->toolStripBlackButton, this->toolStripRedButton, this->toolStripGreenButton, 
        this->toolStripBlueButton, this->toolStripSeparator8, this->penWidthButton, this->lineStyleComboBox});
      this->toolStrip1->Location = System::Drawing::Point(0, 24);
      this->toolStrip1->Name = L"toolStrip1";
      this->toolStrip1->Size = System::Drawing::Size(559, 25);
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
      // toolStripTextButton
      // 
      this->toolStripTextButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripTextButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripTextButton.Image")));
      this->toolStripTextButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripTextButton->Name = L"toolStripTextButton";
      this->toolStripTextButton->Size = System::Drawing::Size(23, 22);
      this->toolStripTextButton->Text = L"Create text element";
      this->toolStripTextButton->Click += gcnew System::EventHandler(this, &Form1::textToolStripMenuItem_Click);
      // 
      // toolStripSeparator7
      // 
      this->toolStripSeparator7->Name = L"toolStripSeparator7";
      this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripFontButton
      // 
      this->toolStripFontButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripFontButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripFontButton.Image")));
      this->toolStripFontButton->ImageTransparentColor = System::Drawing::Color::White;
      this->toolStripFontButton->Name = L"toolStripFontButton";
      this->toolStripFontButton->Size = System::Drawing::Size(23, 22);
      this->toolStripFontButton->Text = L"Select a font";
      this->toolStripFontButton->Click += gcnew System::EventHandler(this, &Form1::toolStripFontButton_Click);
      // 
      // toolStripSeparator10
      // 
      this->toolStripSeparator10->Name = L"toolStripSeparator10";
      this->toolStripSeparator10->Size = System::Drawing::Size(6, 25);
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
      // toolStripSeparator8
      // 
      this->toolStripSeparator8->Name = L"toolStripSeparator8";
      this->toolStripSeparator8->Size = System::Drawing::Size(6, 25);
      // 
      // penWidthButton
      // 
      this->penWidthButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->penWidthButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"penWidthButton.Image")));
      this->penWidthButton->ImageTransparentColor = System::Drawing::Color::White;
      this->penWidthButton->Name = L"penWidthButton";
      this->penWidthButton->Size = System::Drawing::Size(23, 22);
      this->penWidthButton->Text = L"toolStripButton1";
      this->penWidthButton->ToolTipText = L"Change pen width";
      this->penWidthButton->Click += gcnew System::EventHandler(this, &Form1::penWidthButton_Click);
      // 
      // lineStyleComboBox
      // 
      this->lineStyleComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
      this->lineStyleComboBox->FlatStyle = System::Windows::Forms::FlatStyle::Standard;
      this->lineStyleComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Solid lines", L"Dashed lines", L"Dotted lines", 
        L"Dash-dotted lines", L"Dash-dot-dotted lines"});
      this->lineStyleComboBox->Name = L"lineStyleComboBox";
      this->lineStyleComboBox->Size = System::Drawing::Size(150, 25);
      this->lineStyleComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::lineStyleComboBox_SelectedIndexChanged);
      // 
      // contextMenuStrip1
      // 
      this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {this->sendToBackContextMenuItem, 
        this->deleteContextMenuItem, this->moveContextMenuItem, this->contextSeparator, this->lineContextMenuItem, this->rectangleContextMenuItem, 
        this->circleContextMenuItem, this->curveContextMenuItem, this->textContextMenuItem, this->toolStripSeparator9, this->blackContextMenuItem, 
        this->redContextMenuItem, this->greenContextMenuItem, this->blueContextMenuItem});
      this->contextMenuStrip1->Name = L"contextMenuStrip1";
      this->contextMenuStrip1->Size = System::Drawing::Size(143, 280);
      this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::contextMenuStrip1_Opening);
      // 
      // sendToBackContextMenuItem
      // 
      this->sendToBackContextMenuItem->Name = L"sendToBackContextMenuItem";
      this->sendToBackContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->sendToBackContextMenuItem->Text = L"Send to Back";
      this->sendToBackContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::sendToBackContextMenuItem_Click);
      // 
      // deleteContextMenuItem
      // 
      this->deleteContextMenuItem->Name = L"deleteContextMenuItem";
      this->deleteContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->deleteContextMenuItem->Text = L"Delete";
      this->deleteContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteContextMenuItem_Click);
      // 
      // moveContextMenuItem
      // 
      this->moveContextMenuItem->Name = L"moveContextMenuItem";
      this->moveContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->moveContextMenuItem->Text = L"Move";
      this->moveContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::moveContextMenuItem_Click);
      // 
      // contextSeparator
      // 
      this->contextSeparator->Name = L"contextSeparator";
      this->contextSeparator->Size = System::Drawing::Size(139, 6);
      // 
      // lineContextMenuItem
      // 
      this->lineContextMenuItem->Name = L"lineContextMenuItem";
      this->lineContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->lineContextMenuItem->Text = L"Line";
      this->lineContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::lineToolStripMenuItem_Click);
      // 
      // rectangleContextMenuItem
      // 
      this->rectangleContextMenuItem->Name = L"rectangleContextMenuItem";
      this->rectangleContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->rectangleContextMenuItem->Text = L"Rectangle";
      this->rectangleContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::rectangleToolStripMenuItem_Click);
      // 
      // circleContextMenuItem
      // 
      this->circleContextMenuItem->Name = L"circleContextMenuItem";
      this->circleContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->circleContextMenuItem->Text = L"Circle";
      this->circleContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::circleToolStripMenuItem_Click);
      // 
      // curveContextMenuItem
      // 
      this->curveContextMenuItem->Name = L"curveContextMenuItem";
      this->curveContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->curveContextMenuItem->Text = L"Curve";
      this->curveContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::curveToolStripMenuItem_Click);
      // 
      // textContextMenuItem
      // 
      this->textContextMenuItem->Name = L"textContextMenuItem";
      this->textContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->textContextMenuItem->Text = L"Text";
      this->textContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::textToolStripMenuItem_Click);
      // 
      // toolStripSeparator9
      // 
      this->toolStripSeparator9->Name = L"toolStripSeparator9";
      this->toolStripSeparator9->Size = System::Drawing::Size(139, 6);
      // 
      // blackContextMenuItem
      // 
      this->blackContextMenuItem->Name = L"blackContextMenuItem";
      this->blackContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->blackContextMenuItem->Text = L"Black";
      this->blackContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::blackToolStripMenuItem_Click);
      // 
      // redContextMenuItem
      // 
      this->redContextMenuItem->Name = L"redContextMenuItem";
      this->redContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->redContextMenuItem->Text = L"Red";
      this->redContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::redToolStripMenuItem_Click);
      // 
      // greenContextMenuItem
      // 
      this->greenContextMenuItem->Name = L"greenContextMenuItem";
      this->greenContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->greenContextMenuItem->Text = L"Green";
      this->greenContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::greenToolStripMenuItem_Click);
      // 
      // blueContextMenuItem
      // 
      this->blueContextMenuItem->Name = L"blueContextMenuItem";
      this->blueContextMenuItem->Size = System::Drawing::Size(142, 22);
      this->blueContextMenuItem->Text = L"Blue";
      this->blueContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::blueToolStripMenuItem_Click);
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->BackColor = System::Drawing::SystemColors::ControlLightLight;
      this->ClientSize = System::Drawing::Size(559, 312);
      this->ContextMenuStrip = this->contextMenuStrip1;
      this->Controls->Add(this->toolStrip1);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->Name = L"Form1";
      this->Text = L"CLR Sketcher";
      this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
      this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
      this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
      this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->toolStrip1->ResumeLayout(false);
      this->toolStrip1->PerformLayout();
      this->contextMenuStrip1->ResumeLayout(false);
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
  textToolStripMenuItem->Checked = elementType == ElementType::TEXT;
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
     toolStripTextButton->Checked = elementType == ElementType::TEXT;
        }

         // Set the state of the color toolbar buttons
         void SetColorButtonsState(void)
         {
     toolStripBlackButton->Checked = color == Color::Black;
     toolStripRedButton->Checked = color == Color::Red;
     toolStripGreenButton->Checked = color == Color::Green;
     toolStripBlueButton->Checked = color == Color::Blue;
         }

private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
  if(e->Button == System::Windows::Forms::MouseButtons::Left)
  {
    firstPoint = e->Location;
    if(mode == Mode::Normal)
    {
      if(elementType == ElementType::TEXT)
      {
        textDialog->TextString = L"";        // Reset the text box string  
        textDialog->TextFont = textFont;     // Set the font for the edit box
        if(textDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
          tempElement = gcnew TextElement(color, firstPoint,
                                                 textDialog->TextString, textFont);
          sketch += tempElement;
          Invalidate(tempElement->bound);    // The text element region
          tempElement = nullptr;
          Update();
        }
        drawing = false;
      }
      else
      {
        drawing = true;
      }
    }
  }
}

private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
  if(drawing)
  {
    if(tempElement)
      Invalidate(tempElement->bound);               // Invalidate old element area
    switch(elementType)
    {
      case ElementType::LINE:
        tempElement = gcnew Line(color, firstPoint, e->Location, penWidth, lineStyle);
        break;
      case ElementType::RECTANGLE:
        tempElement = gcnew Rectangle(color, firstPoint, e->Location, penWidth, lineStyle);
        break;
      case ElementType::CIRCLE:
        tempElement = gcnew Circle(color, firstPoint, e->Location, penWidth, lineStyle);
        break;
      case ElementType::CURVE:
        if(tempElement)
          safe_cast<Curve^>(tempElement)->Add(e->Location);
        else
          tempElement = gcnew Curve(color, firstPoint, e->Location, penWidth, lineStyle);
        break;
    }
    Invalidate(tempElement->bound);                 // Invalidate new element area
    Update();                                       // Repaint
  }
  else if(mode == Mode::Normal)
  {
    // Find the element under the cursor - if any
    Element^ element(sketch->HitElement(e->Location));
    if(highlightedElement == element)        // If the old is same as the new
      return;                                // there's nothing to do

    // Reset any existing highlighted element
    if(highlightedElement)
    {
      Invalidate(highlightedElement->bound);  // Invalidate element area
      highlightedElement->highlighted = false;
      highlightedElement = nullptr;
    }
    // Find and set new highlighted element, if any
    highlightedElement = element;
    if(highlightedElement)
    {
      highlightedElement->highlighted = true;
      Invalidate(highlightedElement->bound);  // Invalidate element area
    }
    Update();                                 // Send a paint message
  }
  else if(mode == Mode::Move && e->Button == System::Windows::Forms::MouseButtons::Left)
  {  // Move the highlighted element
     if(highlightedElement)
     {
        Invalidate(highlightedElement->bound);    // Region before move
        highlightedElement->Move(e->X - firstPoint.X, e->Y - firstPoint.Y);
        firstPoint = e->Location;
        Invalidate(highlightedElement->bound);     // Region after move
        Update();
     }
   }
}

private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
  if(!drawing)
  {
    mode = Mode::Normal;
    return;
  }
  if(tempElement)
  {
    sketch += tempElement;
    tempElement = nullptr;
    Invalidate();
  }
  drawing = false;
}
         // Drawing in progress when true
         bool drawing;
         // Records initial mouse cursor position
         Point firstPoint;
         // Stores a temporary element
         Element^ tempElement;
         // Stores the whole sketch
         Sketch^ sketch;
         // Currently highlighted element
         Element^ highlightedElement;

private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
{
  Graphics^ g = e->Graphics;
  sketch->Draw(g);

  if(tempElement != nullptr)
  {
    tempElement->Draw(g);
  }
}
private: System::Void sendToBackContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  if(highlightedElement)
  {
    sketch -= highlightedElement;               // Delete the highlighted element
    sketch->push_front(highlightedElement);     // then add it back to the beginning
    highlightedElement->highlighted = false;
    Invalidate(highlightedElement->bound);
    highlightedElement = nullptr;
    Update();
  }
}
private: System::Void deleteContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  if(highlightedElement)
  {
    sketch -= highlightedElement;              // Delete the highlighted element
    Invalidate(highlightedElement->bound);
    highlightedElement = nullptr;
    Update();
  }  
}
private: System::Void moveContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
   mode = Mode::Move;
}
private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
  contextMenuStrip1->Items->Clear();    // Remove existing items
  if(highlightedElement)
  {
    contextMenuStrip1->Items->Add(moveContextMenuItem);
    contextMenuStrip1->Items->Add(deleteContextMenuItem);
    contextMenuStrip1->Items->Add(sendToBackContextMenuItem);
  }
  else
  {
    contextMenuStrip1->Items->Add(lineContextMenuItem);
    contextMenuStrip1->Items->Add(rectangleContextMenuItem);
    contextMenuStrip1->Items->Add(circleContextMenuItem);
    contextMenuStrip1->Items->Add(curveContextMenuItem);
    contextMenuStrip1->Items->Add(textContextMenuItem);
    contextMenuStrip1->Items->Add(contextSeparator);
    contextMenuStrip1->Items->Add(blackContextMenuItem);
    contextMenuStrip1->Items->Add(redContextMenuItem);
    contextMenuStrip1->Items->Add(greenToolStripMenuItem);
    contextMenuStrip1->Items->Add(blueContextMenuItem);

    // Set checks for the menu items
    lineContextMenuItem->Checked = elementType == ElementType::LINE;
    rectangleContextMenuItem->Checked = elementType == ElementType::RECTANGLE;
    circleContextMenuItem->Checked = elementType == ElementType::CIRCLE;
    curveContextMenuItem->Checked = elementType == ElementType::CURVE;
    textContextMenuItem->Checked = elementType == ElementType::TEXT;
    blackContextMenuItem->Checked = color == Color::Black;
    redContextMenuItem->Checked = color == Color::Red;
    greenContextMenuItem->Checked = color == Color::Green;
    blueContextMenuItem->Checked = color == Color::Blue;
  }
         }
         Mode mode;
         // The pen width dialog object
         PenDialog^ penDialog;
private: System::Void penWidthButton_Click(System::Object^  sender, System::EventArgs^  e) {
  if(penDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
  {
    penWidth = penDialog->PenWidth;      // Get the pen width
  }
}
         // Current pen width
         float penWidth;
private: System::Void lineStyleComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
  switch(lineStyleComboBox->SelectedIndex)
  {
    case 1:
     lineStyle = DashStyle::Dash;
     break;    
    case 2:
     lineStyle = DashStyle::Dot;
     break;    
    case 3:
     lineStyle = DashStyle::DashDot;
     break;    
    case 4:
     lineStyle = DashStyle::DashDotDot;
     break;    
    default:
     lineStyle = DashStyle::Solid;
     break;    
  }
         }
         // Current line drawing style
         DashStyle lineStyle;
private: System::Void textToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
              elementType = ElementType::TEXT;
         }
         // Font for drawing text
         System::Drawing::Font^ textFont;
private: System::Void toolStripFontButton_Click(System::Object^  sender, System::EventArgs^  e) {
           if(fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
           {
             textFont = fontDialog1->Font;
           }
}
         // The text dialog object
         TextDialog^ textDialog;
};
}

