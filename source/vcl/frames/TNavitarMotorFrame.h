#ifndef TNavitarMotorFrameH
#define TNavitarMotorFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntegerLabeledEdit.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "TIntLabel.h"
//---------------------------------------------------------------------------


class NavitarMotor;

class TNavitarMotorFrame : public TFrame
{
    __published:
		TGroupBox *MotorGB;
	TIntegerLabeledEdit *MotorPosition;
	TTrackBar *PositionTB;
        TTimer *MotorPositionTimer;
	TButton *HomeBtn;
	TButton *LimitBtn;
	TIntLabel *MaxPosLabel;
	TLabel *Label1;

	void __fastcall FrameBtnClick(TObject *Sender);
	void __fastcall MotorPositionTimerTimer(TObject *Sender);
	void __fastcall MotorPositionKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

    private:
		NavitarMotor*			mMotor;

    public:
        						__fastcall TNavitarMotorFrame(TComponent* Owner);
		void					populate(NavitarMotor& m);
		void					dePopulate();
};

extern PACKAGE TNavitarMotorFrame *NavitarMotorFrame;
#endif
