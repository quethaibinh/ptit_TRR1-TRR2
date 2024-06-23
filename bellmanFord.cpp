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
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
}

void bellmanFord(int u){
    duongdi.push_back({});
    for(int i = 1; i <= n; i ++){
        d[i] = a[u][i];
        e[i] = u;
    }
    d[u] = 0;
    e[u] = 0;
    for(int k = 1; k < n; k ++){ // lap n - 1 lan
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(d[j] > d[i] + a[i][j]){
                    d[j] = d[i] + a[i][j];
                    e[j] = i;
                }
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
    bellmanFord(u);
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

// 8
// 0 1000 1000 1000 1000 1000 2 1000
// 1000 0 4 1000 1000 1000 1000 1000
// 1000 1000 0 1000 1000 4 1000 5
// -2 1000 1000 0 1000 1000 1000 1000
// 1000 1000 1000 5 0 1000 3 1000
// 1000 2 1000 1000 1000 0 1000 -1
// 1000 3 1000 1000 1000 1000 0 1000
// 2 1000 1000 1000 1000 1000 4 0
// 1