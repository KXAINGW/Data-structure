// Write your implementation here.
// Feel free to add any code you need in this file.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int num;
	cin >> num;
	cin.ignore();
	vector<char>left_parenthese;
	vector<char>right_parenthese;
	while (num--)
	{
		string parenthese;
		getline(cin, parenthese, '\n');
		left_parenthese.push_back(parenthese[0]);
		right_parenthese.push_back(parenthese[1]);
	}
	string text;
	cin >> text;
	vector<char>stack;
	typename vector<char>::iterator it;
	for (char ch : text)
	{
		it = find(left_parenthese.begin(), left_parenthese.end(), ch);
		if (it != left_parenthese.end())
			stack.push_back(*it);
		else
		{
			it = find(right_parenthese.begin(), right_parenthese.end(), ch);
			if (it != right_parenthese.end() && stack.size())
			{
				int index = it - right_parenthese.begin();
				if (stack.back() != left_parenthese[index])
				{
					cout << "NO\n";
					return 0;
				}
				stack.pop_back();
			}
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << (!stack.size() ? "YES\n" : "NO\n");
	return 0;
}