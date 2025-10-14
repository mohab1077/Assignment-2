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
    return h;
}

void greddy_search(string start, string goal)
{
    priority_queue<Task, vector<Task>, Cmp> frontire;
    int h = h1(start,goal);
    frontire.push({h,start});
    while(true){
        if (frontire.empty())
        {
            cout << "Goal not found!\n";
            return;
        }

        string expanded = frontire.top().name;
        frontire.pop();
        if(expanded == goal){
            cout<<"founded";
            /// will complete later;
        }
        


    }


}

int main()
{

    return 0;
}
