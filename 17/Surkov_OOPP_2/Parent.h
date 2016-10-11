#pragma once
#include <iostream>

class Parent
{
public:
	void writeE();
	virtual void writeV();
};

class Derived : public Parent 
{
public:
	virtual void writeE();
	void writeV();
};
