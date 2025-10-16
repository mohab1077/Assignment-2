#include <iostream>
#include <string>
#include <queue>
#include <algorithm> // next_permutation

using namespace std;

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

int manhattan(const string start, const string goal) {
    
    int gr[9], gc[9];
    for (int d = 0; d <= 8; ++d) {
        size_t idx = goal.find(char('0' + d));
        gr[d] = int(idx) / 3;
        gc[d] = int(idx) % 3;
    }

    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        char ch = start[i];
        if (ch == '0') continue;           
        int r = i / 3, c = i % 3;           
        int d = ch - '0';                   
        sum += abs(r - gr[d]) + abs(c - gc[d]);  // |row| + |col|
    }
    return sum;
}

int main() {
    
    queue<string> all_states;
    string goal = "012345678";

    string s = "012345678";

    ////// all possible 9! of 8 8 puzlle
    do {
        all_states.push(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << "Total states generated and queued: " << all_states.size() << "\n";
    bool err = false;
    while(!all_states.empty()){
        int h_2 = h2(all_states.front(),goal);
        int manhan = manhattan(all_states.front(),goal);
        if(!(manhan>=h_2)){
            cout<<"  error h2 is bigger than manahnt"<<endl;
            err = true;
        }
        all_states.pop();
    }
    if(err){
      cout<<"thers h2 bigger than manahnt ";
    }
    else{
        cout<<"all good manahnt is greate or equal than h2 on all 9! ";
    }

    

    return 0;
}
