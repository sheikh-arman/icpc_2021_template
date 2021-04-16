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
ll hashCnt=1;
ll base[]= {129,137};
ll mod[]= {1479386893,1928476349};
vector<ll>hashing[2];
vector<ll>hash_power[2];
void power()
{
    for(ll i=0; i<hashCnt; i++)
    {
        ll POWER=1;
        for(ll j=0; j<MAX; j++)
        {
            hash_power[i].PB(POWER);
            POWER*=base[i];
            POWER%=mod[i];
        }
    }
}
void hash_func(string s,ll hashNo)
{
    ll n=s.size();
    ll hash_val=0;
    for(ll i=0; i<n; i++)
    {
        hash_val=((hash_val*base[hashNo])%mod[hashNo])+(s[i]-'A'+1);
        hash_val%=mod[hashNo];
        hashing[hashNo].PB(hash_val);
    }
}
ll seg_hash(ll l,ll r,ll hashNo)
{
    ll hash_val=hashing[hashNo][r];
    if(l>0)
    {
        ll dif=(r-l)+1;
        hash_val-=(hashing[hashNo][l-1]*hash_power[hashNo][dif])%mod[hashNo];
        hash_val+=mod[hashNo];
        hash_val%=mod[hashNo];
    }
    return hash_val;
}
ll sol(ll n,ll siz)
{

    ll hash1=seg_hash(0,siz-1,0);
    ll hash2=seg_hash(n-siz,n-1,0);
    //cout<<hash1<<" "<<hash2<<" 0 "<<siz-1<<" "<<n-siz<<" "<<n-1<<" x\n";
    if(hash1==hash2)return 1;
    return 0;
}
int main()
{
    power();
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        hashing[0].clear();
        hashing[1].clear();
        string s;
        cin>>s;
        hash_func(s,0);
        ll n=s.size();
        ll ans=n;
        vector<ll>V;
        for(ll i=1; (i*i*1LL)<=n; i++)
        {
            if(n%i==0)
            {
                V.PB(i);
                if(n/i!=i)
                {
                    V.PB(n/i);
                }
            }
        }
        VST(V);
        for(ll i:V)
        {
            ll ck=sol(n,n-i);
            if(ck)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<"\n";
        if(test<tcase){
            cout<<"\n";
        }
    }
    return 0;
}
