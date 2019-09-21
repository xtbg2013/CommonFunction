#include "stdafx.h"
#include "Common.h"


vector<string> Split(string str, string delimiter)
{
	vector<string> res;
	if ("" == str) return res;

	char * strs = new char[str.length() + 1];
	strcpy_s(strs, str.length() + 1, str.c_str());
	char * delim = new char[delimiter.length() + 1];
	strcpy_s(delim, delimiter.length() + 1, delimiter.c_str());
	char *pTmp = nullptr;
	char *p = strtok_s(strs, delim, &pTmp);
	while (p)
	{
		string s = p;
		res.push_back(s);
		p = strtok_s(nullptr, delim, &pTmp);
	}
	delete strs;
	delete delim;
	return res;
}

vector<string> Common::Split(string str, string delimiter)
{
	vector<string> res;
	if (str.empty())
		return res;
	string strExtend = str + delimiter; //扩展字符串以方便检索最后一个分隔出的字符串
	size_t pos;
	size_t size = strExtend.size();
	for (size_t i = 0; i < size; ++i)
	{
		pos = strExtend.find(delimiter, i);
		if (pos != string::npos)
		{
			string s = strExtend.substr(i, pos - i);
			if (!s.empty())
				res.push_back(s);
			i = pos + delimiter.size() - 1;
		}
	}
	return res;
}