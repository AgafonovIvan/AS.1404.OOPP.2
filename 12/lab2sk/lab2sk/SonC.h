#pragma once
#include "BasicC.h"

class SonC: public BasicC
{
public:
	SonC(void);
	~SonC(void);
	void show() { cout << "\n�������� ������� ������������ ������\n"; };
	virtual void show_() { cout << "\n����������� ������� ������������ ������\n"; };
};

