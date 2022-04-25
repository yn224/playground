# Example of Downcall

## Requirements
* Visual Studio 2022

## Setup
1. Create `CLR Console App` in Visual Studio.
2. In the Solutions Explorer, add a new project with `C++ Static Library`
3. Set the console application project be the Startup Project.
4. Add the static library as a reference for the console application.
5. Make sure that the `Common Runtime Language Support` is enabled for the console application (under `Properties - C++/CLI Properties - Common Language Runtime Support`)

If any problem arises in searching for these projects, make sure the
installer includes all the necessary files.

## Running
Just like any other ordinary systems, build and run console application on the Visual Studio platform after the codes has been written.

* `managed.cpp` - Sample source file for console application project
* `static_lib.cpp`, `static_lib.h` - Sample source and header file for static library project

## Functionality
Downcall different functions to send and retrieve different data types.

## Results
* Simple data types can successfully be passed around.
  * Type conversion found [here](https://docs.microsoft.com/en-us/cpp/dotnet/managed-types-cpp-cli?view=msvc-170)
* Complex data types (`struct`, `vector`, `list`, etc.) has to be manually 
  copied.