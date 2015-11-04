
// SketcherView.cpp : implementation of the CSketcherView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "SketcherView.h"
#include "ScaleDialog.h"
#include "TextDialog.h"
#include <typeinfo>
#include "PrintData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CScrollView)

BEGIN_MESSAGE_MAP(CSketcherView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSketcherView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
  ON_WM_LBUTTONUP()
  ON_WM_LBUTTONDOWN()
  ON_WM_MOUSEMOVE()
  ON_COMMAND(ID_ELEMENT_MOVE, &CSketcherView::OnElementMove)
  ON_COMMAND(ID_ELEMENT_DELETE, &CSketcherView::OnElementDelete)
  ON_WM_RBUTTONDOWN()
  ON_COMMAND(ID_ELEMENT_SENDTOBACK, &CSketcherView::OnElementSendtoback)
  ON_COMMAND(ID_VIEW_SCALE, &CSketcherView::OnViewScale)
  ON_UPDATE_COMMAND_UI(ID_INDICATOR_SCALE, &CSketcherView::OnUpdateScale)
END_MESSAGE_MAP()

// CSketcherView construction/destruction

CSketcherView::CSketcherView()
: m_FirstPoint(CPoint(0,0))
, m_SecondPoint(CPoint(0,0))
, m_pTempElement(NULL)
, m_pSelected(NULL)
, m_MoveMode(false)
, m_CursorPos(CPoint(0,0))
, m_FirstPos(CPoint(0,0))
, m_Scale(1)
{
   SetScrollSizes(MM_TEXT, CSize(0,0));     // Set arbitrary scrollers
}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSketcherView drawing

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

  CElement* pElement(0);
  for(auto iter = pDoc->begin() ; iter != pDoc->end() ; ++iter)
  {
    pElement = *iter;
    if(pDC->RectVisible(pElement->GetBoundRect())) // If the element is visible
         pElement->Draw(pDC, m_pSelected);         // ...draw it
  }
}


// CSketcherView printing


void CSketcherView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
  CPrintData*p(new CPrintData);             // Create a print data object
  CSketcherDoc* pDoc = GetDocument();       // Get a document pointer
  CRect docExtent = pDoc->GetDocExtent();   // Get the whole document area

  // Save the reference point for the whole document
  p->m_DocRefPoint = CPoint(docExtent.left, docExtent.top);

  // Get the name of the document file and save it
  p->m_DocTitle = pDoc->GetTitle();

  // Calculate how many printed page widths are required
  // to accommodate the width of the document
  p->m_nWidths = static_cast<UINT>(ceil(
                             static_cast<double>(docExtent.Width())/p->printWidth));

  // Calculate how many printed page lengths are required
  // to accommodate the document length
  p->m_nLengths = static_cast<UINT>(
                      ceil(static_cast<double>(docExtent.Height())/p->printLength));

  // Set the first page number as 1 and
  // set the last page number as the total number of pages
  pInfo->SetMinPage(1);
  pInfo->SetMaxPage(p->m_nWidths*p->m_nLengths);
  pInfo->m_lpUserData = p;             // Store address of PrintData object
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
   // Delete our print data object
   delete static_cast<CPrintData*>(pInfo->m_lpUserData);
}

void CSketcherView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
  if(m_MoveMode)
  {
    m_MoveMode = false;
    return;
  }

	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSketcherView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
  if(m_pSelected)
    theApp.GetContextMenuManager()->ShowPopupMenu(IDR_ELEMENT_MENU,
                                                point.x, point.y, this);
  else
    theApp.GetContextMenuManager()->ShowPopupMenu(IDR_NOELEMENT_MENU,
                                                point.x, point.y, this);
#endif
}


// CSketcherView diagnostics

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView message handlers


void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
   if(this == GetCapture())
      ReleaseCapture();        // Stop capturing mouse messages

   // If there is an element, add it to the document
   if(m_pTempElement)
   {
      GetDocument()->AddElement(m_pTempElement);
      GetDocument()->UpdateAllViews(0, 0, m_pTempElement);  // Tell all the views
      m_pTempElement = 0;                                   // Reset the element pointer
   }
}


