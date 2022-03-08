#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int Cmax , n , m , sp , mid , minsent = 0x3f, mintake = 0x3f;
int e[N][N] , dis[N] , carry[N];
bool vis[N];
priority_queue<pair<int,int> > q;
vector<int> pre[N] , path;
void dfs(vector<int> tmp, int now)
{
	if(now == 0)
	{
		int need = 0, back = 0;
		for(int i = tmp.size() - 1; i >= 0; i--)
		{
			int id = tmp[i];
			if(carry[id] > 0)
				back += carry[id];
			else{
				if(back > -carry[id])
					back += carry[id];
				else{
					need += (carry[id] + back);
					back = 0;
				}
			}
		}
		if(need < minsent){
			minsent = need;
			mintake = back;
			path = tmp;
		}
		if(need == minsent && back < mintake)
		{
			mintake = back;
			path = tmp;
		}
	}
	for(int i = 0; i < pre[now].size(); i++)
	{
		tmp.push_back(now);
		dfs(tmp, pre[now][i]);
		tmp.pop_back();
	}
}
void Dijkstra()
{
	memset(dis , 0x3f , sizeof dis);
	memset(vis , 0 ,sizeof vis);
	dis[0] = 0; // 规定PBMC 为顶点 0
	q.push({0 , 0});
	while(!q.empty())
	{
		int x = q.top().second;q.pop();
		if(vis[x])continue;
		vis[x] = 1;
		for(int i = 1;i <= n;i ++)
		{
			int y = i , w = e[x][i];
			if(dis[y] > dis[x] + w) // 更新 x -> y
			{
				pre[y].clear();
				pre[y].push_back(x);
				dis[y] = dis[x] + w;
				q.push({-dis[y] , y});
			}else if(dis[y] == dis[x] + w){
				pre[y].push_back(x);
			}
		}
	}
	vector<int> t;dfs(t, sp);
}
int main()
{
	memset(e , 0x3f , sizeof e);
	for(int i = 0;i <= n;i ++)e[i][i] = 0;
	cin >> Cmax >> n >> sp >> m;
	mid = Cmax / 2;
	for(int i = 1;i <= n;i ++)
		scanf("%d",&carry[i]) , carry[i] = carry[i] - mid;
	int a, b ,c;
	for(int i = 0;i < m;i ++)
	{
		scanf("%d %d %d", &a ,& b, &c);
		e[a][b] = e[b][a] = c;
	}
	Dijkstra();
	cout << minsent << " 0";
	for(int i = path.size() - 1;i >= 0;i --)
	{
		printf("->%d", path[i]);
	}
	cout << " " << mintake << endl;
	return 0;
}

