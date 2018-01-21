//---------------------------------------------------------------------------

#ifndef Unit_dH
#define Unit_dH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm_d : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TDBGrid *DBGrid1;
        void __fastcall DBGrid1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_d(TComponent* Owner);
        TDateTime d_curr;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_d *Form_d;
//---------------------------------------------------------------------------
#endif
