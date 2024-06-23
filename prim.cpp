#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[105][105];
int vis[105];
int d[105];
int e[105];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
}

void prim(int u){
    for(int i = 1; i <= n; i ++){
        d[i] = a[u][i];
        e[i] = u;
    }
    vis[u] = 1;
    d[u] = 0;
    e[u] = 0;
    int WT = 0;
    while(1){
        int v = 0;
        int min = INT_MAX;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && d[i] < min){
                min = d[i];
                v = i;
            }
        }
        if(v == 0) break;
        vis[v] = 1;
        WT += a[v][e[v]];
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && d[i] > a[v][i]){
                d[i] = a[v][i];
                e[i] = v;
            }
        }
    }
    cout << "trong so cua cay khung la: " << WT << '\n';
    cout << "cac canh tuong ung la: \n";
    for(int i = 1; i <= n; i ++){
        if(i != u) cout << e[i] << ' ' << i << '\n';
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
    int u; cin >> u;
    prim(u);

    return 0;
}

// 13
// 0 2 1 3 1000 1000 1000 1000 1000 1000 1000 1000 1000
// 2 0 2 1000 1000 5 5 1000 1000 1000 1000 1000 1000
// 1 2 0 4 1000 5 1000 1000 1000 1000 1000 1000 1000
// 3 1000 4 0 5 5 1000 1000 1000 1000 1000 1000 1000
// 1000 1000 1000 5 0 6 1000 1000 1000 6 1000 1000 1000
// 1000 5 5 5 6 0 6 6 6 6 1000 1000 1000
// 1000 5 1000 1000 1000 6 0 6 1000 1000 1000 1000 1000
// 1000 1000 1000 1000 1000 6 6 0 7 1000 1000 7 7 
// 1000 1000 1000 1000 1000 6 1000 7 0 7 7 1000 1000
// 1000 1000 1000 1000 6 6 1000 1000 7 0 7 7 1000
// 1000 1000 1000 1000 1000 1000 1000 1000 7 7 0 8 1000
// 1000 1000 1000 1000 1000 1000 1000 7 1000 7 8 0 8
// 1000 1000 1000 1000 1000 1000 1000 7 1000 1000 1000 8 0
// 1