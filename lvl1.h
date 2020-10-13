//---------------------------------------------------------------------------

#ifndef lvl1H
#define lvl1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tlevel1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *Launch;
        TImage *BG;
        TImage *Red;
        TImage *Green;
        TTimer *Mover;
        TImage *Win;
        void __fastcall LaunchTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall MoverTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlevel1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlevel1 *level1;
//---------------------------------------------------------------------------
#endif