void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
   CClientDC aDC(this);                // Create a device context
   OnPrepareDC(&aDC);                  // Get origin adjusted
   aDC.DPtoLP(&point);                 // convert point to logical coordinates

  if(m_MoveMode)
  {
    // In moving mode, so drop the element
    m_MoveMode = false;                // Kill move mode
    m_pSelected = nullptr;             // De-select the element
    GetDocument()->UpdateAllViews(0);  // Redraw all the views
    GetDocument()->SetModifiedFlag();  // Set the modified flag
    return;
  }

    CSketcherDoc* pDoc = GetDocument();// Get a document pointer
    if(pDoc->GetElementType() == TEXT)
  {
    CTextDialog aDlg;
    if(aDlg.DoModal() == IDOK)
    {
      // Exit OK so create a text element 
      CSize textExtent = aDC.GetTextExtent(aDlg.m_TextString);
      CRect rect(point, textExtent);      //Create enclosing rectangle
      CText* pTextElement = new CText(
                              aDlg.m_TextString, rect, pDoc->GetElementColor());

      // Add the element to the document
      pDoc->AddElement(pTextElement);

      // Get all views updated
      pDoc->UpdateAllViews(nullptr, 0, pTextElement);
    }
    return;
  }

  m_FirstPoint = point;               // Record the cursor position
   SetCapture();                   // Capture subsequent mouse messages
}


void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
  // Define a Device Context object for the view
  CClientDC aDC(this);                 // DC is for this view
  OnPrepareDC(&aDC);                   // Get origin adjusted
  aDC.DPtoLP(&point);                  // convert point to logical coordinates

  // If we are in move mode, move the selected element and return
  if(m_MoveMode)
  {
    MoveElement(aDC, point);           // Move the element
    return;
  }

  if((nFlags & MK_LBUTTON) && (this == GetCapture()))
  {
    m_SecondPoint = point;             // Save the current cursor position
    if(m_pTempElement)
    {
      if(CURVE == GetDocument()->GetElementType())   // Is it a curve?
      {  // We are drawing a curve so add a segment to the existing curve
         static_cast<CCurve*>(m_pTempElement)->AddSegment(m_SecondPoint);
         m_pTempElement->Draw(&aDC);   // Now draw it
         return;                       // We are done
      }

      // If we get to here it's not a curve so
      // redraw the old element so it disappears from the view
      aDC.SetROP2(R2_NOTXORPEN);       // Set the drawing mode
      m_pTempElement->Draw(&aDC);      // Redraw the old element
      delete m_pTempElement;           // Delete the old element
      m_pTempElement = 0;              // Reset the pointer to 0
    }

    // Create a temporary element of the type and color that
    // is recorded in the document object, and draw it
    m_pTempElement = CreateElement();  // Create a new element
    m_pTempElement->Draw(&aDC);        // Draw the element
  }
  else
  {  // We are not creating an element so do highlighting
    CSketcherDoc* pDoc=GetDocument();         // Get a pointer to the document
    CElement* pOldSelected(m_pSelected);
    m_pSelected = pDoc->FindElement(point);   // Set selected element
    if(m_pSelected != pOldSelected)
    {
      if(m_pSelected)
        InvalidateRect(m_pSelected->GetBoundRect(), FALSE);
      if(pOldSelected)
        InvalidateRect(pOldSelected->GetBoundRect(), FALSE);
      pDoc->UpdateAllViews(0);
    }
  }
}

