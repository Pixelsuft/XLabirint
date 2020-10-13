//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "lvl3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlevel3 *level3;
AnsiString GreenMove="";
AnsiString RedMove="";
//---------------------------------------------------------------------------
__fastcall Tlevel3::Tlevel3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tlevel3::LaunchTimer(TObject *Sender)
{
        Launch->Enabled=false;
        MainForm->Visible=false;
        level3->ClientWidth=800;
        level3->ClientHeight=600;
        level3->Left=MainForm->Left;
        level3->Top=MainForm->Top;
        BG->Left=0;
        BG->Top=0;
        if(MainForm->Players->Caption=="2 игрока")Green->Visible=true;
        else Green->Visible=false;
        GreenMove="";
        RedMove="";
        Red->Left=20;
        Red->Top=0;
        Green->Left=0;
        Green->Top=20;
        Win->Left=780;
        Win->Top=580;
        Mover->Enabled=true;
        CheckPosition->Enabled=true;
        level3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlevel3::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");           
}
//---------------------------------------------------------------------------
void __fastcall Tlevel3::MoverTimer(TObject *Sender)
{
if(GreenMove=="up" && Green->Top>0)Green->Top-=1;
        else if(GreenMove=="down" && Green->Top<600-Green->Height)Green->Top+=1;
        else if(GreenMove=="left" && Green->Left>0)Green->Left-=1;
        else if(GreenMove=="right" && Green->Left<800-Green->Width)Green->Left+=1;
        if(RedMove=="up" && Red->Top>0)Red->Top-=1;
        else if(RedMove=="down" && Red->Top<600-Red->Height)Red->Top+=1;
        else if(RedMove=="left" && Red->Left>0)Red->Left-=1;
        else if(RedMove=="right" && Red->Left<800-Red->Width)Red->Left+=1;
        if(Green->Left>779-20 && Green->Top>579-20)
        {
                Mover->Enabled=false;
                Application->MessageBox("Зелёный подебил, красный лох!","Information!",MB_ICONINFORMATION);
                level3->Visible=false;
                MainForm->Left=level3->Left;
                MainForm->Top=level3->Top;
                Mover->Enabled=false;       
                CheckPosition->Enabled=false;
                MainForm->Visible=true;
        }
        else if(Red->Left>779-20 && Red->Top>579-20)
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
                level3->Visible=false;
                MainForm->Left=level3->Left;
                MainForm->Top=level3->Top;
                Mover->Enabled=false;    
                CheckPosition->Enabled=false;
                MainForm->Visible=true;
        }        
}
//---------------------------------------------------------------------------
void __fastcall Tlevel3::CheckPositionTimer(TObject *Sender)
{
        for(int i=1;i<=12;i++){
                int SLeft=((TImage*)FindComponent("Shape"+IntToStr(i)))->Left;
                int STop=((TImage*)FindComponent("Shape"+IntToStr(i)))->Top;
                int SWidth=((TImage*)FindComponent("Shape"+IntToStr(i)))->Width;
                int SHeight=((TImage*)FindComponent("Shape"+IntToStr(i)))->Height;
                if(Red->Left>SLeft-20&&Red->Left<SLeft+SWidth&&Red->Top>STop-20&&Red->Top<STop+SHeight)
                {
                        Red->Top=0;
                        Red->Left=24;
                        RedMove="";
                }
                else if(Green->Left>SLeft-20&&Green->Left<SLeft+SWidth&&Green->Top>STop-20&&Green->Top<STop+SHeight)
                {
                        Green->Top=24;
                        Green->Left=0;
                        GreenMove="";
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall Tlevel3::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_ESCAPE){
                level3->Visible=false;
                MainForm->Left=level3->Left;
                MainForm->Top=level3->Top;
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
        else if(Key==VK_LEFT){
                RedMove="left";
        }
        else if(Key==VK_RIGHT){
                RedMove="right";
        }
        else if(Key==83 && MainForm->Players->Caption=="2 игрока"){
                GreenMove="down";
        }
        else if(Key==87 && MainForm->Players->Caption=="2 игрока"){
                GreenMove="up";
        }
        else if(Key==65 && MainForm->Players->Caption=="2 игрока"){
                GreenMove="left";
        }
        else if(Key==68 && MainForm->Players->Caption=="2 игрока"){
                GreenMove="right";
        }
}
//---------------------------------------------------------------------------
