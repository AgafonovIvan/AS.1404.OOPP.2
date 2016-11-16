// lab2sk.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "BasicC.h";
#include "SonC.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");

	//BasicC * bas1 = new BasicC;
	//SonC * son1 = new SonC;
	//BasicC* bas2 = son1;//BacicC* bas2= new SonC;
	//SonC* son2 = static_cast<SonC*>(bas2);
	BasicC * bas1;
	BasicC basic_obj;
	bas1=&basic_obj;
	SonC * son1;
    SonC son_obj;
	son1=&son_obj;
	BasicC* bas2;
	bas2=&son_obj;
	SonC*son2;
	son2=static_cast<SonC*>(&son_obj);

	//указатель  базового класса, которому присвоен адрес объекта базового класса;
	bas1->show();
	bas1->show_();

   //указатель  производного класса, которому присвоен адрес объекта производного класса;
	son1->show();
	son1->show_();

//указатель  базового класса, которому присвоен адрес объекта из второго указателя(son1);
	bas2->show();
	bas2->show_();

//указатель  производного класса, которому с использованием статической операции приведения типа присвоен объект из третьего указателя.
	son2->show();
	son2->show_();

	system ("pause");
	return 0;
}

