//---------------------------------------------------------------------------

#ifndef EditlvlH
#define EditlvlH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TEditor : public TForm
{
__published:	// IDE-managed Components
        TTimer *Launch;
        TLabel *StrokCap;
        TEdit *Strok;
        TButton *Ex;
        TButton *Test;
        TLabel *ShapeCap;
        TEdit *Shapes;
        TMemo *Edit;
        TButton *Saver;
        TSaveDialog *SaveSave;
        TOpenDialog *OpenSave;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall LaunchTimer(TObject *Sender);
        void __fastcall ExClick(TObject *Sender);
        void __fastcall SaverClick(TObject *Sender);
        void __fastcall TestClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEditor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditor *Editor;
//---------------------------------------------------------------------------
#endif
