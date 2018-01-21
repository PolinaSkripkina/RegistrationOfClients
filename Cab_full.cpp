//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Cab_full.h"
//#include "CalcAutoOle.h"
#include "Unit_Shed.h"
#include "Unit_sel.h"
#include "Unit_data.h"
#include "Unit_About.h"
#include "Unit_Pers.h"
#include "Uni_grafw.h"
#include "Unit_Calndr.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "Planner"

#pragma resource "*.dfm"
TForm_Cab *Form_Cab;
//---------------------------------------------------------------------------
__fastcall TForm_Cab::TForm_Cab(TComponent* Owner)
        : TForm(Owner)
{
  next_d=false;
  prf=0;
}
//---------------------------------------------------------------------------







void __fastcall TForm_Cab::Planner1PlannerNext(TObject *Sender)
{
//
TDateTime d1,d2;
int w1, dd1, mm1, yy1;
AnsiString  s1, s2;
dd1=Planner1->Mode->PeriodStartDay;
mm1=Planner1->Mode->PeriodStartMonth;
yy1=Planner1->Mode->PeriodStartYear;
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
d1=d1+1;
    s1=DateTimeToStr(d1);

d2=d1+1;
if(sh_f){
Planner1->Items->Clear();
//ReShowCab(d1,d2);
DateEdit1->Date=d1;

}
}
//---------------------------------------------------------------------------


void __fastcall TForm_Cab::Planner1PlannerPrev(TObject *Sender)
{
//
TDateTime d1,d2;
int w1, dd1, mm1, yy1;
AnsiString  s1, s2;
dd1=Planner1->Mode->PeriodStartDay;
mm1=Planner1->Mode->PeriodStartMonth;
yy1=Planner1->Mode->PeriodStartYear;
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
d1=d1-1;
    s1=DateTimeToStr(d1);

d2=d1+1;
if(sh_f){
Planner1->Items->Clear();
//ReShowCab(d1,d2);
DateEdit1->Date=d1;

}



}
//---------------------------------------------------------------------------

