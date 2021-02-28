#pragma once

#include <msclr\marshal_cppstd.h>;
#include <string>;

int decToInt(const System::Decimal& dec)
{
	// System::Decimal to int32
	return dec.ToInt32(dec);
}

std::string s(System::String^ str)
{
	// System::String to std::string
	return msclr::interop::marshal_as<std::string>(str);
}

std::string s(System::Decimal dec)
{
	// System::Decimal to std::string
	return std::to_string(decToInt(dec));
}

template<typename T>
std::string s(const T& value)
{
	// any~ to std::string
	return std::to_string(value);
}


System::String^ cs(std::string str)
{
	// std::string to System::String
	return gcnew System::String(str.c_str());
}

template<typename T>
System::String^ cs(const T& value)
{
	// any to System::String
	return gcnew System::String(s(value).c_str());
}
