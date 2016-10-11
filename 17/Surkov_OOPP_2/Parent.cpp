#include "Parent.h"


void Parent::writeE()
{
	std::cout << "\nПростой метод родителя\n";
}

void Parent::writeV()
{
	std::cout << "\nВиртуальный метод родителя\n";
}

void Derived::writeE()
{
	std::cout << "\nВиртуальный метод производного класса\n";
}

void Derived::writeV()
{
	std::cout << "\nПростой метод производного класса\n";
}

