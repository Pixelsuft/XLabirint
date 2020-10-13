//---------------------------------------------------------------------------

#ifndef lvl2H
#define lvl2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tlevel2 : public TForm
{
__published:	// IDE-managed Components
        TImage *BG;
        TImage *Red;
        TImage *Green;
        TImage *Win;
        TTimer *Launch;
        TTimer *Mover;
        TTimer *CheckPosition;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TShape *Shape5;
        TShape *Shape6;
        TShape *Shape7;
        TShape *Shape8;
        TShape *Shape9;
        void __fastcall LaunchTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall MoverTimer(TObject *Sender);
        void __fastcall CheckPositionTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlevel2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlevel2 *level2;
//---------------------------------------------------------------------------
#endif
