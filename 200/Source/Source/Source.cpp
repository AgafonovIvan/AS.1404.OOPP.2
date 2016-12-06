// Source.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "ParentShokurov.h"
#include "ChildShokurov.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "ru");
	ParentShokurov * bas1 = new ParentShokurov;
	ChildShokurov * der1 = new ChildShokurov;
	ParentShokurov* bas2 = der1;
	int a;
	cin >> a;
	if (!a)
	{
		bas2 = bas1;
	}
	ChildShokurov* der2 = dynamic_cast<ChildShokurov*>(bas2);//���������� ��������� ������������� ������ � ��������� ������� ������ (��� �������� ���� �� ����� ����������);
	//dynamic_cast �������� ������ ��������� ������������ ������������� ���� ������, ������� ��������� ��������� ���������� ���� ������. 
	//� ������� �� �������� ���������� ���� � ����� ��, �������� ������������ ���������� ����� ������������ �� ����� ���������� ���������. �������� dynamic_cast ����� ���� ������� � ���������� ��� �������.

	cout << "��������� �� ������������ �����, �������� �������� ������ ������������� ������ \n=> ����� ������� ������������� ������:" << endl;
	bas1->printSimple();
	bas1->printVirtual();
	cout << endl;

	cout << "��������� �� ������� �����, �������� �������� ������ ������� ������ \n=> ����� ������� ������� ������:" << endl;
	der1->printSimple();
	der1->printVirtual();
	cout << endl;

	cout << "��������� �� ������������ �����, �������� �������� ������ �� ������� ���������:" << endl;
	bas2->printSimple();
	bas2->printVirtual();
	cout << endl;
	if (der2)
	{
		cout << "��������� �� ������� �����, �������� � �������������� ����������� �������� \n���������� ���� �������� ������ �� �������� ���������:" << endl;
		der2->printSimple();
		der2->printVirtual();
		cout << endl;
	}
	system("pause");
	return 0;
}
