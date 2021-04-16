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
ll pre[5010];
ll frequency[5010];
ll ans[5010];
void hash1(ll pos1,string s)
{
    ll POWER=1;
    ll n=s.size();
    ll s_hash=0;
    ll rev_hash=0;
    ll ans=0;
    for(ll i=pos1; i<n; i++)
    {
        ll val=s[i]-'0'+1;
        s_hash=((s_hash*base1)%MOD1)+val;
        s_hash%=MOD1;


        rev_hash=((val*POWER)%MOD1)+rev_hash;
        rev_hash%=MOD1;
        if(s_hash==rev_hash)
        {
            ll pos=(i+pos1)/2;
            ll dif=i-pos1+1;
            if(dif%2!=0)pos-=1;
            pos=max(pos,pos1);
            ll prefix=pre[pos]+1;
            pre[i]=prefix;
            frequency[prefix]++;
        }
        POWER*=base1;
        POWER%=MOD1;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        ll n;
        cin>>s;
        n=s.size();
        for(ll i=0; i<=n; i++)
        {
            ans[i]=0;
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                pre[j]=0;
                frequency[j]=0;
            }
            hash1(i,s);
            ll cnt=0;
            for(ll j=n; j>=1; j--)
            {
                cnt+=frequency[j];
                ans[j]+=cnt;
            }
        }
        for(ll i=1; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
