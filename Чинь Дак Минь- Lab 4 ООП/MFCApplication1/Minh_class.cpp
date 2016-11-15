#include "stdafx.h"
#include "Minh_class.h"
#include "Minh.h"
#include <fstream>
#include<iostream>
using namespace std;


Minh_class::Minh_class()
{
}


Minh_class::~Minh_class()
{
}

void Minh_class::add_book()
{
	shared_ptr <Minh> book = make_shared<Minh>();
	book->input();
	library.push_back(book);
}

void Minh_class::add_journal()
{
	shared_ptr <journal> j = make_shared<journal>();
	j->input();
	library.push_back(j);
}

void Minh_class::v_output()
{
	if (library.size() != 0)
	for (auto it : library)
		it->output();
	else cout << " ERROR";
};



//void Minh_class::fv_output()
//{
//	ofstream out;
//	out.open("File.txt");
//	int k = library.size();
//	out << k << endl;
//	for (int i = 0; i < library.size(); i++)
//		library[i]->foutput(out);
//};
//
//void Minh_class::fv_input()
//{
//	ifstream in;
//	in.open("File.txt");
//	if (in)
//	{
//		int n;
//		in >> n;
//		for (int i = 0; i < n; i++)
//		{
//			Minh* book = new Minh;
//			book->finput(in);
//			library.push_back(book);
//		}
//	}
//	else cout << "Заполните файл!\n";
//	
//}


void Minh_class::foutput()
{
	cout << "Введите имя файла" << endl;
	string name;
	cin >> name;
	CFile f;
	f.Open(name.c_str(), CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&f, CArchive::store);
	int count = library.size();
	ar << count;
	for (auto it : library)
	{
		ar << it.get();
	}
	ar.Close();
	f.Close();
}


void Minh_class::finput()
{
	cout << "Введите имя файла " << endl;
	string name;
	cin >> name;
	CFile f;
	f.Open(name.c_str(), CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	int n;
	ar >> n;
	for (int i = 0; i < n; i++)
	{
		Minh *obj;
		ar >> obj;
		shared_ptr<Minh> it(obj);
		library.push_back(it);
	}
	ar.Close();
	f.Close();
}

void Minh_class::clear()
{
	library.clear();
}
