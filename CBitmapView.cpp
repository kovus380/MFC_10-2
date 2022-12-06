// CBitmapView.cpp: 구현 파일
//

#include "pch.h"
#include "MDITest.h"
#include "CBitmapView.h"


// CBitmapView

IMPLEMENT_DYNCREATE(CBitmapView, CView)

CBitmapView::CBitmapView()
{

}

CBitmapView::~CBitmapView()
{
}

BEGIN_MESSAGE_MAP(CBitmapView, CView)
END_MESSAGE_MAP()


// CBitmapView 그리기

void CBitmapView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CBitmapView 진단

#ifdef _DEBUG
void CBitmapView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CBitmapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBitmapView 메시지 처리기


BOOL CBitmapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	HBRUSH h_brush = CreatePatternBrush(bitmap);
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), h_brush, nullptr);
	return TRUE;
}
