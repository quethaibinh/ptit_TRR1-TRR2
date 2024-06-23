#include<bits/stdc++.h>

using namespace std;

int a[100], k, n;

void in(){
    for(int i = 1; i <= k; i ++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void try1(int i){
    for(int j = a[i - 1] + 1; j <= n - k + i; j ++){
        a[i] = j;
        if(i == n){
            in();
        }
        else{
            try1(i + 1);
        }
    }
}

int main(){

    cin >> n >> k;
    try1(1);

    return 0;
}