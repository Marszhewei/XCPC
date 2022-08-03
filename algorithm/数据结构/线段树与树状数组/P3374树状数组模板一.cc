#include <bits/stdc++.h>
using namespace std;
int n,m,tree[2000010];
void add(int x,int k) {
    while(x<=n) {
        tree[x] += k;
        x += (x & -x);
    }
}
int sum(int x) {
    int ans=0;
    while(x!=0) {
        ans += tree[x];
        x -= (x & -x);
    }
    return ans;
}
int main(void) {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    for(int i=1;i<=m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
            add(b,c);
        if(a==2)
            cout<<sum(c)-sum(b-1)<<endl;
    }
    return 0;
}