#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double xa,ya,xb,yb;
	scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
	
	double ans=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
	
	printf("%.3f\n",ans);
	return 0;
}
