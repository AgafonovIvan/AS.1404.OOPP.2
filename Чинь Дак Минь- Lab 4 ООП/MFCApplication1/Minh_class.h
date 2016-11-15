#pragma once
#include <vector>
#include "Minh.h"
#include <memory>
class Minh_class
{
public:
	Minh_class();
	~Minh_class();
	void add_book();
	void add_journal();
	void v_output();
	//void fv_output();
	//void fv_input();
	void foutput();
	void finput();
	void clear();
	vector <shared_ptr<Minh>> library;
};

