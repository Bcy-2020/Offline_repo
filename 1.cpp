#include<bits/stdc++.h>
using namespace std; 
int m1[2][110000];
bool can[2][110000];
vector<int>t[110000];
int n,m,Q;
struct pt
{
	int a;
	int l;
};
queue<pt> q;
void bfs()
{
	q.push((pt){1,0});
	while(!q.empty())
	{
		pt p=q.front();
		q.pop();
		int u=p.a,l=p.l;
		can[l%2][u]=1;
		m1[l%2][u]=l;
		for(int i=0;i<t[u].size();i++)
		{
			int v=t[u][i];
			if(!can[(l+1)%2][v])
			{
				can[(l+1)%2][v]=1;
				m1[(l+1)%2][v]=l+1;
				q.push((pt){v,l+1});
			}
		}
	}
}
int main()
{
    cin>>n>>m>>Q;
    for(int i=1;i<=m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	t[a].push_back(b);
    	t[b].push_back(a);
	}
	memset(can,0,sizeof(can));
	memset(m1,1,sizeof(m1));
	bfs();
	for(int i=1;i<=Q;i++)
	{
		int a,l;
		cin>>a>>l;
		if(t[1].size()==0)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(can[l%2][a] && l>=m1[l%2][a])
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		cout<<endl;
	}
	return 0;
}

