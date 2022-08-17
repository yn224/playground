// Source: https://www.codeproject.com/Articles/35437/Moving-Data-between-Managed-Code-and-Unmanaged-Cod
// Remove if compiling with Developer Command Line
#include "pch.h"

// Developer Command Line: cl /clr ManagedPragma.cpp
// Outputs: ManagedPragma.exe, ManagedPragma.obj
#include <stdio.h> 
#include <stdlib.h> 
#include <vcclr.h> 
#include <iostream> 
#include <chrono>

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
    Console::WriteLine("===C++ Managed===\n- Simple printing");
}

#pragma unmanaged 
void doTheStuff1( int _a, double _d, const wchar_t* const _str ) {
    std::cout << "===C++ Unmanaged===" << std::endl;
    std::cout << "- Int: " << _a << std::endl;
    printf_s("- String: %S\n", _str);
    std::cout << "- Double: " << _d << std::endl;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    std::cout << "* Upcall & measure the execution time" << std::endl;
    auto t1 = high_resolution_clock::now();

    moreInManaged();

    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Total Execution time in ms ";
    std::cout << ms_int.count() << "ms, (double precision: " << ms_double.count() << "ms)" << std::endl;
}

#pragma managed
CConfig::CConfig(int _a, String^ _str, double _d)
{
    m_a = _a;
    m_str = _str;
    m_d = _d;
}

void CConfig::doTheStuff()
{
    Console::WriteLine("===C++ Managed===");
    pin_ptr<const wchar_t> wch = PtrToStringChars(m_str);
    Console::WriteLine("- Pass arguments into unmanaged function");
    doTheStuff1(m_a, m_d, wch);
}

int main(array<System::String ^> ^args)
{
    CConfig^ cfg = gcnew CConfig(10, "Hi", 8.1232);
    cfg->doTheStuff();
    return 0;
}
