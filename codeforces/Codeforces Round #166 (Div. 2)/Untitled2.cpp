#include<cstdio>
#include<cstring>
int ans,n,k;
char    a[50],C[2000];
int T[1200000][26];
int main(){
    gets(C);n=strlen(C);
    for(int i=0;i<26;i++){
        char    c;
        for(c=getchar();c!='0'&&c!='1';c=getchar());
        a[i]=c;
    }
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        int x=0,cnt=0;
        for(int j=i;j<n;j++){
            if(a[C[j]-'a']=='0')cnt++;
            if(cnt>k)break;
            if(!T[x][C[j]-'a'])T[x][C[j]-'a']=++ans;
            x=T[x][C[j]-'a'];
        }
    }
    printf("%d",ans);
    getchar(),getchar();