bool TForm_Cab::ReShowCab(TDateTime d1, TDateTime d2)
{
int ii=0, w1, id, ID_w,dd1,mm, yy1, perid,i=0,un, stat,pos, it_pos,i_b,  i_e;
unsigned short hh1,mm1,sss1,mss1,hh2,mm2,sss2,mss2, ht1,mt1,ht2,mt2, mn, mk ;
 char days[7][11] = {"Понедельник", "Вторник    ", "Среда      ", "Четверг    ", "Пятница    ", "Суббота    ", "Воскресенье" };
     bool zapr, zz;
TDateTime dt, bd, ed, dn, dk;
 Variant v1[4];
AnsiString PName, CName, sn, sk, ss1, s1, s2;


dd1=DayOf(d1);
mm=MonthOf(d1);
yy1=YearOf(d1);
Planner1->Mode->PeriodStartDay = dd1;
Planner1->Mode->PeriodStartMonth = mm;
Planner1->Mode->PeriodStartYear = yy1;
        d1=EncodeDate((Word)yy1,(Word)mm,(Word)dd1);

    // DateEdit1->Date=d1;

        dd1=DayOf(d2);
mm1=MonthOf(d2);
yy1=YearOf(d2);
Planner1->Mode->PeriodEndDay = dd1;
Planner1->Mode->PeriodEndMonth = mm1;
Planner1->Mode->PeriodEndYear = yy1;

un=Planner1->Display->DisplayStart;
MTemp->SQL->Clear();
MTemp->SQL->Add("Select * from Cabinet order by ID");
MTemp->Open();

//TPlannerItem *plCab, *plCab2;
Planner1->Items->Clear();
Planner1->Overlap=true;
 dt=d1;
//for (dt=d1;dt<d2;dt=dt+1)            {

dd1=DayOf(dt);
mm=MonthOf(dt);
yy1=YearOf(dt);

v1[0]=dd1;
v1[1]=mm;
v1[2]=yy1;

 w1=DayOfTheWeek(dt);
 Label1->Caption = "";
 if(w1==7)
     Label1->Caption ="Воскресенье";
 if(w1==1)
     Label1->Caption ="Понедельник";
 if(w1==2)
     Label1->Caption ="Вторник";
 if(w1==3)
     Label1->Caption ="Среда";
 if(w1==6)
     Label1->Caption ="Суббота";
 if(w1==4)
     Label1->Caption ="Четверг";
 if(w1==5)
     Label1->Caption ="Пятница";
// Label1->Caption = days[w1 - 1];
      ProgressBar1->Position =0;
      ii=0;
 for (MTemp->First();!MTemp->Eof;MTemp->Next())
{
dt=d1;
     id= MTemp->FieldByName("ID")->AsInteger;
     it_pos = ii;//id-1;
     ii++;
  /*
switch(id)
        {
        case 28:
        it_pos = 4;
        break;

        case 29:
        it_pos = 2;
        break;

        case 30:
        it_pos = 1;
                break;
        case 31:
       it_pos = 0;
        break;

        case 33:
        it_pos = 3;
        break;

        case 34:
       it_pos = 5;
        break;

        case 35:
        it_pos = 6;
        break;

        case 36:
      it_pos = 7;
        break;
        default:   ;
           }
*/
     v1[3]=id;
     ss1+="";
 MTemp1->SQL->Clear();
 MTemp1->SQL->Add("select per.Name as PName, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat ");
MTemp1->SQL->Add(" from GrafikWork sc ");
MTemp1->SQL->Add(" inner join PersonalView  per on per.ID=sc.PerID ");
MTemp1->SQL->Add(" where DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  ");
MTemp1->SQL->Add(" and sc.CabID=:i4   order by sc.TN_w");
 for(int i=0;i<4;i++)    MTemp1->Parameters->operator [](i)->Value=v1[i];
MTemp1->ExecSQL(); MTemp1->Open();
ss1="";
i=0;
 hh1=mm1=hh2=mm2=0;
if(MTemp1->RecordCount>0) {
//  ShowGrafik(id,it_pos,dd1, mm, yy1, hh1*60+mm1, hh2*60+mm2);
     ShowGrafik(id,it_pos,dd1, mm, yy1, 8*60, 21*60);
}



 if(sh_f)
   ProgressBar1->Position+=10;
 }  //for Cab

          ii=0;
 for (MTemp->First();!MTemp->Eof;MTemp->Next())
{
    id= MTemp->FieldByName("ID")->AsInteger;
    it_pos = ii;//id-1;
    ii++;
             /*
switch(id)
        {
        case 28:
        it_pos = 4;
        break;

        case 29:
        it_pos = 2;
        break;

        case 30:
        it_pos = 1;
                break;
        case 31:
       it_pos = 0;
        break;

        case 33:
        it_pos = 3;
        break;

        case 34:
       it_pos = 5;
        break;

        case 35:
        it_pos = 6;
        break;

        case 36:
      it_pos = 7;
        break;
        default:   ;
           }
           */
     v1[3]=id;
 MTemp2->SQL->Clear();
MTemp2->SQL->Add("select  per.Name as PName, pc.ID as ID, isNull(pc.Status,1) as stat, pc.Comment as Comment, pc.PerID,pc.Name as Name, cc.Name as CName,pc.Date_w as tn, pc.Date_end as tk, ");
MTemp2->SQL->Add(" DATEPART(hh,pc.Date_w)*60+DATEPART(mi,pc.Date_w) as mn, DATEPART(hh,pc.Date_end)*60+DATEPART(mi,pc.Date_end) as mk from Write_Client pc");
MTemp2->SQL->Add("inner join PersonalView  per on per.ID=pc.PerID ");
MTemp2->SQL->Add("inner join Cabinet cc on cc.ID=pc.CabID ");
MTemp2->SQL->Add("where pc.Status<>5 and DATEPART(dd,pc.Date_w)=:i1 and DATEPART(mm,pc.Date_w)=:i2 and DATEPART(yy,pc.Date_w)=:i3  ");
MTemp2->SQL->Add(" and pc.CabID=:i4  order by pc.Date_w ");
 for(int i=0;i<4;i++)    MTemp2->Parameters->operator [](i)->Value=v1[i];
MTemp2->ExecSQL(); MTemp2->Open();
CName="";
PName="";
  for (MTemp2->First();!MTemp2->Eof;MTemp2->Next())
{
 bd=MTemp2->FieldByName("tn")->AsDateTime;
 ed=MTemp2->FieldByName("tk")->AsDateTime;
 mn=MTemp2->FieldByName("mn")->AsInteger;
  mk=MTemp2->FieldByName("mk")->AsInteger;
     stat=MTemp2->FieldByName("stat")->AsInteger;
  ID_w=MTemp2->FieldByName("ID")->AsInteger;
     CName=MTemp2->FieldByName("Name")->AsString.Trim();
PName=MTemp2->FieldByName("PName")->AsString.Trim();
s1=MTemp2->FieldByName("Comment")->AsString;
ss1=CName+" " +s1;

 perid=MTemp2->FieldByName("PerID")->AsInteger;
   i_b= mn/15 - Planner1->Display->DisplayStart;
     i_e= mk/15 - Planner1->Display->DisplayStart;
     if(stat!=5)
  UpdWrite(perid, it_pos, id, i_b,  i_e, ID_w, stat, PName,ss1 );


                               }  //      for (MTemp2->First();!MTemp2->Eof;MTemp2->Next())



 if(sh_f)
   ProgressBar1->Position+=10;
}


  ProgressBar1->Position=0;
        return(1);


}
void __fastcall TForm_Cab::FormShow(TObject *Sender)
{
//
TDateTime d1,d2;
int w1, dd1, mm1, yy1;
AnsiString CName;
  next_d=false;
  prf=0;
   ProgressBar1->Position=0;
//d1=d_n;
d1=Now();
DateEdit1->Date=d1;

w1=DayOfTheWeek(d1);

d2=d1+1;
//ReShowCab(d1,d2);
sh_f=true;
///Timer1->Enabled =true;
prd=false;
MTemp->SQL->Clear();
MTemp->SQL->Add("Select * from Cabinet order by ID");
MTemp->Open();
    Planner1->Positions = MTemp->RecordCount;
    Planner1->Header->Captions->Add(" ");

    TPlannerStringList* MyList = new TPlannerStringList();
       MyList->Add(" ");
 for (MTemp->First();!MTemp->Eof;MTemp->Next())
{
  CName=MTemp->FieldByName("Name")->AsString.Trim();
      MyList->Add(CName);
}
     Planner1->Header->Captions->Clear();

         Planner1->Header->Captions->AddStrings(MyList);
       delete MyList;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Button1Click(TObject *Sender)
{
//
int w1, id, dd1, mm1, yy1, perid, mi=0;
TDateTime dt, bd, ed, d1, d2;
 Variant v1[4];
AnsiString PName, CName, sn, sk, ss1, s1;
//d1=DateTimePicker1->DateTime;
/*d1=DateEdit1->Date;
dd1=1;
mm1=MonthOf(d1);
yy1=YearOf(d1);
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
dd1=DaysInMonth(d1);
d2=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);

 CalcAutoOle *OO = new CalcAutoOle;
 OO->connect();
 OO->loadDocument(false);
 AnsiString ts;
 int i=0;
 OO->getSheet(0);
 OO->setActiveSheet();
 OO->setSheetName("Кабинеты");

 ts="ЗАГРУЖЕННОСТЬ КАБИНЕТОВ НА "+DateEdit1->Date.FormatString("mmmm.yyyy");
OO->putTextToCell(1,i,ts.c_str());
OO->setFontBold();
i++;
i++;

MTemp->SQL->Clear();
MTemp->SQL->Add("Select * from Cabinet order by ID");
MTemp->Open();
int j=0, nd=0;
for (MTemp->First();!MTemp->Eof;MTemp->Next())
{
     j++;
     CName=MTemp->FieldByName("Name")->AsString.Trim();
     OO->putTextToCell(j,2,CName.c_str());
     OO->setFontBold();
     OO->setColumnWidth(j,6000);
}
i++;
OO->getCellRange( 0, 2, j, 3);
OO->drawRangeBorders( 2, 70);
OO->drawRangeBorders( 3, 70);
OO->drawRangeBorders( 4, 70);
OO->drawRangeBorders( 5, 70);
OO->drawRangeBorders( 7, 30);
OO->drawRangeBorders( 8, 30);

j=0;
for (dt=d1;dt<=d2;dt=dt+1)
        {

    i++;
dd1=DayOf(dt);
mm1=MonthOf(dt);
yy1=YearOf(dt);
   ts=DateTimeToStr(dt);
   OO->putTextToCell(0,i,ts.c_str());


v1[0]=dd1;
v1[1]=mm1;
v1[2]=yy1;
j=0;
nd=i;
mi=0;
for (MTemp->First();!MTemp->Eof;MTemp->Next())
{
     j++;
     id= MTemp->FieldByName("ID")->AsInteger;
     CName=MTemp->FieldByName("Name")->AsString.Trim();
     v1[3]=id;



MTemp1->SQL->Clear();
MTemp1->SQL->Add("select per.Name as PName, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e ");
MTemp1->SQL->Add(" from GrafikWork sc ");
MTemp1->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID ");
//MTemp1->SQL->Add("inner join PerCabs pc on per.ID=pc.PerID ");
MTemp1->SQL->Add("where sc.Stat=1 and DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  ");
MTemp1->SQL->Add(" and sc.CabID=:i4  order by sc.TN_w");
 for(int i=0;i<4;i++)    MTemp1->Parameters->operator [](i)->Value=v1[i];
MTemp1->ExecSQL(); MTemp1->Open();
ss1="";

if (mi<MTemp1->RecordCount) mi=MTemp1->RecordCount;
nd=i;
for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())
{
 PName=MTemp1->FieldByName("PName")->AsString.Trim();
// perid=MTemp1->FieldByName("PerID")->AsInteger;
 bd=MTemp1->FieldByName("b")->AsDateTime;
 s1=DateTimeToStr(bd);
 sn=MTemp1->FieldByName("b")->AsDateTime.FormatString("hh:nn");
   ed=MTemp1->FieldByName("e")->AsDateTime;
  s1=DateTimeToStr(ed);
    sk=MTemp1->FieldByName("e")->AsDateTime.FormatString("hh:nn");
ss1=PName+" "+ sn+"-"+sk;
    OO->putTextToCell(j,nd,ss1.c_str());
    nd++;
}
//mi=MTemp1->RecordCount;

  }
i=i+mi+1;
OO->getCellRange( 0, i, j, i);
OO->drawRangeBorders( 3, 70);


}
for(mi=0;mi<=j;mi++)
{
OO->getCellRange( mi, 2, mi, i);
OO->drawRangeBorders( 4, 70);
//OO->drawRangeBorders( 5, 70);
}
OO->getCellRange( j, 2, j, i);
OO->drawRangeBorders( 5, 70);


OO->setColumnWidth(0,2500);



delete OO;      */
}
//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Planner1ItemDblClick(TObject *Sender,
      TPlannerItem *Item)
{
//
int CabID, id, PerID, ProfID, i_b, i_e, n1,n2, index, pos,du, tn, tk, i=0, ID_w, dt, mn, mk;
TDateTime d1,d2, d_n, d_e, dk;
AnsiString ss, s1,s2,PName, CName;
unsigned short dd1, mm1, yy1,hh1, mmm1, ss1,mss1;
bool zapr;
 Variant v1[6];

Variant v[9]={0,0,0,0,0,0,0,0,0};
dd1=Planner1->Mode->PeriodStartDay;
  mm1=Planner1->Mode->PeriodStartMonth;
     yy1=Planner1->Mode->PeriodStartYear;
  n1=Item->ItemBegin;
  i_b=n1;
   n2=Item->ItemEnd;
   pos=Item->ItemPos;
     id=Item->ImageID;
   index=Item->Index;
   ss=Item->Text->Text;
   ID_w=Item->ID;
       bool kk;
       kk=ss.IsEmpty();
      tn=(Planner1->Display->DisplayStart+n1)*900; //время начала в секундах n1*3600/4
      tk=tn+15*60;
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
d2=d1+1;
d_n=d1+tn/86400.;
d_e=d1+tk/86400.;
     CabID=id;//pos+1;
     /*
     switch(pos)
        {
        case 4:
        CabID=28;
        break;

        case 2:
        CabID=29;
        break;

        case 1:
        CabID=30;
        break;

        case 0:
        CabID=31;
        break;

        case 3:
        CabID=33;
        break;

        case 5:
        CabID=34;
        break;

        case 6:
        CabID=35;
        break;

        case 7:
        CabID=36;
        break;

        default:   ;
           }     */
if (!kk)
      {

 if(Item->Color==clSilver)
 {
/*s1=ss.SubString(0,ss.AnsiPos(" ")-1);
 Form_sel->RadioGroup2->Items->Strings[0]=s1;
s2=ss.SubString(ss.AnsiPos(" ")+1, ss.Length()); */
s2=ss;
pos=ss.AnsiPos(" ");
i=0;
// Form_sel->RadioGroup2->Items->Clear();
 Form_sel->CheckListBox1->Items->Clear();


v1[0]=dd1;
v1[1]=mm1;
v1[2]=yy1;
v1[3]=CabID;
v1[4]=tn/60;
v1[5]=tk/60;

 MTemp1->SQL->Clear();
MTemp1->SQL->Add("select per.Name as PName, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat, ");
MTemp1->SQL->Add("DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w) as mn, DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w) as mk from GrafikWork sc ");
MTemp1->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID ");
  MTemp1->SQL->Add("where sc.Stat=1 and DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  ");
MTemp1->SQL->Add(" and sc.CabID=:i4  ");

 for(int i=0;i<4;i++)    MTemp1->Parameters->operator [](i)->Value=v1[i];
MTemp1->ExecSQL(); MTemp1->Open();
for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())
{
 n1=MTemp1->FieldByName("mn")->AsInteger;
 dk= MTemp1->FieldByName("e")->AsDateTime;
  s1=DateTimeToStr(dk);
  n2=MTemp1->FieldByName("mk")->AsInteger;
   PName=MTemp1->FieldByName("PName")->AsString.Trim();
   PerID=MTemp1->FieldByName("PerID")->AsInteger;
if(n1<=v1[4]&&n2>=v1[5])
{
 MTemp3->SQL->Clear();
MTemp3->SQL->Add("select per.Name as PName, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat, ");
MTemp3->SQL->Add("DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w) as mn, DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w) as mk from GrafikWork sc ");
MTemp3->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID ");
  MTemp3->SQL->Add("where sc.Stat=0 and DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  ");
MTemp3->SQL->Add(" and sc.CabID=:i4 and (DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w)<=:i5 and DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w)>=:i6)  and sc.PerID=:i7  ");

 for(int i=0;i<6;i++)    MTemp3->Parameters->operator [](i)->Value=v1[i];
   MTemp3->Parameters->operator [](6)->Value=PerID;
MTemp3->ExecSQL(); MTemp3->Open(); i=0;
  if(MTemp3->RecordCount==0)  {
   MTemp3->SQL->Clear();
MTemp3->SQL->Add("select  pc.ID as ID, isNull(pc.Status,1) as stat, pc.PerID, DATEPART(hh,pc.Date_w)*60+DATEPART(mi,pc.Date_w) as mn, DATEPART(hh,pc.Date_end)*60+DATEPART(mi,pc.Date_end) as mk, pc.Date_w as tn, pc.Date_end as tk ");
MTemp3->SQL->Add(" from Write_Client pc");
MTemp3->SQL->Add("where pc.Status<>5 and DATEPART(dd,pc.Date_w)=:i1 and DATEPART(mm,pc.Date_w)=:i2 and DATEPART(yy,pc.Date_w)=:i3  ");
MTemp3->SQL->Add(" and pc.CabID<>:i4 and (DATEPART(hh,pc.Date_w)*60+DATEPART(mi,pc.Date_w)<=:i5 and  DATEPART(hh,pc.Date_end)*60+DATEPART(mi,pc.Date_end)>=:i6) and pc.PerID=:i7  ");
 for(int i=0;i<6;i++)    MTemp3->Parameters->operator [](i)->Value=v1[i];
   MTemp3->Parameters->operator [](6)->Value=PerID;
MTemp3->ExecSQL(); MTemp3->Open();
 if(MTemp3->RecordCount==0)
     Form_sel->CheckListBox1->Items->Add(PName);
                             } //  if(MTemp3->RecordCount>0

                         } //if(n1<=v1[4]&&n2>=v1[5])
}  //for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())


/*
i=0;s1="";s2="";pos=0;

 while(pos<s2.Length()&& pos>0)
{
s1=s2.SubString(0,pos);
 Form_sel->CheckListBox1->Items->Add(s1);
s2=s2.SubString(pos+1, s2.Length());
pos=s2.AnsiPos(" ");
i++;
 }
*/
Form_sel->CheckListBox1->MultiSelect=false;

if(Form_sel->CheckListBox1->Items->Count==1) {Form_sel->CheckListBox1->ItemIndex=0;

                                   Form_sel->CheckListBox1->Checked[0]=true;}
 else
    Form_sel->CheckListBox1->ItemIndex=-1;
Form_sel->DName="";
Form_sel->RadioGroup1->ItemIndex =0;
         if (Form_sel->ShowModal()==mrOk)
             {
   PName=Form_sel->DName;
MTemp1->SQL->Clear();
MTemp1->SQL->Add("select per.Name as PName, pc.CabID,pc.PerID as PerID, Profession.ID as ProfID");
MTemp1->SQL->Add(" from PersonalView  per ");
MTemp1->SQL->Add("inner join PerCabs pc on per.ID=pc.PerID ");
MTemp1->SQL->Add(" INNER JOIN Profession ON per.PCIdent = Profession.ID ");
MTemp1->SQL->Add("where pc.CabID="+IntToStr(CabID)+" and  per.Name like '"+Form_sel->DName+"%'");
MTemp1->Open();
if(MTemp1->RecordCount>0)
{
       PerID=MTemp1->FieldByName("PerID")->AsInteger;
       ProfID=MTemp1->FieldByName("ProfID")->AsInteger;
       PName=MTemp1->FieldByName("PName")->AsString.Trim();
}
else {PerID=0; ProfID=0;PName=" ";}
               if(prf<2){
Data1->WriServ->Close();
Data1->WriServ->Parameters->operator [](0)->Value=ProfID;
Data1->WriServ->ExecSQL();
Data1->WriServ->Open();
   if(!next_d)        {
  Form_About->Edit1->Text="";
  Form_About->Edit2->Text="8(000)0000000";   Form_About->Edit4->Text="";
                     }
    Form_About->Edit3->Text="";
        
  Form_About->Memo1->Lines->Clear();
    Form_About->ComboBox1->ItemIndex=0;
      Form_About->shag=0;
/*Form_About->CheckListBox3->MultiSelect =false;

                              Form_About->CheckListBox3->Checked[3]=false;
                              Form_About->CheckListBox3->Checked[1]=false;
                              Form_About->CheckListBox3->Checked[2]=false;
                              Form_About->CheckListBox3->Checked[0]=false;

      if(Form_sel->RadioGroup1->ItemIndex ==0)
        {
          Form_About->GroupBox1->Enabled = false;
     Form_About->GroupBox1->Visible =false;

        }
    else   {
          Form_About->GroupBox1->Enabled = true;
     Form_About->GroupBox1->Visible =true;
        }    */
                             }//if(prf<2)
 if(Form_About->ShowModal()==1)
 {


 MTemp1->SQL->Clear();
MTemp1->SQL->Add("select sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat,");
MTemp1->SQL->Add("DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w) as mn, DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w) as mk from GrafikWork sc ");
  MTemp1->SQL->Add(" where sc.Stat=1 and DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  ");
MTemp1->SQL->Add(" and sc.CabID=:i4 and sc.PerID= "+IntToStr(PerID));

 for(int i=0;i<4;i++)    MTemp1->Parameters->operator [](i)->Value=v1[i];
MTemp1->ExecSQL(); MTemp1->Open();
for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())
{
 n1=MTemp1->FieldByName("mn")->AsInteger;


  n2=MTemp1->FieldByName("mk")->AsInteger;

if(n1<=v1[4]&&n2>=v1[5])

  dk= MTemp1->FieldByName("e")->AsDateTime;
}
s1=DateTimeToStr(dk);
 dt=Form_About->shag;//minutes
 s1=DateTimeToStr(d_n);
 d_e=d_n+dt*60./86400;

 s2=DateTimeToStr(d_e);
 CName=Form_About->Name.UpperCase();;
 v[0]=PerID;
v[1]=Form_About->Name.UpperCase();
v[2]=Form_About->Phone.Trim();
v[3]=Form_About->Comment;
v[4]=d_n;
v[5]=d_e;
v[6]=Form_About->Prim.Trim();
v[7]=CabID;
v[8]=Form_About->stat;

  MTemp3->SQL->Clear();
MTemp3->SQL->Add("select pc.Date_w as tn, pc.Date_end as tk from Write_Client pc");
MTemp3->SQL->Add("where pc.Status<>5 and (pc.Date_w>=:i1 and pc.Date_w<:i2) and (pc.CabID=:i3 or pc.PerID=:i4)");
 MTemp3->Parameters->operator [](0)->Value=v[4];
   MTemp3->Parameters->operator [](1)->Value=v[5];
      MTemp3->Parameters->operator [](2)->Value=v[7];
            MTemp3->Parameters->operator [](3)->Value=v[0];
MTemp3->ExecSQL(); MTemp3->Open();
if(MTemp3->RecordCount >0){
MTemp3->First() ;
 ShowMessage("Запись пересекается с другой записью врача");

                           }
else //if(MTemp3->RecordCount >0
                          {
 int sel;
   sel=0;
     if(d_e<=dk)    sel=6;
      else    sel=Application->MessageBox("Запись вне зоны графика врача.Продолжить?","Предупреждение",MB_YESNO);
if(sel==6){

/*for(int j=1;j<=9;j++)
  Data1->Writer->Parameters->Items[j]->Value  = v[j];  */
  Data1->Writer->Parameters->operator [](1)->Value=PerID;
  Data1->Writer->Parameters->operator [](2)->Value=Form_About->Name.UpperCase();
  Data1->Writer->Parameters->operator [](3)->Value=Form_About->Phone.Trim();
  Data1->Writer->Parameters->operator [](4)->Value=Form_About->Comment;
  Data1->Writer->Parameters->operator [](5)->Value=d_n;
Data1->Writer->Parameters->operator [](6)->Value=d_e;
     Data1->Writer->Parameters->operator [](7)->Value=Form_About->Prim.Trim();
  Data1->Writer->Parameters->operator [](8)->Value=CabID;
    Data1->Writer->Parameters->operator [](9)->Value=Form_About->stat;
 Data1->Writer->Parameters->operator [](10)->Value=Form_About->Milo.Trim();
//Data1->Writer->Prepared = true;
Data1->Writer->ExecProc();//Data1->Writer->Open();
sel=0;
   sel=Application->MessageBox("Клиент будет записываться к другому врачу?","Предупреждение",MB_YESNO);
   if(sel==6)
     {prf=1;next_d=true;}
   else {prf=0;next_d=false;}
 //  ReShowCab(d1,d2);

s1= CName+" "+Form_About->Comment;
i_e=i_b+dt/15;
ID_w=0;
MTemp2->SQL->Clear();MTemp2->SQL->Add("select  max(ID) as ID_w  from Write_Client");
MTemp2->Open();
if(MTemp2->RecordCount>0)     ID_w=MTemp2->FieldByName("ID_w")->AsInteger;


 UpdWrite(PerID, Item->ItemPos, Item->ImageID, i_b, i_e, ID_w,Form_About->stat, PName, s1 );

}
    }//else //if(MTemp3->RecordCount >0


 }   // if(Form_About->ShowModal()==1)
 else next_d=false;

             }  //if (Form_sel->ShowModal()==mrOk)


 }// if(Item->Color==clSilver)

 else{
  if(Item->Color!=clRed) {
       tn=(Planner1->Display->DisplayStart+n1)*900; //время начала в секундах n1*3600/4
      tk=tn+15*60;
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
d2=d1+1;
       PName=Form_sel->DName;
//d1=d1+n1;
d_n=d1+tn/86400.;
d_e=d1+tk/86400.;


MTemp1->SQL->Clear();
MTemp1->SQL->Add("select ID, isNull(Status,1) as stat, Comment, PerID, Name, DATEPART(hh,Date_w)*60+DATEPART(mi,Date_w) as mn, DATEPART(hh,Date_end)*60+DATEPART(mi,Date_end) as mk,");
MTemp1->SQL->Add("Phone, Prim, CabID, Date_w as tn, Date_end as tk, Email from Write_Client  ");
MTemp1->SQL->Add("where ID="+IntToStr(ID_w));
MTemp1->Open();

if(MTemp1->RecordCount>0)
{
       PerID=MTemp1->FieldByName("PerID")->AsInteger;
              CabID=MTemp1->FieldByName("CabID")->AsInteger;
        d_n=MTemp1->FieldByName("tn")->AsDateTime;
        d_e=MTemp1->FieldByName("tk")->AsDateTime;
         n1=MTemp1->FieldByName("mn")->AsInteger;
  n2=MTemp1->FieldByName("mk")->AsInteger;
      dt=n2-n1;
MTemp2->SQL->Clear();
MTemp2->SQL->Add("select per.Name as PName, per.ID, Profession.ID as ProfID");
MTemp2->SQL->Add(" from PersonalView  per ");
MTemp2->SQL->Add(" INNER JOIN Profession ON per.PCIdent = Profession.ID ");
MTemp2->SQL->Add("where per.ID="+IntToStr(PerID));
MTemp2->Open();
if(MTemp2->RecordCount>0)
      {
       ProfID=MTemp2->FieldByName("ProfID")->AsInteger;
       PName=MTemp2->FieldByName("PName")->AsString;

      }
    else  ProfID=0;

Data1->WriServ->Close();
Data1->WriServ->Parameters->operator [](0)->Value=ProfID;
Data1->WriServ->ExecSQL();
Data1->WriServ->Open();
    if(Data1->WriServ->RecordCount>0)
Form_About->shag=Data1->WriServ->FieldByName("ServTime")->AsInteger;
    else  Form_About->shag=0;

    Form_sel->RadioGroup1->ItemIndex =0;
    Form_About->stat=MTemp1->FieldByName("stat")->AsInteger;
Form_About->ComboBox1->ItemIndex=Form_About->stat-1;
       Form_About->shag=dt;
        Form_About->Edit1->Text=MTemp1->FieldByName("Name")->AsString.Trim() ;
Form_About->Edit2->Text=MTemp1->FieldByName("Phone")->AsString.Trim();
Form_About->Edit3->Text=MTemp1->FieldByName("Comment")->AsString.Trim();
//Form_About->Edit4->Text=MTemp1->FieldByName("Email")->AsString.Trim();
ss=MTemp1->FieldByName("Prim")->AsString.Trim();
  Form_About->Memo1->Lines->Clear();
 Form_About->Memo1->Lines->Add(ss);
  Form_About-> Edit3->Enabled = true;
     Form_About->Edit3->Visible =true;
    // Form_About-> Edit4->Enabled = true;
    // Form_About->Edit4->Visible =true;
  Form_About->Edit2->Enabled = true;
     Form_About->Edit2->Visible =true;
     Form_About->Memo1->Enabled = true;
     Form_About->Memo1->Visible =true;
        Form_About->ComboBox1->Visible =true;
      //  Form_About->GroupBox1->Enabled = false;
//     Form_About->GroupBox1->Visible =false;

 if(Form_About->ShowModal()==1)
 {

 CName=Form_About->Name;
s1=DateTimeToStr(d_n);
  dt=Form_About->shag;//minutes
if(dt>0) d_e=d_n+dt*60./86400;

 s2=DateTimeToStr(d_e);

Data1->Temp->SQL->Clear();
s1="Delete from Write_Client where ID="+ IntToStr(ID_w);
Data1->Temp->SQL->Add(s1);Data1->Temp->ExecSQL();


v[0]=PerID;
v[1]=Form_About->Name.UpperCase();
v[2]=Form_About->Phone.Trim();
v[3]=Form_About->Comment;
v[4]=d_n;
v[5]=d_e;
v[6]=Form_About->Prim.Trim();
v[7]=CabID;
v[8]=Form_About->stat;

/*Data1->Writer->Close();
for(int j=1;j<=9;j++)
  Data1->Writer->Parameters->Items[j]->Value  = v[j];
Data1->Writer->Prepared = true;*/
 Data1->Writer->Parameters->operator [](1)->Value=PerID;
  Data1->Writer->Parameters->operator [](2)->Value=Form_About->Name.UpperCase();
  Data1->Writer->Parameters->operator [](3)->Value=Form_About->Phone.Trim();
  Data1->Writer->Parameters->operator [](4)->Value=Form_About->Comment;
  Data1->Writer->Parameters->operator [](5)->Value=d_n;
Data1->Writer->Parameters->operator [](6)->Value=d_e;
     Data1->Writer->Parameters->operator [](7)->Value=Form_About->Prim.Trim();
  Data1->Writer->Parameters->operator [](8)->Value=CabID;
    Data1->Writer->Parameters->operator [](9)->Value=Form_About->stat;
      Data1->Writer->Parameters->operator [](10)->Value=Form_About->Milo.Trim();
Data1->Writer->ExecProc();//Data1->Writer->Open();
ID_w=0;
  ID_w=(int)Data1->Writer->Parameters->operator [](11)->Value;

s1= Form_About->Name.UpperCase()+" "+Form_About->Comment;
i_e=i_b+dt/15;

/*MTemp2->SQL->Clear();MTemp2->SQL->Add("select  max(ID) as ID_w  from Write_Client");MTemp2->Open();
if(MTemp2->RecordCount>0)     ID_w=MTemp2->FieldByName("ID_w")->AsInteger;         */


 //
      if(Form_About->stat!=5)
  UpdWrite(PerID, Item->ItemPos, Item->ImageID, i_b, i_e, ID_w, Form_About->stat, PName, s1 );
  else
  ReShowCab(d1,d2);
  prf=0;
  Form_About->Edit1->Text="";
  Form_About->Edit2->Text="8(000)0000000";
    Form_About->Edit3->Text="";
   // Form_About->Edit4->Text="";
  Form_About->Memo1->Lines->Clear();
    Form_About->ComboBox1->ItemIndex=0;
      Form_About->shag=0;
     //  Form_About->GroupBox1->Enabled = false;
     //Form_About->GroupBox1->Visible =false;
          Form_sel->RadioGroup1->ItemIndex =0;
  }}


 }}

       }

}
//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Planner1ItemRightClick(TObject *Sender,
      TPlannerItem *Item)
{
//
AnsiString s1;
int sel,ID_w;
TDateTime d1,d2, d_n, d_e;
unsigned short dd1, mm1, yy1;
ID_w=Item->ID;
sel=0;
if(ID_w>0){
    sel=Application->MessageBox("Вы действительно хотите удалить эту запись?","Удаление",MB_YESNO);
if(sel==6)
  {
sel=0;
 prf=0;
 sel=Application->MessageBox("Будете переносить запись в др.кабинет(др.время)?","Удаление",MB_YESNO);
if(sel==6){
 prf=2;
 UpdFAbout(ID_w,prf);
            }
 Data1->Temp->Close();
Data1->Temp->SQL->Clear();
s1="Delete from Write_Client where Status<>5 and ID="+ IntToStr(ID_w);
Data1->Temp->SQL->Add(s1);
Data1->Temp->ExecSQL();
dd1=Planner1->Mode->PeriodStartDay;
mm1=Planner1->Mode->PeriodStartMonth;
yy1=Planner1->Mode->PeriodStartYear;
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
d2=d1+1;

 ReShowCab(d1,d2);
 if(prf==2) ShowMessage("Не забудьте перенести запись прямо сейчас!!!");

   } }
}
//---------------------------------------------------------------------------


