#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

void Primary_code(ifstream& inFile, ofstream& outFile);
int main()
{
	string fileNum[] = { "00", "01","02","03","04","05","06","07","08","09",
					"10","11","12","13","14","15","16","17","18","19","20" };
	for (int i = 11; i <= 20; ++i)
		//for (int i = 1; i <= 20; ++i)
	{
		string path = "";
		//path += "C:/Users/ASUS/Desktop/yzu/大二下/資結/hw/hw3/count_tuples/data/";

		string fileName = path + "count_tuples." + fileNum[i] + ".in.txt";
		string fileName2 = path + "count_tuples." + fileNum[i] + ".out.txt";

		ifstream inFile(fileName, ios::in);
		ofstream outFile(fileName2, ios::out);
		if (!inFile)
		{
			cerr << "File could not be opened!\n";
			exit(1);
		}

		Primary_code(inFile, outFile);

		inFile.close();
		outFile.close();
	}
}
void Primary_code(ifstream& inFile, ofstream& outFile)
{
	int num, d;
	inFile >> num >> d;
	int* arr = new int[num + 1];
	for (size_t i = 0; i < num; ++i)
		inFile >> arr[i];

	int count = 0;
	for (size_t i = 0; i < num - 2; ++i)
	{
		for (size_t j = i + 1; j < num - 1; ++j)
		{
			if (arr[i] > arr[j] || arr[j] - arr[i] > d)
				continue;
			for (size_t k = j + 1; k < num; ++k)
			{
				if (arr[j] > arr[k] || arr[k] - arr[j] > d)
					continue;
				++count;
			}
		}
	}
	delete[] arr;
	outFile << count << endl;

}