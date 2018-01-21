//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_sel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXCtrls"
#pragma resource "*.dfm"
TForm_sel *Form_sel;
//---------------------------------------------------------------------------
__fastcall TForm_sel::TForm_sel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_sel::FormClose(TObject *Sender, TCloseAction &Action)
{
//
/*if( CheckListBox1->ItemIndex==-1)
{     ;

}
else{
int kk=0;
 for (int i = 0; i < CheckListBox1->Items->Count; i++)
   if (CheckListBox1->Selected[i])
{      DName=CheckListBox1->Items->Strings[i];
        DName=DName.Trim();
        kk++;
}
if(kk==CheckListBox1->Items->Count&&kk>1)
    {
 ShowMessage("Нужно выбрать одного врача!!!");
     ModalResult=mrNone;
        return;
}
 }*/
}
//---------------------------------------------------------------------------





void __fastcall TForm_sel::FormShow(TObject *Sender)
{
//
RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_sel::Button1Click(TObject *Sender)
{
 int kk=0;
 for (int i = 0; i < CheckListBox1->Items->Count; i++)
   if (CheckListBox1->Checked[i])
{      DName=CheckListBox1->Items->Strings[i];
        DName=DName.Trim();
        kk++;
}
if(kk!=1)
    {
 ShowMessage("Нужно выбрать одного врача!!!");
     ModalResult=mrNone;
        return;
    }
}
//---------------------------------------------------------------------------

