#include<bits/stdc++.h>

using namespace std;

int a[100], used[100], n;

void in(){
    for(int i = 1; i <= n; i ++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void try1(int i){
    for(int j = 1; j <= n; j ++){
        if(!used[j]){
            a[i] = j;
            used[j] = 1;
            if(i == n) in();
            else try1(i + 1);
            used[j] = 0;
        }
    }
}

int main(){

    memset(used, 0, sizeof(used));
    cin >> n;
    try1(1);

    return 0;
}