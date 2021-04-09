#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>rHash[4];
vector<ll>reverseHash[4];
ll base[]= {31,29,37,41};
ll mod[]= {1000000007,1000000009,1000000021,1000000033};
ll basePow[1][1000006];
ll hashct=1;
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
void reversectRollHash(string s)
{
    ll len=s.size();
    ll ch=s[len-1]-'a'+1;
    for(ll i=0; i<hashct; i++)
    {
        reverseHash[i].resize(len+5);
        reverseHash[i][len-1]=ch;
    }
    for(ll i=len-2; i>=0; i--)
    {
        for(ll j=0; j<hashct; j++)
        {
            reverseHash[j][i]=(((reverseHash[j][i+1]*base[j])%mod[j])+(s[i]-'a'+1))%mod[j];
        }
    }
}
ll solve(string s)
{
    ctRollHash(s);
    reversectRollHash(s);
    ll n=s.size();
    ll idx=n-1;
    ll len=s.size();
    ll ans=0;

    for(ll i=0; i<len; i++)
    {
        ll ct=0;
        for(ll j=0; j<hashct; j++)
        {
            ll revval=reverseHash[j][i];
            ll val=rHash[j][n-1];
            ll ptn_siz=n-i;
            if(i>0)
            {
                val=val-((rHash[j][i-1]*basePow[j][ptn_siz])%mod[j]);
                if(val<0)val+=mod[j];
            }
            if(revval==val)ct++;
        }
        if(ct==hashct)
        {
            ans=i;
            break;
        }
    }
    return n+ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("1input.txt","r",stdin);
    ctBasePow();
    ll n;
    ll ck=0;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string pt,s;
        cin>>s;
        ll ans=solve(s);
        cout<<"Case "<<test<<": "<<ans<<"\n";

    }
    return 0;
}
