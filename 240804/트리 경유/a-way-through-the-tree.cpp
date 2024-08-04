#define MAX 2000000
#include <iostream>
#include <stack>
using namespace std;

int N, Q;
stack<int> s;
int arr[MAX];

int main() {
    cin >> N >> Q;
    for(int i = 0; i < Q; i++){
        int t;
        cin >> t;
        s = stack<int>();
        s.push(t);
        while(t > 1){
            t /= 2;
            if(arr[t]){
                s.push(t);
            }
        }

        int u = s.top();
        if(arr[u]){
            cout << u << "\n";
        }
        else{
            arr[u] = 1;
            cout << 0 << "\n";
        }
    }
    return 0;
}