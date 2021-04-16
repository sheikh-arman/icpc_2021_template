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
vector<ll> prefix_function(string s,ll start)
{
    ll n=s.size();
    vector<ll>prefix(n+1);
    ll j=0;
    prefix[0]=0;
    for(ll i=1; i<n; i++)
    {
        while(j>0&&s[i]!=s[j])
        {
            j=prefix[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        prefix[i]=j;
    }
//    cout<<s<<" \n";
//    for(ll i=0;i<n;i++){
//        cout<<prefix[i]<<" ";
//    }
//    cout<<"\n";
    return prefix;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        string s;
        while(cin>>s)
        {
            n=s.size();
            string pre_s=s;
            string rev_s=s;
            reverse(rev_s.begin(),rev_s.end());
            s=rev_s+"#"+s;
            vector<ll>V=prefix_function(s,n+1);
            ll ans=V[(ll)s.size()-1];
            ans=n-ans;
            for(ll i=ans-1; i>=0; i--)
            {
                pre_s+=pre_s[i];
            }
            cout<<pre_s<<"\n";
        }
    }
    return 0;
}
