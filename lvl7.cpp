//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "lvl7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlevel7 *level7;   
AnsiString RedMove="";
AnsiString GreenMove="";
bool s2=false;
bool s19=false;
//---------------------------------------------------------------------------
__fastcall Tlevel7::Tlevel7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tlevel7::LaunchTimer(TObject *Sender)
{
        Launch->Enabled=false;
        MainForm->Visible=false;
        level7->ClientWidth=800;
        level7->ClientHeight=600;
        level7->Left=MainForm->Left;
        level7->Top=MainForm->Top;
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
        level7->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlevel7::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");        
}
//---------------------------------------------------------------------------
void __fastcall Tlevel7::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_ESCAPE){
                level7->Visible=false;
                MainForm->Left=level7->Left;
                MainForm->Top=level7->Top;
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
void __fastcall Tlevel7::CheckPositionTimer(TObject *Sender)
{
        for(int i=1;i<=45;i++){
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
void __fastcall Tlevel7::MoverTimer(TObject *Sender)
{
        if(Green->Top<0 && level7->Top>=0)level7->Top-=1;
        else if(Green->Top>600-Green->Height && level7->Top<Screen->Height-600)level7->Top+=1;
        else if(Green->Left<0 && level7->Left>=0)level7->Left-=1;
        else if(Green->Left>800-Green->Height && level7->Left<Screen->Width-800)level7->Left+=1;
        if(GreenMove=="up" && Green->Top>-1)Green->Top-=1;
        else if(GreenMove=="down" && Green->Top<601-Green->Height)Green->Top+=1;
        else if(GreenMove=="left" && Green->Left>-1)Green->Left-=1;
        else if(GreenMove=="right" && Green->Left<801-Green->Width)Green->Left+=1;
        if(Red->Top<0 && level7->Top>=0)level7->Top-=1;
        else if(Red->Top>600-Red->Height && level7->Top<Screen->Height-600)level7->Top+=1;
        else if(Red->Left<0 && level7->Left>=0)level7->Left-=1;
        else if(Red->Left>800-Red->Height && level7->Left<Screen->Width-800)level7->Left+=1;
        if(RedMove=="up" && Red->Top>-1)Red->Top-=1;
        else if(RedMove=="down" && Red->Top<601-Red->Height)Red->Top+=1;
        else if(RedMove=="left" && Red->Left>-1)Red->Left-=1;
        else if(RedMove=="right" && Red->Left<801-Red->Width)Red->Left+=1;
        if(Green->Left>779-20 && Green->Top>579-20)
        {
                Mover->Enabled=false;
                Application->MessageBox("Зелёный подебил, красный лох!","Information!",MB_ICONINFORMATION);
                level7->Visible=false;
                MainForm->Left=level7->Left;
                MainForm->Top=level7->Top;
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
                level7->Visible=false;
                MainForm->Left=level7->Left;
                MainForm->Top=level7->Top;
                Mover->Enabled=false;    
                CheckPosition->Enabled=false;
                MainForm->Visible=true;
        }
        if(Shape2->Left<0)s2=true;
        else if(Shape2->Left>800-Shape2->Width)s2=false;
        if(s2==true)Shape2->Left+=2;
        else Shape2->Left-=2;

        if(Shape19->Left<0)s19=true;
        else if(Shape19->Left>800-Shape19->Width)s19=false;
        if(s19==true)Shape19->Left+=1;
        else Shape19->Left-=1;
}
//---------------------------------------------------------------------------
