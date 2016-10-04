#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int M,N,T,sx,sy,ex,ey;
int mt[210][210][10],map[210][210];  //0为随便走，1为手下(需花一个查克拉通过) 
struct NODE {
	int x;
	int y;
	int t;
	int d;
}queue[10000000],tmp;

int first,last=-1;

void push(int x,int y,int t,int d) {
	queue[++last].x=x;
	queue[last].y=y;
	queue[last].t=t;
	queue[last].d=d;
}

void bfs() {
	int x,y,t,d;
	while(first<=last) {
		tmp=queue[first++];
		x=tmp.x,y=tmp.y,t=tmp.t,d=tmp.d;
		
//		printf("!! %d %d %d %d\n",x,y,t,d);
		
		//上
		if(x>1) {
//			cout<<"上  ";
			if(map[x-1][y]==0) {
//				cout<<"非 "<<mt[x-1][y][t]<<' '<<mt[x][y][t]+1<<endl;
				if(mt[x-1][y][t]>mt[x][y][t]+1) {
					mt[x-1][y][t]=mt[x][y][t]+1;
					push(x-1,y,t,d+1);
				}
			} else {
//				cout<<"是 "<<mt[x-1][y][t-1]<<' '<<mt[x][y][t]+1<<endl;
				if(t>0 && mt[x-1][y][t-1]>mt[x][y][t]+1) {
					mt[x-1][y][t-1]=mt[x][y][t]+1;
					push(x-1,y,t-1,d+1);
				}
			}
		}
		
		//右 
		if(y<N) {
//			cout<<"右  ";
			if(map[x][y+1]==0) {
//				cout<<"非 "<<mt[x][y+1][t]<<' '<<mt[x][y][t]+1<<endl;
				if(mt[x][y+1][t]>mt[x][y][t]+1) {
					mt[x][y+1][t]=mt[x][y][t]+1;
					push(x,y+1,t,d+1);
				}
			} else {
//				cout<<"是 "<<mt[x][y+1][t-1]<<' '<<mt[x][y][t]+1<<endl;
				if(t>0 && mt[x][y+1][t-1]>mt[x][y][t]+1) {
					mt[x][y+1][t-1]=mt[x][y][t]+1;
					push(x,y+1,t-1,d+1);
				}
			}
		}
		
		//下
		if(x<M) {
//			cout<<"下  ";
			if(map[x+1][y]==0) {
//				cout<<"非 "<<mt[x+1][y][t]<<' '<<mt[x][y][t]+1<<endl;
				if(mt[x+1][y][t]>mt[x][y][t]+1) {
					mt[x+1][y][t]=mt[x][y][t]+1;
					push(x+1,y,t,d+1);
				}
			} else {
//				cout<<"是 "<<mt[x+1][y][t-1]<<' '<<mt[x][y][t]+1<<endl;
				if(t>0 && mt[x+1][y][t-1]>mt[x][y][t]+1) {
					mt[x+1][y][t-1]=mt[x][y][t]+1;
					push(x+1,y,t-1,d+1);
				}
			}
		}
		
		//左
		if(y>1) {
//			cout<<"左  ";
			if(map[x][y-1]==0) {
//				cout<<"非 "<<mt[x][y-1][t]<<' '<<mt[x][y][t]+1<<endl;
				if(mt[x][y-1][t]>mt[x][y][t]+1) {
					mt[x][y-1][t]=mt[x][y][t]+1;
					push(x,y-1,t,d+1);
				}
			} else {
//				cout<<"是 "<<mt[x][y-1][t-1]<<' '<<mt[x][y][t]+1<<endl;
				if(t>0 && mt[x][y-1][t-1]>mt[x][y][t]+1) {
					mt[x][y-1][t-1]=mt[x][y][t]+1;
					push(x,y-1,t-1,d+1);
				}
			}
		}
	}
}

int main() {
	
	scanf("%d%d%d",&M,&N,&T);
	memset(map,0,sizeof(map));
	char c;
	getchar();
	for(int i=1;i<=M;i++) {
		for(int j=1;j<=N;j++) {
			scanf("%c",&c);
			if(c=='#') map[i][j]=1;
			if(c=='@') {
				sx=i;
				sy=j;
			}
			if(c=='+') {
				ex=i;
				ey=j;
			}
		}
		getchar();
	}
	
//	for(int i=1;i<=M;i++) {
//		for(int j=1;j<=N;j++) printf("%d ",map[i][j]);
//		printf("\n");
//	}
	for(int i=1;i<=M;i++) {
		for(int j=1;j<=N;j++) {
			for(int k=0;k<=T;k++) mt[i][j][k]=INT_MAX;
		}
	}
	
	for(int i=0;i<=T;i++) mt[sx][sy][i]=0;
	
//	for(int i=1;i<=M;i++) {
//		for(int j=1;j<=N;j++) {
//			cout<<i<<' '<<j<<':'<<endl;
//			for(int k=0;k<=T;k++) cout<<mt[i][j][k]<<' ';
//			cout<<endl; 
//		}
//		printf("\n");
//	}
	
	push(sx,sy,T,0);
	bfs();
	
	int zx=INT_MAX;
//	cout<<endl<<endl;
	for(int i=0;i<=T;i++) {
//		cout<<mt[ex][ey][i]<<endl;
		if(mt[ex][ey][i]<zx) zx=mt[ex][ey][i];
	}
	
	if(zx==INT_MAX) printf("-1");
	else printf("%d\n",zx);
	return 0;
}
