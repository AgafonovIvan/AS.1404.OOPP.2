// Source.cpp: определяет точку входа для консольного приложения.
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
	ChildShokurov* der2 = dynamic_cast<ChildShokurov*>(bas2);//приведение указателя родительского класса к указателю потомка класса (без проверок типа во время выполнения);
	//dynamic_cast является частью механизма динамической идентификации типа данных, который позволяет выполнять приведение типа данных. 
	//В отличие от обычного приведения типа в стиле Си, проверка корректности приведения типов производится во время выполнения программы. Оператор dynamic_cast может быть применён к указателям или ссылкам.

	cout << "Указатель на родительский класс, которому присвоен объект родительского класса \n=> Вызов функций родительского класса:" << endl;
	bas1->printSimple();
	bas1->printVirtual();
	cout << endl;

	cout << "Указатель на потомок класс, которому присвоен объект потомка класса \n=> Вызов функций потомка класса:" << endl;
	der1->printSimple();
	der1->printVirtual();
	cout << endl;

	cout << "Указатель на родительский класс, которому присвоен объект из второго указателя:" << endl;
	bas2->printSimple();
	bas2->printVirtual();
	cout << endl;
	if (der2)
	{
		cout << "Указатель на потомок класс, которому с использованием статической операции \nприведения типа присвоен объект из третьего указателя:" << endl;
		der2->printSimple();
		der2->printVirtual();
		cout << endl;
	}
	system("pause");
	return 0;
}
