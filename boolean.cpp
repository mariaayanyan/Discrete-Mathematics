#include "boolean.h"
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <map>
#include <bitset>
#include <functional>
#include <stack>
using namespace std;

map<wchar_t, function<bool(bool, bool)> > functions;
void fill()
{
	functions[L'&'] = AND;
	functions[L'|'] = NAND;
	functions[L'V'] = OR;
	functions[L'+'] = XOR;
	functions[L'↓'] = NOR;
	functions[L'~'] = EQ;
	functions[L'→'] = IMPL;
}

int priority(wchar_t oper)
{
	if (oper == L'(')
		return 3;
	if (oper == L'¬')
		return 2;
	if (oper == L'&')
		return 1;
	return 0;
}

void performOperation(stack<bool>& num, stack<wchar_t>& oper)
{
	if (oper.top() == L'¬')
	{
		bool a = num.top();
		num.pop();
		num.push(NOT(a));
		oper.pop();
		return;
	}

	bool b = num.top();
	num.pop();
	bool a = num.top();
	num.pop();
	num.push(functions[oper.top()](a, b));
	oper.pop();
}

wstring parse(const wstring& func, const wstring& var)
{
	wstring ans;
	static int cur = 0;
	if (cur == (1 << var.size()))
	{
		cur = 0;
		return L"";
	}
	map<wchar_t, bool> val;
	bitset<10> bs(cur);

	for (int i = 0; i < var.size(); ++i)
		val[var[i]] = bs[var.size() - 1 - i];
	val[L'0'] = 0;
	val[L'1'] = 1;

	stack<bool> num;
	stack<wchar_t> oper;

	for (auto c : func)
	{
		if (c == L'(' || c == L'¬')
		{
			oper.push(c);
			continue;
		}

		if (c == L')')
		{
			while (oper.top() != L'(')
				performOperation(num, oper);
			oper.pop();
			continue;
		}

		if (val.find(c) != val.end())
		{
			num.push(val[c]);
			if (oper.top() == L'¬')
				performOperation(num, oper);
			continue;
		}
			
		while (!oper.empty() && priority(c) <= priority(oper.top()) && oper.top() != '(')
		{
			performOperation(num, oper);
		}
		oper.push(c);
	}

	while (!oper.empty())
		performOperation(num, oper);

	ans += L'0' + num.top();
	++cur;
	return ans + parse(func, var);
}
 
int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	fill();
	
	wstring func;
	wcout << "Enter the function: ";
	wcin >> func;
	
	wcout << "Enter the variables: ";
	wstring var;

	{
		wchar_t v;
		while(wcin >> v)
			var.push_back(v);
	}
	
	wcout << parse(func, var);
}