#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int sx[4]= {0,0,1,-1};
int sy[4]= {1,-1,0,0};
struct hp {
	int x,y,sum;
	bool operator < (const hp &a)const {
		return a.sum<sum;
	}
};
priority_queue<hp>q;
hp now;
char s[205],a[205][205];
bool b[205][205],pd;
int x,y,x1,y1,x2,y2,t,n,m;
int main() {
	scanf("%d\n",&t);
	while (t--) {
		scanf("%d%d\n",&n,&m);
		for (int i=1; i<=n; ++i) {
			gets(s);
			for (int j=1; j<=m; ++j) {
				a[i][j]=s[j-1];
				if (a[i][j]=='r') x1=i,y1=j;
				if (a[i][j]=='a') x2=i,y2=j;
			}
		}
		pd=false;
		memset(b,0,sizeof(b));
		while (!q.empty()) q.pop();
		q.push((hp) {
			x1,y1,0
		});
		while (!q.empty()) {
			if (pd) break;
			now=q.top();
			q.pop();
			for (int i=0; i<4; ++i) {
				x=now.x+sx[i],y=now.y+sy[i];
				if (x>0&&x<=n&&y>0&&y<=m&&a[x][y]!='#'&&!b[x][y]) {
					b[x][y]=true;
					if (a[x][y]=='@') q.push((hp) {
						x,y,now.sum+1
					});
					if (a[x][y]=='x') q.push((hp) {
						x,y,now.sum+2
					});
					if (x==x2&&y==y2) {
						printf("%d\n",now.sum+1);
						pd=true;
						break;
					}
				}
			}
		}
		if (!pd) printf("Impossible\n");
	}
}
