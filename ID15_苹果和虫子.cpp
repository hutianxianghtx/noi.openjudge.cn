#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	
	double cnt=(double)y/x;
	if((int)cnt!=cnt) cnt=(int)cnt+1;
	
	n-=cnt;
	
	if(n<=0) printf("%d\n",0);
	else printf("%d\n",n);
	return 0;
}
