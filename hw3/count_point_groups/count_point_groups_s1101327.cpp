#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

using namespace std;

void Primary_code(ifstream& inFile, ofstream& outFile);
int main()
{
	string fileNum[] = {"00", "01","02","03","04","05","06","07","08","09",
						"10","11","12","13","14","15","16","17","18","19","20" };
	for (int i = 11; i <= 20; ++i)
	//for (int i = 1; i <= 20; ++i)
	{
		string path = "";
		//path += "C:/Users/ASUS/Desktop/yzu/大二下/資結/hw/hw3/count_point_groups/data/";

		string fileName = path + "count_point_groups." + fileNum[i] + ".in.txt";
		string fileName2 = path + "count_point_groups." + fileNum[i] + ".out.txt";
		
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
	vector < vector < pair< int, int > > >groups;
	int vertex = 0, distance = 0, x = 0, y = 0;

	inFile >> vertex >> distance;
	inFile >> x >> y;
	vector<pair<int, int>>temp(1, { x, y });
	groups.emplace_back(temp);

	while (--vertex)
	{
		inFile >> x >> y;

		bool check = 0;
		int group = 0;
		for(int i = 0; i < groups.size(); i++)
		{
			for (int j = 0; j < groups[i].size(); j++)
			{
				int aX = groups[i][j].first, aY = groups[i][j].second;
				if (abs(aX - x) + abs(aY - y) <= distance && !check)
				{
					check = 1;
					group = i;
					groups[i].push_back({ x, y });
					break;
				}
				else if (abs(aX - x) + abs(aY - y) <= distance && check)
				{
					for(int k = 0; k < groups[i].size(); k++)
					{
						int bX = groups[i][k].first, bY = groups[i][k].second;
						groups[group].emplace_back(bX, bY);
					}
					auto it = groups.begin() + i;
					if (it != groups.end() - 1)
						groups.erase(it);
					else if (it == groups.end() - 1)
					{
						groups.pop_back();
						break;
					}
				}
			}

		}
		if (!check)
			groups.emplace_back(vector<pair<int, int>>(1, { x, y }));
	}
	outFile << groups.size() << endl;
}