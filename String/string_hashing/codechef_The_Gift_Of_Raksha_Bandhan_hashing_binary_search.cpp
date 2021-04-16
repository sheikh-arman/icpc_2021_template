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
vector<ll>for_hash1;
vector<ll>power_p;
void pow_p()
{
    ll POWER=1;
    ll P=base1,M=MOD1;
    power_p.PB(POWER);
    for(ll i=1; i<=5000010; i++)
    {
        POWER=((POWER%M)*(P%M))%M;
        power_p.push_back(POWER);
    }
}
ll hash1(string S,ll status)
{
    ll P=base1,M=MOD1;
    ll SIZ=S.size();
    ll ANS=0;
    for(ll i=0; i<SIZ; i++)
    {
        ll VAL=(ANS*P)%M;
        ANS=(((S[i]-'a'+1)%M)+(VAL%M))%M;
        if(status==0)
            for_hash1.push_back(ANS);
    }
    return ANS;
}
ll seg_hash(ll l,ll r)
{
    ll P=base1,M=MOD1;
    ll ans=for_hash1[r];
    if(l>0)
    {
        ll dif=(r-l)+1;
        ans-=(for_hash1[l-1]*power_p[dif])%M;
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
        for_hash1.clear();
        string s;
        cin>>s;
        ll ans=hash1(s,0);
        ll n;
        cin>>n;
        ll siz=s.size();
        for(ll i=0; i<n; i++)
        {
            ll pivot;
            cin>>pivot;
            ll siz_left=pivot;
            ll siz_right=siz-siz_left;
            ll mi=min(siz_left,siz_right);
            ll left=1,right=mi;
            ll ans=0;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ll left_str_hash=seg_hash(0,mid-1);
                ll right_str_hash=seg_hash(siz_left,(siz_left+mid)-1);
                if(left_str_hash==right_str_hash)
                {
                    ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
