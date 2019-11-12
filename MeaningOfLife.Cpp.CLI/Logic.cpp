#include "Logic.h"
#include <string>
#include <Windows.h>
#include "..\MeaningOfLife.Cpp\Logic.h"
#include "CastUtils.h"

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;


MeaningOfLife::Cpp::CLI::Logic::Logic()
	: _impl(new Cpp::Logic()) 
	// Allocate some memory for the native implementation
{
}

String^ MeaningOfLife::Cpp::CLI::Logic::Get(String^ text)
{
	const char* mText = string_to_char_array(text);
	String^ a = wstring_to_sys_string(_impl->Get(mText).c_str());
	return a;
}

void MeaningOfLife::Cpp::CLI::Logic::Destroy()
{
	if (_impl != nullptr)
	{
		delete _impl;
		_impl = nullptr;
	}
}

MeaningOfLife::Cpp::CLI::Logic::~Logic()
{
	// C++ CLI compiler will automaticly make all ref classes implement IDisposable.
	// The default implementation will invoke this method + call GC.SuspendFinalize.
	Destroy(); // Clean-up any native resources 
}

MeaningOfLife::Cpp::CLI::Logic::!Logic()
{
	// This is the finalizer
	// It's essentially a fail-safe, and will get called
	// in case Logic was not used inside a using block.
	Destroy(); // Clean-up any native resources 
}



void MeaningOfLife::Cpp::CLI::Logic::InitializeLibrary(System::String^ path)
{
	string nativePath = ManagedStringToStdString(path);
	LoadLibrary(nativePath.c_str()); // Actually load the delayed library from specific location
}
