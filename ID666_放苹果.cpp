#include<cstdio>
#include<cstring>
using namespace std;

int dfs(int x,int y) {
	if(x<y)y=x;
	if(x==0)return 1;
	if(y==1)return 1;
	if(x>=y)return dfs(x,y-1)+dfs(x-y,y);
	return 0;
}
int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		printf("%d\n",dfs(n,m));
	}
	return 0;
}
