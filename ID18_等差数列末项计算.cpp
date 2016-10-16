#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	
	if(a+b<=c || a+c<=b || b+c<=a) printf("Data Error\n");
	else {
		double r=(a+b+c)/2;
		printf("%.4lf\n",sqrt(r*(r-a)*(r-b)*(r-c)));
	}
	return 0;
}
