#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<ll>for_hash1;
vector<ll>power_p;
void pow_p()
{
    ll POWER=1;
    ll P=31,M=1e9+7;
    power_p.PB(POWER);
    for(ll i=1; i<=1000000; i++)
    {
        POWER=((POWER%M)*(P%M))%M;
        power_p.push_back(POWER);
    }
}
ll hash1(string S,ll status)
{
    ll P=31,M=1e9+7;
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
    ll P=31,M=1e9+7;
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
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for_hash1.clear();
        string s;
        cin>>s;
        cout<<"Hash 1 of "<<s<<" is : "<<hash1(s,1)<<"\n";
    }
    return 0;
}

