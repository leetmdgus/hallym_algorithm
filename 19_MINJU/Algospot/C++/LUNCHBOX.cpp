#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstdint>
#include <iomanip>
using namespace std;

struct Point{
    int x,y;

    bool operator<(const Point& other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int main(){
    int T;
    cin >> T;
    vector<int> ans(T, 0);
    for(int t=0;t<T;++t){
        int N;
        cin >> N;
        vector<int> micro_time;
        vector<int> eat_time;
        for(int i=0;i<N;i++){
            int tempt;
            cin >> tempt;
            micro_time.push_back(tempt);
        }
        for(int i=0;i<N;i++){
            int tempt;
            cin >> tempt;
            eat_time.push_back(tempt);
        }
        priority_queue<Point> heap;
        for(int i=0;i<N;i++){
            heap.push({eat_time[i],micro_time[i]});
        }
        int answer = 0;
        int time = 0;
        while(heap.size() > 0) {
            Point tmp = heap.top();
            heap.pop();
            time += tmp.y;
            answer = max(answer, time+tmp.x);
        }
        ans[t] = answer;
    }
    for(int tempt : ans) cout << tempt << endl;
}