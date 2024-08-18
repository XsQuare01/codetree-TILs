#define MAX 200000
#define MOD 13

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int left;
    int right;
    int cnt = 0;
    bool leaf_check = false;
    Node(){};
    Node(int l, int r): left(l), right(r){};
};

long long N, K;
int leaf_cnt = 0;
Node narr[MAX+1];
vector<int> varr;

int SearchTree(int idx){
    Node node = narr[idx];
    if(node.left == -1 && node.right == -1){
        if(!node.leaf_check){
            node.leaf_check = true;
            leaf_cnt--;
        }
        return idx;
    }
    else if(node.left == -1){
        return SearchTree(node.right);
    }
    else if(node.right == -1){
        return SearchTree(node.left);
    }
    else {
        int l_cnt = narr[node.left].cnt;
        int r_cnt = narr[node.right].cnt;

        if(l_cnt <= r_cnt){
            return SearchTree(node.left);
        }
        else{
            return SearchTree(node.right);
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        int l, r;
        cin >> l >> r;
        narr[i] = Node(l, r);
        if(l == -1 && r == -1){
            leaf_cnt++;
        }
    }
    cin >> K;

    for(int i = 0; i < MAX; i++){
        int arrival = SearchTree(1);
        varr.push_back(arrival);

        if(leaf_cnt == 0){
            break;
        }
    }

    long long len = varr.size();
    cout << varr[K % len];
    return 0;
}