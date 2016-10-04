#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int h[1000001],d[1000001];
int head,tail=1,y,x;
bool w[1000001];
const int mo=1000001;

int getint()
{
int w=0,q=0;
char c=getchar();
while((c>'9'||c<'0')&&c!='-') c=getchar();
if(c=='-') q=1,c=getchar();
while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
return q?-w:w;
}

bool test(int k)
{
if(k<0||k>1000000||w[k])
return 0;
return 1;
}

void enter(int k)
{
tail=(tail+1)%mo;
h[tail]=k;
d[tail]=d[head]+1;
}

int main()
{
while(scanf("%d%d",&h[1],&y)!=EOF)
{
if(h[1]>=y){printf("%d\n",h[1]-y);continue;}
memset(w,0,sizeof(w));
head=0,tail=1;d[head]=d[tail]=0;
while(head!=tail)
{
head=(head+1)%mo;x=h[head];
if(x*2==y||x+1==y||x-1==y)
{printf("%d\n",d[head]+1);break;}
w[x]=1;
if(test(x*2)) enter(x*2);
if(test(x+1)) enter(x+1);
if(test(x-1)) enter(x-1);
}
}
return 0;
}
