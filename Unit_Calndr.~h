//---------------------------------------------------------------------------

#ifndef Unit_CalndrH
#define Unit_CalndrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "PlannerMonthView.hpp"
#include <ExtCtrls.hpp>

#include "Planner.hpp"
//---------------------------------------------------------------------------
class TForm_Calndr : public TForm
{
__published:	// IDE-managed Components
        TPlannerMonthView *PlannerMonthView1;

        void __fastcall PlannerMonthView1DaySelect(TObject *Sender,
          TDateTime SelDate);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PlannerMonthView1DateChange(TObject *Sender,
          TDateTime origDate, TDateTime newDate);
        void __fastcall PlannerMonthView1ItemDblClick(TObject *Sender,
          TPlannerItem *Item);
private:	// User declarations
public:		// User declarations
void ShowShed(TDateTime newDate);
//TPlannerItem *plIt;
AnsiString Name;
int ClientID;
int workID,PerID, CabID;
        __fastcall TForm_Calndr(TComponent* Owner);
        bool sh_f;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Calndr *Form_Calndr;
//---------------------------------------------------------------------------
#endif
