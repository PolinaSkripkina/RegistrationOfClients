//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TData1 *Data1;
//---------------------------------------------------------------------------
__fastcall TData1::TData1(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TData1::WriterAfterInsert(TDataSet *DataSet)
{
ShowMessage("Insert");
}
//---------------------------------------------------------------------------

void __fastcall TData1::WriterBeforeInsert(TDataSet *DataSet)
{
  ShowMessage("Insert");
}
//---------------------------------------------------------------------------

void __fastcall TData1::Write_ClientAfterInsert(TDataSet *DataSet)
{
  ShowMessage("aftInsert");
}
//---------------------------------------------------------------------------

void __fastcall TData1::Write_ClientBeforeInsert(TDataSet *DataSet)
{
  ShowMessage("bInsert");        
}
//---------------------------------------------------------------------------

void __fastcall TData1::Write_ClientAfterPost(TDataSet *DataSet)
{
  ShowMessage("apost");
}
//---------------------------------------------------------------------------

