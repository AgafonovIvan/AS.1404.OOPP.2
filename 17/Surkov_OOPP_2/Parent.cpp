#include "Parent.h"


void Parent::writeE()
{
	std::cout << "\n������� ����� ��������\n";
}

void Parent::writeV()
{
	std::cout << "\n����������� ����� ��������\n";
}

void Derived::writeE()
{
	std::cout << "\n����������� ����� ������������ ������\n";
}

void Derived::writeV()
{
	std::cout << "\n������� ����� ������������ ������\n";
}

