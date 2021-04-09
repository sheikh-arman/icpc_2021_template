#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>rHash[4];
ll base[]= {31,29,37,41};
ll mod[]= {1000000007,1000000009,1000000021,1000000033};
ll basePow[4][1000006];
ll hashct=3;

void ctBasePow()
{
    for(ll i=0; i<hashct; i++)basePow[i][0]=1;
    for(ll i=1; i<=1000000; i++)
    {
        for(ll j=0; j<hashct; j++)
        {
            basePow[j][i]=(basePow[j][i-1]*base[j])%mod[j];
        }
    }
}

void ctRollHash(string s)
{
    ll len=s.size();
    ll ch=s[0]-'a'+1;
    for(ll i=0; i<hashct; i++)
    {
        rHash[i].resize(len+5);
        rHash[i][0]=ch;
    }
    for(ll i=1; i<len; i++)
    {
        for(ll j=0; j<hashct; j++)
        {
            rHash[j][i]=(((rHash[j][i-1]*base[j])%mod[j])+(s[i]-'a'+1))%mod[j];
        }
    }
}
vector<ll>pHash;
void ctPatHash(string s)
{
    ll len=s.size();
    ll ch=s[0]-'a'+1;
    pHash.resize(hashct+2);
    for(ll i=0; i<hashct; i++)pHash[i]=ch;
    for(ll i=1; i<len; i++)
    {
        for(ll j=0; j<hashct; j++)
        {
            pHash[j]=(((pHash[j]*base[j])%mod[j])+(s[i]-'a'+1))%mod[j];
        }
    }
}

ll solve(string pt,string s)
{
    ctRollHash(s);
    ctPatHash(pt);
    ll n=pt.size();
    ll idx=n-1;
    ll len=s.size();
    ll ans=0;
    for(ll i=idx; i<len; i++)
    {
        ll ct=0;
        for(ll j=0; j<hashct; j++)
        {
            ll val=rHash[j][i];
            if(i>=n)
            {
                val=val-((rHash[j][i-n]*basePow[j][n])%mod[j]);
                if(val<0)val+=mod[j];
            }
            if(pHash[j]==val)ct++;
        }
        if(ct==hashct)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ctBasePow();
    ll n;
    ll ck=0;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string pt,s;
        cin>>s;
        cin>>pt;
        ll ans=solve(pt,s);
        cout<<"Case "<<test<<": "<<ans<<"\n";

    }
    return 0;
}
