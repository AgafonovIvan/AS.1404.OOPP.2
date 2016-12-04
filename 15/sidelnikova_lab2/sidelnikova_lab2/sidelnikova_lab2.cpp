// sidelnikova_lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sidelnikova_basic.h"
#include "sidelnikova_child.h"
#include <iostream>

int main()
{
	sidelnikova_basic * basic = new sidelnikova_basic();
	sidelnikova_child * child = new sidelnikova_child();
	sidelnikova_basic * basic2 = child;
	sidelnikova_child * child2 = static_cast<sidelnikova_child*>(basic2);


	basic->simp();
	basic->virt();

	child->simp();
	child->virt();


	basic2->simp();
	basic2->virt();


	child2->simp();
	child2->virt();


	return 0;
}