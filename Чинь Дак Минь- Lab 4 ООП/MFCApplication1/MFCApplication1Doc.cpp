
// MFCApplication1Doc.cpp : ���������� ������ CMFCApplication1Doc
//

#include "stdafx.h"
#include "Minh_class.h"
#include "Minh.h"
#include <algorithm>

// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include <propkey.h>
#include <functional>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1Doc

IMPLEMENT_DYNCREATE(CMFCApplication1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication1Doc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� CMFCApplication1Doc

CMFCApplication1Doc::CMFCApplication1Doc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CMFCApplication1Doc::~CMFCApplication1Doc()
{
}

BOOL CMFCApplication1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)
	library.clear();
	return TRUE;
}




// ������������ CMFCApplication1Doc

class output
{

public:
	CArchive &ar;
	output(CArchive& archive)
		:ar(archive){};

	void operator()(shared_ptr<Minh>& elem)
	{
		ar << elem.get();
	}

};

void print(shared_ptr<Minh>& elem, CArchive& ar)
{
	ar << elem.get();
}


void CMFCApplication1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << library.library.size();
		for_each(library.library.begin(), library.library.end(), bind(print, std::placeholders::_1, ref(ar)));
//		for_each(library.library.begin(), library.library.end(), output(ar));

	}
	else
	{
		int n;
		ar >> n;
		for (int i = 0; i < n; i++)
		{
			Minh* elem;
			ar >> elem;
			library.library.push_back(shared_ptr<Minh>(elem));
			if (length < elem->GetSumLength())
				length = elem->GetSumLength();
		}
		// TODO: �������� ��� ��������
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CMFCApplication1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CMFCApplication1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CMFCApplication1Doc

#ifdef _DEBUG
void CMFCApplication1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CMFCApplication1Doc
