//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyThread.h"
#include "Unit3.h"
#include <vector>
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
std::vector <Complex> avg;


__fastcall MyThread::MyThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;
}

//---------------------------------------------------------------------------
void __fastcall MyThread::Execute()
{
	//---- Place thread code here ----
	Form3->WrBytes=0;
    Form3->Label4->Visible = true;
	Form3->Label3->Visible = true;
	int iFileHandle = FileOpen(Form3->Edit1->Text, fmOpenRead);
	//int iNewFileHandle = 0;
	UnicodeString outFileName = Form3->Edit2->Text;
	if(iFileHandle<=0)
	{
		ShowMessage("Ошибка открытия входного файла");
		Form3->Button1->Enabled = true;
		return;
	}
//	if(!FileExists(outFileName))
//	{
//		iNewFileHandle = FileCreate(outFileName);
//		FileClose(iNewFileHandle);
//		ShowMessage("Cjplfkb ds[jlyjq afqk");
//	}
//	else
//	{
//		ShowMessage("Не удалось создать выходной файл");
//		return;
//	}

	avg.clear();

	RggHeader fileHeader = {0};
	__int64 fileLength = (__int64)FileSeek(iFileHandle, (__int64)0,2);
	Form3->allBytes = fileLength;
	FileSeek(iFileHandle, 0, 0);
	__int64 iBytesRead = FileRead(iFileHandle, &fileHeader, sizeof(RggHeader));
	//ShowMessage(iFileHandle);

	//ShowMessage(fileLength);

	//__int64 aa =  4226827264;
	//ShowMessage(sizeof(short));
	int sizeOfDataType;
	if(fileHeader.format.typeSamples==0)sizeOfDataType=1;//char
	if(fileHeader.format.typeSamples==1)sizeOfDataType=2;//short
	if(fileHeader.format.typeSamples==2)sizeOfDataType=1;//uchar
	if(fileHeader.format.typeSamples==3)sizeOfDataType=2;//ushort
	if(fileHeader.format.typeSamples==4)sizeOfDataType=4;//float
	if(fileHeader.format.typeSamples==5)sizeOfDataType=8;//double
	__int64 FileLength = fileLength; ///то что надо))
	__int64 countOfStr = (FileLength - sizeof(RggHeader))/(sizeof(RggStrHeader) + fileHeader.format.cntSamples*2*sizeOfDataType);
	//ShowMessage(sizeOfDataType);
	//ShowMessage(countOfStr);
	int iNewFileHandle = FileCreate(Form3->Edit2->Text);
	FileClose(iNewFileHandle);
	iNewFileHandle = FileOpen(Form3->Edit2->Text, fmOpenWrite);
	if(iNewFileHandle<=0)
	{
		ShowMessage("Не удалось создать выходной файл");
			//ShowMessage(iNewFileHandle);
        Form3->Button1->Enabled = true;
		return;
	}
	__int64 iBytesWrite = FileWrite(iNewFileHandle, &fileHeader, sizeof(RggHeader));
	Form3->WrBytes = iBytesWrite;
	//ShowMessage(countOfStr);
	Complex *Cmas = new Complex[fileHeader.format.cntSamples];
	for(int i = 0; i<countOfStr; i++)
	{
		float ReSum = 0;
		float ImSum = 0;
		float ReAvg = 0;
		float ImAvg = 0;
		RggStrHeader strHeader = {0};
		iBytesRead+=FileRead(iFileHandle, &strHeader, sizeof(strHeader));
		iBytesWrite+=FileWrite(iNewFileHandle ,&strHeader, sizeof(strHeader));
		Form3->WrBytes = iBytesWrite;
		//std::vector<Complex> vec;

		iBytesRead+=FileRead(iFileHandle, &Cmas[0], sizeof(Complex)*fileHeader.format.cntSamples);

		for(int j = 0; j<fileHeader.format.cntSamples; j++)
		{
			ReSum+=Cmas[j].Re;
			ImSum+=Cmas[j].Im;
		}

		ReAvg = ReSum/(float)fileHeader.format.cntSamples;
		ImAvg = ImSum/(float)fileHeader.format.cntSamples;
		Complex AVG;
		AVG.Re = ReAvg;
		AVG.Im = ImAvg;
		avg.push_back(AVG);
		for(int j = 0; j<fileHeader.format.cntSamples; j++)
		{
			Cmas[j].Re -=(short)ReAvg;
			Cmas[j].Im -=(short)ImAvg;
		}
		iBytesWrite+=FileWrite(iNewFileHandle, &Cmas[0], sizeof(Complex)*fileHeader.format.cntSamples);
		Form3->WrBytes = iBytesWrite;
	}
	delete[] Cmas;

	FileClose(iNewFileHandle);
	FileClose(iFileHandle);
	iFileHandle = FileCreate(Form3->Edit2->Text  + ".txt");
	FileClose(iFileHandle);
	iFileHandle = FileOpen((Form3->Edit2->Text + ".txt"), fmOpenWrite);
	for(int i= 0; i<avg.size(); i++)
	{
		AnsiString string = (UnicodeString)i;// + "\t\t";
		FileWrite(iFileHandle, &((AnsiString)string).c_str()[0], string.Length());
		string = "\t\t";
		FileWrite(iFileHandle, &string.c_str()[0], string.Length());
		//ShowMessage(i);

		string =avg[i].Re;// + "\t\t";
		FileWrite(iFileHandle, &string.c_str()[0], string.Length());
		string = "\t\t";
		FileWrite(iFileHandle, &string.c_str()[0], string.Length());
		//ShowMessage(avg[i].Re);
		string =avg[i].Im;// + "\n";
		FileWrite(iFileHandle, &string.c_str()[0], string.Length());
		string ="\n";
		//ShowMessage(avg[i].Im);
		//ShowMessage(string);
		FileWrite(iFileHandle, &string.c_str()[0], string.Length());
	}
	FileClose(iFileHandle);
	Form3->WrBytes = 0;
	Form3->ProgressBar1->Visible = false;
	Form3->isUpdateForm = false;
	Form3->Button2->Enabled = true;


	ShowMessage("Готово");
    Form3->Timer1->Tag =0;

	Form3->Label4->Visible = false;
	Form3->Label3->Caption = "";
	Terminate();
}
//---------------------------------------------------------------------------
