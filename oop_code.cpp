#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, string> parent;
unordered_map<string, string> movee;
// this is for priority queue
struct Task
{
    int priority;
    string name;
    int dep; /// this is option (only used on a*)
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

class TilePuzzle
{

private:
    string start;
    string goal;

public:
    TilePuzzle(string start, string goal)
    {
        start = start;
        goal = goal;
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

    string move_up(string a)
    {
    }
    string move_down(string a)
    {
    }
    string move_left(string a)
    {
    }
    string move_right(string a)
    {
    }

    queue<path> expand_node(string expanded)
    {
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
        return actions;
    }

    void greddy_search(string start, string goal, int main_h)
    {
    }

    void a_star(string start, string goal, int main_h)
    {
    }
};

int main()
{

    return 0;
}