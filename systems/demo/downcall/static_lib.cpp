// StaticLib1.cpp : Defines the functions for the static library.
//


#include "pch.h"
#include "framework.h"
#include "StaticLib1.h"

#include <iostream>

// TODO: This is an example of a library function
void fnStaticLib1()
{
	std::cout << "Hello" << std::endl;
}

int return_integer()
{
	return 4;
}

double return_double()
{
	return 3.1415;
}

char return_byte()
{
	return 'a';
}

char* return_string()
{
	char greeting[9] = { 'c','h','a','r',' ', 'a', 'r','r','\0'};
	return greeting;
}

std::string return_stdstr() 
{
	std::string str = "Standard String";
	return str;
}

struct Mix return_mix()
{
	struct Mix var;
	var.integer = 6;
	var.double_val = 5.14512;
	var.bool_val = false;
	var.name_string = "Alex Na";
	return var;
}

std::vector<Mix> return_vec_mix()
{
	std::vector<Mix> v1;
	struct Mix m1;
	struct Mix m2;
	struct Mix m3;
	struct Mix m4;
	struct Mix m5;
	
	v1.push_back(m1);
	v1.push_back(m2);
	v1.push_back(m3);
	v1.push_back(m4);
	v1.push_back(m5);
	return v1;
}
