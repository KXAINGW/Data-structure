// Write your implementation here.
// Feel free to add any code you need in this file.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void BinaryInsert(vector<int>&, int);
int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<int>num_vec(N);
	for (size_t i = 0; i < N; ++i)
		cin >> num_vec[i];
	sort(num_vec.begin(), num_vec.end());

	while (Q--)
	{
		char operation;
		int X_K;
		cin >> operation >> X_K;
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
