#include "stdafx.h"
#include "sidelnikova_child.h"
#include <iostream>

sidelnikova_child::sidelnikova_child()
{
}


sidelnikova_child::~sidelnikova_child()
{
}

void sidelnikova_child::simp() {
	std::cout << "simple,child " << std::endl;
}

void sidelnikova_child::virt() {
	std::cout << "virtual,child " << std::endl << std::endl;;
}