//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_Pers.h"
#include "Unit_data.h"
#include "Unit_Calndr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Pers *Form_Pers;
//---------------------------------------------------------------------------
__fastcall TForm_Pers::TForm_Pers(TComponent* Owner)
        : TForm(Owner)
{
pr=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Pers::DBGrid1DblClick(TObject *Sender)
{
//
TDateTime d1,d2,tbegin,tend;
AnsiString s1,s2,ss;
unsigned short year,  month,  day;

d1=Now();

 d1.DecodeDate(&year,  &month,&day);
s1= d1.FormatString("mm.01.yyyy");
if (month==12) s2="01.01."+IntToStr(year+1);
else
 s2= IntToStr(month+1)+"."+"01."+IntToStr(year);


PerID=Data1->Person->FieldByName("ID")->AsInteger;

 Data1->Shed->Close();
Data1->Shed->SQL->Clear();
Data1->Shed->SQL->Add("select per.Name as Name, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat");
Data1->Shed->SQL->Add("from GrafikWork sc ");
Data1->Shed->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID");
Data1->Shed->SQL->Add("where (sc.TN_w between :i1 and :i2) and sc.PerID=:i3 order by sc.TN_w");

tbegin = EncodeDateTime(year,  month,  1,0,0,0,0);
if (month==12) {year=year+1;month=1;}
else month=month+1;
tend = EncodeDateTime(year,  month,  1,0,0,0,0);

Variant v[3]={tbegin,tend,PerID};
 for(int i=0;i<3;i++)
   Data1->Shed->Parameters->Items[i]->Value  = v[i];
Data1->Shed->ExecSQL();
Data1->Shed->Open();

Form_Calndr->ShowModal() ;

 Close();


}
//---------------------------------------------------------------------------


void __fastcall TForm_Pers::FormShow(TObject *Sender)
{
float prop_h, prop_w;
prop_h = 1.94;
prop_w = 2.3;
Width = Screen->Width/prop_w;
Height= Screen->Height/prop_h;
Top = (Screen->Height - Height)/2;
Left= (Screen->Width - Width)/2;
}
//---------------------------------------------------------------------------

