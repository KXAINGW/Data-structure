// Write your implementation here.
// Feel free to add any code you need in this file.
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>
#include<map>
using namespace std;
void Primary_code(ifstream& inFile);
void BinaryInsert(vector<int>&, int);
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
		cout <<"--------------------------------------------------" << '\n';
		inFile.close();
	}
}
void Primary_code(ifstream& inFile)
{
	int N, Q;
	inFile >> N >> Q;
	vector<int>num_vec(N);
	for (size_t i = 0; i < N; ++i)
		inFile >> num_vec[i];
	sort(num_vec.begin(), num_vec.end());

	while (Q--)
	{
		char operation;
		int X_K;
		inFile >> operation >> X_K;
		if (operation == 'i')
			BinaryInsert(num_vec, X_K);
		else if (operation == 'q')
			cout << num_vec[X_K - 1] << endl;
		else
		{
			cout << "Error!\n";
			exit(1);
		}
	}
}
void BinaryInsert(vector<int>& num_vec, int num)
{
	int first = 0, last = num_vec.size() - 1;
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (num_vec[mid] > num)
			last = mid - 1;
		else if (num_vec[mid] < num)
			first = mid + 1;
		else
		{
			num_vec.insert(num_vec.begin() + mid, num);
			return;
		}
	}
	num_vec.insert(num_vec.begin() + first, num);
}

