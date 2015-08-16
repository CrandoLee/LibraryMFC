#pragma once
#include <iostream>
#include <string>
using namespace std;
class StringConvert
{
public:
	StringConvert();
	~StringConvert();
	wstring s2ws(const string& s);
	wstring Ansi2WChar(LPCSTR pszSrc, int nLen);
	string ws2s(wstring& inputws);
	string WChar2Ansi(LPCWSTR pwszSrc);
};

