//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "lvl4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlevel4 *level4;
AnsiString RedMove="";
AnsiString GreenMove="";
//---------------------------------------------------------------------------
__fastcall Tlevel4::Tlevel4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tlevel4::LaunchTimer(TObject *Sender)
{
        Launch->Enabled=false;
        MainForm->Visible=false;
        level4->ClientWidth=800;
        level4->ClientHeight=600;
        level4->Left=MainForm->Left;
        level4->Top=MainForm->Top;
        BG->Left=0;
        BG->Top=0;
        if(MainForm->Players->Caption=="2 игрока")Green->Visible=true;
        else Green->Visible=false;
        GreenMove="";
        RedMove="";
        Red->Left=0;
        Red->Top=256;
        Green->Left=0;
        Green->Top=284;
        Win->Left=780;
        Win->Top=0;
        Mover->Enabled=true;
        CheckPosition->Enabled=true;
        level4->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlevel4::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");           
}
//---------------------------------------------------------------------------
void __fastcall Tlevel4::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_ESCAPE){
                level4->Visible=false;
                MainForm->Left=level4->Left;
                MainForm->Top=level4->Top;
                Mover->Enabled=false;
                CheckPosition->Enabled=false;
                MainForm->Visible=true;
        }
        else if(Key==VK_DOWN){
                RedMove="down";
        }
        else if(Key==VK_UP){
                RedMove="up";
        }
        else if(Key==83 && MainForm->Players->Caption=="2 игрока"){
                GreenMove="down";
        }
        else if(Key==87 && MainForm->Players->Caption=="2 игрока"){
                GreenMove="up";
        }
}
//---------------------------------------------------------------------------
void __fastcall Tlevel4::MoverTimer(TObject *Sender)
{
        if(GreenMove=="up" && Green->Top>0)Green->Top-=2;
        else if(GreenMove=="down" && Green->Top<600-Green->Height)Green->Top+=2;
        if(RedMove=="up" && Red->Top>0)Red->Top-=2;
        else if(RedMove=="down" && Red->Top<600-Red->Height)Red->Top+=2;
        Red->Left+=1;
        if(MainForm->Players->Caption=="2 игрока")Green->Left+=1;
        if(Green->Left>779-20)
        {
                Mover->Enabled=false;
                Application->MessageBox("Зелёный подебил, красный лох!","Information!",MB_ICONINFORMATION);
                level4->Visible=false;
                MainForm->Left=level4->Left;
                MainForm->Top=level4->Top;
                Mover->Enabled=false;       
                CheckPosition->Enabled=false;
                MainForm->Visible=true;
        }
        if(Red->Left>779-20)
        {
                Mover->Enabled=false;
                if(MainForm->Players->Caption=="2 игрока")
                {
                        Application->MessageBox("Красный подебил, зелёный лох!","Information!",MB_ICONINFORMATION);
                }
                else
                {
                        Application->MessageBox("Капец ты долгий!","Information!",MB_ICONINFORMATION);
                }
                level4->Visible=false;
                MainForm->Left=level4->Left;
                MainForm->Top=level4->Top;
                Mover->Enabled=false;    
                CheckPosition->Enabled=false;
                MainForm->Visible=true;
        }        
}
//---------------------------------------------------------------------------
void __fastcall Tlevel4::CheckPositionTimer(TObject *Sender)
{
        for(int i=1;i<=10;i++){
                int SLeft=((TImage*)FindComponent("Shape"+IntToStr(i)))->Left;
                int STop=((TImage*)FindComponent("Shape"+IntToStr(i)))->Top;
                int SWidth=((TImage*)FindComponent("Shape"+IntToStr(i)))->Width;
                int SHeight=((TImage*)FindComponent("Shape"+IntToStr(i)))->Height;
                if(Red->Left>SLeft-20&&Red->Left<SLeft+SWidth&&Red->Top>STop-20&&Red->Top<STop+SHeight)
                {
                        Red->Left=0;
                        Red->Top=256;
                }
                else if(Green->Left>SLeft-20&&Green->Left<SLeft+SWidth&&Green->Top>STop-20&&Green->Top<STop+SHeight)
                {
                        Green->Left=0;
                        Green->Top=284;
                }
        }
}
//---------------------------------------------------------------------------
