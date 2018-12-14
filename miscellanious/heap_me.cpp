#include<cstdio>
#include<algorithm>
using namespace std;
#define SIZE 100
struct heap{
	int n,a[SIZE];
	heap(){ n=0; };
	void insert(int v)
	{
		int p,pr;
		if(n==SIZE)
			printf("Heap full !!!!\n");
		else 
		{
			a[++n]=v;
			p=n;
			while(p>1)
			{
				pr=p/2;
				if(a[p]<a[pr])
				{
					swap(a[p],a[pr]);
					p=pr;
				}
				else
					break;
			}
		}
		return;
	}
	int remove()
	{
		int t,h,p;
		t=a[1];
		a[1]=a[n];
		n--;
		p=1;
		h=2*p;
		while(h<=n)
		{
			if(h+1<=n)
			{
				if(a[h+1]<a[h])
					h++;
			}
			if(a[h]<a[p])
			{
				swap(a[h],a[p]);
				p=h;
				h=2*p;
			}
			else
				break;
		}
		return t;
	}
	void print()
	{
		int i;
		printf("contents are\n\n");
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
};
int main()
{
	heap A;
	
    //A.clear();
 
    // testing
    A.insert(4);
    A.print();
 
    A.insert(5);
    A.print();
 
    A.insert(3);
    A.print();
 
    A.insert(2);
    A.print();
 
    A.insert(8);
    A.print();
 
    A.insert(9);
    A.print();
 
    A.insert(6);
    A.print();
 
    A.insert(1);
    A.print();
 
    printf("Deleting %d\n", A.remove());
    A.print();
    printf("Deleting %d\n", A.remove());
    A.print();
    printf("Deleting %d\n", A.remove());
    A.print();
	return 0;
}

			