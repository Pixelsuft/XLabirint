//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "lvl1.h"
#include "lvl2.h"
#include "lvl3.h"
#include "lvl4.h" 
#include "lvl5.h"
#include "lvl6.h"  
#include "lvl7.h" 
#include "Editlvl.h"
#include "customlvl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartupTimer(TObject *Sender)
{
        Startup->Enabled=false;
        MainForm->ClientWidth=800;
        MainForm->ClientHeight=600;
        MainForm->Left=Screen->Width/2-MainForm->Width/2;
        MainForm->Top=Screen->Height/2-MainForm->Height/2;
        BG->Left=0;
        BG->Top=0;
        MainForm->AlphaBlendValue=255;
        MainForm->AlphaBlend=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HowToPlayClick(TObject *Sender)
{
        Application->MessageBox("Управление:\n   Зелёный: WASD\n   Красный: СтрелОчки\n   ESCape - Выход в меню","Information!",MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PlayersClick(TObject *Sender)
{
        if(Players->Caption=="1 игрок")Players->Caption="2 игрока";
        else Players->Caption="1 игрок";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::l1Click(TObject *Sender)
{
        level1->Launch->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::l2Click(TObject *Sender)
{
        level2->Launch->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::l3Click(TObject *Sender)
{
        level3->Launch->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::l4Click(TObject *Sender)
{
        level4->Launch->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::l5Click(TObject *Sender)
{
        level5->Launch->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::l6Click(TObject *Sender)
{
        level6->Launch->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::l7Click(TObject *Sender)
{
        level7->Launch->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EditlClick(TObject *Sender)
{
        Editor->Launch->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::customlClick(TObject *Sender)
{
        CustomLevel->Launch->Enabled=true;
}
//---------------------------------------------------------------------------

