#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[105][105];
int vis[105][105];
int lt[105];
vector<int> tplt[105];

void input(){
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
}

void DFS(int u, int v){
    for(int i = 1; i <= n; i ++){
        if(!vis[u][i] && a[v][i]){
            vis[u][i] = 1;
            DFS(u, i);
        }
    }
}

void dem_tplt_manh(){
    memset(lt, 0, sizeof(lt));
    int k = 1;
    for(int j = 1; j <= n; j ++)
        DFS(j, j);
    for(int j = 1; j <= n; j ++){
        bool check = false;
        for(int j1 = 1; j1 <= n; j1 ++){
            if(lt[j1] == 0 && vis[j][j1] && vis[j1][j]){
                lt[j1] = k;
                tplt[k].push_back(j1);
                check = true;
            }
        }
        if(check) k ++;
    }
    cout << "so thanh phan lien thong manh la: " << k - 1 << '\n';
    for(int i = 1; i < k; i ++){
        cout << "tplt thu " << i << " la: ";
        for(int j : tplt[i]) cout << j << ' ';
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
    dem_tplt_manh();

    return 0;
}