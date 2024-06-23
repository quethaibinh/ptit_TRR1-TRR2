#include<bits/stdc++.h>

using namespace std;

int a[100], cnt, n, ok;

// vector<vector<int>> v;

void khoi_tao(){
    cnt = 1;
    a[1] = n;
}

void sinh(){
    int i = cnt;
    while(i >= 1 && a[i] == 1){
        -- i;
    }
    if(i == 0){
        ok = 0;
    }
    else{
        a[i] --;
        int d = cnt - i + 1; // so luong cac so 1
        cnt = i; // so luong mang tam thoi
        int q = d / a[i];
        int r = d % a[i];
        // bieu dien nhung so 1 theo a[i];
        for(int j = 0; j < q; j ++){
            cnt ++;
            a[cnt] = a[i];
        }
        if(r != 0){
            cnt ++;
            a[cnt] = r;
        }
    }
}

int main(){
    
    cin >> n;
    ok = 1;
    khoi_tao();
    while(ok){
        for(int i = 1; i <= cnt; i ++){
            cout << a[i] << ' ';
        }
        cout << '\n';
        sinh();
    }

    return 0;
}