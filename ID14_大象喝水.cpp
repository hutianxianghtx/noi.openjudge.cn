#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int h,r;
	cin>>h>>r;
	
	double s=20000/(r*r*3.14159*h);
	if((int)s!=s) s=(int)s+1;
	
	printf("%.0lf\n",s);
	return 0;
}
