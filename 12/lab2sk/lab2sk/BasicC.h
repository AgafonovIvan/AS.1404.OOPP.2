#pragma once
#include <iostream>
using namespace std;

class BasicC
{
public:
	BasicC(void);
	~BasicC(void);
	void show() { cout << "\n������� ������� �������� ������\n"; };
	virtual void show_() { cout << "\n����������� ������� �������� ������\n"; };
};

