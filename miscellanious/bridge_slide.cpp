#include<stdio.h>
#include<iostream.h>
bool M[128][128]; // adjacency matrix
int colour[128]; // 0 is white, 1 is gray and 2 is black
int dfsNum[128], num; // DFS numbers
int n; // the number of vertices
// returns the smallest DFS number that has a back edge pointing to it
// in the DFS subtree rooted at u
int min(int x,int y)
{
	return x<y?x:y;
}
int dfs( int u, int p ) {
colour[u] = 1;
dfsNum[u] = num++;
int leastAncestor = num;
for( int v = 0; v < n; v++ ) if( M[u][v] && v != p ) {
if( colour[v] == 0 ) {
// (u,v) is a forward edge
int rec = dfs( v, u );
if( rec > dfsNum[u] )
cout << "Bridge: " << u << " " << v << endl;
leastAncestor = min( leastAncestor, rec );
}
else {
// (u,v) is a back edge
leastAncestor = min( leastAncestor, dfsNum[v] );
}
}
colour[u] = 2;
return leastAncestor;
}
int main() {
// ... fill up M[][] with an adjacency matrix
	int u,v,e;
	scanf("%d %d",&n,&e);
	while(e--)
	{
		scanf("%d %d",&u,&v);
		M[v][u]=1;
		M[u][v]=1;
	}
// ... set n to be the number of vertices
for( int i = 0; i < n; i++ ) colour[i] = 0;
num = 0;
dfs( 0, 1
);
return 0;
}