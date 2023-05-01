// Write your implementation here.
// Feel free to add any code you need in this file.

#include<iostream>
#include<vector>
using namespace std;

void judge(int& min, int count)
{
	min = min > count ? count : min;
}
int main()
{
	int n, T;
	cin >> n >> T;
	int* num_array = new int[n]();
	for (size_t i = 0; i < n; ++i)
		cin >> num_array[i];

	int min = n, count = 0;
	int T_temp = T;
	for(size_t i =0;i<n;++i)
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
	cout << min << endl;
	return 0;

}