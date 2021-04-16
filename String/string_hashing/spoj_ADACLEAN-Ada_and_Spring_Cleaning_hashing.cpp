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
vector<ll>for_hash2;
vector<ll>power_p;
vector<ll>power_p2;
void pow_p()
{
    ll POWER=1;
    ll POWER2=1;
    ll P=base1,M=MOD1;
    ll P2=base2,M2=MOD2;
    power_p.PB(POWER);
    power_p2.PB(POWER2);
    for(ll i=1; i<=100010; i++)
    {
        POWER=((POWER%M)*(P%M))%M;
        power_p.push_back(POWER);

        POWER2=((POWER2%M2)*(P2%M2))%M2;
        power_p2.push_back(POWER2);
    }
}
ll hash1(string S,ll status)
{
    ll P=base1,M=MOD1;
    ll P2=base2,M2=MOD2;
    ll SIZ=S.size();
    ll ANS=0;
    ll ANS2=0;
    for(ll i=0; i<SIZ; i++)
    {
        ll VAL=(ANS*P)%M;
        ANS=(((S[i]-'a'+1)%M)+(VAL%M))%M;

        ll VAL2=(ANS2*P2)%M2;
        ANS2=(((S[i]-'a'+1)%M2)+(VAL2%M2))%M2;
        if(status==0)
        {
            for_hash1.push_back(ANS);
            for_hash2.push_back(ANS2);
        }
    }
    return ANS;
}
ll seg_hash1(ll l,ll r)
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
ll seg_hash2(ll l,ll r)
{
    ll P=base2,M=MOD2;
    ll ans=for_hash2[r];
    if(l>0)
    {
        ll dif=(r-l)+1;
        ans-=(for_hash2[l-1]*power_p2[dif])%M;
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
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for_hash1.clear();
        for_hash2.clear();
        string s;
        ll n,k;
        cin>>n>>k;
        cin>>s;
        ll ans=hash1(s,0);
        set<pair<ll,ll> >st;
        ll l=0,r=k-1;
        for(; r<n;)
        {
            ll seg1=seg_hash1(l,r);
            ll seg2=seg_hash2(l,r);
            //cout<<seg1<<" "<<seg2<<" \n";
            st.insert({seg1,seg2});
            l++,r++;
        }
        ans=st.size();
        cout<<ans<<"\n";
    }
    return 0;
}
