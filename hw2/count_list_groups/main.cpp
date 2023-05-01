// Do not modify this file.
// All modification will be dropped.

#include <iostream>
#include <vector>
#include <algorithm>
#include "list.hpp"

int main()
{
    int n, m;
    std::cin >> n >> m;

    // generate n nodes
    std::vector<ListNode *> lists(n);
    for (size_t i = 0; i < n; i++)
    {
        lists[i] = new ListNode(i);
    }

    // read m edges
    for (size_t i = 0; i < m; i++)
    {
        int f, t;
        std::cin >> f >> t;
        lists[f]->next = lists[t];
    }

    int c = count_list_groups(n, lists);
    std::cout << c << '\n';

    return 0;
}
