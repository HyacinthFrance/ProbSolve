#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int map[1002]={};
bool search(int c,int n)
{
	int i,j;
	i=j=0;
	while(i<n && j<n)
	{
		if(map[j]-map[i]==c) return 1;
		else if(map[j]-map[i]<c) j++;
		else i++;
	}
	while(i<n)
	{
		if(map[j]-map[i]==c) return 1;
		i++;
	}
	while(j<n)
	{
		if(map[j]-map[i]==c) return 1;
		j++;
	}
	return 0;
}
		
int main()
{
	int n,q,sum=0,c;
	int l[1002]={};
	vector<bool> enable;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i];
		sum+=l[i];
		map[i]=sum;
	}
	/*for(int i=0;i<=n;i++)
	{
		cout << map[i] << " ";
	}*/
	//cout << endl;
	for(int i=0;i<q;i++)
	{
		cin >> c;
		if(search(c,n+1)) enable.push_back(1);
		else enable.push_back(0);
	}
	for(vector<bool>::iterator i=enable.begin();i!=enable.end();i++)
	{
		if(*i==1) cout << "Y";
		else cout << "N";
	}
}
		
