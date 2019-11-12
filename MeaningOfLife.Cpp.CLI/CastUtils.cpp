
#include <string>
#include "CastUtils.h"


using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;


const char* string_to_char_array(String^ str)
{
	return (const char*)(void*)
		Marshal::StringToHGlobalAnsi(str);
}

string ManagedStringToStdString(System::String^ str)
{
	cli::array<unsigned char>^ bytes = System::Text::Encoding::ASCII->GetBytes(str);
	pin_ptr<unsigned char> pinned = &bytes[0];
	std::string nativeString((char*)pinned, bytes->Length);
	return nativeString;
}

System::String^ wstring_to_sys_string(std::wstring const& os) {
	String^ str = gcnew String(os.c_str());
	return str;
}
