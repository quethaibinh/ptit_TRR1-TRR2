#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[105][105];
struct canh{
    int u, v, w;
};
vector<canh> ds;
vector<canh> kq;
int par[105];

void input(){
    cin >> n; 
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
}

bool cmp(canh a, canh b){
    if(a.w == b.w){
        if(a.u == b.u) return a.v < b.v;
        return a.u < b.u;
    }
    return a.w < b.w;
}

void init(){
    for(int i = 1; i <= n; i ++) par[i] = i;
}

int find(int u){
    while(u != par[u]) u = par[u];
    return u;
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    par[u] = v;
    return true;
}

void Kruskal(){
    canh x;
    init();
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            x.u = i; x.v = j; x.w = a[i][j];
            ds.push_back(x);
        }
    }
    sort(ds.begin(), ds.end(), cmp);
    int dem = 1;
    for(auto xc : ds){
        if(Union(xc.u, xc.v)){
            kq.push_back(xc);
            dem ++;
        }
        if(dem == n) break;
    }
    for(auto xc : kq) cout << xc.u << ' ' << xc.v << " : " << xc.w << '\n';
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    Kruskal();

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