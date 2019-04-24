#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
int map[100001],n,q;
int rnk[100001];
int find(int x)
{
  if(map[x]!=x) return find(map[x]);
  return x;
}
void u(int x,int y)
{
  int fx=find(x);
  int fy=find(y);
  if(fx!=fy)
  {
      if(rnk[fx]<rnk[fy]) map[fx]=fy;
      else if(rnk[fx]>rnk[fy]) map[fy]=fx;
      else
      {
        map[fx]=fy;
        rnk[fy]=rnk[fy]+1;
      }
  }
}
int main()
{
  cin >> n >> q;
  char c;
  int x,y,fx,fy;
  for(int i=1;i<=n;i++)
  {
    map[i]=i;
    rnk[i]=0;
  }
  for(int i=0;i<q;i++)
  {
    //cin >> c >> x >> y;
    scanf(" %c %d %d" ,&c,&x,&y);
    if(c=='q')
    {
      if(find(x)==find(y)) printf("yes\n");
      else printf("no\n");
    }
    else if(c=='c')
    {
        u(x,y);
        /*for(int j=1;j<=n;j++)
        {
          cout << map[j] << " ";
        }
        cout << endl;*/
    }

  }
}
