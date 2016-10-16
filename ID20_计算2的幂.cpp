#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	
	long long s=1;
	for(int i=0;i<n;i++) s*=2;
	
	printf("%lld\n",s);
	return 0;
}
