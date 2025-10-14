#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;
// this is for priority queue
struct Task
{
    int priority;
    string name;
    int dep;
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

int h2(string start, string goal)
{
    int h = 0;
    for(int i = 0; i <= 8; i++){
      if (start[i] == '0')
        {
            continue;
        }

      int index  = i;
      int row = index / 3;
      int col = index % 3;
      /////////////////
      int index2  = searchindex(goal,start[i]);
      int row2 = index2 / 3;
      int col2 = index2 % 3;
      if(row != row2){
        h++;
      }
      if(col != col2){
        h++;
      }
   
    }
    return h;
    
}

int searchindex(string s,char find)
{
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == find)
            return i;
    }
    return -1;
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
    unordered_set<string> checkfrontire_exp; // ignore fronitrer and explored;
    int h = h1(start, goal);
    frontire.push({h, start});
    checkfrontire_exp.insert(start);
    while (true)
    {
        if (frontire.empty())
        {
            cout << "Goal not found!\n";
            return;
        }

        string expanded = frontire.top().name;
        frontire.pop();
        if (expanded == goal)
        {
            cout << "founded";
            break;
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

        while (!actions.empty())
        {
            string newbuzz = swapstr(expanded, index, actions.front().val);
            string mv = actions.front().path;
            actions.pop();
            if (checkfrontire_exp.find(newbuzz) != checkfrontire_exp.end())
            {
                continue;
            }
            int h = h1(newbuzz, goal);
            frontire.push({h, newbuzz});
            checkfrontire_exp.insert(newbuzz);
        }
    }
}

void a_star(string start, string goal)
{
    priority_queue<Task, vector<Task>, Cmp> frontire;
    unordered_set<string> checkfrontire_exp; // ignore fronitrer and explored;
    int h = h1(start, goal);
    frontire.push({h, start, 0});
    checkfrontire_exp.insert(start);
    while (true)
    {
        if (frontire.empty())
        {
            cout << "Goal not found!\n";
            return;
        }

        string expanded = frontire.top().name;
        int dep = frontire.top().dep;
        frontire.pop();
        if (expanded == goal)
        {
            cout << "founded";
            break;
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

        while (!actions.empty())
        {
            string newbuzz = swapstr(expanded, index, actions.front().val);
            string mv = actions.front().path;
            actions.pop();
            if (checkfrontire_exp.find(newbuzz) != checkfrontire_exp.end())
            {
                continue;
            }
            int h = h1(newbuzz, goal);
            frontire.push({h + dep + 1, newbuzz, dep + 1});
            checkfrontire_exp.insert(newbuzz);
        }
    }
}
int main()
{

    return 0;
}
