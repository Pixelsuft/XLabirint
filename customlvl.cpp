//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "customlvl.h"  
#include "Editlvl.h"
bool in_editor=false;
int strok=0;
int shapes=0;
int speed=1;
int redleft=20;
int redtop=0;
int greenleft=0;
int greentop=20;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCustomLevel *CustomLevel; 
AnsiString RedMove="";
AnsiString GreenMove="";
//---------------------------------------------------------------------------
__fastcall TCustomLevel::TCustomLevel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCustomLevel::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im XLabirint.exe");              
}
//---------------------------------------------------------------------------
void __fastcall TCustomLevel::LaunchTimer(TObject *Sender)
{
        Launch->Enabled=false;
        if(OpenLevel->Execute()){
        in_editor=false;
        MainForm->Visible=false;
        LevelStr->Lines->LoadFromFile(OpenLevel->FileName);
        strok=StrToInt(LevelStr->Lines->Strings[0]);
        shapes=StrToInt(LevelStr->Lines->Strings[1]);
        CustomLevel->ClientWidth=800;
        CustomLevel->ClientHeight=600;   
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
        speed=1;
        for(int i=1;i<101;i++)
        {
                ((TImage*)FindComponent("Shape"+IntToStr(i)))->Left=-600;
        }
        for(int i=2;i<strok;i+=5)
        {
                if(LevelStr->Lines->Strings[i]=="Speed")
                {
                        speed=StrToInt(LevelStr->Lines->Strings[i+1]);
                        i+=2;
                }
                ((TImage*)FindComponent(LevelStr->Lines->Strings[i]))->Left=StrToInt(LevelStr->Lines->Strings[i+1]);
                ((TImage*)FindComponent(LevelStr->Lines->Strings[i]))->Top=StrToInt(LevelStr->Lines->Strings[i+2]);
                ((TImage*)FindComponent(LevelStr->Lines->Strings[i]))->Width=StrToInt(LevelStr->Lines->Strings[i+3]);
                ((TImage*)FindComponent(LevelStr->Lines->Strings[i]))->Height=StrToInt(LevelStr->Lines->Strings[i+4]);
        }
        redleft=Red->Left;
        redtop=Red->Top;
        greenleft=Green->Left;
        greentop=Green->Top;
        CustomLevel->Visible=true;    
        Mover->Enabled=true;
        CheckPosition->Enabled=true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TCustomLevel::EditLaunchTimer(TObject *Sender)
{
        EditLaunch->Enabled=false;   
        in_editor=true;
        CustomLevel->ClientWidth=800;
        CustomLevel->ClientHeight=600;
        strok=StrToInt(Editor->Edit->Lines->Strings[0]);
        shapes=StrToInt(Editor->Edit->Lines->Strings[1]);   
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
        speed=1;
        for(int i=1;i<101;i++)
        {
                ((TImage*)FindComponent("Shape"+IntToStr(i)))->Left=-600;
        }
        for(int i=2;i<strok;i+=5)
        {
                if(Editor->Edit->Lines->Strings[i]=="Speed")
                {
                        speed=StrToInt(Editor->Edit->Lines->Strings[i+1]);
                        i+=2;
                }
                ((TImage*)FindComponent(Editor->Edit->Lines->Strings[i]))->Left=StrToInt(Editor->Edit->Lines->Strings[i+1]);
                ((TImage*)FindComponent(Editor->Edit->Lines->Strings[i]))->Top=StrToInt(Editor->Edit->Lines->Strings[i+2]);
                ((TImage*)FindComponent(Editor->Edit->Lines->Strings[i]))->Width=StrToInt(Editor->Edit->Lines->Strings[i+3]);
                ((TImage*)FindComponent(Editor->Edit->Lines->Strings[i]))->Height=StrToInt(Editor->Edit->Lines->Strings[i+4]);
        }   
        redleft=Red->Left;
        redtop=Red->Top;
        greenleft=Green->Left;
        greentop=Green->Top;
        CustomLevel->Visible=true;  
        Mover->Enabled=true;
        CheckPosition->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TCustomLevel::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_ESCAPE)
        {
                Mover->Enabled;
                CheckPosition->Enabled=false;
                if(in_editor==true)CustomLevel->Visible=false;
                else
                {
                        CustomLevel->Visible=false;
                        MainForm->Visible=true;
                }
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

void __fastcall TCustomLevel::MoverTimer(TObject *Sender)
{
        if(GreenMove=="up" && Green->Top>0)Green->Top-=speed;
        else if(GreenMove=="down" && Green->Top<600-Green->Height)Green->Top+=speed;
        else if(GreenMove=="left" && Green->Left>0)Green->Left-=speed;
        else if(GreenMove=="right" && Green->Left<800-Green->Width)Green->Left+=speed;
        if(RedMove=="up" && Red->Top>0)Red->Top-=speed;
        else if(RedMove=="down" && Red->Top<600-Red->Height)Red->Top+=speed;
        else if(RedMove=="left" && Red->Left>0)Red->Left-=speed;
        else if(RedMove=="right" && Red->Left<800-Red->Width)Red->Left+=speed;
        int SLeft=Win->Left;
        int STop=Win->Top;
        int SWidth=Win->Width;
        int SHeight=Win->Height;

        if(Green->Left>SLeft-Green->Width&&Green->Left<SLeft+SWidth&&Green->Top>STop-Green->Height&&Green->Top<STop+SHeight)
        {
                Mover->Enabled=false;
                Application->MessageBox("Зелёный подебил, красный лох!","Information!",MB_ICONINFORMATION);
                CustomLevel->Visible=false;
                Mover->Enabled=false;
                CheckPosition->Enabled=false;
                if(in_editor==false)MainForm->Visible=true;
        }
        else if(Red->Left>SLeft-Red->Width&&Red->Left<SLeft+SWidth&&Red->Top>STop-Red->Height&&Red->Top<STop+SHeight)
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
                CustomLevel->Visible=false;
                Mover->Enabled=false;    
                CheckPosition->Enabled=false;
                if(in_editor==false)MainForm->Visible=true;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TCustomLevel::CheckPositionTimer(TObject *Sender)
{
        for(int i=1;i<=shapes;i++){
                int SLeft=((TImage*)FindComponent("Shape"+IntToStr(i)))->Left;
                int STop=((TImage*)FindComponent("Shape"+IntToStr(i)))->Top;
                int SWidth=((TImage*)FindComponent("Shape"+IntToStr(i)))->Width;
                int SHeight=((TImage*)FindComponent("Shape"+IntToStr(i)))->Height;
                if(Red->Left>SLeft-Red->Width&&Red->Left<SLeft+SWidth&&Red->Top>STop-Red->Height&&Red->Top<STop+SHeight)
                {
                        Red->Top=redtop;
                        Red->Left=redleft;
                        RedMove="";
                }
                else if(Green->Left>SLeft-Green->Width&&Green->Left<SLeft+SWidth&&Green->Top>STop-Green->Height&&Green->Top<STop+SHeight)
                {
                        Green->Top=greentop;
                        Green->Left=greenleft;
                        GreenMove="";
                }
        }        
}
//---------------------------------------------------------------------------

