#include "stdafx.h"
#include "ChildShokurov.h"
#include <iostream>
using namespace std;
ChildShokurov::ChildShokurov()
{
}


ChildShokurov::~ChildShokurov()
{
}

void ChildShokurov::printSimple() {
	i = 0;

	cout <<i<< endl;
}

void ChildShokurov::printVirtual() {
	cout << "Это виртуальная функция потомка класса" << endl;
}
