//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_About.h"
#include "Unit_data.h"
#include "Unit_sel.h"
#include "Cab_full.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_About *Form_About;
//---------------------------------------------------------------------------
__fastcall TForm_About::TForm_About(TComponent* Owner)
        : TForm(Owner)
{

Name= Comment= Phone= Prim=" ";
}
//---------------------------------------------------------------------------
void __fastcall TForm_About::Edit1Change(TObject *Sender)
{
//

if(Form_sel->RadioGroup1->ItemIndex ==0)       {
AnsiString S=Edit1->Text;
S=S.Trim().UpperCase();
if (Edit1->Text!=""&&ClientID==0)
              {
             Data1->SearchClient->Close();
              Data1->SearchClient->SQL->Clear();
Data1->SearchClient->SQL->Add("select top 150 ID,Name,Phone, Prim, Email from Client where Name like '"+S+"%'");
              Data1->SearchClient->Open();
/*          S="'"+S+"%'";
Data1->SearchClient->SQL->Clear();
Data1->SearchClient->SQL->Add("exec CM_RetClient"+S);
Data1->SearchClient->Open();   */


    if( Data1->SearchClient->RecordCount>0){
     DBGrid1->Enabled = true;
     DBGrid1->Visible =true;
     Edit3->Enabled = false;
     Edit3->Visible = false;
     Edit4->Enabled = false;
     Edit4->Visible = false;

    Edit2->Enabled = false;
     Edit2->Visible = false;
    ComboBox1->Visible =false;
  //  GroupBox1->Enabled = false;
//GroupBox1->Visible =false;
                                            }
else{
    DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
       Edit3->Enabled = true;
     Edit3->Visible =true;
    //   Edit4->Enabled = true;
    // Edit4->Visible =true;

  Edit2->Enabled = true;
     Edit2->Visible =true;
          ComboBox1->Visible =true;
Form_sel->RadioGroup1->ItemIndex =1;
//GroupBox1->Enabled = true;
//GroupBox1->Visible =true;
    }
              }


    }


}
//---------------------------------------------------------------------------
void __fastcall TForm_About::DBGrid1DblClick(TObject *Sender)
{
     //
       DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
     Edit3->Enabled = true;
     Edit3->Visible =true;
//      Edit4->Enabled = true;
  //   Edit4->Visible =true;

     if(Data1->SearchClient->RecordCount!=0)
{
 Name= Data1->SearchClient->FieldByName("Name")->AsString;
 Phone= Data1->SearchClient->FieldByName("Phone")->AsString;
 Milo= Data1->SearchClient->FieldByName("Email")->AsString;
        ClientID=Data1->SearchClient->FieldByName("ID")->AsInteger;
 int pos=0;
 AnsiString s1, s2, ss, s3;
 s3=Data1->SearchClient->FieldByName("Prim")->AsString.Trim();
//Memo2->Lines->Add(s3);
s1=Phone.Trim();
pos=s1.Length();
if(pos>7)
ss=s1.SubString(pos-6,7);
   else ss=s1;
if(pos>10)
{
if (s1.Pos(")")!=0)
    s2=s1.SubString(s1.Pos(")") - 3,3);
else s2=s1.SubString(pos-9,3);
}
   else s2="495";
Phone="8("+s2+")"+ss;
 Edit1->Text= Name.TrimRight();//TrimLeft();
 Edit2->Text= Phone.TrimRight();//TrimLeft();
 //Edit4->Text= Milo.TrimRight();//TrimLeft();
 //Memo2->Enabled = false;
       DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
       Edit3->Enabled = true;
     Edit3->Visible =true;
  Edit2->Enabled = true;
     Edit2->Visible =true;
     // Edit4->Enabled = true;
   //  Edit4->Visible =true;

          ComboBox1->Visible =true;
 Edit1->SetFocus() ;
// Close();
}
   ComboBox1->Visible =true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_About::DBGrid1KeyPress(TObject *Sender, char &Key)
{
//
if (Key==VK_ESCAPE)
{
     DBGrid1->Enabled = false;
     DBGrid1->Visible =false;

         Edit3->Enabled = true;
     Edit3->Visible =true;
        ComboBox1->Visible =true;
        Form_sel->RadioGroup1->ItemIndex =0;
               ClientID=0;
             Edit1->SetFocus() ;

}
if(Key==VK_RETURN)
  DBGrid1DblClick(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TForm_About::FormClose(TObject *Sender,
      TCloseAction &Action)
{
     DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
     DBGrid2->Enabled = false;
     DBGrid2->Visible =false;
     Edit3->Enabled = true;
     Edit3->Visible =true;
  Edit2->Enabled = true;
     Edit2->Visible =true;
       ComboBox1->Visible =true;
     Name=Edit1->Text.UpperCase();
     Phone=Edit2->Text;
     Comment=Edit3->Text;
    // Milo=Edit4->Text;
     Prim=Memo1->Lines->Text;
       Form_sel->RadioGroup1->ItemIndex =0;
     Name= Name.TrimRight();
     Phone= Phone.TrimRight();//TrimLeft();
     Comment=Comment.TrimRight();
 //    Milo= Milo.TrimRight();
   stat=ComboBox1->ItemIndex+1;
     ClientID=0;
      Form_Cab->prf=0;
   /*  if(Data1->WriServ->RecordCount!=0)
{
     Comment=Data1->WriServ->FieldValues["ServName"];
     Comment=Comment.TrimRight();
     shag=Data1->WriServ->FieldByName("ServTime")->AsInteger;

}*/

}
//---------------------------------------------------------------------------
void __fastcall TForm_About::FormShow(TObject *Sender)
{
//
     float prop_h, prop_w;
prop_h = 2.3;
prop_w = 2;
/*Width = Screen->Width/prop_w;
Height= Screen->Height/prop_h;
Top = (Screen->Height - Height)/2;
Left= (Screen->Width - Width)/2;  */
     ComboBox1->Visible =true;
ActivateKeyboardLayout(LoadKeyboardLayout(IntToHex(MAKELANGID(LANG_RUSSIAN, SUBLANG_DEFAULT) ,8).c_str(), 0), 0);

     DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
     DBGrid2->Enabled = false;
     DBGrid2->Visible =false;
     // Form_sel->RadioGroup1->ItemIndex =0;
             ClientID=0;
  Name="";
  Phone="";
  Milo="";
  //shag=0;
  DBGrid1->Left =Edit1->Left;
  DBGrid1->Top = Edit1->Top + Edit1->Height + 6;
/*  Edit1->Text="";
  Edit2->Text="8(000)0000000";
    Edit3->Text="";
  Memo1->Lines->Clear();
*/
}
//---------------------------------------------------------------------------
void __fastcall TForm_About::Edit3Click(TObject *Sender)
{
//
  DBGrid2->Left =Edit3->Left;
  DBGrid2->Top = Edit3->Top + Edit3->Height + 6;

 DBGrid2->Enabled = true;
 DBGrid2->Visible =true;
    Edit2->Enabled = false;
     Edit2->Visible = false;
       ComboBox1->Visible =false;
 DBGrid2->SetFocus() ;

}

//---------------------------------------------------------------------------

void __fastcall TForm_About::DBGrid2KeyPress(TObject *Sender, char &Key)
{
if (Key==VK_ESCAPE)
{
     DBGrid2->Enabled = false;
     DBGrid2->Visible =false;
             ComboBox1->Visible =true;
     Edit3->SetFocus() ;
}
if(Key==VK_RETURN)
  DBGrid2DblClick(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm_About::DBGrid2DblClick(TObject *Sender)
{
       //
     DBGrid2->Enabled = false;
     DBGrid2->Visible =false;
       Edit2->Enabled = true;
     Edit2->Visible =true;
    //  Edit4->Enabled = true;
//     Edit4->Visible =true;
            ComboBox1->Visible =true;
     if(Data1->WriServ->RecordCount!=0)
{
     Comment=Data1->WriServ->FieldValues["ServName"];
     Comment=Comment.TrimRight();
     shag=Data1->WriServ->FieldByName("ServTime")->AsInteger;
/*     if((Form_Shed->d_curr+(shag*60./86400.))>Form_Shed->d_end)
     {
      Application->MessageBox("Выберите другое время или день!", "Внимание!", MB_OK);
DBGrid2->Visible =false;
       Edit2->Enabled = true;
     Edit2->Visible =true;
      ModalResult=mrNone;
      Close();

     }*/

     Edit3->Text= Comment.TrimRight();
     DBGrid2->Visible =false;
       Edit2->Enabled = true;
     Edit2->Visible =true;
   //   Edit4->Enabled = true;
    // Edit4->Visible =true;

 Edit3->SetFocus() ;
 ComboBox1->Visible =true;

}

  ComboBox1->Visible =true;
}
//---------------------------------------------------------------------------


void __fastcall TForm_About::ComboBox1Select(TObject *Sender)
{
//
   stat=ComboBox1->ItemIndex+1;
}
//---------------------------------------------------------------------------


void __fastcall TForm_About::Button1Click(TObject *Sender)
{
//
 if(shag==0){
   ShowMessage("Вы не выбрали услугу!");
   ModalResult=mrNone;
   return;

 }
if(Form_sel->RadioGroup1->ItemIndex ==1)       {
AnsiString s1,s2;
    Variant v1[4];
  Name=Edit1->Text.UpperCase();
     Phone=Edit2->Text;
//  Milo=Edit4->Text;
//  Milo.TrimRight();
     /*
if(!CheckListBox3->Checked[3]&&!CheckListBox3->Checked[1]&&!CheckListBox3->Checked[2]&&!CheckListBox3->Checked[0])
 {
  ShowMessage("Вы не ответили на вопрос - Как вы узнали о нашем центре?!!!");
     ModalResult=mrNone;
        return;
 }
 */
v1[0]=Name; v1[1]=Phone; v1[2]=Adv; v1[3]=Milo;
Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add(" Insert into Client  (Name,Phone,Adv,Email) VALUES (:i1, :i2, :i3, :i4)");
for(int j=0;j<4;j++)
  Data1->Temp->Parameters->Items[j]->Value  = v1[j];
Data1->Temp->Prepared = true;        Data1->Temp->ExecSQL();


}
}
//---------------------------------------------------------------------------
     /*
void __fastcall TForm_About::CheckListBox3ClickCheck(TObject *Sender)
{

  if(CheckListBox3->ItemIndex==0)
  {
  //ID=8

  Adv=8;
  CheckListBox3->Checked[1]=false;
  CheckListBox3->Checked[2]=false;
  CheckListBox3->Checked[3]=false;


   }

  if(CheckListBox3->ItemIndex==1)
  {
  //ID=5

  Adv=5;
  CheckListBox3->Checked[2]=false;
  CheckListBox3->Checked[3]=false;
    CheckListBox3->Checked[0]=false;

   }

 if(CheckListBox3->ItemIndex==2)
  {                                //32
  Adv=32;
  CheckListBox3->Checked[1]=false;
  CheckListBox3->Checked[0]=false;
  CheckListBox3->Checked[3]=false;

   }
  if(CheckListBox3->ItemIndex==3)
  {
   //ID=6

  Adv=6;
  CheckListBox3->Checked[1]=false;
  CheckListBox3->Checked[0]=false;
  CheckListBox3->Checked[2]=false;

   }


}  */
//---------------------------------------------------------------------------



void __fastcall TForm_About::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_ESCAPE)
        {
       DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
     Edit3->Enabled = true;
     Edit3->Visible =true;
  Edit2->Enabled = true;
     Edit2->Visible =true;
          ComboBox1->Visible =true;
          ClientID=0;
        return;
        }

       if (Key==VK_DOWN&&Edit1->Text!="")
                {
                DBGrid1->SetFocus();
                }
        else
                {
                Edit1->SetFocus();
                }
}
//---------------------------------------------------------------------------

void __fastcall TForm_About::BitBtn1Click(TObject *Sender)
{
//
 /*
IdSMTP1->AuthenticationType =atLogin;
IdSMTP1->UserId ="lenaevt2003";
IdSMTP1->Password ="WS35tm28";
IdSMTP1->Host ="smtp.mail.ru";
                              */
//pusk-> run ping smtp.mail.ru
 IdMessage1->Body->Text="SFGHJJ";//текст
 IdMessage1->From->Text="LENA";//отправитель
 IdMessage1->Recipients->EMailAddresses = Milo; //получатель
 IdMessage1->Subject = "Theme";//тема


 IdSMTP1->Connect();
 if(IdSMTP1->Connected())
     IdSMTP1->Send(IdMessage1);
 IdSMTP1->Disconnect();       
}
//---------------------------------------------------------------------------

