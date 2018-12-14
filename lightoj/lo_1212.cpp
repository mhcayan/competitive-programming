#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    deque<int>dq;
    int cas,tc,n,sz,v;
    char m[12];
    scanf("%d",&cas);
    for(tc=1;tc<=cas;tc++)
    {
        dq.clear();
        scanf("%d %d",&sz,&n);
        printf("Case %d:\n",tc);
        while(n--)
        {
            scanf("%s",m);
            if(m[1]=='u')
            {
                scanf("%d",&v);
                if(dq.size()==sz)
                {
                    printf("The queue is full\n");
                    continue;
                }
                if(m[4]=='L')
                {
                    dq.push_back(v);
                    printf("Pushed in left: %d\n",v);
                }
                else
                {
                    dq.push_front(v);
                    printf("Pushed in right: %d\n",v);
                }
            }
            else
            {
                if(dq.empty())
                {
                    printf("The queue is empty\n");
                    continue;
                }
                if(m[3]=='L')
                {
                    printf("Popped from left: %d\n",dq.back());
                    dq.pop_back();
                }
                else
                {
                    printf("Popped from right: %d\n",dq.front());
                    dq.pop_front();
                }
            }
                         
        }
    }
    return 0;
}
