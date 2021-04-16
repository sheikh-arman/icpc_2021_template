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
vector<ll> prefix_function(string s){
    ll n=s.size();
    vector<ll>prefix(n+1);
    ll j=0;
    for(ll i=1;i<n;i++){
        while(j>0&&s[j]!=s[i]){
            j=prefix[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        prefix[i]=j;
    }
    return prefix;
}
int main(){
	//freopen("1input.txt","r",stdin);
	fast;
	ll tcase=1;
	//cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		string pattern,s;
		cin>>pattern>>s;ll siz=pattern.size();
		pattern+="#"+s;
		vector<ll>V=prefix_function(pattern);
        ll ans=0;
        for(ll i:V){
            if(i==siz){
                ans++;
            }
        }
        cout<<ans<<"\n";
	}
	return 0;
}
