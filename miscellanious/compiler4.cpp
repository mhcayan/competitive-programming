#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int ruleno[200][200];
string rule[100];
void init()
{
    rule[1]="eT"; rule[2]="eT+"; rule[3]="tF"; rule[4]="tF*"; rule[7]="s"; rule[8]="N"; rule[9]="i"; rule[10]=")E(";    
    ruleno['E']['i']=1;
    //rule['E']['+']=;
   // rule['E']['*']=;
    ruleno['E']['(']=1; ruleno['E'][')']=7; ruleno['E']['$']=7; ruleno['e']['+']=2;
    //rule['e']['*']=;
   // rule['e']['(']=;
    ruleno['e'][')']=8; ruleno['e']['$']=8;
    ruleno['T']['i']=3; ruleno['T']['+']=7;
    //rule['T']['*']=;
    ruleno['T']['(']=3; ruleno['T'][')']=7; ruleno['T']['$']=7;
    //rule['t']['i']=;
    ruleno['t']['+']=8; ruleno['t']['*']=4;
    //rule['t']['(']=;
    ruleno['t'][')']=8; ruleno['t']['$']=8;	ruleno['F']['i']=9; ruleno['F']['+']=7; ruleno['F']['*']=7;ruleno['F']['(']=10; 
    ruleno['F'][')']=7; ruleno['F']['$']=7;    
}
int main()
{
	char str[100],ch,r,s,stack[100],input[100];
	int i,st[1000],top,j,k;
	init();
	freopen("compiler4.txt","w",stdout);
	while(gets(str))
	{
        k=strlen(str);
        str[k]='$';
        str[k+1]='\0';
        printf("\n%-15s %15s\n","STACK","INPUT");
        printf("%-15s %15s\n\n","_____","_____");
        top=0;
        st[++top]='$';
        st[++top]='E';
		i=0;
		while(top>0)
		{
            for(j=0,k=i;str[k];k++)
                input[j++]=str[k];
            input[j]='\0';
 	        for(k=0,j=1;j<=top;j++)
		    {
		        if(st[j]=='i')
                    stack[k++]='i',stack[k++]='d';
                else if(st[j]=='e' || st[j]=='t')
                    stack[k++]=st[j]-32,stack[k++]='\'';
                else
		            stack[k++]=st[j];
            }
            stack[k]='\0';
            printf("%-15s %15s\n",stack,input);
			if(str[i]==')')
			{
                i++;
				continue;
            }
			else if(str[i]=='i')
			{
				ch='i';
			}
			else 
				ch=str[i];
			if(st[top]==ch)
			{
                if(ch=='i')
                    i++;
                top--,i++;
            }
			else
			{
				s=st[top--];
				r=ruleno[s][ch];
				if(rule[r]=="s" || rule[r]=="N")
					 continue;
				for(k=0;k<rule[r].size();k++)
					st[++top]=rule[r][k];
				
			}
		}
	}
	return 0;
}
