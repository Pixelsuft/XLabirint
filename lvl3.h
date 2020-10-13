//---------------------------------------------------------------------------

#ifndef lvl3H
#define lvl3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tlevel3 : public TForm
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
        void __fastcall LaunchTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall MoverTimer(TObject *Sender);
        void __fastcall CheckPositionTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall Tlevel3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlevel3 *level3;
//---------------------------------------------------------------------------
#endif
