// CCircleView.cpp: 구현 파일
//

#include "pch.h"
#include "MDITest.h"
#include "CCircleDoc.h"
#include "CCircleView.h"


// CCircleView

IMPLEMENT_DYNCREATE(CCircleView, CView)

CCircleView::CCircleView()
{

}

CCircleView::~CCircleView()
{
}

BEGIN_MESSAGE_MAP(CCircleView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCircleView 그리기

void CCircleView::OnDraw(CDC* pDC)
{
	CCircleDoc* pDoc = (CCircleDoc*)GetDocument();
	CFont font;
	font.CreateFont(30, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, _T("궁서"));
	pDC->SelectObject(&font);

	// 현재까지 입력된 글자를 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);

	CString str;



	CString strDefaultDocName, strBaseName, strExt, strNewName, strFilterName, strRegFileTypeId, strRegFileTypeName;
	CDocTemplate* pDocTemplate = pDoc->GetDocTemplate();
	if (!pDocTemplate->GetDocString(strBaseName, CDocTemplate::docName) || !pDocTemplate->GetDocString(strExt, CDocTemplate::filterExt) || !pDocTemplate->GetDocString(strNewName, CDocTemplate::fileNewName)
		|| !pDocTemplate->GetDocString(strFilterName, CDocTemplate::filterName) || !pDocTemplate->GetDocString(strRegFileTypeId, CDocTemplate::regFileTypeId) || !pDocTemplate->GetDocString(strRegFileTypeName, CDocTemplate::regFileTypeName))
	{
		AfxThrowUserException(); // These doc template strings will
		// be available if you created the application using AppWizard
		// and specified the file extension as an option for
		// the document class produced by AppWizard.
	}
	str.Format(_T("windowTitle:\n-docName: %s\n-fileNewName: %s\n-filterName: %s\n-filterExt: %s\n-regFileTypeid: %s\n-regFileTypeName: %s"), strBaseName, strNewName, strFilterName, strExt, strRegFileTypeId, strRegFileTypeName);

	pDC->DrawText(str, &rect, DT_LEFT);
}


// CCircleView 진단

#ifdef _DEBUG
void CCircleView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCircleView 메시지 처리기


void CCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CCircleDoc* pDoc = (CCircleDoc*)GetDocument();
	pDoc->m_points.Add(point);
	pDoc->UpdateAllViews(NULL);
}
