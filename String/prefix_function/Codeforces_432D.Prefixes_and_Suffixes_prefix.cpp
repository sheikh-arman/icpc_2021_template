#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
ll cnt_ar[500010];
vector<ll> prefix_function(string s){
    ll n=s.size();
    vector<ll>prefix(n+1);
    prefix[0]=0;
    ll j=0;
    for(ll i=1;i<n;i++){
        while(j>0&&s[i]!=s[j]){
            j=prefix[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        prefix[i]=j;
        cnt_ar[j]++;
    }
    return prefix;
}
int main(){
	//freopen("1input.txt","r",stdin);
	fast;
	ll tcase=1;
	//cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		string s;
		cin>>s;
		ll n=s.size();
        for(ll i=0;i<=n;i++){
            cnt_ar[i]=0;
		}
		vector<ll>V=prefix_function(s);vector<ll>ans;
        for (int i = n-1; i > 0; i--)
            cnt_ar[V[i-1]] += cnt_ar[i];
        ll i=n-1;
		ll j=V[n-1];
		while(j>0){
            if(s[j-1]==s[i]){
                ans.PB(j);
            }
            j=V[j-1];
		}
		ans.PB(n);
        VST(ans);
        ll siz=ans.size();
        cout<<siz<<"\n";
        for(ll i=0;i<=n;i++){
            cnt_ar[i]+=1;
		}
        for(ll i:ans){
            cout<<i<<" ";
            cout<<cnt_ar[i]<<"\n";
        }
	}
	return 0;
}
