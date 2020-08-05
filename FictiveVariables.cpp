#include <iostream>
#include <string>
using namespace std;
bool isFictive(const string &str, int n)
{
	int pow = 1<<n;
	int len = str.size() / pow;

	for(int i = 0; i < str.size(); i += 2*len)
	{
		if(str.substr(i, len) != str.substr(i + len, len))
			return false;
	}

	return true;	
}

int powerOf2(int num)
{
	int ans = 0;
	while (num % 2 == 0)
	{
		num /= 2;
		++ans;
	}
	if (num != 1)
		throw "Invalid length";
	return ans;
}

int main()
{
	//Количество запросов
	int num;
	cin >> num;

	while(num--)
	{
		string str;
		//Вектор истинности
		cin >> str;
		cout << str << ": ";
		
		try
		{
			int varCount = powerOf2(str.length());

			//Вектор истинности : фиктивные переменные
			for (int i = 1; i <= varCount; ++i)
			{
				if (isFictive(str, i))
					cout << "X" << i << " ";
			}
			cout << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
}

/*
6 
1100001111000011 
1100001011000010 
0011001100110011 
0011011100110111 
1100110000110011 
0101000011110101 
*/
