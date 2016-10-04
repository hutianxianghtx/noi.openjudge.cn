#include <iostream>
using namespace std;

const int M=2147483647;
int b[5][5];

void calc(int a[][5],int i,int j);
void print(int i,int j);
int main() {
	int i,j;
	int a[5][5];
	for(i=0; i<=4; i++)
		for(j=0; j<=4; j++) {
			cin>>a[i][j];
			if(a[i][j]==1) a[i][j]=M;
		}
	calc(a,0,0);
	print(4,4);
	return 0;
}
void calc(int a[][5],int i,int j) {
	int indexX[4]= {-1,0,0,1};
	int indexY[4]= {0,-1,1,0};
	if(a[i][j]==M) return;
	for(int ii=0; ii<=3; ii++) {
		int s=i+indexX[ii];
		int t=j+indexY[ii];
		if(a[s][t]!=M&&0<=s&&s<=4&&0<=t&&t<=4) {
			int temp=a[i][j]+1;
			if(temp<a[s][t]||a[s][t]==0) {
				a[s][t]=temp;
				b[s][t]=i*5+j;
				calc(a,s,t);
			}
		}
	}
	return;
}
void print(int i,int j) {
	if(i==0&&j==0) {
		cout<<"(0, 0)"<<endl;
		return;
	}
	print(b[i][j]/5,b[i][j]%5);
	cout<<"("<<i<<", "<<j<<")"<<endl;
}
