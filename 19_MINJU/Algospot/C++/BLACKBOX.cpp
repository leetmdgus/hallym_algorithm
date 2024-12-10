#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstdint>
using namespace std;

int init(int start, int end, int node, vector<int>& vec,vector<int>& tree){
    if(start == end) return tree[node] = vec[start];
    int mid = (start + end)/2;
    return tree[node] = init(start, mid, node*2, vec, tree) + init(mid+1,end,node*2+1, vec, tree);
}

int sum(int start, int end, int node, int left, int right,vector<int>& tree){
    if(left > end || right < start) return 0;

    if(left <= start && end <= right) return tree[node];

    int mid = (start + end)/2;
    return sum(start, mid, node*2, left, right, tree) + sum(mid+1, end, node*2+1, left, right, tree);
}

void update(int start, int end, int node, int index, int dif, vector<int>& tree){
    if(index < start || index > end) return;

    tree[node] += dif;

    if(start == end) return;
    int mid = (start + end)/2;
    update(start, mid, node*2, index, dif, tree);
    update(mid+1, end, node*2+1, index, dif, tree);
}

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    vector<int> real_vec(n,0);
    vector<int> count(n, 0);
    for(int i=0;i<n;i++) {
        int tempt;
        cin >> tempt;
        vec.push_back(tempt);
    }
    int Pear = vec.size()-1;
    int coconut = vec[Pear]%Pear;
    int tempt = vec[coconut];
    vec[coconut] = vec[0];
    vec[0] = tempt;
    vector<int> tree(4*vec.size(), 0);
    count[0] += 1;
    init(0, n-1, 1, count, tree);
    real_vec[0] = vec[0];
    int Papaya = vec.size();
    int Mango = 0;
    for(int i=1;i<real_vec.size();i++){
        Papaya--;
        int Kiwi = vec[i-1];
        Mango = (Mango+Kiwi-1)%Papaya;
        int update_idx = Mango+sum(0,n-1,1,0,Mango, tree);
        while(update_idx != Mango+sum(0,n-1,1,0,update_idx,tree)) update_idx = Mango+sum(0,n-1,1,0,update_idx,tree); 
        real_vec[update_idx] = vec[i];
        // cout << Mango<< " " << update_idx << endl;
        update(0, n-1, 1, update_idx, 1, tree);
    }
    for(int k : real_vec) printf("%d\n", k);
}