// Create an element of the current type
CElement* CSketcherView::CreateElement(void) const
{
   // Get a pointer to the document for this view
   CSketcherDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);                 // Verify the pointer is good

   // Now select the element using the type stored in the document
   // Version of code for using imported constants
   unsigned int elementType = pDoc->GetElementType();
   if(elementType == LINE)
         return new CLine(m_FirstPoint, m_SecondPoint, pDoc->GetElementColor(),
                                                               pDoc->GetPenWidth());
   if(elementType == RECTANGLE)
     return new CRectangle(m_FirstPoint, m_SecondPoint, pDoc->GetElementColor(),
                                                               pDoc->GetPenWidth());
   if(elementType == CIRCLE)
     return new CCircle(m_FirstPoint, m_SecondPoint, pDoc->GetElementColor(),
                                                               pDoc->GetPenWidth());
   if(elementType == CURVE)
     return new CCurve(m_FirstPoint, m_SecondPoint, pDoc->GetElementColor(),
                                                               pDoc->GetPenWidth());
   else
   {
     // Something’s gone wrong
     AfxMessageBox(_T("Bad Element code"), MB_OK);
     AfxAbort();
     return nullptr;
   }
}


void CSketcherView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
   // Invalidate the area corresponding to the element pointed to
   // if there is one, otherwise invalidate the whole client area
   if(pHint)
   {
      CClientDC aDC(this);            // Create a device context
      OnPrepareDC(&aDC);              // Get origin adjusted

      // Get the enclosing rectangle and convert to client coordinates
      CRect aRect = static_cast<CElement*>(pHint)->GetBoundRect();
      aDC.LPtoDP(aRect);
      InvalidateRect(aRect);          // Get the area redrawn
   }
   else
   {
      InvalidateRect(0);
   }
}

void CSketcherView::OnInitialUpdate()
{
  ResetScrollSizes();                  // Set up the scrollbars
  CScrollView::OnInitialUpdate();
}


void CSketcherView::OnElementMove()
{
   CClientDC aDC(this);
   OnPrepareDC(&aDC);              // Set up the device context
   GetCursorPos(&m_CursorPos);     // Get cursor position in screen coords
   ScreenToClient(&m_CursorPos);   // Convert to client coords
   aDC.DPtoLP(&m_CursorPos);       // Convert to logical
   m_FirstPos = m_CursorPos;       // Remember first position
   m_MoveMode = true;              // Start move mode
}


void CSketcherView::OnElementDelete()
{
  if(m_pSelected)
  {
    CSketcherDoc* pDoc = GetDocument();// Get the document pointer
    pDoc->DeleteElement(m_pSelected);  // Delete the element
    pDoc->UpdateAllViews(0);           // Redraw all the views
    m_pSelected = 0;                   // Reset selected element ptr
  }
}

void CSketcherView::MoveElement(CClientDC& aDC, const CPoint& point)
{
  CSize distance = point - m_CursorPos;   // Get move distance
  m_CursorPos = point;                    // Set current point as 1st for next time

  // If there is an element, selected, move it
  if(m_pSelected)
  {
    // If the element is text use this method...
    if (typeid(*m_pSelected) == typeid(CText))
    {
      CRect oldRect=m_pSelected->GetBoundRect(); // Get old bound rect
      aDC.LPtoDP(oldRect);                       // Convert to client coords
      m_pSelected->Move(distance);               // Move the element
      InvalidateRect(&oldRect);                  // Invalidate combined area
      UpdateWindow();                            // Redraw immediately
      m_pSelected->Draw(&aDC,m_pSelected);       // Draw highlighted

      return;
    }

    // ...otherwise, use this method
    aDC.SetROP2(R2_NOTXORPEN);
    m_pSelected->Draw(&aDC, m_pSelected); // Draw the element to erase it
    m_pSelected->Move(distance);          // Now move the element
    m_pSelected->Draw(&aDC, m_pSelected); // Draw the moved element
  }
}


void CSketcherView::OnRButtonDown(UINT nFlags, CPoint point)
{
   if(m_MoveMode)
   {
     // In moving mode, so drop element back in original position
     CClientDC aDC(this);
     OnPrepareDC(&aDC);                // Get origin adjusted
     MoveElement(aDC, m_FirstPos);     // Move element to original position
     m_pSelected = 0;                  // De-select element
     GetDocument()->UpdateAllViews(0); // Redraw all the views
  }
}


