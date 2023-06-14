#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

void Primary_code(ifstream& inFile, ofstream& outFile);
void Product(int* beg, int* end, long long int& p);
int main()
{
	string fileNum[] = { "00", "01","02","03","04","05","06","07","08","09",
					"10","11","12","13","14","15","16","17","18","19","20" };
	for (int i = 11; i <= 20; ++i)
		//for (int i = 1; i <= 20; ++i)
	{
		string path = "";
		//path += "C:/Users/ASUS/Desktop/yzu/大二下/資結/hw/hw3/array_product/data/";

		string fileName = path + "array_product." + fileNum[i] + ".in.txt";
		string fileName2 = path + "array_product." + fileNum[i] + ".out.txt";

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
	int num;
	inFile >> num;
	int* arr = new int[num + 1];
	int* arr_done = new int[num / 2 + 1];
	int num_done = 0;
	for (size_t i = 0; i < num; ++i)
		inFile >> arr[i];

	long long int p = 1;
	
	for (size_t i = 0; i < num; ++i)
	{
		if (count(arr_done, arr_done + num_done, arr[i]))
			continue;
		arr_done[num_done++] = arr[i];
		Product(find(arr + i, arr + num, arr[i]), find(arr + i + 1, arr + num, arr[i]), p);
	}

	delete[] arr;
	delete[] arr_done;
	outFile << p << endl;

}

void Product(int* beg, int* end, long long int& p)
{
	int x = *(beg++);
	for (; beg != end; ++beg)
		if (x > *beg)
		{
			p *= *beg;
			p = p > 1000000007 ? p % 1000000007 : p;
		}

}