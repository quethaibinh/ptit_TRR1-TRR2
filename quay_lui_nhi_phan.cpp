#include<bits/stdc++.h>

using namespace std;

int a[100], n;

void in(){
    for(int i = 1; i <= n; i ++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void try1(int i){
    for(int j = 0; j <= 1; j ++){
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
    
    cin >> n;
    try1(1);

    return 0;
}