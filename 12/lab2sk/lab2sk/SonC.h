#pragma once
#include "BasicC.h"

class SonC: public BasicC
{
public:
	SonC(void);
	~SonC(void);
	void show() { cout << "\nПрострая функция производного класса\n"; };
	virtual void show_() { cout << "\nВиртуальная функция производного класса\n"; };
};

