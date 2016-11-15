#include "stdafx.h"
#include "Minh.h"
#include <iostream>
#include <fstream>

IMPLEMENT_SERIAL(Minh, CObject, 0);
IMPLEMENT_SERIAL(journal, Minh, 0);

using namespace std;



Minh::Minh()
{
}

Minh::~Minh()
{
}

journal::~journal()
{

}

journal::journal()
{

}

void Minh::input()
{
	string n;
	string a;
	cout << "������� ��������\n";
	cin >> n;
	name = n.c_str();
	cout << "������� ������� ������\n";
	cin >> a;
	author = a.c_str();
	cout << "������� ��� �������\n";
	cin >> year;

}

void Minh::output()
{
	cout << "��������:" << name << endl;
	cout << "�����:" << author << endl;
	cout << "��� �������:" << year << endl;
}


void Minh::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << name << author << year;
	}
	else
	{
		ar >> name >> author >> year;
	}
}

//void Minh::finput(ifstream& in)
//{
//	in >> name;
//	in >> author;
//	in >> year;
//}

//void Minh::foutput(ofstream& out)
//{
//	out << name<<endl;
//	out << author<<endl;
//	out << year<<endl;
//}

void journal::input()
{
	string n;
	string a;
	string h;
	cout << "������� �������e\n";
	cin >> n;
	name = n.c_str();
	cout << "������� ������� ������\n";
	cin >> a;
	author = a.c_str();
	cout << "������� ��� �������\n";
	cin >> year;
	cout << "������� ����� �������\n";
	cin >> number;
	cout << "������� ���������\n";
	cin >> h;
	header = h.c_str();
}

void journal::output()
{
	cout << "��������:" << name << endl;
	cout << "�����:" << author << endl;
	cout << "��� �������:" << year << endl;
	cout << "����� ��������:" << number << endl;
	cout << "���������:" << header << endl;
}

void journal::Serialize(CArchive &ar)
{
	Minh::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << number << header;
	}
	else
	{
		ar >>  number >> header;
	}
}


int Minh::GetSumLength()
{
	return name.GetLength() + author.GetLength() + 4;
}

int journal::GetSumLength()
{
	return name.GetLength() + author.GetLength() + 4 + 3 + header.GetLength();
}


void Minh::WinOutput(int &i, CDC* pDC)
{
	CString n = "";
	n.Format("%d", i);
	CRect rect(0, 15 * i, 15 * n.GetLength(), 15 * (i + 1));
	pDC->DrawText(n, rect, 0);

	rect = CRect(15 * n.GetLength(), 15 * i, 15 * (n.GetLength() + name.GetLength()), 15 * (i + 1));
	pDC->DrawText(name, rect, 0);

	rect = CRect(15 * (n.GetLength() + name.GetLength()),
		15 * i, 
		15 * (n.GetLength() + name.GetLength() + author.GetLength()),
		15 * (i + 1));
	pDC->DrawText(author, rect, 0);

	CString s = "";
	s.Format("%d", year);
	rect = CRect(15 * (n.GetLength() + name.GetLength() + author.GetLength()),
		15 * i,
		15 * (n.GetLength() + name.GetLength() + author.GetLength() + s.GetLength()),
		15 * (i + 1));
	pDC->DrawText(s, rect, 0);
	i++;
}

void journal::WinOutput(int &i, CDC* pDC)
{
	CString n = "";
	n.Format("%d", i);
	CRect rect(0, 15 * i, 15 * n.GetLength(), 15 * (i + 1));
	pDC->DrawText(n, rect, 0);

	rect = CRect(15 * n.GetLength(), 15 * i, 15 * (n.GetLength() + name.GetLength()), 15 * (i + 1));
	pDC->DrawText(name, rect, 0);

	rect = CRect(15 * (n.GetLength() + name.GetLength()),
		15 * i,
		15 * (n.GetLength() + name.GetLength() + author.GetLength()),
		15 * (i + 1));
	pDC->DrawText(author, rect, 0);

	CString s = "";
	s.Format("%d", year);
	rect = CRect(15 * (n.GetLength() + name.GetLength() + author.GetLength()),
		15 * i,
		15 * (n.GetLength() + name.GetLength() + author.GetLength() + s.GetLength()),
		15 * (i + 1));
	pDC->DrawText(s, rect, 0);


	CString s1 = "";
	s1.Format("%d", number);
	 rect=CRect (15 * (n.GetLength() + name.GetLength() + author.GetLength() + s.GetLength()),
		15 * i,
		15 * (n.GetLength() + name.GetLength() + author.GetLength() + s.GetLength()+s1.GetLength()),
		15 * (i + 1)); 
	pDC->DrawText(s1, rect, 0);


	rect = CRect(15 * (n.GetLength() + name.GetLength() + author.GetLength() + s.GetLength() + s1.GetLength()),
		15 * i,
		15 * (n.GetLength() + name.GetLength() + author.GetLength() + s.GetLength() + s1.GetLength()+header.GetLength()),
		15 * (i + 1));

	pDC->DrawText(header, rect, 0);

	i++;
}