void __fastcall TForm_Cab::Planner1ItemDelete(TObject *Sender,
      TPlannerItem *Item)
{
//
AnsiString s1;
int sel,ID_w;
TDateTime d1,d2, d_n, d_e;
unsigned short dd1, mm1, yy1;

}
//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Button2Click(TObject *Sender)
{
//
/*  Form_Pers->pr=false;
  Form_Pers->ShowModal() ;        */
  Form_grafw->DateTimePicker1->Date= DateEdit1->Date;//DateTimePicker1->Date;
    Form_grafw->DateTimePicker2->Date= DateEdit1->Date;//DateTimePicker1->Date;
    Form_grafw->ComboBox1->ItemIndex=0;
         Form_grafw->ComboBox2->ItemIndex=0;
    Form_grafw->ComboBox3->ItemIndex=0;
        Form_grafw->ComboBox4->ItemIndex=0;
      Form_grafw->ShowModal() ;
TDateTime d1,d2;
d1=DateEdit1->Date;//DateTimePicker1->DateTime;
d2=d1+1;
ReShowCab(d1,d2);


      }

//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Button3Click(TObject *Sender)
{
/*Form_Calndr->sh_f=false;

Form_Pers->ShowModal() ;   */
}
//---------------------------------------------------------------------------

void __fastcall TForm_Cab::FormClose(TObject *Sender, TCloseAction &Action)
{
sh_f=false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Button4Click(TObject *Sender)
{
//
int w1, id, dd1, mm1, yy1, perid, mi=0, ID_w, stat;
TDateTime dt, bd, ed, d1, d2;
 Variant v1[4];
AnsiString PName, CName,Phone, prim,sn, sk, ss1, s1,s2;
//d1=DateTimePicker1->DateTime;
d1=DateEdit1->Date;

dd1=DayOf(d1);
mm1=MonthOf(d1);
yy1=YearOf(d1);
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);


v1[0]=dd1;
v1[1]=mm1;
v1[2]=yy1;
      /*
dd1=DaysInMonth(d1);
d2=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);

 CalcAutoOle *OO = new CalcAutoOle;
 OO->connect();
 OO->loadDocument(false);
 AnsiString ts;
 int i=0;
 OO->getSheet(0);
 OO->setActiveSheet();
 OO->setSheetName("Запись");

 ts="ЗАПИСЬ К ВРАЧАМ НА "+DateEdit1->Date.DateString() ;

 //FormatString("mmmm.yyyy");
OO->putTextToCell(1,i,ts.c_str());
OO->setFontBold();
i++;
i++;

OO->putTextToCell(0,i,"ФИО ВРАЧА");
OO->setFontBold();
     OO->setColumnWidth(0,6000);
OO->putTextToCell(1,i,"ЗАПИСЬ");
OO->setFontBold();
 OO->setColumnWidth(1,11000);
 OO->putTextToCell(2,i,"ПРИМЕЧАНИЕ");
OO->setFontBold();
 OO->setColumnWidth(2,10000);
        i++; // i++;
MTemp->SQL->Clear();
MTemp->SQL->Add("Select * from Cabinet order by ID");
MTemp->Open();
int j=0, nd=0;
  MTemp2->SQL->Clear();
MTemp2->SQL->Add("select   pc.PerID as PerID, per.Name as PName,isNull(pc.Status,1) as stat, pc.Prim as prim,pc.Phone as Phone, pc.Comment as Comment,pc.Name as Name, cc.Name as CName,pc.Date_w as tn, pc.Date_end as tk, count(*) as cnt ");
MTemp2->SQL->Add(" from Write_Client pc");
MTemp2->SQL->Add("inner join PersonalView  per on per.ID=pc.PerID ");
MTemp2->SQL->Add("inner join Cabinet cc on cc.ID=pc.CabID ");
MTemp2->SQL->Add("where DATEPART(dd,pc.Date_w)=:i1 and DATEPART(mm,pc.Date_w)=:i2 and DATEPART(yy,pc.Date_w)=:i3  ");
MTemp2->SQL->Add("group by   pc.PerID, per.Name, pc.Status, pc.Prim, pc.Phone, pc.Comment,pc.Name, cc.Name,pc.Date_w, pc.Date_end order by per.Name, pc.Date_w ");
 for(int i=0;i<3;i++)    MTemp2->Parameters->operator [](i)->Value=v1[i];
MTemp2->ExecSQL(); MTemp2->Open();
        ID_w=0;
 for (MTemp2->First();!MTemp2->Eof;MTemp2->Next())
{
 bd=MTemp2->FieldByName("tn")->AsDateTime;
 ed=MTemp2->FieldByName("tk")->AsDateTime;
      CName=MTemp2->FieldByName("Name")->AsString.Trim();
PName=MTemp2->FieldByName("PName")->AsString.Trim();
  stat=MTemp2->FieldByName("stat")->AsInteger;
  prim=MTemp2->FieldByName("prim")->AsString.Trim();
  s1=MTemp2->FieldByName("CName")->AsString.Trim();

Phone=MTemp2->FieldByName("Phone")->AsString.Trim();
  s2=MTemp2->FieldByName("Comment")->AsString.Trim();

   if(ID_w!=MTemp2->FieldByName("PerID")->AsInteger)
   {
   // if(j!=0) i=i+5;
   i++;
  OO->putTextToCell(0,i,PName.c_str());
     OO->setFontBold();

   }
//   else        i=i+4;
ID_w=MTemp2->FieldByName("PerID")->AsInteger;
   sn=MTemp2->FieldByName("tn")->AsDateTime.FormatString("hh:nn");
    sk=MTemp2->FieldByName("tk")->AsDateTime.FormatString("hh:nn");
ss1=sn+"-"+sk+"  "+CName;
    OO->putTextToCell(1,i,ss1.c_str());
    OO->setFontBold();
          OO->putTextToCell(2,i,prim.c_str());
    i++;
          OO->putTextToCell(1,i,s1.c_str());i++;
     OO->putTextToCell(1,i,Phone.c_str()); i++;
          OO->putTextToCell(1,i,s2.c_str()); i++;
switch(stat)
        {
    case 5:
        OO->putTextToCell(1,i,"Статус: Отказ");
        break;

        case 4:
       OO->putTextToCell(1,i,"Статус: Ушел");
        break;

        case 3:
          OO->putTextToCell(1,i,"Статус: Пришел");
        break;

        case 2:
           OO->putTextToCell(1,i,"Статус: Подтвержден");
        break;

        case 1:
           OO->putTextToCell(1,i,"Статус: Записан");
        break;
        default:   ;
           }
 i++;


                    i++;
   ss1="";

j++;
}       */
}
//---------------------------------------------------------------------------

