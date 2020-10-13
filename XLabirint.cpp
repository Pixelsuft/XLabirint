//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("main.cpp", MainForm);
USEFORM("lvl1.cpp", level1);
USEFORM("lvl2.cpp", level2);
USEFORM("lvl3.cpp", level3);
USEFORM("lvl4.cpp", level4);
USEFORM("lvl5.cpp", level5);
USEFORM("lvl6.cpp", level6);
USEFORM("lvl7.cpp", level7);
USEFORM("Editlvl.cpp", Editor);
USEFORM("customlvl.cpp", CustomLevel);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(Tlevel1), &level1);
                 Application->CreateForm(__classid(Tlevel2), &level2);
                 Application->CreateForm(__classid(Tlevel3), &level3);
                 Application->CreateForm(__classid(Tlevel4), &level4);
                 Application->CreateForm(__classid(Tlevel5), &level5);
                 Application->CreateForm(__classid(Tlevel6), &level6);
                 Application->CreateForm(__classid(Tlevel7), &level7);
                 Application->CreateForm(__classid(TEditor), &Editor);
                 Application->CreateForm(__classid(TCustomLevel), &CustomLevel);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
