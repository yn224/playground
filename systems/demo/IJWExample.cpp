#include "pch.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <vcclr.h> 
#include <iostream> 

using namespace System;

public ref class CConfig
{
public:
    CConfig(int _a, String^ _str, double _d);
    void doTheStuff();
    int m_a;
    String^ m_str;
    double m_d;
};

void moreInManaged() {
    Console::WriteLine("C++ Managed - some more");
}

#pragma unmanaged 
void doTheStuff1( int _a, double _d, const wchar_t* const _str) {
    std::cout << "C++ Unmanaged - Do Stuff 1" << std::endl;
    std::cout << _a << std::endl;
    printf_s("%S\n", _str);
    std::cout << _d << std::endl;
    moreInManaged();
}

#pragma managed
CConfig::CConfig(int _a, String^ _str, double _d)
{
    m_a = _a;
    m_str = _str;
    m_d = _d;
    //throw gcnew System::NotImplementedException();
}

void CConfig::doTheStuff()
{
    Console::WriteLine("C++ Managed - do stuff");
    pin_ptr<const wchar_t> wch = PtrToStringChars(m_str);
    doTheStuff1(m_a, m_d, wch);
    //throw gcnew System::NotImplementedException();
}

int main(array<System::String ^> ^args)
{
    CConfig^ cfg = gcnew CConfig(10, "Hi", 8.1232);
    cfg->doTheStuff();
    return 0;
}

