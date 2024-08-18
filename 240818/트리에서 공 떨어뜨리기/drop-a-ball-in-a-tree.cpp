#define MAX 200000
#define MOD 13

#include<iostream>

using namespace std;

struct Node{
    int left;
    int right;
    Node(){};
    Node(int l, int r): left(l), right(r){};
};

long long N, K;
Node narr[MAX+1];

int SearchTree(int idx){
    Node* node = &narr[idx];

    if(node->left == -1 && node->right == -1){
        return idx;
    }
    else if(node->left == -1){
        return SearchTree(node->right);
    }
    else if(node->right == -1){
        return SearchTree(node->left);
    }
    else {
        if(K%2){
            K = (K+1) / 2;
            return SearchTree(node->left);
        }
        else{
            K/= 2;
            return SearchTree(node->right);
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
    }
    cin >> K;
    cout << SearchTree(1);
    return 0;
}