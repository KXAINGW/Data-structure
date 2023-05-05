#include "list.hpp"

// Write your implementation here.
// Feel free to add any code you need in this file.
int count_list_groups(int n, std::vector<ListNode *> &lists)
{
	for (ListNode* ptr : lists)
		if (ptr->next)
			n--;
	return n;
}
