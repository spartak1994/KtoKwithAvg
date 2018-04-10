//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "MyThread.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;


//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    OpenDialog1->Filter = "Файлы (*.k)|*.K|Все Файлы (*.*)|*.*";
	OpenDialog1->Execute();
	Edit1->Text=OpenDialog1->FileName;
	//String filename = Edit1->Text.LowerCase();
	//ShowMessage(filename);
	if(ExtractFileExt(Edit1->Text.LowerCase())!=".k") Edit1->Text="Выберите файл нужного расширения";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Button2->Enabled = false;
	isUpdateForm = true;
	MyThread *thread = new MyThread(false);
	Form3->ProgressBar1->Visible = true;
	//read->Execute();

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	if(isUpdateForm)
	{
          //ShowMessage(Form3->WrBytes);
		//ProgressBar1->max = Form3->allBytes;
		//ShowMessage((double)Form3->WrBytes/(double)Form3->allBytes);
		if(Form3->allBytes!=0 && Form3->allBytes>=Form3->WrBytes)
		{
			ProgressBar1->Position = ((double)Form3->WrBytes / (double)Form3->allBytes)*100;
			//ShowMessage(Form3->WrBytes/Form3->allBytes);
			//ShowMessage(Form3->allBytes);
			Timer1->Tag++;

		}//ProgressBar1->Position++;
		//else(ShowMessage(Form3->allBytes));
		Label3->Caption = Timer1->Tag;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	SaveDialog1->Filter = "Файлы (*.k)|*.K|Все Файлы (*.*)|*.*";
	SaveDialog1->Execute();
	Edit2->Text = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------

