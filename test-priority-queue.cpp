#include <iostream>
#include <string>
#include <queue>


using namespace std;

struct Task
{
    int priority;
    string name;
};

struct Cmp {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority) return a.priority < b.priority; 
        return a.name > b.name; //
    }
};

int main()
{
 std::priority_queue<Task, std::vector<Task>, Cmp> q;
    q.push({3,"low"}); q.push({10,"high"}); q.push({7,"mid"});

    return 0;
}
