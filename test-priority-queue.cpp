#include <iostream>
#include <string>
#include <queue>
#include <vector>



using namespace std;

struct Task
{
    int priority;
    string name;
};

struct Cmp {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority) return a.priority > b.priority; 
        return a.name < b.name; //
    }
};

int main()
{
 priority_queue<Task, vector<Task>, Cmp> q;
    q.push({3,"low"}); q.push({10,"high"}); q.push({7,"mid"});
    q.pop();
    
    cout << q.top().name;
    return 0;
}
