#pragma once
#include "ParentShokurov.h"

//ParentShokurov
class ChildShokurov : public ParentShokurov
{
public:
	ChildShokurov();
	~ChildShokurov();
	int i;
	void printSimple();
	void printVirtual();
};