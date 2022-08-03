#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int MAXN = 1000010;
struct node {
    long long l, r, data;
    long long lt;    
}tree[MAXN<<2];
long long arr[MAXN], input[MAXN];
void build(long long l, long long r, long long index, long long arr[]) {
    tree[index].lt=0;
    tree[index].l=l;
    tree[index].r=r;
    if(l == r) {
        tree[index].data=arr[l];
        return ;
    }
    long long mid=(l+r)/2;
    build(l,mid,index*2,arr);
    build(mid+1,r,index*2+1,arr);
    tree[index].data=tree[index*2].data+tree[index*2+1].data;
    return ;
}
void push_down(long long index) {
    if(tree[index].lt != 0) {
        tree[index*2].lt+=tree[index].lt;
        tree[index*2+1].lt+=tree[index].lt;
        long long mid=(tree[index].l+tree[index].r)/2;
        tree[index*2].data+=tree[index].lt*(mid-tree[index*2].l+1);
        tree[index*2+1].data+=tree[index].lt*(tree[index*2+1].r-mid);
        tree[index].lt=0;
    }
    return ;
}
void update(long long index, long long l, long long r, long long k) {
    if(tree[index].r <= r && tree[index].l >= l) {
        tree[index].data += k*(tree[index].r-tree[index].l+1);
        tree[index].lt += k;
        return ;
    }
    push_down(index);
    if(tree[index*2].r>=l)
        update(index*2,l,r,k);
    if(tree[index*2+1].l<=r)
        update(index*2+1,l,r,k);
    tree[index].data=tree[index*2].data+tree[index*2+1].data;
    return ;
}
long long search(long long index, long long l, long long r) {
    if(tree[index].l >= l && tree[index].r <= r) return tree[index].data;
    push_down(index);
    long long num=0;
    if(tree[index*2].r >= l) num+=search(index*2,l,r);
    if(tree[index*2+1].l <= r) num+=search(index*2+1,l,r);
    return num;
}

int main(void) {
    freopen("data.txt", "r", stdin);
    freopen("aout.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n >> m;
    arr[0] = 0;
    for(long long i = 1; i <= n; i++) {cin >> input[i]; arr[i] = input[i] + arr[i-1];}
    build(1, n, 1, arr);
    for(long long i = 1; i <= m; i++) {
        int op; cin >> op;
        if(op == 1) {
            long long x, v; cin >> x >> v;
            update(1, x, n, v-input[x]);
        }
        else {
            long long l, r; cin >> l >> r;
            cout << search(1, l, r) << '\n';
        }
    }
    return 0;
}