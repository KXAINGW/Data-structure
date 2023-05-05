// Write your implementation here.
// Feel free to add any code you need in this file.
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void judge(int& min, int count)
{
	min = min > count ? count : min;
}
void Primary_code(ifstream&, ofstream&);
int main()
{
	for (size_t i = 0; i <= 9; ++i)
	{
		ifstream inFile(string(1, char(i + 48)) + ".in.txt");
		if (!inFile)
		{
			cout << "File could not be opened" << endl;
			exit(1);
		}
		ofstream outFile(string(1, char(i + 48)) + ".out2.txt");
		//cout << string(1, char(i + 48)) + ".in.txt" << endl;
		Primary_code(inFile, outFile);
		//cout << "--------------------------------------------------" << '\n';
		inFile.close();
	}
	return 0;
}
void Primary_code(ifstream& inFile, ofstream& outFile)
{
	int n, T;
	inFile >> n >> T;
	int* num_array = new int[n]();
	for (size_t i = 0; i < n; ++i)
		inFile >> num_array[i];

	int min = n, count = 0;
	int T_temp = T;
	for (size_t i = 0; i < n; ++i)
	{
		T_temp -= num_array[i];
		count++;
		if (T_temp <= 0)
		{
			judge(min, count);
			T_temp = T;
			count = 0;
			continue;
		}
		for (size_t j = i + 1; j < n; ++j)
		{
			T_temp -= num_array[j];
			count++;
			if (T_temp <= 0)
			{
				judge(min, count);
				break;
			}
		}
		T_temp = T;
		count = 0;
	}
	outFile << min << endl;

}