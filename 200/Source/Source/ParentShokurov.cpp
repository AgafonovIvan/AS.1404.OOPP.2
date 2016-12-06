#include "stdafx.h"
#include "ParentShokurov.h"
#include <iostream>

using namespace std;

ParentShokurov::ParentShokurov()
{
}


ParentShokurov::~ParentShokurov()
{
}
void ParentShokurov::printSimple() {
	cout << "Это простая функция родительского класса" << endl;
}

void ParentShokurov::printVirtual() {
	cout << "Это виртуальная функция родительского класса" << endl;
}