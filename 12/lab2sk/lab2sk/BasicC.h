#pragma once
#include <iostream>
using namespace std;

class BasicC
{
public:
	BasicC(void);
	~BasicC(void);
	void show() { cout << "\nПростая функция базового класса\n"; };
	virtual void show_() { cout << "\nВиртуальная функция базового класса\n"; };
};