void __fastcall TForm_Cab::Timer1Timer(TObject *Sender)
{
//
TDateTime d1,d2;
//d1=DateTimePicker1->DateTime;

d1=DateEdit1->Date;
d2=d1+1;
//ShowMessage("QUQU");
ReShowCab(d1,d2);
}
//---------------------------------------------------------------------------


void __fastcall TForm_Cab::DateEdit1Change(TObject *Sender)
{
//
TDateTime d1,d2;
d1=DateEdit1->Date;
d2=d1+1;
ReShowCab(d1,d2);
}
//---------------------------------------------------------------------------

void TForm_Cab::UpdWrite(int PerID,int it_pos,int CabID, int i_b, int i_e, int ID_w, int stat, AnsiString tit,  AnsiString txt)
{
TDateTime d1,d2,d_n,d_e;
unsigned short dd1, mm1, yy1,hh1, mmm1, ss1,mss1;
 int tn,tk,pos, kpos;

AnsiString ss, s1,s2,PName, CName;

 Variant v[9]={0,0,0,0,0,0,0,0,0};
dd1=Planner1->Mode->PeriodStartDay;
  mm1=Planner1->Mode->PeriodStartMonth;
     yy1=Planner1->Mode->PeriodStartYear;
         kpos=Planner1->Positions;
       bool kk;
       kk=ss.IsEmpty();
      tn=(Planner1->Display->DisplayStart+i_b)*900; //время начала в секундах n1*3600/4
      tk=tn+15*60;
d1=EncodeDate((Word)yy1,(Word)mm1,(Word)dd1);
d2=d1+1;
d_n=d1+tn/86400.;
d_e=d1+tk/86400.;


TPlannerItem *plCab,*plIt0;
for(int j=i_b;j<i_e;j++)
  {
      plCab = Planner1->Items->FindFirst(j,j+1,it_pos);
   if(plCab)
       plCab->Free();
for(int i=0;i<kpos;i++)
{
 if(i!=it_pos)
  {
   plCab = Planner1->Items->FindFirst(j,j+1,i);
   if(plCab)    {
 if(plCab->ID==-1)
     {
      ss=plCab->Text->Text;
      pos=ss.AnsiPos(tit);
       if(pos>0)
       {
       s1= ss.SubString(0,pos-1);
s2=ss.SubString(pos+tit.Length()+1,ss.Length());
       ss=s1+s2;
    if(ss.Length()>2)
       plCab->Text->Text=ss;
      else
        plCab->Free();
     }
      }

               }  }
}//for(int i=0;i<7;i++)
  } //for(int j=i_b;j<i_e;j++)

    plCab=Planner1->Items->Add();
     plCab->Background =false;
     plCab->AllowOverlap=true;
     plCab->CaptionType=ctNone;

     plCab->Selected =false;
     plCab->Shape = psRect;  //psTool;
     plCab->ShowSelection =false;
     plCab->TrackVisible =false;
     plCab->CompletionDisplay = cdNone;
     plCab->Shadow =false;

    plCab->Text->Text=txt;
       plCab->CaptionText = tit;
      plCab->CaptionType=1;
        plCab->CaptionBkgDirection=1;
     plCab->ShowDeleteButton =false;
                   plCab->ID =ID_w;
         plCab->ImageID=CabID;
                         plCab->ColorTo=clWhite;
     plCab->ItemBegin =i_b;
     plCab->ItemEnd= i_e;
     plCab->ItemPos=it_pos;
     switch(stat)
        {
    case 5:
       plCab->Color=clFuchsia ;
       plCab->CaptionBkg=clFuchsia ;
        plCab->CaptionBkgTo=clWhite ;
        break;

        case 4:
        plCab->Color=clYellow ;
       plCab->CaptionBkg=clYellow ;
        plCab->CaptionBkgTo=clWhite ;
        break;

        case 3:
        plCab->Color=clMaroon;
       plCab->CaptionBkg=clMaroon ;
        plCab->CaptionBkgTo=clWhite ;
        break;

        case 2:
        plCab->Color=clGreen;
       plCab->CaptionBkg=clGreen ;
        plCab->CaptionBkgTo=clWhite ;
        break;


        case 1:
        plCab->Color=clBlue;

       plCab->CaptionBkg=clBlue ;
        plCab->CaptionBkgTo=clWhite ;
        break;
        default:   ;
            }

       plCab->ColorTo=clWhite;
             plCab->ReadOnly=true;
     plCab->Visible = true;


}

