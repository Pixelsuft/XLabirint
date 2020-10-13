//---------------------------------------------------------------------------

#ifndef lvl7H
#define lvl7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tlevel7 : public TForm
{
__published:	// IDE-managed Components
        TImage *BG;
        TImage *Red;
        TImage *Green;
        TImage *Win;
        TShape *Shape2;
        TShape *Shape4;
        TShape *Shape19;
        TTimer *Launch;
        TTimer *Mover;
        TTimer *CheckPosition;
        TShape *Shape1;
        TShape *Shape3;
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
        TShape *Shape20;
        TShape *Shape21;
        TShape *Shape22;
        TShape *Shape23;
        TShape *Shape24;
        TShape *Shape25;
        TShape *Shape26;
        TShape *Shape27;
        TShape *Shape28;
        TShape *Shape29;
        TShape *Shape30;
        TShape *Shape31;
        TShape *Shape32;
        TShape *Shape33;
        TShape *Shape34;
        TShape *Shape35;
        TShape *Shape36;
        TShape *Shape37;
        TShape *Shape38;
        TShape *Shape39;
        TShape *Shape40;
        TShape *Shape41;
        TShape *Shape42;
        TShape *Shape43;
        TShape *Shape44;
        TShape *Shape45;
        void __fastcall LaunchTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall CheckPositionTimer(TObject *Sender);
        void __fastcall MoverTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlevel7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlevel7 *level7;
//---------------------------------------------------------------------------
#endif
