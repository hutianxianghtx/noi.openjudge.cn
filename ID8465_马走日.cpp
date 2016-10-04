#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std;

int n,m,sum,startx,starty,step;
int book[105][105];
void dfs(int x,int y,int step) {
	int next[8][2]= {{1,2},{2,1},{2,-1},{-1,2},{1,-2},{-2,1},{-2,-1},{-1,-2}};
	int tx,ty,k;
	if(step==n*m) {
		sum++;
		return;
	}
	for(k=0; k<=7; k++) {
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<0||tx>n-1||ty<0||ty>m-1)
			continue;

		if(book[tx][ty]==0) {
			book[tx][ty]=step;
			dfs(tx,ty,step+1);
			book[tx][ty]=0;
		}

	}
	return;

}

int main() {
	int i,j,h,q;

	cin>>h;
	for(q=1; q<=h; q++) {
		sum=0;
		cin>>n>>m>>startx>>starty;
		book[startx][starty]=1;
		dfs(startx,starty,1);
		cout<<sum<<endl;
		book[startx][starty]=0;
	}
	return 0;

}
