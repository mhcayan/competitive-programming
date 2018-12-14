#include<cstdio>
#include<queue>
using namespace std;
int main()
{
	long m,n,i,cost,tc;
	priority_queue<int>q;
	while(scanf("%ld",&n) && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&m);
			q.push(-m);
		}
		tc=0;
		while(q.size()>1)
		{
			m=-q.top();
			q.pop();
			n=-q.top();
			q.pop();
			cost=m+n;
			tc+=cost;
			q.push(-cost);
		}
		q.pop();
		printf("%ld\n",tc);
	}
	return 0;
}
