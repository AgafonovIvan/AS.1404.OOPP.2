
// MFCApplication1View.cpp : ���������� ������ CMFCApplication1View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include <algorithm>
#include "Minh.h"
#include <functional>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CScrollView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CScrollView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ��������/����������� CMFCApplication1View

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: �������� ��� ��������

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// ��������� CMFCApplication1View

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
	
	int i = 1;
	for_each(pDoc->library.library.begin(),
		pDoc->library.library.end(),
		bind(&Minh::WinOutput, std::placeholders::_1, i, pDC));

}

void CMFCApplication1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: ����������� ������ ������ ����� �������������
	sizeTotal.cx = GetDocument()->length * 15;
	sizeTotal.cy = GetDocument()->library.library.size()*15;
	
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// ������ CMFCApplication1View

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CMFCApplication1View
