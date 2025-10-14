#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
// this is for priority queue
struct Task
{
    int priority;
    string name;
};

struct Cmp
{
    bool operator()(const Task &a, const Task &b) const
    {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.name < b.name; //
    }
};
// working on assigment

int h1(string start, string goal)
{
    int h = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (start[i] == '0')
        {
            continue;
        }
        if (start[i] != goal[i])
        {
            h++;
        }
    }
}

void greddy_search()
{
}

int main()
{

    return 0;
}
