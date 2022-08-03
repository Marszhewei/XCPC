#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 INF = 0x7fffffff;;
const i64 MOD = 1000000007;
#define rep(i, a, b) for(int i=(a), __=(b); i<=__; ++i)
#define per(i, a, b) for(int i=(b), __=(a); i>=__; --i)
i64 powmod(i64 a, i64 b) {i64 res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a;}
// #define _DEBUG
// #define _FILE_IO
 
const int maxn = 30;  
struct bign{  
    int d[maxn], len;  
  
    void clean() { while(len > 1 && !d[len-1]) len--; }  
  
    bign()          { memset(d, 0, sizeof(d)); len = 1; }  
    bign(int num)   { *this = num; }   
    bign(char* num) { *this = num; }  
    bign operator = (const char* num){  
        memset(d, 0, sizeof(d)); len = strlen(num);  
        for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';  
        clean();  
        return *this;  
    }  
    bign operator = (int num){  
        char s[20]; sprintf(s, "%d", num);  
        *this = s;  
        return *this;  
    }  
  
    bign operator + (const bign& b){  
        bign c = *this; int i;  
        for (i = 0; i < b.len; i++){  
            c.d[i] += b.d[i];  
            if (c.d[i] > 9) c.d[i]%=10, c.d[i+1]++;  
        }  
        while (c.d[i] > 9) c.d[i++]%=10, c.d[i]++;  
        c.len = max(len, b.len);  
        if (c.d[i] && c.len <= i) c.len = i+1;  
        return c;  
    }  
    bign operator - (const bign& b){  
        bign c = *this; int i;  
        for (i = 0; i < b.len; i++){  
            c.d[i] -= b.d[i];  
            if (c.d[i] < 0) c.d[i]+=10, c.d[i+1]--;  
        }  
        while (c.d[i] < 0) c.d[i++]+=10, c.d[i]--;  
        c.clean();  
        return c;  
    }  
    bign operator * (const bign& b)const{  
        int i, j; bign c; c.len = len + b.len;   
        for(j = 0; j < b.len; j++) for(i = 0; i < len; i++)   
            c.d[i+j] += d[i] * b.d[j];  
        for(i = 0; i < c.len-1; i++)  
            c.d[i+1] += c.d[i]/10, c.d[i] %= 10;  
        c.clean();  
        return c;  
    }  
    bign operator / (const bign& b){  
        int i, j;  
        bign c = *this, a = 0;  
        for (i = len - 1; i >= 0; i--)  
        {  
            a = a*10 + d[i];  
            for (j = 0; j < 10; j++) if (a < b*(j+1)) break;  
            c.d[i] = j;  
            a = a - b*j;  
        }  
        c.clean();  
        return c;  
    }  
    bign operator % (const bign& b){  
        int i, j;  
        bign a = 0;  
        for (i = len - 1; i >= 0; i--)  
        {  
            a = a*10 + d[i];  
            for (j = 0; j < 10; j++) if (a < b*(j+1)) break;  
            a = a - b*j;  
        }  
        return a;  
    }  
    bign operator += (const bign& b){  
        *this = *this + b;  
        return *this;  
    }  
  
    bool operator <(const bign& b) const{  
        if(len != b.len) return len < b.len;  
        for(int i = len-1; i >= 0; i--)  
            if(d[i] != b.d[i]) return d[i] < b.d[i];  
        return false;  
    }  
    bool operator >(const bign& b) const{return b < *this;}  
    bool operator<=(const bign& b) const{return !(b < *this);}  
    bool operator>=(const bign& b) const{return !(*this < b);}  
    bool operator!=(const bign& b) const{return b < *this || *this < b;}  
    bool operator==(const bign& b) const{return !(b < *this) && !(b > *this);}  
  
    string str() const{  
        char s[maxn]={};  
        for(int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';  
        return s;  
    }  
};  
  
istream& operator >> (istream& in, bign& x) {  
    string s;  
    in >> s;  
    x = s.c_str();  
    return in;  
}  
  
ostream& operator << (ostream& out, const bign& x) {  
    out << x.str();  
    return out;  
}  


const long long MAXN=1e6+10;
i64 n, m;
i64 tmp[MAXN], B[MAXN], A[MAXN];

inline void add(i64 pos,i64 a) {
    const i64 ia = a*pos;
    for(int i = pos; i <= n; i+=(i&(-i)))
        A[i] += ia, B[i] += a;
}
inline bign sum(int pos) {
    bign ans = 0, temp = pos+1;
    for(int i=pos; i; i -= (i&(-i))) ans = ans + B[i];
    ans = ans * temp;
    for(int i=pos; i; i -= (i&(-i))) ans = ans - A[i];
    return ans;
}
inline void update(i64 h,i64 t,i64 a) { add(h,a); add(t+1,-a); }
inline bign query(i64 h,i64 t) { return sum(t)-sum(h-1); }

void solve() {
    cin >> n >> m;
    i64 t1 = 0;
    rep(i, 1, n) {cin >> tmp[i]; t1 += tmp[i]; update(i, i, t1);}
    rep(i, 1, m) {
        i64 t; cin >> t;
        if (t == 1) {
            i64 pos, val; cin >> pos >> val;
            update(pos, n, (val-tmp[pos]));
            tmp[pos] = val;
        }
        else {
            i64 l, r; cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
