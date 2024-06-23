#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[105][105];
int vis[105];

void input(){
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
}

void DFS(int u){
    vis[u] = 1;
    for(int i = 1; i <= n; i ++){
        if(!vis[i] && a[u][i]) DFS(i);
    }
}

bool checkLtManh(){
    for(int i = 1; i <= n; i ++){
        memset(vis, 0, sizeof(vis));
        DFS(i);
        for(int i = 1; i <= n; i ++)
            if(!vis[i]) return false;
    }
    return true;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    if(checkLtManh) cout << "do thi lien thong manh\n";
    else{
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                if(a[i][j]) a[j][i] = 1;
        memset(vis, 0, sizeof(vis));
        DFS(1);
        bool check = true;
        for(int i = 1; i <= n; i ++){
            if(!vis[i]){
                check = false;
                break;
            }
        }
        if(check) cout << "do thi lien thong yeu\n";
        else cout << "do thi khong lien thong\n";
    }

    return 0;
}