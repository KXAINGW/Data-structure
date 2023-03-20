#include <string>
#include <vector>
#include<map>
#include<algorithm>
class Team
{
public:
    std::string name;
    // Time to solve each problem, -1 means not solved
    std::vector<int> problems;
    int sum = 0;
};

bool compare(Team team1, Team team2)
{
    return team1.sum < team2.sum;
}
void rank_teams(std::vector<Team>& team)
{
    std::map<int, std::vector<Team>>unfinished;

    for (auto i : team)
    {
        int num = 0;
        for (int j : i.problems)
            j == -1 ? ++num : i.sum += j;
        
        unfinished[num].push_back(i);
    }

    for (auto &i : unfinished)
        std::sort(i.second.begin(), i.second.end(), compare);

    team.clear();
    for (auto i : unfinished)
        for (auto j : i.second)
            team.push_back(j);

}
