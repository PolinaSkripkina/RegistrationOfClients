//---------------------------------------------------------------------------

#ifndef Unit_dataH
#define Unit_dataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TData1 : public TDataModule
{
__published:	// IDE-managed Components
        TADOConnection *Med;
        TADOQuery *Person;
        TADOQuery *Prof;
        TDataSource *dsProf;
        TDataSource *dsPerson;
        TDataSource *dsShed;
        TADOQuery *Shed;
        TADOQuery *Temp;
        TADOQuery *Shed_daily;
        TADOQuery *SearchClient;
        TADOQuery *ADOQuery2;
        TADOQuery *WriServ;
        TDataSource *dsWriServ;
        TDataSource *dsSearchClient;
        TADOQuery *Alarm;
        TDataSource *dsAlarm;
        TADOQuery *Write_cab;
        TADOQuery *Temp1;
        TAutoIncField *WriServID;
        TIntegerField *WriServProfID;
        TStringField *WriServServName;
        TIntegerField *WriServServTime;
        TADOTable *Write_Client;
        TADOStoredProc *Writer;
        void __fastcall WriterAfterInsert(TDataSet *DataSet);
        void __fastcall WriterBeforeInsert(TDataSet *DataSet);
        void __fastcall Write_ClientAfterInsert(TDataSet *DataSet);
        void __fastcall Write_ClientBeforeInsert(TDataSet *DataSet);
        void __fastcall Write_ClientAfterPost(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TData1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TData1 *Data1;
//---------------------------------------------------------------------------
#endif
