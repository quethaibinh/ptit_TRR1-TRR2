#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[105][105];
int vis[105];
stack<int> st;
vector<int> CE;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
}

int checkLt_vohuong(){
    int deg[105];
    memset(deg, 0, sizeof(deg));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            deg[i] += a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(deg[i] % 2 != 0) cnt ++;
    }
    if(cnt = 0) return 1; // co do thi euler
    else if(cnt <= 2) return 2; // co duong di euler
    else return 0; // khong ton tai duong di euler
}

int checkLt_cohuong(){
    int degc[105], degt[105];
    memset(degc, 0, sizeof(degc));
    memset(degt, 0, sizeof(degt));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            degc[i] += a[i][j];
            degt[j] += a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(abs(degc - degt) == 1) cnt ++;
        else if(abs(degc - degt) > 1) return 0;
    }
    if(cnt == 0) return 1;
    else if(cnt == 2) return 2;
    else return 0;
}

void euler_vohuong(int u){
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        bool check = false;
        for(int i = 1; i <= n; i ++){
            if(a[v][i] != 0){
                a[v][i] --;
                a[i][v] --;
                st.push(i);
                check = true;
                break;
            }
        }
        if(!check){
            st.pop();
            CE.push_back(v);
        }
    }
    cout << "duong di euler cua do thi la: \n";
    for(int i = CE.size() - 1; i >= 0; i --) cout << CE[i] << ' ';
    cout << '\n';
}

void euler_cohuong(int u){
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        bool check = false;
        for(int i = 1; i <= n; i ++){
            if(a[v][i] != 0){
                a[v][i] --;
                st.push(i);
                check = true;
                break;
            }
        }
        if(!check){
            st.pop();
            CE.push_back(v);
        }
    }
    cout << "duong di euler cua do thi la: \n";
    for(int i = CE.size() - 1; i >= 0; i --) cout << CE[i] << ' ';
    cout << '\n';
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
    euler_vohuong(u);

    return 0;
}