void TForm_Cab::UpdFAbout(int Id_w,short int pp)
{
 if(pp==0 || pp==1) {
  if(pp==0)
          {
  Form_About->Edit1->Text="";
  Form_About->Edit2->Text="8(000)0000000";
          }
    Form_About->Edit3->Text="";
  Form_About->Memo1->Lines->Clear();
    Form_About->ComboBox1->ItemIndex=0;
      Form_About->shag=0;
/*Form_About->CheckListBox3->MultiSelect =false;

                              Form_About->CheckListBox3->Checked[3]=false;
                              Form_About->CheckListBox3->Checked[1]=false;
                              Form_About->CheckListBox3->Checked[2]=false;
                              Form_About->CheckListBox3->Checked[0]=false;
                */
   }
if(pp==2)
{

int CabID, PerID, ProfID, dt, mn, mk, n1,n2;
//TDateTime d1,d2, d_n, d_e, dk;
AnsiString ss, s1,s2,PName, CName;

MTemp1->SQL->Clear();
MTemp1->SQL->Add("select ID, isNull(Status,1) as stat, Comment, PerID, Name, DATEPART(hh,Date_w)*60+DATEPART(mi,Date_w) as mn, DATEPART(hh,Date_end)*60+DATEPART(mi,Date_end) as mk,");
MTemp1->SQL->Add("Phone, Prim, CabID, Date_w as tn, Date_end as tk   from Write_Client  ");
MTemp1->SQL->Add("where ID="+IntToStr(Id_w));
MTemp1->Open();

if(MTemp1->RecordCount>0)
{
       PerID=MTemp1->FieldByName("PerID")->AsInteger;
              CabID=MTemp1->FieldByName("CabID")->AsInteger;
         n1=MTemp1->FieldByName("mn")->AsInteger;
  n2=MTemp1->FieldByName("mk")->AsInteger;
      dt=n2-n1;
MTemp2->SQL->Clear();
MTemp2->SQL->Add("select per.Name as PName, per.ID, Profession.ID as ProfID");
MTemp2->SQL->Add(" from PersonalView  per ");
MTemp2->SQL->Add(" INNER JOIN Profession ON per.PCIdent = Profession.ID ");
MTemp2->SQL->Add("where per.ID="+IntToStr(PerID));
MTemp2->Open();
if(MTemp2->RecordCount>0)
      {
       ProfID=MTemp2->FieldByName("ProfID")->AsInteger;
       PName=MTemp2->FieldByName("PName")->AsString;
      }
    else  ProfID=0;
Data1->WriServ->Close();
Data1->WriServ->Parameters->operator [](0)->Value=ProfID;
Data1->WriServ->ExecSQL();
Data1->WriServ->Open();

    Form_About->stat=MTemp1->FieldByName("stat")->AsInteger;
Form_About->ComboBox1->ItemIndex=Form_About->stat-1;
       Form_About->shag=dt;
        Form_About->Edit1->Text=MTemp1->FieldByName("Name")->AsString.Trim() ;
Form_About->Edit2->Text=MTemp1->FieldByName("Phone")->AsString.Trim();
Form_About->Edit3->Text=MTemp1->FieldByName("Comment")->AsString.Trim();
ss=MTemp1->FieldByName("Prim")->AsString.Trim();
  Form_About->Memo1->Lines->Clear();
 Form_About->Memo1->Lines->Add(ss);
  Form_About-> Edit3->Enabled = true;
     Form_About->Edit3->Visible =true;
  Form_About->Edit2->Enabled = true;
     Form_About->Edit2->Visible =true;
     Form_About->Memo1->Enabled = true;
     Form_About->Memo1->Visible =true;
        Form_About->ComboBox1->Visible =true;
       // Form_About->GroupBox1->Enabled = false;
     //Form_About->GroupBox1->Visible =false;

   }

}//if(pr==2)


}