void CSketcherView::OnElementSendtoback()
{
  GetDocument()->SendToBack(m_pSelected);   // Move element in to start of list
}


void CSketcherView::OnViewScale()
{
  CScaleDialog aDlg;                   // Create a dialog object
  aDlg.m_Scale = m_Scale;              // Pass the view scale to the dialog
  if(aDlg.DoModal() == IDOK)
  {
    m_Scale = aDlg.m_Scale;            // Get the new scale
    ResetScrollSizes();                // Adjust scrolling to the new scale
    InvalidateRect(0);                 // Invalidate the whole window
  }
}


void CSketcherView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
  int scale = m_Scale;                       // Store the scale locally
  if(pDC->IsPrinting())
    scale = 1;                               // If we are printing, set scale to 1

  CScrollView::OnPrepareDC(pDC, pInfo);
  CSketcherDoc* pDoc = GetDocument();
  pDC->SetMapMode(MM_ANISOTROPIC);     // Set the map mode
  CSize DocSize = pDoc->GetDocSize();  // Get the document size

  pDC->SetWindowExt(DocSize);          // Now set the window extent

  // Get the number of pixels per inch in x and y
  int xLogPixels = pDC->GetDeviceCaps(LOGPIXELSX);
  int yLogPixels = pDC->GetDeviceCaps(LOGPIXELSY);

  // Calculate the viewport extent in x and y
  int xExtent = (DocSize.cx*scale*xLogPixels)/100;
  int yExtent = (DocSize.cy*scale*yLogPixels)/100;

  pDC->SetViewportExt(xExtent, yExtent);      // Set viewport extent
}


void CSketcherView::ResetScrollSizes(void)
{
  CClientDC aDC(this);
  OnPrepareDC(&aDC);                             // Set up the device context
  CSize DocSize = GetDocument()->GetDocSize();   // Get the document size
  aDC.LPtoDP(&DocSize);                          // Get the size in pixels
  SetScrollSizes(MM_TEXT, DocSize);              // Set up the scrollbars
}


void CSketcherView::OnUpdateScale(CCmdUI *pCmdUI)
{
    CString scaleStr;
    scaleStr.Format(_T(" View Scale : %d  "), m_Scale); 
    pCmdUI->SetText(scaleStr); 
    pCmdUI->Enable(); 
}


void CSketcherView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
  CPrintData* p(static_cast<CPrintData*>(pInfo->m_lpUserData));
  // Output the document file name
  pDC->SetTextAlign(TA_CENTER);        // Center the following text
  pDC->TextOut(pInfo->m_rectDraw.right/2, 20, p->m_DocTitle);
  CString str;
  str.Format(_T("Page %u") , pInfo->m_nCurPage);
  pDC->TextOut(pInfo->m_rectDraw.right/2, pInfo->m_rectDraw.bottom-20, str);
  pDC->SetTextAlign(TA_LEFT);          // Left justify text

  // Calculate the origin point for the current page
  int xOrg = p->m_DocRefPoint.x + 
                           p->printWidth*((pInfo->m_nCurPage - 1)%(p->m_nWidths));
  int yOrg = p->m_DocRefPoint.y +
                           p->printLength*((pInfo->m_nCurPage - 1)/(p->m_nWidths));

  // Calculate offsets to center drawing area on page as positive values
  int xOffset = (pInfo->m_rectDraw.right - p->printWidth)/2;
  int yOffset = (pInfo->m_rectDraw.bottom - p->printLength)/2;

  // Change window origin to correspond to current page & save old origin
  CPoint OldOrg = pDC->SetWindowOrg(xOrg-xOffset, yOrg-yOffset);

  // Define a clip rectangle the size of the printed area
  pDC->IntersectClipRect(xOrg, yOrg, xOrg+p->printWidth, yOrg+p->printLength);

  OnDraw(pDC);                         // Draw the whole document
  pDC->SelectClipRgn(nullptr);         // Remove the clip rectangle
  pDC->SetWindowOrg(OldOrg);           // Restore old window origin
}
