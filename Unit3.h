//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "rgg.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
struct Complex
{
	short Re;
	short Im;
};
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button2;
	TOpenDialog *OpenDialog1;
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Button3;
	TSaveDialog *SaveDialog1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	bool isUpdateForm = false;
	__int64 WrBytes;// = 0;
	__int64 allBytes;// = sizeof(RggHeader);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