void TForm_Cab::ShowGrafik(int CabID, int it_pos, int dd1, int mm, int yy1, int mn, int mk)
{
int PerID, ProfID, id, i_b, i_e, n1,n2, index, pos,du, tn, tk, i=0, ID_w, dt, j=0,jj;
TDateTime d1,d2, d_n, d_e, dk;
AnsiString ss, ss1,s1,s2,PName, CName;
/*unsigned short hh1, mm1, mss1;
unsigned short hh2,mm2,sss2,mss2, ht1,mt1,ht2,mt2,;  */
bool zapr,zz;
 Variant v1[6];
TPlannerItem *plCab;

v1[0]=dd1;
v1[1]=mm;
v1[2]=yy1;
v1[3]=CabID;
          /////////////////////////////////////////
MTemp2->SQL->Clear();
MTemp2->SQL->Add("Select * from PerCabs where CabID="+IntToStr(CabID));
MTemp2->Open();
for (MTemp2->First();!MTemp2->Eof;MTemp2->Next())
   {
   PerID=MTemp2->FieldByName("PerID")->AsInteger;
v1[4]=PerID;


MTemp1->SQL->Clear();
MTemp1->SQL->Add("select sc.PerID, per.Name as PName, sc.TN_w as b, sc.TK_w as e, sc.Stat, ");
MTemp1->SQL->Add("DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w) as mn, DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w) as mk   from GrafikWork sc");
MTemp1->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID ");
MTemp1->SQL->Add("where  DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  and sc.CabID=:i4 ");
MTemp1->SQL->Add("and  sc.PerID=:i5 ORDER by sc.TN_w, sc.Stat DESC");
  for(int i=0;i<5;i++)    MTemp1->Parameters->operator [](i)->Value=v1[i];
MTemp1->ExecSQL(); MTemp1->Open();
ss1=""; i=0;s1="";s2="";
for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())
{
  PName=MTemp1->FieldByName("PName")->AsString.Trim();
  n1=MTemp1->FieldByName("mn")->AsInteger;
if(n1/60 <8)    n1=8*60;
  zapr=MTemp1->FieldByName("Stat")->AsBoolean;
  n2=MTemp1->FieldByName("mk")->AsInteger;
  s1="";s2=PName;
   for(int j=n1;j<n2;j+=15)
    {
   s1="";
  jj=j/15 - Planner1->Display->DisplayStart;
  plCab = Planner1->Items->FindFirst(jj,jj+1,it_pos);
 if(!plCab)
        {plCab=Planner1->Items->Add(); if(zapr) plCab->Color =clSilver;
                                       else {s2="Запрет"+PName;plCab->Color =clRed;plCab->ColorTo =clRed; } }
   else {
      ss=plCab->Text->Text;
      s1=ss;
      pos=ss.AnsiPos(PName);
      if(pos>0)
       {
       s1= ss.SubString(0,pos-1);
       s2=ss.SubString(pos+PName.Length()+1,ss.Length()-1);
       s1=s1+s2;//
        }
      if(!zapr) { s2="Запрет"+PName;
      if(plCab->Color==clRed) plCab->Color==clRed;
          else {plCab->Color =clSilver;  plCab->ColorTo =clRed; }
                 }
        }// else if(!plCab)

     ss1=s2+" "+s1;
     plCab->Background =false;
     plCab->AllowOverlap=false;
     plCab->CaptionType=ctNone;
     plCab->Selected =false;
     plCab->Shape = psRect;  //psTool;
     plCab->ShowSelection =false;
     plCab->TrackVisible =false;
     plCab->CompletionDisplay = cdNone;
     plCab->Shadow =false;
     plCab->ItemBegin = jj;
     plCab->ItemEnd= plCab->ItemBegin+1;
     plCab->Text->Text=ss1;
        //clWhite
     plCab->ID =-1;
     plCab->ImageID=CabID;
     plCab->ReadOnly=true;
     plCab->Visible = true;
     plCab->ItemPos = it_pos;



     }// for(int j=n1;j<n2;j+=15)
  }//for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())

 }//for (MTemp2->First();!MTemp2->Eof;MTemp2->Next())



