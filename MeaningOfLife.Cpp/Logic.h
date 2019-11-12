// Logic.h
#pragma once

#include <string>

namespace MeaningOfLife
{	
	namespace Cpp
	{
	using namespace std;
		// This is our native implementation
		// It's marked with __declspec(dllexport) 
		// to be visible from outside the DLL boundaries
		class __declspec(dllexport) Logic
		{
		public:
			std::wstring Get(const char* text) const; // That's where our code goes
		};
	}
}