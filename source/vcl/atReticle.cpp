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
mLineColor(clRed),
mReticleCenter(0,0)
{
}

void TReticle::setCircleRadius(int r)
{
	mCircleRadius = r;
}

void TReticle::setReticleCenter(int x, int y)
{
	mReticleCenter = pair<int,int>(x,y);
}

void TReticle::draw(int w, int h)
{
    HDC hDC = mCanvas->Handle;

    //Set 0,0 in the middle
	MoveWindowOrg(hDC, w/2, h/2);

    mCanvas->Pen->Color = mLineColor;
    mCanvas->Brush->Style = bsClear;

    int r(mCircleRadius); //Circle radius
    mCanvas->Ellipse(-r + mReticleCenter.first, -r + mReticleCenter.second, r + mReticleCenter.first, r + mReticleCenter.second);

	//Top vertical
    mCanvas->MoveTo(mReticleCenter.first, -h/2);
    mCanvas->LineTo(mReticleCenter.first, -r+ mReticleCenter.second);

	//Bottom vertical
    mCanvas->MoveTo(mReticleCenter.first, h/2);
    mCanvas->LineTo(mReticleCenter.first, r + mReticleCenter.second);

    //Left horiz
    mCanvas->MoveTo(-w/2 , mReticleCenter.second);
    mCanvas->LineTo(-r + mReticleCenter.first, mReticleCenter.second);

    //Right horiz
    mCanvas->MoveTo(w/2, mReticleCenter.second);
    mCanvas->LineTo(r + mReticleCenter.first, mReticleCenter.second);

}
