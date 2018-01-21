//---------------------------------------------------------------------------

#ifndef Unit_selH
#define Unit_selH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include "RXCtrls.hpp"
//---------------------------------------------------------------------------
class TForm_sel : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TRadioGroup *RadioGroup1;
        TButton *Button1;
        TCheckListBox *CheckListBox1;
        TLabel *Label1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_sel(TComponent* Owner);

        AnsiString DName;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_sel *Form_sel;
//---------------------------------------------------------------------------
#endif
