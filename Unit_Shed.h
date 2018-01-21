//---------------------------------------------------------------------------

#ifndef Unit_ShedH
#define Unit_ShedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Planner.hpp"
//#include "PlanSimpleEdit.hpp"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//#include "PlannerWaitList.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
//#include "PlanItemEdit.hpp"
//#include "PlanRecurrEdit.hpp"
//#include "PlanPeriodEdit.hpp"
//---------------------------------------------------------------------------
class TForm_Shed : public TForm
{
__published:	// IDE-managed Components
        TPlanner *Planner1;
        TPanel *Panel1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TButton *Button1;
        TPrintDialog *PrintDialog1;
        TDBGrid *DBGrid1;
        void __fastcall Planner1ItemStartEdit(TObject *Sender,
          TPlannerItem *Item);
        void __fastcall Planner1ItemEndEdit(TObject *Sender,
          TPlannerItem *Item);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Planner1PlannerSelectCell(TObject *Sender,
          int Index, int Pos, bool &CanSelect);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall N151Click(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall Planner1ItemRightClick(TObject *Sender,
          TPlannerItem *Item);
        void __fastcall Planner1PlannerDblClick(TObject *Sender,
          int Position, int FromSel, int FromSelPrecise, int ToSel,
          int ToSelPrecise);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_Shed(TComponent* Owner);
        void WriteClient();
        void ReShed(int );
        int xm,ym,shag,du,ItemIndex;
        AnsiString ServName;
        bool show_form;
        TDateTime d_end, d_b, d_curr;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Shed *Form_Shed;
//---------------------------------------------------------------------------
#endif
