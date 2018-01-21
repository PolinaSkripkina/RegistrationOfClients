//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>

#pragma hdrstop

#include "Unit_Calndr.h"

#include "Unit_data.h"
#include "Unit_main.h"
#include "Unit_Pers.h"
#include "Cab_full.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PlannerMonthView"
//#pragma link "PictureContainer"
#pragma link "Planner"
#pragma resource "*.dfm"
TForm_Calndr *Form_Calndr;
//---------------------------------------------------------------------------
__fastcall TForm_Calndr::TForm_Calndr(TComponent* Owner)
        : TForm(Owner)
{
  sh_f=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Calndr::PlannerMonthView1DaySelect(TObject *Sender,
      TDateTime SelDate)
{
int n_it;
int du;
double ddd1, t_z;
TDateTime d1,d2, d_n, d_e;
unsigned short y1, m1,dd1,hh1,mm1,ss1,mss1 ;
AnsiString s1,s2;





n_it = PlannerMonthView1->Items->Count;
//n_it = PlannerMonthView1->Items->NumItemsAtDate(SelDate) ;
TPlannerItem *plIt;
for(int i=0;i<n_it;i++)
if (PlannerMonthView1->Items->Items[i]->Selected)
    {
    plIt=PlannerMonthView1->Items->Items[i];

    // if(plIt->Color ==32768){

      d1= plIt->ItemStartTime;

  d_n=plIt->ItemStartTime;
  d_e=plIt->ItemEndTime;
 //d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
     //s1=DateTimeToStr(Form_Shed->d_end);
     

    if(sh_f)     {
 Form_Cab->d_n =d_n;
 s1=DateTimeToStr(d_n);
 if(Form_Cab->sh_f)   {
 Form_Cab->DateEdit1->Date=d_n;
 //Form_Cab->ReShowCab(d_n, d_n+1);
 //ShowModal() ;
 Close();     }
 }



                     //    }

    }


}
//---------------------------------------------------------------------------
void __fastcall TForm_Calndr::FormShow(TObject *Sender)
{
//
float prop_h, prop_w;
prop_h = 1.4;
prop_w = 1.6;
Width = Screen->Width/prop_w;
if(Screen->Height/prop_h >700)
Height= Screen->Height/prop_h;
else {if(Screen->Height>700) Height=700; else Height=Screen->Height;}
Top = (Screen->Height - Height)/2;
Left= (Screen->Width - Width)/2;

TDateTime d1,d2,tbegin,tend;
unsigned short year,  month,  day;
//d1.CurrentDate()
AnsiString ss, s2,sn,sk;
int workID;
bool stat=true;
double ddd1, t_z;
int dd1,i;
d1=Now();
 d1.DecodeDate(&year,  &month,&day);
dd1=DayOf(d1);
 tbegin = EncodeDateTime(year,  month,  1,0,0,0,0);
if (month==12) {year=year+1;month=1;}
else month=month+1;
tend = EncodeDateTime(year,  month,  1,0,0,0,0);

Variant v[3]={tbegin,tend,Form_Pers->PerID};

PlannerMonthView1->Date =  d1.CurrentDate();//  Now();
TPlannerItem *plIt;

Variant v1[3]={0,0,0};
 v1[2]=  Form_Pers->PerID;

for(i=0;i<31;i++)
{

v1[0]=tbegin+i;
v1[1]=tbegin+i+1;

Data1->Shed->SQL->Clear();
Data1->Shed->SQL->Add("select per.Name as Name, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat");
Data1->Shed->SQL->Add("from GrafikWork sc ");
Data1->Shed->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID");
Data1->Shed->SQL->Add("where sc.Stat=1 and (sc.TN_w between :i1 and :i2) and sc.PerID=:i3 order by sc.TN_w");
      for(int j=0;j<3;j++)
   Data1->Shed->Parameters->Items[j]->Value  = v1[j];
Data1->Shed->ExecSQL();
Data1->Shed->Open();
 if(Data1->Shed->RecordCount>0)
 {
 Data1->Shed->First();
 ss=Data1->Shed->FieldByName("Name")->AsString.Trim();
 d1=Data1->Shed->FieldByName("b")->AsFloat;//FieldValues["ScBegTime"];
    d2=Data1->Shed->FieldByName("e")->AsFloat;
 sn=Data1->Shed->FieldByName("b")->AsDateTime.FormatString("hh:nn");
   sk=Data1->Shed->FieldByName("e")->AsDateTime.FormatString("hh:nn");
  s2=sn+"-"+sk;
    plIt = PlannerMonthView1->Items->Add();
  plIt->ItemStartTime = d1;
  plIt->ItemEndTime = d2;
  plIt->ID = PerID;

  plIt->Shadow =false;
  plIt->CaptionText=ss;
  plIt->CaptionType =1;

   plIt->CaptionBkgDirection=1;
  plIt->CaptionType =1;
  plIt->CaptionBkg=clGreen ;
        plIt->CaptionBkgTo=clWhite ;

  //  plIt->ShowDeleteButton=true;
   plIt->CompletionDisplay = cdNone;
  plIt->Selected =false;
  plIt->ShowSelection =false;
  plIt->TrackVisible =false;
      plIt->Text->Text = s2;
  plIt->Color =clGreen;

 }
Data1->Shed->SQL->Clear();
Data1->Shed->SQL->Add("select per.Name as Name, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat");
Data1->Shed->SQL->Add("from GrafikWork sc ");
Data1->Shed->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID");
Data1->Shed->SQL->Add("where sc.Stat=0 and (sc.TN_w between :i1 and :i2) and sc.PerID=:i3 order by sc.TN_w");
      for(int j=0;j<3;j++)
   Data1->Shed->Parameters->Items[j]->Value  = v1[j];
Data1->Shed->ExecSQL();Data1->Shed->Open();
 if(Data1->Shed->RecordCount>0)
 {
 Data1->Shed->First();
 ss=Data1->Shed->FieldByName("Name")->AsString.Trim();
 d1=Data1->Shed->FieldByName("b")->AsFloat;//FieldValues["ScBegTime"];
    d2=Data1->Shed->FieldByName("e")->AsFloat;
 sn=Data1->Shed->FieldByName("b")->AsDateTime.FormatString("hh:nn");
   sk=Data1->Shed->FieldByName("e")->AsDateTime.FormatString("hh:nn");
  s2=sn+"-"+sk;

    plIt = PlannerMonthView1->Items->Add();
  plIt->ItemStartTime = d1;
  plIt->ItemEndTime = d2;
  plIt->ID = PerID;

  plIt->Shadow =false;
 plIt->CaptionText="Запрет"+ss;
  plIt->CaptionBkgDirection=1;
  plIt->CaptionType =1;
  plIt->CaptionBkg=clRed ;
        plIt->CaptionBkgTo=clWhite ;
   // plIt->ShowDeleteButton=true;
   plIt->CompletionDisplay = cdNone;

  plIt->Selected =false;
  plIt->ShowSelection =false;
  plIt->TrackVisible =false;
    plIt->Text->Text = s2;
  plIt->Color =clRed;

 }

}

     sh_f=true;
}
//---------------------------------------------------------------------------





void __fastcall TForm_Calndr::FormClose(TObject *Sender,
      TCloseAction &Action)
{

sh_f=false;
int n_it;
n_it = PlannerMonthView1->Items->Count;
PlannerMonthView1->Items->UnSelectAll() ;
TPlannerItem *plIt;
//n_it = PlannerMonthView1->Items->NumItemsAtDate(SelDate) ;
//Form_Shed->Planner1->Items->ClearAll();
PlannerMonthView1->Items->ClearAll();

}
//---------------------------------------------------------------------------


void TForm_Calndr::ShowShed(TDateTime newDate)
{
 //

TDateTime d1,d2,tbegin,tend;
//d1.CurrentDate()
AnsiString ss,s1,s2,sn,sk;
 bool stat=true;
 int i,dd1;
 unsigned short year,  month,  day;
d1=PlannerMonthView1->Date;// =  d1.CurrentDate();//  Now();
 d1.DecodeDate(&year,  &month,&day);
dd1=DayOf(d1);

ss=DateTimeToStr(newDate);
newDate.DecodeDate(&year,  &month,&day);
s1=IntToStr(month)+"."+"01."+IntToStr(year);
if (month==12) s2="01.01."+IntToStr(year+1);
else
 s2= IntToStr(month+1)+"."+"01."+IntToStr(year);

 newDate= newDate -day+1;
tbegin=newDate;
tend=newDate+30;

tbegin = EncodeDateTime(year,  month,  1,0,0,0,0);
if (month==12) {year=year+1;month=1;}
else month=month+1;
tend = EncodeDateTime(year,  month,  1,0,0,0,0);
TPlannerItem *plIt;


Variant v1[3]={0,0,0};
 v1[2]=  Form_Pers->PerID;

for(i=0;i<31;i++)
{

v1[0]=tbegin+i;
v1[1]=tbegin+i+1;

Data1->Shed->SQL->Clear();
Data1->Shed->SQL->Add("select per.Name as Name, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat");
Data1->Shed->SQL->Add("from GrafikWork sc ");
Data1->Shed->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID");
Data1->Shed->SQL->Add("where sc.Stat=1 and (sc.TN_w between :i1 and :i2) and sc.PerID=:i3 order by sc.TN_w");
      for(int j=0;j<3;j++)
   Data1->Shed->Parameters->Items[j]->Value  = v1[j];
Data1->Shed->ExecSQL();
Data1->Shed->Open();
 if(Data1->Shed->RecordCount>0)
 {
 Data1->Shed->First();
 ss=Data1->Shed->FieldByName("Name")->AsString.Trim();
 d1=Data1->Shed->FieldByName("b")->AsFloat;//FieldValues["ScBegTime"];
    d2=Data1->Shed->FieldByName("e")->AsFloat;
 sn=Data1->Shed->FieldByName("b")->AsDateTime.FormatString("hh:nn");
   sk=Data1->Shed->FieldByName("e")->AsDateTime.FormatString("hh:nn");
  s2=sn+"-"+sk;
    plIt = PlannerMonthView1->Items->Add();
  plIt->ItemStartTime = d1;
  plIt->ItemEndTime = d2;
  plIt->ID = PerID;

  plIt->Shadow =false;
  plIt->CaptionText=ss;
  plIt->CaptionType =1;

   plIt->CaptionBkgDirection=1;
  plIt->CaptionType =1;
  plIt->CaptionBkg=clGreen ;
        plIt->CaptionBkgTo=clWhite ;
   plIt->CompletionDisplay = cdNone;
   // plIt->ShowDeleteButton=true;
  plIt->Selected =false;
  plIt->ShowSelection =false;
  plIt->TrackVisible =false;
      plIt->Text->Text = s2;
  plIt->Color =clGreen;

 }
Data1->Shed->SQL->Clear();
Data1->Shed->SQL->Add("select per.Name as Name, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat");
Data1->Shed->SQL->Add("from GrafikWork sc ");
Data1->Shed->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID");
Data1->Shed->SQL->Add("where sc.Stat=0 and (sc.TN_w between :i1 and :i2) and sc.PerID=:i3 order by sc.TN_w");
      for(int j=0;j<3;j++)
   Data1->Shed->Parameters->Items[j]->Value  = v1[j];
Data1->Shed->ExecSQL();Data1->Shed->Open();
 if(Data1->Shed->RecordCount>0)
 {
 Data1->Shed->First();
 ss=Data1->Shed->FieldByName("Name")->AsString.Trim();
 d1=Data1->Shed->FieldByName("b")->AsFloat;//FieldValues["ScBegTime"];
    d2=Data1->Shed->FieldByName("e")->AsFloat;
  sn=Data1->Shed->FieldByName("b")->AsDateTime.FormatString("hh:nn");
   sk=Data1->Shed->FieldByName("e")->AsDateTime.FormatString("hh:nn");
  s2=sn+"-"+sk;
    plIt = PlannerMonthView1->Items->Add();
  plIt->ItemStartTime = d1;
  plIt->ItemEndTime = d2;
  plIt->ID = PerID;

  plIt->Shadow =false;
 plIt->CaptionText="Запрет"+ss;
  plIt->CaptionBkgDirection=1;
  plIt->CaptionType =1;
  plIt->CaptionBkg=clRed ;
        plIt->CaptionBkgTo=clWhite ;
   plIt->CompletionDisplay = cdNone;
    plIt->ShowDeleteButton=true;
  plIt->Selected =false;
  plIt->ShowSelection =false;
  plIt->TrackVisible =false;
    plIt->Text->Text = s2;
  plIt->Color =clRed;

 }

}




}
void __fastcall TForm_Calndr::PlannerMonthView1DateChange(TObject *Sender,
      TDateTime origDate, TDateTime newDate)
{
//
PlannerMonthView1->Items->ClearAll();
AnsiString s1;
s1= DateTimeToStr( newDate);
ShowShed(newDate);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Calndr::PlannerMonthView1ItemDblClick(
      TObject *Sender, TPlannerItem *Item)
{
//
}
//---------------------------------------------------------------------------