/*********************************************************
for(int j=mn;j<mk;j+=15)
{
v1[4]=j;
v1[5]=j+15;

MTemp1->SQL->Clear();
MTemp1->SQL->Add("select sc.PerID, per.Name as PName, sc.TN_w as b,sc.TK_w as e, sc.Stat from GrafikWork sc ");
//MTemp1->SQL->Add("DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w) as mn, DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w) as mk  ");
MTemp1->SQL->Add("inner join PersonalView  per on per.ID=sc.PerID ");
  MTemp1->SQL->Add("where  DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  and sc.CabID=:i4 ");
  MTemp1->SQL->Add("and  DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w)<=:i5 and DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w)>=:i6 ");
  //MTemp1->SQL->Add("group by sc.PerID, per.Name, sc.TN_w,sc.TK_w, sc.Stat,DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w), DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w ");
MTemp1->SQL->Add(" ORDER by sc.TN_w");
 for(int i=0;i<6;i++)    MTemp1->Parameters->operator [](i)->Value=v1[i];
MTemp1->ExecSQL(); MTemp1->Open();
ss1=""; i=0;
 zz=true;

for (MTemp1->First();!MTemp1->Eof;MTemp1->Next())
{
 PName=MTemp1->FieldByName("PName")->AsString.Trim();
  PerID=MTemp1->FieldByName("PerID")->AsInteger;
  zapr=MTemp1->FieldByName("Stat")->AsBoolean;

 if(zapr){
// if(PerID==986 &&j==750 &&CabID==29)     ShowMessage("GGb");
           MTemp3->SQL->Clear();
MTemp3->SQL->Add("select  pc.ID as ID, isNull(pc.Status,1) as stat, pc.PerID,  pc.Date_w as tn, pc.Date_end as tk ");
MTemp3->SQL->Add(" from Write_Client pc");
MTemp3->SQL->Add("where pc.Status<>5 and DATEPART(dd,pc.Date_w)=:i1 and DATEPART(mm,pc.Date_w)=:i2 and DATEPART(yy,pc.Date_w)=:i3  ");
MTemp3->SQL->Add(" and pc.CabID<>:i4 and pc.PerID=:i5 and (DATEPART(hh,pc.Date_w)*60+DATEPART(mi,pc.Date_w)<=:i6 and  DATEPART(hh,pc.Date_end)*60+DATEPART(mi,pc.Date_end)>=:i7)  order by pc.Date_w ");
 for(int i=0;i<4;i++)    MTemp3->Parameters->operator [](i)->Value=v1[i];
   MTemp3->Parameters->operator [](4)->Value=PerID;
      MTemp3->Parameters->operator [](5)->Value=j;
      MTemp3->Parameters->operator [](6)->Value=j+15;
MTemp3->ExecSQL(); MTemp3->Open();

  if(MTemp3->RecordCount==0)  {

  MTemp3->SQL->Clear();
MTemp3->SQL->Add("select per.Name as PName, sc.PerID,sc.CabID,sc.TN_w as b,sc.TK_w as e, sc.Stat from GrafikWork sc ");
//MTemp3->SQL->Add("DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w) as mn, DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w) as mk ");
MTemp3->SQL->Add(" inner join PersonalView  per on per.ID=sc.PerID ");
  MTemp3->SQL->Add("where sc.Stat=0 and DATEPART(dd,sc.TN_w)=:i1 and DATEPART(mm,sc.TN_w)=:i2 and DATEPART(yy,sc.TN_w)=:i3  ");
MTemp3->SQL->Add(" and sc.CabID=:i4  and sc.PerID=:i5 and (DATEPART(hh,sc.TN_w)*60+DATEPART(mi,sc.TN_w)<=:i6 and DATEPART(hh,sc.TK_w)*60+DATEPART(mi,sc.TK_w)>=:i7)  ");

 for(int ii=0;ii<4;ii++)    MTemp3->Parameters->operator [](ii)->Value=v1[ii];
   MTemp3->Parameters->operator [](4)->Value=PerID;
      MTemp3->Parameters->operator [](5)->Value=j;
      MTemp3->Parameters->operator [](6)->Value=j+15;
MTemp3->ExecSQL(); MTemp3->Open();

 if(MTemp3->RecordCount==0) { ss1+=PName+" ";i++; }
                                }

 }//     if(zapr)
                     else {zz=false;ss1+="Запрет"+PName+" ";}
 } //for
   if(!ss1.IsEmpty() )  {

   plCab=Planner1->Items->Add();
     plCab->Background =false;
     plCab->AllowOverlap=false;
     plCab->CaptionType=ctNone;
     plCab->Selected =false;
     plCab->Shape = psRect;  //psTool;
     plCab->ShowSelection =false;
     plCab->TrackVisible =false;
     plCab->CompletionDisplay = cdNone;
     plCab->Shadow =false;
     plCab->ItemBegin =j/15 - Planner1->Display->DisplayStart;
     plCab->ItemEnd= plCab->ItemBegin+1;
     plCab->Text->Text=ss1;
 if(zz) //нет запрета
      plCab->Color =clSilver;   //clWhite;
 else{
 if(i==0)
 plCab->Color =clRed;
 else{
  plCab->Color =clSilver;  plCab->ColorTo =clRed;  }}

     plCab->ID =-1;
     plCab->ReadOnly=true;
     plCab->Visible = true;
     plCab->ItemPos = it_pos;

       }//   if(!ss1.IsEmpty() )  {


 }

*************************************/


}


