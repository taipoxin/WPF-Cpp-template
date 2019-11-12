#pragma once


#include <string>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;


const char* string_to_char_array(String^ str);

string ManagedStringToStdString(System::String^ str);

System::String^ wstring_to_sys_string(std::wstring const& os);
