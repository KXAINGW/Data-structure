#include "list.hpp"
#include<vector>
// Write your implementation here.
// Feel free to add any code you need in this file.
int count_list_groups(int n, std::vector<ListNode *> &lists)
{
	/*std::vector<int>link_count(n, 1);*/
	for (ListNode* ptr : lists)
		if (ptr->next)
			/*link_count[ptr->id]--;*/
			n--;
	return n;
	//int sum = 0;
	//for (int num : link_count)
	//	sum += num;
	//return sum;
}
