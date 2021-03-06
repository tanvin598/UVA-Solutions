#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 100001
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define mp make_pair
#define pb push_back
#define inf INT64_MAX
#define pi acos(-1)
#define eps 1e-8
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define pf(a) printf("%d\n", a);
#define pfl(a) printf("%lld\n", a);
#define pfi(a) printf("%d ", a);
#define pfll(a) printf("%lld ", a);
#define sc(a) scanf("%d", &a)
#define scc(a, b) scanf("%d %d", &a, &b)
#define sccdbl(a, b) scanf("%lf %lf", &a, &b)
#define sccc(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scccdbl(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
#define scl(a) scanf("%lld", &a)
#define sccl(a, b) scanf("%lld %lld", &a, &b)
#define scccl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
using namespace std;
//int X[]={1,-1,0,0}; //co-ordinate move
//int Y[]={0,0,1,-1}; //co-ordinate move
//int X[]={1,1,2,2,-1,-1,-2,-2}; //Knights move
//int Y[]={2,-2,1,-1,2,-2,1,-1}; //Knights move
/******Always use printf & scanf*******/
int wt[21],dp[21][1000001]; 
int cap,item,x;               
int func(int i,int w)   //0/1 knapsack
{
    int profit1,profit2,result;
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(i==item)
        return 0;
    else if(w+wt[i]<=cap)
    {
        profit1=wt[i]+func(i+1,w+wt[i]);
        profit2=func(i+1,w);  
        result=max(profit1,profit2); 
    }
    else if(w+wt[i]>cap)
    {
        result=func(i+1,w);          
    }
    dp[i][w]=result;
    return result;
}
void subset_sum(int sol[],int cur_sum,int sum,int i){
    if(cur_sum==sum){
        for(int i=0;i<item;i++){
            if(sol[i]==1){
                cout<<wt[i]<<" ";
            }
        }
        x=-1;
    }
    else if(i==item){
        return ;
    }
    else{
        sol[i]=1;
        cur_sum+=wt[i];
        subset_sum(sol,cur_sum,sum,i+1);
        if(x==-1){
            return;
        }
        cur_sum-=wt[i];
        sol[i]=0;
        subset_sum(sol,cur_sum,sum,i+1);
        if(x==-1){
            return;
        }
    }
}
int main()
{
    while(cin>>cap>>item){
        for(int i=0;i<item;i++){
            sc(wt[i]);
        }
        int ans;
        for(int i=0;i<=item;i++){
            for(int j=0;j<=cap;j++){
                dp[i][j]=-1;
            }
        }
        ans=func(0,0);
        int sol[item]={0};
        x=0;
        subset_sum(sol,0,ans,0);
        cout<<"sum:"<<ans<<endl;
    }
    return 0;
}
