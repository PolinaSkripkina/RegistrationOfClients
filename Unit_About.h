//---------------------------------------------------------------------------

#ifndef Unit_AboutH
#define Unit_AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdMessage.hpp>
#include <IdMessageClient.hpp>
#include <IdSMTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TForm_About : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TEdit *Edit1;
        TLabel *Label1;
        TButton *Button1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TMemo *Memo1;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TEdit *Edit3;
        TMaskEdit *Edit2;
        TLabel *Label5;
        TComboBox *ComboBox1;
        TMemo *Memo2;
        TEdit *Edit4;
        TBitBtn *BitBtn1;
        TIdSMTP *IdSMTP1;
        TIdMessage *IdMessage1;
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall DBGrid2KeyPress(TObject *Sender, char &Key);
        void __fastcall DBGrid2DblClick(TObject *Sender);
        void __fastcall ComboBox1Select(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
//        void __fastcall CheckListBox3ClickCheck(TObject *Sender);
        void __fastcall Edit1KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
AnsiString Name, Comment, Phone, Prim, Milo ;
int shag, stat, Adv, ClientID;
        __fastcall TForm_About(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_About *Form_About;
//---------------------------------------------------------------------------
#endif
