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
vector<ll> prefix_function(string s)
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
    return prefix;
}
string sol(string s)
{
    string tm_s=s;
    string tm_rev=s;
    reverse(tm_rev.begin(),tm_rev.end());
    tm_s=tm_s+"#"+tm_rev;
    vector<ll>V=prefix_function(tm_s);
    string ans=tm_s.substr(0,V[tm_s.size()-1]);
    tm_s=s;
    tm_s=tm_rev+"#"+tm_s;
    V=prefix_function(tm_s);
    if(V[tm_s.size()-1]>(ll)ans.size())
    {
        ans=tm_s.substr(0,V[tm_s.size()-1]);
    }
    return ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        string s,ans;
        cin>>s;
        n=s.size();
        ll left=0,right=n-1;
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                break;
            }
            ans+=s[left];
            left++;
            right--;
        }
        string rev_ans=ans;
        reverse(rev_ans.begin(),rev_ans.end());
        if(left<=right)
        {
            ll dif=right-left+1;
            s=s.substr(left,dif);
            string mid=sol(s);
            ans+=mid;
        }
        ans+=rev_ans;
        cout<<ans<<"\n";
    }
    return 0;
}
