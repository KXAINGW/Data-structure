// Write your implementation here.
// Feel free to add any code you need in this file.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int num, T, T_temp;
	cin >> num >> T;
	T_temp = T;
	vector<int> num_vec;
	while (num--)
	{
		int cin_num;
		cin >> cin_num;
		num_vec.push_back(cin_num);
	}
	sort(num_vec.begin(), num_vec.end());
	
	vector<int> subarray;
	for (int i = num_vec.size() - 1; i >= 0; --i)
	{
		subarray.push_back(num_vec[i]);
		T_temp -= num_vec[i];
		if (!T_temp)
		{
			cout << subarray.size() << endl;
			return 0;
		}
		else if (T_temp < 0)
		{
			T_temp += subarray.back();
			subarray.pop_back();
			continue;
		}
		for (int j = i - 1; j >= 0; --j)
		{
			subarray.push_back(num_vec[j]);
			T_temp -= num_vec[j];
			if (!T_temp)
			{
				cout << subarray.size() << endl;
				return 0;
			}
			else if (T_temp < 0)
			{
				T_temp += subarray.back();
				subarray.pop_back();
				continue;
			}
			for (int k = j - 1; k >= 0; --k)
			{
				subarray.push_back(num_vec[k]);
				T_temp -= num_vec[k];
				if (!T_temp)
				{
					cout << subarray.size() << endl;
					return 0;
				}
				else if (T_temp < 0)
				{
					T_temp += subarray.back();
					subarray.pop_back();
					continue;
				}
			}
			subarray.resize(0);
			T_temp = T - num_vec[i];
			subarray.push_back(num_vec[i]);
		}
		subarray.resize(0);
		T_temp = T;
	}
	
	for (int i = num_vec.size() - 1; i >= 0; --i)
	{
		T -= num_vec[i];
		subarray.push_back(num_vec[i]);
		if (T <= 0)
			break;
	}
	cout << subarray.size() << endl;


}