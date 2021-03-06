#ifndef TXYZUnitFrameH
#define TXYZUnitFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "dslTFloatLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------

using std::vector;
class TMotorFrame;
namespace at
{
	class XYZUnit;
}
using at::XYZUnit;


class PACKAGE TXYZUnitFrame : public TFrame
{
    __published:

    private:
        XYZUnit*			    mUnit;
		static int				mFrameNr;

    public:
        __fastcall 			    TXYZUnitFrame(TComponent* Owner);
        void				    assignUnit(XYZUnit* u);
        void				    disable();
        void				    enable();
        vector<TMotorFrame*> 	mFrames;
};
extern PACKAGE TXYZUnitFrame *XYZUnitFrame;

#endif
