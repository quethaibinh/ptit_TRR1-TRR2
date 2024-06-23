#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, a[105][105];
int d[105];
int vis[105];
int e[105];
vector<vector<int>> duongdi;
bool check;

void input(){
    cin >> n;
    check = false;
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
}

void hamintol(int k){
    for(int i = 1; i <= n; i ++){
        if(k == n + 1){
            if(a[e[k - 1]][i] && i == e[1]){
                check = true;
                for(int j = 1; j <= n; j ++) cout << e[j] << ' ';
                cout << i << '\n';
            }
        }
        else{
            if(a[e[k - 1]][i] && !vis[i]){
                vis[i] = 1;
                e[k] = i;
                hamintol(k + 1);
                vis[i] = 0;
            }
        }
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
    e[1] = u;
    vis[u] = 1;
    cout << "cac chu trinh hamintol la: \n";
    hamintol(2); 
    if(!check) cout << "do ti khong ton tai chu trinh hamintol!\n";

    return 0;
}