#include "pch.h"
#include "../StaticLib1/StaticLib1.h"
using namespace System;

public ref struct ManagedMix
{
    Int32^ integer;
    Double^ double_val;
    Boolean^ bool_val;
    String^ name_string;
};

int main(array<System::String ^> ^args)
{
    // Print "Hello" using iostream of static library
    fnStaticLib1();

    // Return a value 4
    Int32^ val = return_integer();
    Console::WriteLine("Should return int 4:\t\t" + val);

    // Return a double - 3.1415
    Double^ dval = return_double();
    Console::WriteLine("Should return double 3.1415:\t" + dval);

    // Return byte - char
    SByte^ bt = return_byte();
    Console::WriteLine("Should return char a:\t\t" + bt); // displays in char

    // Return a string (char array)
    const char* str = return_string();
    String^ clistr = gcnew String(str);
    Console::WriteLine("Should return char array (string):\t" + clistr);

    // Return a string (std::string)
    String^ std_str_cli = gcnew String(return_stdstr().c_str());
    Console::WriteLine("Should return std::string:\t" + std_str_cli);
    
    // Return a custom struct
    ManagedMix^ mobj = gcnew ManagedMix;
    mobj->bool_val = true;

    // Return a vector of struct
    //array< Mix^ >^ arr = nullptr;
    return 0;
}
