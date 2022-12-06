// CBitmapDoc.cpp: 구현 파일
//

#include "pch.h"
#include "MDITest.h"
#include "CBitmapDoc.h"


// CBitmapDoc

IMPLEMENT_DYNCREATE(CBitmapDoc, CDocument)

CBitmapDoc::CBitmapDoc()
{
}

BOOL CBitmapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CBitmapDoc::~CBitmapDoc()
{
}


BEGIN_MESSAGE_MAP(CBitmapDoc, CDocument)
END_MESSAGE_MAP()


// CBitmapDoc 진단

#ifdef _DEBUG
void CBitmapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CBitmapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CBitmapDoc serialization

void CBitmapDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}
#endif


// CBitmapDoc 명령
