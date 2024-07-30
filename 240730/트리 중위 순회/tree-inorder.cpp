#define MAX 1024

#include <iostream>
#include <vector>
using namespace std;

int N;
int height;
int arr[MAX];
vector<int> res[MAX];

void BST(int st, int ed, int h){
    
    int mid = (st + ed) / 2;
    res[h].push_back(arr[mid]);
    if(st != ed){
        BST(st, mid-1, h+1);
        BST(mid+1, ed, h+1);
    }
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    height = (1 << N) - 1;

    for(int i = 0; i < height; i++){
        cin >> arr[i];
    }
    BST(0, height-1, 0);

    for(int i = 0; i < N; i++){
        for(auto a: res[i]){
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}