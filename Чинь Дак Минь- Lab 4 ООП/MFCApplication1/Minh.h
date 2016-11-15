#pragma once
#include <string>
#include <memory>
#include <afx.h>
#define _AFXDLL

using namespace std;

class Minh :public CObject
{
protected:

	CString name;//название книги
	CString author;//автор книги
	int year;//год издания
	DECLARE_SERIAL(Minh);
public:
	Minh();
	~Minh();
	virtual void input();
	/*void finput(ifstream& in);*/

	virtual void output();
	//void foutput(ofstream& out);
	virtual void Serialize(CArchive &ar);

	virtual int GetSumLength();
	virtual void WinOutput(int &i, CDC* pDC);
};

class journal : public Minh
{
protected:
	DECLARE_SERIAL(journal);
private:
	int number;
	CString header;
public:
	journal();
	~journal();
	void input();
	void output();
	void Serialize(CArchive &ar);
	int GetSumLength();
	void WinOutput(int &i, CDC* pDC);
};