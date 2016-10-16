#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	double a,b;
	scanf("%lf%lf",&a,&b);
	
	while(a>=b) a-=b;
	
	printf("%g\n",a);
	return 0;
}
