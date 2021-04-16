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
vector<ll>power;
ll hashing[1000010];
void pow_p()
{
    ll POWER=1;
    for(ll i=1; i<=1000010; i++)
    {
        power.PB(POWER);
        POWER*=base1;
        POWER%=MOD1;
    }
}
void hash1(string s)
{
    ll P=base1,M=MOD1;
    ll SIZ=s.size();
    ll ANS=0;
    for(ll i=0; i<SIZ; i++)
    {
        ll VAL=(ANS*P)%M;
        ANS=(((s[i]-'a'+1)%M)+(VAL%M))%M;
        hashing[i]=ANS;
    }
}
ll sol(string s)
{
    ll n=s.size();
    ll siz=n-3;
    ll pos=-1;
    for(ll i=siz; i>=0; i--)
    {
        ll prefix=hashing[i];
        ll start=n-i-1;
        ll sufix=hashing[n-1]-(power[i+1]*hashing[start-1])%MOD1;
        sufix%=MOD1;
        sufix+=MOD1;
        sufix%=MOD1;
        if(prefix==sufix)
        {
            ll ck=0;
            for(ll j=i+1; j<n-1; j++)
            {
                ll segment=hashing[j]-(power[i+1]*hashing[j-(i+1)])%MOD1;
                segment%=MOD1;
                segment+=MOD1;
                segment%=MOD1;
                if(segment==prefix)
                {
                    ck=1;
                    break;
                }
            }
            if(ck==1)
            {
                pos=i+1;
                break;
            }
        }
    }
    return pos;
}
int main()
{
    pow_p();
    // freopen("1input.txt","r",stdin);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        cin>>s;
        hash1(s);
        ll ans=sol(s);
        if(ans==-1)
        {
            cout<<"Just a legend\n";
        }
        else
        {
            for(ll i=0; i<ans; i++)
            {
                cout<<s[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}

