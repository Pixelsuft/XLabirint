//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "Editlvl.h"
#include "customlvl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditor *Editor;
//---------------------------------------------------------------------------
__fastcall TEditor::TEditor(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEditor::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");        
}
//---------------------------------------------------------------------------
void __fastcall TEditor::LaunchTimer(TObject *Sender)
{
        Launch->Enabled=false;
        MainForm->Visible=false;
        if(OpenSave->Execute())
        {
                Edit->Lines->LoadFromFile(OpenSave->FileName);
                Strok->Text=Edit->Lines->Strings[0];
                Shapes->Text=Edit->Lines->Strings[1];
        }
        Editor->Visible=true;        
}
//---------------------------------------------------------------------------
void __fastcall TEditor::ExClick(TObject *Sender)
{
        Editor->Visible=false;
        CustomLevel->Visible=false;
        MainForm->Visible=true;        
}
//---------------------------------------------------------------------------
void __fastcall TEditor::SaverClick(TObject *Sender)
{
        if(SaveSave->Execute())
        {
                Edit->Lines->Strings[0]=Strok->Text;
                Edit->Lines->Strings[1]=Shapes->Text;
                Edit->Lines->SaveToFile(SaveSave->FileName + ".xlab");
        }
}
//---------------------------------------------------------------------------
void __fastcall TEditor::TestClick(TObject *Sender)
{
        Edit->Lines->Strings[0]=Strok->Text;
        Edit->Lines->Strings[1]=Shapes->Text;
        CustomLevel->EditLaunch->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TEditor::FormResize(TObject *Sender)
{
        Edit->Left=8;
        Edit->Top=32;
        Edit->Width=Editor->ClientWidth-16;
        Edit->Height=Editor->ClientHeight-40;
}
//---------------------------------------------------------------------------
