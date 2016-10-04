#include<cstdio>
#include<cstring>
using namespace std;
int a[15],b[15],n,ans;
bool bk;
int gcd(int a,int b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
void dfs(int x,int y) {
	if(x>n) {
		if(y<ans)ans=y;
		return ;
	}
	for(int i=1; i<=y; i++) {
		bk=true;
		for(int j=1; j<x; j++) {
			if(gcd(a[x],a[j])!=true&&b[j]==i) {
				bk=false;
				break;
			}
		}
		if(bk==true) {
			b[x]=i;
			dfs(x+1,y);
			b[x]=false;
		}
	}
	b[x]=y+1;
	dfs(x+1,y+1);
	b[x]=false;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	b[1]=1;
	ans=99999999;
	dfs(2,1);
	printf("%d\n",ans);
	return 0;
}
