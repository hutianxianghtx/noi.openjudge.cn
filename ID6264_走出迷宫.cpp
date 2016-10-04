#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n,m,ans,vis[1000][1000];
char mat[1000][1000],dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}}; ;

struct Point {
	int x,y,k;
};

int Bfs(Point a,Point b) {
	queue<Point> q;
	q.push(a);
	vis[a.x][a.y]=1;
	Point top,next;
	while(!q.empty()) {
		top=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			next.x=top.x+dir[i][0];
			next.y=top.y+dir[i][1];
			next.k=top.k+1;
			if(next.x==b.x&&next.y==b.y) {
				printf("%d",next.k);
				return 0;
			}
			if(next.x>=0&&next.x<n&&next.y>=0&&next.y<n&&vis[next.x][next.y]==0&&mat[next.x][next.y]=='.') {
				q.push(next);
				vis[next.x][next.y]=1;
			}
		}
	}
}

int main() {
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	Point s,t;
	for(int i=0; i<n; i++) {
		scanf("%s",mat[i]);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(mat[i][j]=='S') {
				s.x=i;
				s.y=j;
				s.k=0;

			}
			if(mat[i][j]=='T') {
				t.x=i;
				t.y=j;
			}
		}
	}
	Bfs(s,t);
	return 0;
}
