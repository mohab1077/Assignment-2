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
    int searchindex(string s, char find)
    {
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] == find)
                return i;
        }
        return -1;
    }
    int h2(string start, string goal)
    {
        int h = 0;
        for (int i = 0; i <= 8; i++)
        {
            if (start[i] == '0')
            {
                continue;
            }

            int index = i;
            int row = index / 3;
            int col = index % 3;
            /////////////////
            int index2 = searchindex(goal, start[i]);
            int row2 = index2 / 3;
            int col2 = index2 % 3;
            if (row != row2)
            {
                h++;
            }
            if (col != col2)
            {
                h++;
            }
        }
        return h;
    }

    string move_up(string expanded, int idx)
    {
        swap(expanded[idx], expanded[idx + 3]);
    }
    string move_down(string expanded, int idx)
    {
        swap(expanded[idx], expanded[idx - 3]);
    }
    string move_left(string expanded, int idx)
    {
        swap(expanded[idx], expanded[idx + 1]);
    }
    string move_right(string expanded, int idx)
    {
        swap(expanded[idx], expanded[idx - 1]);
    }

    queue<string> expand_node(string expanded)
    {
        queue<string> actions;
        int index = searchzero(expanded);
        int row = index / 3;
        int col = index % 3;

        if (row > 0)
            actions.push({"down"});
        if (row < 2)
            actions.push({"up"});
        if (col > 0)
            actions.push({"right"});
        if (col < 2)
            actions.push({"left"});
        return actions;
    }

    void printing_result(string start, string goal, int nodes_frontire, int nodes_exp)
    {
        vector<string> path;
        vector<string> buzz;
        string cur = goal;
        while (cur != start)
        {
            path.push_back(movee[cur]);
            buzz.push_back(cur);
            cur = parent[cur];
        }
        buzz.push_back(start);
        reverse(path.begin(), path.end());
        reverse(buzz.begin(), buzz.end());

        cout << "States: " << endl;
        for (auto &st : buzz)
        {
            for (int i = 0; i < 9; i++)
            {
                cout << st[i] << " ";
                if ((i + 1) % 3 == 0)
                    cout << endl;
            }
            cout << "------" << endl;
        }

        cout << "Path: ";
        for (auto &m : path)
            cout << m << " ";
        cout << endl;

        cout << "Steps (Cost): " << path.size() << endl;
        cout << "Number of Nodes Entering the Frontier : " << nodes_frontire << endl;
        cout << "Number of Nodes Expanded from the Frontier : " << nodes_exp << endl;
        return;
    }

    void greddy_search(string start, string goal, int main_h)
    {
        priority_queue<Task, vector<Task>, Cmp> frontire;
        unordered_set<string> checkfrontire_exp; // ignore fronitrer and explored;
        int nodes_frontire = 0;
        int nodes_exp = 0;
        int h;
        if (main_h == 1)
        {
            h = h1(start, goal);
        }
        if (main_h == 2)
        {
            h = h2(start, goal);
        }
        frontire.push({h, start});
        nodes_frontire++;
        checkfrontire_exp.insert(start);
        parent[start] = "";
        movee[start] = "";
        while (true)
        {
            if (frontire.empty())
            {
                cout << "Goal not found!\n";
                return;
            }

            string expanded = frontire.top().name;
            nodes_exp++;
            frontire.pop();
            if (expanded == goal)
            {
                printing_result(start, goal, nodes_frontire, nodes_exp);
                break;
                /// will complete later;
            }

            int index = searchzero(expanded);
            queue<string> actions = expand_node(expanded);

            while (!actions.empty())
            {
                string newbuzz;
                if (actions.front() == "down")
                {
                    newbuzz = move_down(expanded, index);
                }
                else if (actions.front() == "up")
                {
                    newbuzz = move_up(expanded, index);
                }
                else if (actions.front() == "right")
                {
                    newbuzz = move_right(expanded, index);
                }
                else
                {
                    newbuzz = move_left(expanded, index);
                }
                string mv = actions.front();
                actions.pop();
                if (checkfrontire_exp.find(newbuzz) != checkfrontire_exp.end())
                {
                    continue;
                }
                parent[newbuzz] = expanded;
                movee[newbuzz] = mv;
                int h;
                if (main_h == 1)
                {
                    h = h1(newbuzz, goal);
                }
                if (main_h == 2)
                {
                    h = h2(newbuzz, goal);
                }
                frontire.push({h, newbuzz});
                nodes_frontire++;
                checkfrontire_exp.insert(newbuzz);
            }
        }
    }

    void a_star(string start, string goal, int main_h)
    {
        priority_queue<Task, vector<Task>, Cmp> frontire;
        unordered_set<string> checkfrontire_exp; // ignore fronitrer and explored;
        int nodes_frontire = 0;
        int nodes_exp = 0;
        int h;
        if (main_h == 1)
        {
            h = h1(start, goal);
        }
        if (main_h == 2)
        {
            h = h2(start, goal);
        }
        frontire.push({h, start, 0});
        nodes_frontire++;
        checkfrontire_exp.insert(start);
        parent[start] = "";
        movee[start] = "";
        while (true)
        {
            if (frontire.empty())
            {
                cout << "Goal not found!\n";
                return;
            }

            string expanded = frontire.top().name;
            nodes_exp++;
            int dep = frontire.top().dep;
            frontire.pop();
            if (expanded == goal)
            {
                printing_result(start, goal, nodes_frontire, nodes_exp);
                break;
            }
            int index = searchzero(expanded);
            queue<string> actions = expand_node(expanded);

            while (!actions.empty())
            {
                string newbuzz;
                if (actions.front() == "down")
                {
                    newbuzz = move_down(expanded, index);
                }
                else if (actions.front() == "up")
                {
                    newbuzz = move_up(expanded, index);
                }
                else if (actions.front() == "right")
                {
                    newbuzz = move_right(expanded, index);
                }
                else
                {
                    newbuzz = move_left(expanded, index);
                }
                string mv = actions.front();
                actions.pop();
                if (checkfrontire_exp.find(newbuzz) != checkfrontire_exp.end())
                {
                    continue;
                }
                parent[newbuzz] = expanded;
                movee[newbuzz] = mv;
                int h;
                if (main_h == 1)
                {
                    h = h1(newbuzz, goal);
                }
                if (main_h == 2)
                {
                    h = h2(newbuzz, goal);
                }
                frontire.push({h + dep + 1, newbuzz, dep + 1});
                nodes_frontire++;
                checkfrontire_exp.insert(newbuzz);
            }
        }
    }
};

int main()
{

    return 0;
}