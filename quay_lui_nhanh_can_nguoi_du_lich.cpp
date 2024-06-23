#include<bits/stdc++.h>

using namespace std;

int n, x[100], used[100], c[100][100], chiphi = 0, cmin = INT_MAX, chiphi_min = INT_MAX;

void nhap(){
    cin >> n;
    memset(used, 0, sizeof(used));
    x[1] = 1;
    used[1] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> c[i][j];
            if(c[i][j] != 0){
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}

void try1(int i){
    for(int j = 1; j <= n; j ++){
        if(used[j] == 0){
            x[i] = j;
            used[j] = 1;
            chiphi += c[x[i - 1]][x[i]];
            if(i == n){
                chiphi_min = min(chiphi_min, chiphi + c[x[n]][x[1]]);
            }
            else if(chiphi + (n - i + 1) * cmin < chiphi_min){
                try1(i + 1);
            }
            used[j] = 0;
            chiphi -= c[x[i - 1]][x[i]];
        }
    }
}

int main(){

    nhap();
    try1(2);
    cout << chiphi_min << '\n';

    return 0;
}