#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	float x1,y1,x2,y2,x3,y3;
	scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
	
	float ans=0.5*abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
	
	printf("%.2f\n",ans);
	return 0;
}
