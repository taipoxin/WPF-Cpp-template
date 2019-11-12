// Logic.cpp

#include "Logic.h"

#include <iostream>

#include <locale>
#include <codecvt>
#include <string>


#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

using namespace std;

wstring string_to_wstring(string str)
{
	wstring a;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::string narrow = converter.to_bytes(a);
	std::wstring wide = converter.from_bytes(str);
	return wide;
}

std::wstring MeaningOfLife::Cpp::Logic::Get(const char* text) const
{
	std::cout << text << endl;
	int id = -10;
	// sample std::string from library
	string two = "sample string casted from std::string";

	wstring wide = string_to_wstring(two);
	wstring res = wide + L" || wstring number: " + to_wstring(id);
	return res;
}
