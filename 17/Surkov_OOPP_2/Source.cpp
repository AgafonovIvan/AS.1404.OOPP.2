#include "Parent.h"

int main()
{
	setlocale(LC_ALL, "");
	Parent parent, *parent_parent, *parent_derived_derived;
	Derived derived, *derived_derived, *derived_parent_derived;
	parent_parent = &parent;
	parent_derived_derived = derived_derived;
	derived_parent_derived = static_cast<Derived*>(parent_derived_derived);//4 �����

	parent_parent->writeE();
	parent_parent->writeV();

	derived_derived->writeE();
	derived_derived->writeV();

	parent_derived_derived->writeE();
	parent_derived_derived->writeV();

	derived_parent_derived->writeE();
	derived_parent_derived->writeV();

	system("pause>>void");
	return 0;
}
