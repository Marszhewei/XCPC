//树状数组代码 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,mod,x,y,s,inn[500001],tree[500001];
ll lowbit(ll num){
	return num&-num;//返回值为二进制下num从左往右第一个1的位置 
}
void add(ll s,ll num){
	for(ll i=s;i<=n;i+=lowbit(i)) tree[i]+=num;//差分的思想 
}
ll ask(ll s){
	ll ans=0;
	for(ll i=s;i>=1;i-=lowbit(i)) ans+=tree[i];//寻找差分的标记 
	return ans;
}
int main(){
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&inn[i]);
	for(int i=1;i<=q;i++){
		scanf("%lld",&mod);//输入1或2 
		if(mod==1){
			scanf("%lld%lld%lld",&x,&y,&s);
			add(x,s);
			add(y+1,-s);
		}
		if(mod==2){
			scanf("%lld",&x);
			printf("%lld\n",inn[x]+ask(x));//区间查询则为右边界前缀和减去左边界前缀和 
		}
	}
}
