#pragma once
#include <iostream>
#include <string>
using namespace std;
class StringConvert
{
public:
	StringConvert();
	~StringConvert();
	BOOL StringToWString(string &str, wstring &wstr);
	BOOL WStringToString(wstring &wstr, string &str);
};

