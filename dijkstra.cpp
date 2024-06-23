#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, a[105][105];
int d[105];
int vis[105];
int e[105];
vector<vector<int>> duongdi;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
}

void dijkstra(int u){
    duongdi.push_back({});
    for(int i = 1; i <= n; i ++){
        e[i] = u;
        d[i] = a[u][i];
    }
    d[u] = 0; e[u] = 0; vis[u] = 1;
    while(1){
        int minn = INT_MAX;
        int v = 0;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && d[i] < minn){
                minn = d[i];
                v = i;
            }
        }
        if(v == 0) break;
        vis[v] = 1;
        for(int i = 1; i <= n; i ++){
            if(d[i] > d[v] + a[v][i]){
                d[i] = d[v] + a[v][i];
                e[i] = v;
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        if(i != u){
            vector<int> check;
            check.push_back(i);
            int x = e[i];
            while(x != 0){
                check.push_back(x);
                x = e[x];
            }
            duongdi.push_back(check);
        }
        else duongdi.push_back({});
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
    int u;
    cin >> u;
    dijkstra(u);
    for(int i = 1; i <= n; i ++){
        if(i != u){
            cout << "duong di tu " << u << " toi " << i << " la: ";
            for(int j : duongdi[i]) cout << j << "<-";
            cout << " trong so la: " << d[i]; 
            cout << '\n';
        }
    }

    return 0;
}

// 7
// 0 20 5 17 1000 1000 1000
// 10 0 1000 1 1000 1000 1
// 5 1000 0 25 3 10 1000
// 17 1 25 0 15 1000 1000
// 1000 1000 3 15 0 1 1000
// 1000 1000 10 1000 1 0 1
// 1000 1 1000 1000 1000 1 0
// 1

// 7
// 0 10 15 20 1000 1 1000
// 1000 0 3 1000 1000 1000 30
// 1000 1000 0 25 3 1000 45
// 1000 10 25 0 35 1000 1000
// 1000 2 3 1000 0 1000 3
// 1000 1000 1 1 1000 0 25
// 1000 1 1000 30 1000 1 0
// 1

// 7
// 0 15 1000 1000 1000 1 9
// 1000 0 8 1000 1000 1000 1000
// 1000 1000 0 4 1 1000 1000
// 1000 7 1000 0 1000 1000 1
// 1000 10 1000 2 0 1000 1000
// 1000 14 2 1000 1000 0 1000
// 1000 2 1000 1000 1000 1000 0
// 1

// 7
// 0 25 1000 27 1000 30 1000
// 25 0 1000 1000 1 1000 15
// 1000 1000 0 15 3 1 1000
// 27 1000 15 0 25 1000 1000
// 1000 1 3 25 0 1000 1000
// 1000 1000 1 1000 1000 0 1
// 1000 15 1000 1000 1000 1 0
// 2

// 7
// 0 15 1000 1000 1000 1 9
// 1000 0 8 1000 1000 1000 1000
// 1000 1000 0 4 1 1000 1000
// 1000 7 1000 0 1000 1000 1
// 1000 10 1000 2 0 1000 1000
// 1000 14 2 1000 1000 0 1000
// 1000 2 1000 1000 1000 1000 0
// 6