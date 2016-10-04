#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b,c;
	cin>>a>>b>>c;
	
	if(a.length()<8) {
		for(int i=0;i<8-a.length();i++) cout<<' ';
	}
	cout<<a<<' ';
	
	if(b.length()<8) {
		for(int i=0;i<8-b.length();i++) cout<<' ';
	}
	cout<<b<<' ';
	
	if(c.length()<8) {
		for(int i=0;i<8-c.length();i++) cout<<' ';
	}
	cout<<c<<endl;
	return 0;
}
