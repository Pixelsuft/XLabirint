//---------------------------------------------------------------------------

#ifndef lvl5H
#define lvl5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tlevel5 : public TForm
{
__published:	// IDE-managed Components
        TImage *BG;
        TImage *Red;
        TImage *Green;
        TImage *Win;
        TShape *Shape1;
        TTimer *Launch;
        TTimer *Mover;
        TTimer *CheckPosition;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TShape *Shape5;
        TShape *Shape6;
        TShape *Shape7;
        TShape *Shape8;
        TShape *Shape9;
        TShape *Shape10;
        TShape *Shape11;
        TShape *Shape12;
        TShape *Shape13;
        TShape *Shape14;
        TShape *Shape15;
        TShape *Shape16;
        TShape *Shape17;
        TShape *Shape18;
        TShape *Shape19;
        TShape *Shape20;
        TShape *Shape21;
        TShape *Shape22;
        TShape *Shape23;
        TShape *Shape24;
        TShape *Shape25;
        TShape *Shape26;
        TShape *Shape27;
        void __fastcall LaunchTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall MoverTimer(TObject *Sender);
        void __fastcall CheckPositionTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall Tlevel5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlevel5 *level5;
//---------------------------------------------------------------------------
#endif
