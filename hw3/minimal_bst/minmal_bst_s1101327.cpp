#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void Primary_code(ifstream& inFile, ofstream& outFile);
int calculateSum(int start, int end, const vector<int>& num);
int main()
{
    string fileNum[] = { "00", "01","02","03","04","05","06","07","08","09",
                    "10","11","12","13","14","15","16","17","18","19","20" };
    for (int i = 11; i <= 20; ++i)
        //for (int i = 1; i <= 20; ++i)
    {
        string path = "";
        //path += "C:/Users/ASUS/Desktop/yzu/大二下/資結/hw/hw3/minimal_bst/data/";

        string fileName = path + "minimal_bst." + fileNum[i] + ".in.txt";
        string fileName2 = path + "minimal_bst." + fileNum[i] + ".out.txt";

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
    int size = 0;
    vector<int> num;
    int miniProduct;
    inFile >> size;

    for (int i = 0; i < size; i++) 
    {
        int temp;
        inFile >> temp;
        num.push_back(temp);
    }

    size_t n = num.size();
    if (n == 0) 
    {
        miniProduct = 0;
        return;
    };
    sort(num.begin(), num.end());

    vector<vector<int>> ac(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) 
        ac[i][i] = num[i];
    
    for (int diag = 1; diag < n; diag++) 
    {
        for (int i = 0; i < n - diag; i++) 
        {
            int j = i + diag;
            ac[i][j] = numeric_limits<int>::max();
            for (int k = i; k <= j; k++) {
                int sum = calculateSum(i, j, num);
                int product = sum + (k > i ? ac[i][k - 1] : 0) + (k < j ? ac[k + 1][j] : 0);
                ac[i][j] = min(ac[i][j], product);
            }
        }
    }
    miniProduct = ac[0][n - 1];
    outFile << miniProduct << endl;
}

int calculateSum(int start, int end, const vector<int>& num)
{
    int sum = 0;
    for (int r = start; r <= end; r++) 
        sum = sum + num[r];
    
    return sum;
}