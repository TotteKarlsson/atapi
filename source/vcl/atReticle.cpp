//---------------------------------------------------------------------------
#pragma hdrstop
#include "atReticle.h"
#include <vcl.controls.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

TReticle::TReticle(TCanvas* canvas, ReticleType rt)
:
mCanvas(canvas),
mReticleType(rt),
mCircleRadius(10),
mLineColor(clRed)
{
}

void TReticle::draw(int w, int h)
{
    HDC hDC = mCanvas->Handle;
	MoveWindowOrg(hDC, w/2, h/2);

    mCanvas->Pen->Color = mLineColor;
    mCanvas->Brush->Style = bsClear;

    int r(mCircleRadius); //Circle radius
    mCanvas->Ellipse(-r, -r, r, r);

	//Top vertical
    mCanvas->MoveTo(0, -h/2);
    mCanvas->LineTo(0, -r);

	//Bottom vertical
    mCanvas->MoveTo(0, h/2);
    mCanvas->LineTo(0, r);

    //Left horiz
    mCanvas->MoveTo(-w/2, 0);
    mCanvas->LineTo(-r, 0);

    //Right horiz
    mCanvas->MoveTo(w/2, 0);
    mCanvas->LineTo(r, 0);

}
