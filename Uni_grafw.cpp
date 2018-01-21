//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Uni_grafw.h"
#include "Unit_d.h"
#include "Unit_data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_grafw *Form_grafw;
//---------------------------------------------------------------------------
__fastcall TForm_grafw::TForm_grafw(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_grafw::Button1Click(TObject *Sender)
{
//
int PerID,CabID,dd1,mm,yy1,ID;
float tn, tk;
   TDateTime dn, dk,  d_curr;
unsigned short year,  month,  day, hh1,mm1,hh2,mm2;
   AnsiString s1,s2,ss;
        Variant v[4]={0,0,0,0};
       Variant v1[5];
d_curr=DateTimePicker1->Date;
d_curr.DecodeDate(&year,  &month,&day);
 int index;
index= ComboBox1->ItemIndex;

tn= 8 + index*15./60.;
  tk=8.25 + (ComboBox2->ItemIndex*15./60.);
  //d1=EncodeDateTime(year,month,day,9,0,0,0);   //47
 dn=EncodeDate((Word)year,(Word)month,(Word)day);
  dn=dn+ tn*3600./86400.;
    dk=EncodeDate((Word)year,(Word)month,(Word)day);
  dk=dk+ tk*3600./86400.;
   s1=DateTimeToStr(dk);
dd1=DayOf(dn);
mm=MonthOf(dn);
yy1=YearOf(dn);
 if(!DBLookupComboBox1->Text.IsEmpty())
                 {
 if(ComboBox1->ItemIndex>=0&&ComboBox2->ItemIndex>=0){
 PerID=Data1->Person->FieldByName("ID")->AsInteger;
      v[0]=PerID; v[1]=dd1; v[2]=mm; v[3]=yy1;

  Data1->Temp1->SQL->Clear();
//Data1->Temp1->SQL->Add(" Select ID from GrafikWork where Stat=1 and PerID=:i1  and ");
//Data1->Temp1->SQL->Add(" (DATEPART(dd,TN_w)=:i2 and DATEPART(mm,TN_w)=:i3 and DATEPART(yy,TN_w)=:i4 )");
Data1->Temp1->SQL->Add(" delete from GrafikWork where Stat=1 and PerID=:i0  and DATEPART(dd,TN_w)=:i1 and DATEPART(mm,TN_w)=:i2 and DATEPART(yy,TN_w)=:i3 ");
for(int i=0;i<4;i++)
  Data1->Temp1->Parameters->Items[i]->Value  = v[i];
Data1->Temp1->Prepared = true;        Data1->Temp1->ExecSQL();

           /*
 for (Data1->Temp1->First();!Data1->Temp1->Eof;Data1->Temp1->Next())
 {
  ID=Data1->Temp1->FieldByName("ID")->AsInteger;
Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add(" delete from GrafikWork where ID="+IntToStr(ID));
     Data1->Temp->ExecSQL();

}                                                            */

     Data1->Temp1->Close();Data1->Temp1->SQL->Clear();
Data1->Temp1->SQL->Add("Select *  from PerCabs where PerID="+IntToStr(PerID));
Data1->Temp1->Open();
 if(dn<dk) {
 for (Data1->Temp1->First();!Data1->Temp1->Eof;Data1->Temp1->Next())
 {
  CabID=Data1->Temp1->FieldByName("CabID")->AsInteger;
    v1[0]=PerID; v1[1]=dn; v1[2]=dk; v1[3]=1; v1[4]=CabID;

Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add(" Insert into GrafikWork  (PerID,TN_w,TK_w,Stat,CabID) VALUES (:i1, :i2, :i3, :i4, :i5)");
for(int j=0;j<5;j++)
  Data1->Temp->Parameters->Items[j]->Value  = v1[j];
Data1->Temp->Prepared = true;        Data1->Temp->ExecSQL();

 }


     ShowMessage("¬ÌÂÒÂÌÓ");
               } else ShowMessage("¬ÂÏˇ Ì‡˜‡Î‡ ·ÓÎ¸¯Â ‚ÂÏÂÌË ÓÍÓÌ˜‡ÌËˇ");

             } else  ShowMessage("¬–≈Ãﬂ Õ≈À‹«ﬂ –≈ƒ¿ “»–Œ¬¿“‹!¬€¡≈–»“≈ ¬–≈Ãﬂ »« —œ»— ¿ » œŒ¬“Œ–»“≈!!!");

              }


else      ShowMessage("¬˚ ÌÂ ‚˚·‡ÎË ‚‡˜‡");
}
//---------------------------------------------------------------------------






void __fastcall TForm_grafw::Button2Click(TObject *Sender)
{
//
int PerID,CabID,dd1,mm,yy1,ID;
float tn, tk;
   TDateTime  d1,d2, d_curr;
unsigned short year,  month,  day, hh1,mm1,hh2,mm2;
   AnsiString s1,s2,ss;
       Variant v1[5];
                Variant v[4]={0,0,0,0};
d_curr=DateTimePicker2->Date;
d_curr.DecodeDate(&year,  &month,&day);


  d1=EncodeDate((Word)year,(Word)month,(Word)day);

dd1=DayOf(d1);
mm=MonthOf(d1);
yy1=YearOf(d1);

    d2=EncodeDate((Word)year,(Word)month,(Word)day);
 tn= 8 + (ComboBox3->ItemIndex-1)*15./60.;
  tk=8.25 + (ComboBox4->ItemIndex-1)*15./60.;
  d1=d1+ tn*3600./86400.;
       d2=d2+ tk*3600./86400.;
        if(!DBLookupComboBox1->Text.IsEmpty())
                {
 if(ComboBox3->ItemIndex>=0&&ComboBox4->ItemIndex>=0){
 PerID=Data1->Person->FieldByName("ID")->AsInteger;
          v[0]=PerID; v[1]=dd1; v[2]=mm; v[3]=yy1;

  Data1->Temp1->SQL->Clear();
Data1->Temp1->SQL->Add(" delete from GrafikWork where Stat=0 and PerID=:i0  and DATEPART(dd,TN_w)=:i1 and DATEPART(mm,TN_w)=:i2 and DATEPART(yy,TN_w)=:i3 ");
for(int i=0;i<4;i++)
  Data1->Temp1->Parameters->Items[i]->Value  = v[i];
Data1->Temp1->Prepared = true;        Data1->Temp1->ExecSQL();

     Data1->Temp1->Close();Data1->Temp1->SQL->Clear();
Data1->Temp1->SQL->Add("Select *  from PerCabs where PerID="+IntToStr(PerID));
Data1->Temp1->Open();
   if(d1<d2) {
 for (Data1->Temp1->First();!Data1->Temp1->Eof;Data1->Temp1->Next())
 {
  CabID=Data1->Temp1->FieldByName("CabID")->AsInteger;
   v1[0]=PerID; v1[1]=d1; v1[2]=d2; v1[3]=0; v1[4]=CabID;
      if(ComboBox3->ItemIndex>0 && ComboBox4->ItemIndex>0)
          {

Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add(" Insert into GrafikWork  (PerID,TN_w,TK_w,Stat,CabID) VALUES (:i1, :i2, :i3, :i4, :i5)");
for(int j=0;j<5;j++)
  Data1->Temp->Parameters->Items[j]->Value  = v1[j];
Data1->Temp->Prepared = true;        Data1->Temp->ExecSQL();
          }
 }
/*       ComboBox3->ItemIndex=0;
      ComboBox4->ItemIndex=0;*/
      Data1->Person->Close();Data1->Person->Open();
     ShowMessage("¬ÌÂÒÂÌÓ");
         }   else ShowMessage("¬ÂÏˇ Ì‡˜‡Î‡ ·ÓÎ¸¯Â ‚ÂÏÂÌË ÓÍÓÌ˜‡ÌËˇ");
  }// if(ComboBox3->ItemIndex>=0&&ComboBox4->ItemIndex>=0){
              else  ShowMessage("¬–≈Ãﬂ Õ≈À‹«ﬂ –≈ƒ¿ “»–Œ¬¿“‹!¬€¡≈–»“≈ ¬–≈Ãﬂ »« —œ»— ¿ » œŒ¬“Œ–»“≈!!!");
             }
else      ShowMessage("¬˚ ÌÂ ‚˚·‡ÎË ‚‡˜‡");
}
//---------------------------------------------------------------------------

void __fastcall TForm_grafw::Button3Click(TObject *Sender)
{
//
int PerID,CabID,dd1,mm,yy1,ID;
float tn, tk;
   TDateTime  d1,d2, d_curr;
unsigned short year,  month,  day, hh1,mm1,hh2,mm2;
   AnsiString s1,s2,ss;
       Variant v1[5];
                Variant v[4]={0,0,0,0};
d_curr=DateTimePicker2->Date;
d_curr.DecodeDate(&year,  &month,&day);


  d1=EncodeDate((Word)year,(Word)month,(Word)day);

dd1=DayOf(d1);
mm=MonthOf(d1);
yy1=YearOf(d1);

    d2=EncodeDate((Word)year,(Word)month,(Word)day);
 tn= 9 + (ComboBox3->ItemIndex-1)*15./60.;
  tk=9.25 + (ComboBox4->ItemIndex-1)*15./60.;
  d1=d1+ tn*3600./86400.;
       d2=d2+ tk*3600./86400.;
        if(!DBLookupComboBox1->Text.IsEmpty())
           {
 PerID=Data1->Person->FieldByName("ID")->AsInteger;
          v[0]=PerID; v[1]=dd1; v[2]=mm; v[3]=yy1;

Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add("select  pc.ID as ID from Write_Client pc");
Data1->Temp->SQL->Add("where pc.Status<>5 and pc.PerID =:i0 and DATEPART(dd,pc.Date_w)=:i1 and DATEPART(mm,pc.Date_w)=:i2 and DATEPART(yy,pc.Date_w)=:i3  ");
   for(int i=0;i<4;i++)    Data1->Temp->Parameters->operator [](i)->Value=v[i];
Data1->Temp->ExecSQL(); Data1->Temp->Open();

if( Data1->Temp->RecordCount ==0){
  Data1->Temp1->SQL->Clear();
Data1->Temp1->SQL->Add(" delete from GrafikWork where Stat=1 and PerID=:i0  and DATEPART(dd,TN_w)=:i1 and DATEPART(mm,TN_w)=:i2 and DATEPART(yy,TN_w)=:i3 ");
for(int i=0;i<4;i++)
  Data1->Temp1->Parameters->Items[i]->Value  = v[i];
Data1->Temp1->Prepared = true;        Data1->Temp1->ExecSQL();
     ShowMessage("—‰ÂÎ‡ÌÓ");  }
     else        ShowMessage("≈ÒÚ¸ Á‡ÔËÒ¸ Ì‡ ˝ÚÓÚ ‰ÂÌ¸!"); 
          }
}
//---------------------------------------------------------------------------

void __fastcall TForm_grafw::Button4Click(TObject *Sender)
{
int PerID,CabID,dd1,mm,yy1,ID;
float tn, tk;
   TDateTime  d1,d2, d_curr;
unsigned short year,  month,  day, hh1,mm1,hh2,mm2;
   AnsiString s1,s2,ss;
       Variant v1[5];
                Variant v[4]={0,0,0,0};
d_curr=DateTimePicker2->Date;
d_curr.DecodeDate(&year,  &month,&day);


  d1=EncodeDate((Word)year,(Word)month,(Word)day);

dd1=DayOf(d1);
mm=MonthOf(d1);
yy1=YearOf(d1);

        if(!DBLookupComboBox1->Text.IsEmpty())
           {
 PerID=Data1->Person->FieldByName("ID")->AsInteger;
          v[0]=PerID; v[1]=dd1; v[2]=mm; v[3]=yy1;

  Data1->Temp1->SQL->Clear();
Data1->Temp1->SQL->Add(" delete from GrafikWork where Stat=0 and PerID=:i0  and DATEPART(dd,TN_w)=:i1 and DATEPART(mm,TN_w)=:i2 and DATEPART(yy,TN_w)=:i3 ");
for(int i=0;i<4;i++)
  Data1->Temp1->Parameters->Items[i]->Value  = v[i];
Data1->Temp1->Prepared = true;        Data1->Temp1->ExecSQL();
     ShowMessage("—‰ÂÎ‡ÌÓ");
          }

}
//---------------------------------------------------------------------------


