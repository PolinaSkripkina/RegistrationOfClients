//---------------------------------------------------------------------------

#ifndef Cab_fullH
#define Cab_fullH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Planner.hpp"
/*#include "AdvDateTimePicker.hpp"
#include "AdvEdBtn.hpp"
#include "advedit.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "PlannerDatePicker.hpp"*/

#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <DateUtils.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <Buttons.hpp>
#include "ToolEdit.hpp"
#include <Mask.hpp>
//#include "PlanSimpleEdit.hpp"
//#include "plancheck.hpp"

//---------------------------------------------------------------------------
class TForm_Cab : public TForm
{
__published:	// IDE-managed Components
        TPlanner *Planner1;
        TPanel *Panel1;
        TADOQuery *MTemp;
        TADOQuery *MTemp1;
        TButton *Button1;
        TLabel *Label1;
        TADOQuery *MTemp2;
        TButton *Button2;
        TADOQuery *MTemp3;
        TButton *Button3;
        TButton *Button4;
        TBitBtn *BitBtn1;
        TTimer *Timer1;
        TProgressBar *ProgressBar1;
        TDateEdit *DateEdit1;

        void __fastcall Planner1PlannerNext(TObject *Sender);
        void __fastcall Planner1PlannerPrev(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);

        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Planner1ItemDblClick(TObject *Sender,
          TPlannerItem *Item);
        void __fastcall Planner1ItemRightClick(TObject *Sender,
          TPlannerItem *Item);
        void __fastcall Planner1ItemDelete(TObject *Sender,
          TPlannerItem *Item);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall DateEdit1Change(TObject *Sender);

private:	// User declarations

public:		// User declarations

        __fastcall TForm_Cab(TComponent* Owner);
           bool ReShowCab(TDateTime , TDateTime );
           void UpdWrite(int PerID,int it_pos, int CabID, int i_b, int i_e, int ID_w, int stat, AnsiString tit,  AnsiString txt);
           TDateTime d_n;
           bool sh_f, prd, next_d;
           short int prf;
           void UpdFAbout(int Id_w,short int pp);
           void ShowGrafik(int , int , int , int , int,int,int );
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Cab *Form_Cab;
//---------------------------------------------------------------------------
#endif
