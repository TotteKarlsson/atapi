#ifndef atReticleH
#define atReticleH
#include <VCL.Graphics.hpp>
//---------------------------------------------------------------------------

class PACKAGE TReticle
{
	public:
    	enum ReticleType	{rtCrossHair, rtCircle, rtBoth};
							TReticle(TCanvas* canvas, ReticleType rt = rtCrossHair);
		void				draw(int clientW, int clientH);

        void				setCircleRadius(int r){mCircleRadius = r;}

    protected:
    	TCanvas* 			mCanvas;
        ReticleType			mReticleType;
        TColor				mLineColor;
        int					mCircleRadius;
};
#endif
