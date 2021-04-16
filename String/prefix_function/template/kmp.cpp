#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
vector<ll> prefix_function(string s)
{
    ll n=s.size();
    vector<ll>prefix(n+1);
    prefix[0]=0;
    for(ll i=1; i<n; i++)
    {
        ll j=prefix[i-1];
        while(j>0&&s[j]!=s[i])
        {
            j=prefix[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        prefix[i]=j;
    }
    return prefix;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s,pattern;
        cin>>s>>pattern;
        vector<ll>V=prefix_function(pattern);
        ll siz=pattern.size();
        vector<ll>ans;
        ll n=s.size();
        ll i=0;
        ll k=0;
        while(i<n)
        {
            if(pattern[k]==s[i])
            {
                k++;
                i++;
            }
            if(k>=siz)
            {
                ans.PB((i+1)-siz);
                k=V[k-1];
            }
            else if(i<n&&pattern[k]!=s[i])
            {
                if(k!=0)
                {
                    k=V[k-1];
                }
                else
                {
                    i++;
                }
            }
        }
        ll si=ans.size();
        if(si>0)
        {
            cout<<si<<"\n";
            for(ll i=0; i<si; i++)
            {
                cout<<ans[i];
                if(i<si-1)
                {
                    cout<<" ";
                }
            }
            cout<<"\n";
        }
        else
        {
            cout<<"Not Found\n";
        }
        if(test<tcase)
            cout<<"\n";
    }
    return 0;
}


