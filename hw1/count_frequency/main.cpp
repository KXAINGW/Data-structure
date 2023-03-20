#include<iostream>
#include<string>
#include<map>

using namespace std;
int main()
{
	map<char, int>frequency;
	for (int n = 'a'; n <= 'z'; n++)
		frequency[n] = 0;
	string str;
	cin >> str;
	for (char it : str)
		frequency[it]++;
	int i = 0;
	for (auto it : frequency)
	{
		if (i++)
			cout << ' ';
		cout << it.second;
	}
	cout << endl;
}