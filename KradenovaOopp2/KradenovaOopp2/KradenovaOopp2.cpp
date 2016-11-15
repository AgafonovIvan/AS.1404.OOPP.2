// KradenovaOopp2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

class Kradenova1 // базовый класс
{
public:
	virtual void f1()
	{
		cout << "Virtual function base class" << endl;
	}
	void f2()
	{
		cout << "Simple function base class" << endl;
	}

};



class Kradenova2 : public Kradenova1 // потомок
{
public:
	virtual void f1()
	{
		cout << "Virtual function arbitrary class" << endl;
	}
	void f2()
	{
		cout << "Simple function arbitrary class" << endl;
	}

};




int main()
{


	Kradenova1 *ptr1;
	Kradenova1 base_obj;

	ptr1 = &base_obj;

	Kradenova2 *ptr2;
	Kradenova2 arb_obj;

	ptr2 = &arb_obj;

	Kradenova1 *ptr3;

	ptr3 = &arb_obj;

	Kradenova2 *ptr4;

	ptr4 = static_cast <Kradenova2*>(&arb_obj);

	ptr1->f1();
	ptr1->f2();
	cout << endl;
	ptr2->f1();
	ptr2->f2();
	cout << endl;
	ptr3->f1();
	ptr3->f2();
	cout << endl;
	ptr4->f1();
	ptr4->f2();

	system("pause");

	return 0;
}


