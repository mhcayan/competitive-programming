#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct cmp
{
    bool operator()(const long &a,const long &b)  //for min_priority_queue
    {
         return a>b;
    }
};      
int main()
{
    long n,a,i;
    priority_queue<long,vector<long>,cmp>q;  //for min_priority_queue
    while(scanf("%ld",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a);
            q.push(a);
        }
        for(i=0;i<n;i++)
        {
            printf("%ld\n",q.top());
            q.pop();
        }
    }
    return 0;
}
        
