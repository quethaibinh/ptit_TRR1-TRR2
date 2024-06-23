#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[105][105];
int d[105][205];
int e[105][105];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
}

void floyd(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            d[i][j] = a[i][j];
            e[i][j] = i;
        }
    }
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    e[i][j] = k;
                }
            }
        }
    }
    cout << "   ";
    for(int i = 1; i <= n; i ++) cout << i << "    ";
    cout << '\n';
    for(int i = 1; i <= n; i ++){
        cout << i << ' ';
        for(int j = 1; j <= n; j ++) cout << d[i][j] << '|' << e[i][j] << "  ";
        cout << '\n';
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    floyd();

    return 0;
}

// 6
// 0 15 5 20 1000 1000
// 1 0 1000 17 10 1000
// 1000 1000 0 2 1000 50
// 15 1 1000 0 1000 70
// 20 30 1000 10 0 10
// 1000 18 1000 23 20 0

// 4
// 0 4 3 1000
// 1000 0 2 1000
// 1000 1000 0 2
// 1 1000 1000 0