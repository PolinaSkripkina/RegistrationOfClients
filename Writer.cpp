//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Cab_full.cpp", Form_Cab);
USEFORM("Uni_grafw.cpp", Form_grafw);
USEFORM("Unit_About.cpp", Form_About);
USEFORM("Unit_d.cpp", Form_d);
USEFORM("Unit_data.cpp", Data1); /* TDataModule: File Type */
USEFORM("Unit_Pers.cpp", Form_Pers);
USEFORM("Unit_sel.cpp", Form_sel);
USEFORM("Unit_Calndr.cpp", Form_Calndr);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm_Cab), &Form_Cab);
                 Application->CreateForm(__classid(TForm_grafw), &Form_grafw);
                 Application->CreateForm(__classid(TForm_About), &Form_About);
                 Application->CreateForm(__classid(TForm_d), &Form_d);
                 Application->CreateForm(__classid(TData1), &Data1);
                 Application->CreateForm(__classid(TForm_Pers), &Form_Pers);
                 Application->CreateForm(__classid(TForm_sel), &Form_sel);
                 Application->CreateForm(__classid(TForm_Calndr), &Form_Calndr);
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
