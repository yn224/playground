#pragma once
#include <vector>
#include <string>

struct Mix {
	int integer;
	double double_val;
	bool bool_val;
	std::string name_string;
};

void fnStaticLib1();
int return_integer();
double return_double();
char return_byte();
char* return_string();
std::string return_stdstr();
struct Mix return_mix();
std::vector<Mix> return_vec_mix();