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
#define MAX 100010
ll hashCnt=2;
ll base[]= {129,129};
ll mod[]= {1479386893,1479386893};
vector<ll>hashing[2];
vector<ll>hash_power[2];
void power(ll hashNo)
{
    ll POWER=1;
    for(ll j=0; j<MAX; j++)
    {
        hash_power[hashNo].PB(POWER);
        POWER*=base[hashNo];
        POWER%=mod[hashNo];
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
ll sol(ll val,ll n)
{
    ll left=0,right=val-1;
    ll rev_right=n-1;
    ll rev_left=n-val;
    while(right<n)
    {
        ll hash_val1=seg_hash(left,right,0);
        ll rev_hash_val1=seg_hash(rev_left,rev_right,1);
        if(hash_val1==rev_hash_val1)
        {
            return 1;
        }
        left++;
        right++;
        rev_left--;
        rev_right--;
    }
    return 0;
}
int main()
{
    power(0);
    power(1);
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        hashing[0].clear();
        hashing[1].clear();
        string s;
        ll n;
        cin>>n;
        cin>>s;
        hash_func(s,0);
        reverse(s.begin(),s.end());
        hash_func(s,1);
        ll ans=1;
        ll left,right;
        vector<ll>V;
        n=s.size();
        for(ll i=2; i<=n; i+=2)
        {
            V.PB(i);
        }
        left=0,right=V.size()-1;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll ck=sol(V[mid],n);
            if(ck>0)
            {
                ans=max(ans,V[mid]);
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        V.clear();
        for(ll i=3; i<=n; i+=2)
        {
            V.PB(i);
        }
        left=0,right=V.size()-1;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll ck=sol(V[mid],n);
            if(ck>0)
            {
                ans=max(ans,V[mid]);
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*


*/
