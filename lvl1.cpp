//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "lvl1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlevel1 *level1;
AnsiString RedMove="";
AnsiString GreenMove="";
//---------------------------------------------------------------------------
__fastcall Tlevel1::Tlevel1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tlevel1::LaunchTimer(TObject *Sender)
{
        Launch->Enabled=false;
        MainForm->Visible=false;
        level1->ClientWidth=800;
        level1->ClientHeight=600;
        level1->Left=MainForm->Left;
        level1->Top=MainForm->Top;
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
        level1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlevel1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_ESCAPE){
                level1->Visible=false;
                MainForm->Left=level1->Left;
                MainForm->Top=level1->Top;
                Mover->Enabled=false;
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
void __fastcall Tlevel1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");        
}
//---------------------------------------------------------------------------
void __fastcall Tlevel1::MoverTimer(TObject *Sender)
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
                level1->Visible=false;
                MainForm->Left=level1->Left;
                MainForm->Top=level1->Top;
                Mover->Enabled=false;
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
                level1->Visible=false;
                MainForm->Left=level1->Left;
                MainForm->Top=level1->Top;
                Mover->Enabled=false;
                MainForm->Visible=true;
        }
}
//---------------------------------------------------------------------------
