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
struct path
{
    int val;
    string path;
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

int searchzero(string s)
{
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == '0')
            return i;
    }
    return -1;
}
string swapstr(string a, int idx, int action)
{
    swap(a[idx], a[action]);
    return a;
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
        queue<path> actions;

        int index = searchzero(expanded);
        int row = index / 3;
        int col = index % 3;

        if (row > 0)
            actions.push({index - 3, "down"});
        if (row < 2)
            actions.push({index + 3, "up"});
        if (col > 0)
            actions.push({index - 1, "right"});
        if (col < 2)
            actions.push({index + 1, "left"});

        while (!actions.empty()){
            string newbuzz = swapstr(expanded, index, actions.front().val);
            string mv = actions.front().path;
            actions.pop();
        }




    }


}

int main()
{

    return 0;
}
