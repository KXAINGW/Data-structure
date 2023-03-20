#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
void set(vector<int>& vec, string str)
{
	while (1)
	{
		int num = stoi(str.substr(0, str.find(' ')));
		if (find(vec.begin(), vec.end(), num) == vec.end())
			vec.push_back(num);
		str = str.substr(str.find(' ') + 1, str.size());
		if (str.find(' ') == -1)
		{
			int num = atoi((str.substr(0, str.find(' '))).c_str());
			if (find(vec.begin(), vec.end(), num) == vec.end())
				vec.push_back(num);
			return;
		}
	}
}
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	vector<int>arr1;
	vector<int>arr2;
	set(arr1, str1);
	set(arr2, str2);

	vector<int>target;
	for (size_t i = 0; i < arr1.size(); ++i)
		if (find(arr2.begin(), arr2.end(), arr1[i]) == arr2.end())
			target.push_back(arr1[i]);

	for (size_t i = 0; i < arr2.size(); ++i)
		if (find(target.begin(), target.end(), arr2[i]) == target.end() && find(arr1.begin(), arr1.end(), arr2[i]) == arr1.end())
			target.push_back(arr2[i]);
	sort(target.begin(), target.end());

	int space_num = 0;
	for (int i : target)
	{
		if (space_num++)
			cout << ' ';
		cout << i;
	}
	cout << endl;
}
