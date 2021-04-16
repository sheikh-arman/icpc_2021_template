#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
vector<ll>power;
vector<ll>hashing_pattern1;
vector<ll>hashing_pattern2;
void pow_p()
{
    ll POWER=1;
    for(ll i=1; i<2000100; i++)
    {
        power.PB(POWER);
        POWER=(POWER*base1)%MOD1;
    }
}
void hash1(string s,ll ptn)
{
    ll hash_val=0;
    ll n=s.size();
    for(ll i=0; i<n; i++)
    {
        hash_val=(hash_val*base1)%MOD1+s[i]-'a'+1;
        hash_val%=MOD1;
        if(ptn==0)
        {
            hashing_pattern1.PB(hash_val);
        }
        else
        {
            hashing_pattern2.PB(hash_val);
        }
    }
}
ll seg_hash(ll l,ll r)
{
    ll P=base1,M=MOD1;
    ll ans=hashing_pattern2[r];
    if(l>0)
    {
        ll dif=(r-l)+1;
        ans-=(hashing_pattern2[l-1]*power[dif])%M;
        ans+=M;
        ans%=M;
    }
    return ans;
}
int main()
{
    pow_p();
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        string pattern1,pattern2;
        cin>>pattern1>>pattern2;
        hash1(pattern1,0);
        hash1(pattern2,2);
        ll ans=0,mx=0;
        for(ll i=0; i<n; i++)
        {
            ll left=1,right=n;
            ll tm_ans=0;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ll ptn1=hashing_pattern1[mid-1];
                ll ptn2=seg_hash(i,i+mid-1);
                if(ptn1==ptn2)
                {
                    tm_ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            if(tm_ans>mx)
            {
                mx=tm_ans;
                ans=i;
            }
            ll siz=hashing_pattern2.size();
            ll hash_val=(hashing_pattern2[siz-1]*base1)%MOD1+pattern2[i]-'a'+1;
            hash_val%=MOD1;
            hashing_pattern2.PB(hash_val);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
