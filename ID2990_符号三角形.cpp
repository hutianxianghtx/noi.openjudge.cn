#include <cstdio>
#include <cstring>
using namespace std;

int k[16777220];
bool s[30][30];
int n;
int T;
int ans=0;
int qr (int x,int y) {
	if (y>T) return 0;
	if (x<1)
		return 0;
	int t=1;
	int o=0;
	for (int u=1; u<=x; u++) {
		s[x][u]=s[x+1][u]^s[x+1][u+1];
		o=o+s[x][u];
		t=t<<1;
		if (s[x][u]) t++;
	}
	if (k[t]!=-1) {
		if (y+o+k[t]==T) ans++;
		return o+k[t];
	}
	k[t]=qr(x-1,y+o);
	return k[t]+o;
}
void qs (int x,int y,int z) {
	if (x>n) {
		qr(n-1,z);
		return ;
	}
	s[n][x]=true;
	qs(x+1,(y<<1)+1,z+1);
	s[n][x]=false;
	qs(x+1,y<<1,z);
}
int main() {
	memset(k,-1,sizeof(k));
	while (true) {
		ans=0;
		scanf("%d",&n);
		if (n==0) break;
		T=(1+n)*n/4;
		if (((1+n)*n/2)%2!=0) {
			printf("%d 0\n",n);
			continue;
		}
		qs(1,1,0);
		printf("%d %d\n",n,ans);
	}
	return 0;
}
