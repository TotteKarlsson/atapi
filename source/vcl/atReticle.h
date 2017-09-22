#ifndef atReticleH
#define atReticleH
#include <VCL.Graphics.hpp>
#include <utility>
#include "core/atATObject.h"
//---------------------------------------------------------------------------

using std::pair;
class PACKAGE TReticle : public ATObject
{
	public:
    	enum ReticleType	        {rtCrossHair, rtCircle, rtBoth};
							        TReticle(TCanvas* canvas, ReticleType rt = rtBoth, TColor = clRed);
		void				        draw(int clientW, int clientH);

        void				        setCircleRadius(int r);
        void				        setReticleCenter(int x, int y);
        void						visible(bool vis);
        bool						isVisible(){return mVisible;}

    protected:
    	TCanvas* 			        mCanvas;
        bool						mVisible;
        ReticleType			        mReticleType;
        TColor				        mLineColor;
        int					        mCircleRadius;
        pair<int,int>		        mReticleCenter;
};
#endif
