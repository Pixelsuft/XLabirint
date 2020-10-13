//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TTimer *Startup;
        TImage *BG;
        TButton *HowToPlay;
        TButton *Players;
        TButton *l1;
        TButton *l2;
        TButton *l3;
        TButton *l4;
        TButton *l5;
        TButton *l6;
        TButton *l7;
        TButton *customl;
        TButton *Editl;
        void __fastcall StartupTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall HowToPlayClick(TObject *Sender);
        void __fastcall PlayersClick(TObject *Sender);
        void __fastcall l1Click(TObject *Sender);
        void __fastcall l2Click(TObject *Sender);
        void __fastcall l3Click(TObject *Sender);
        void __fastcall l4Click(TObject *Sender);
        void __fastcall l5Click(TObject *Sender);
        void __fastcall l6Click(TObject *Sender);
        void __fastcall l7Click(TObject *Sender);
        void __fastcall EditlClick(TObject *Sender);
        void __fastcall customlClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
