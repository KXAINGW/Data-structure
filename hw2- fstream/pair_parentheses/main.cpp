// Write your implementation here.
// Feel free to add any code you need in this file.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
void Primary_code(ifstream&);
int main()
{
	for (int i = 0; i <= 9; ++i)
	{
		ifstream inFile(string(1, char(i + 48)) + ".in.txt", ios::in);
		if (!inFile)
		{
			cout << "File could not be opened" << endl;
			exit(1);
		}
		cout << string(1, char(i + 48)) + ".in.txt" << endl;
		Primary_code(inFile);
		cout << "--------------------------------------------------" << '\n';
		inFile.close();
	}


	return 0;
}

void Primary_code(ifstream& inFile)
{
	int num;
	inFile >> num;
	inFile.ignore();
	vector<char>left_parenthese;
	vector<char>right_parenthese;
	while (num--)
	{
		string parenthese;
		inFile >> parenthese;
		left_parenthese.push_back(parenthese[0]);
		right_parenthese.push_back(parenthese[1]);
	}
	string text;
	inFile >> text;
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
					return;
				}
				stack.pop_back();
			}
			else
			{
				cout << "NO\n";
				return;
			}
		}
	}
	cout << (!stack.size() ? "YES\n" : "NO\n");

}