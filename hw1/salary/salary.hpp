#include <string>
#include <vector>
#include<algorithm>

class Employee
{
public:
    std::string name;
    int age;
    int salary;
    std::string department;
};

bool compare(std::pair<std::string, int> x, std::pair<std::string, int> y)
{
    return x.first > y.first;
}

std::vector<std::pair<std::string, int>>
calculate_average(const std::vector<Employee>& employees)
{
    std::vector<std::pair<std::string, int>> department_ave;
    std::vector<std::string> department;
    std::vector<int*>info;

    for (auto employee : employees)
    {
        if (std::find(department.begin(), department.end(), employee.department) == department.end())
        {
            int* frequency_sum = new int[2]();
            department.push_back(employee.department);
            info.push_back(frequency_sum);
        }
        size_t index = std::find(department.begin(), department.end(), employee.department) - department.begin();
        info[index][0] += 1;
        info[index][1] += employee.salary;
    }

    for (size_t i = 0; i < department.size(); ++i)
        department_ave.push_back(std::make_pair(department[i], info[i][1] / info[i][0]));

    sort(department_ave.begin(), department_ave.end(), compare);
    return department_ave;
}
