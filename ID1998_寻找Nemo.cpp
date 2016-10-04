#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN = 200 + 10;
const int move[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

struct Data {
	int u, step;
};

struct Edge {
	int go, next;
} edge[MAXN * MAXN];

int f[MAXN][MAXN][4], cnt[MAXN][MAXN], N, M, tot, head[MAXN * MAXN];
bool vis[MAXN * MAXN];
double sx, sy;

void Dfs(int xp, int yp) {
	if (cnt[xp][yp]) return;
	cnt[xp][yp] = tot;
	for (int i = 0; i < 4; ++ i)
		if (!f[xp][yp][i])
			Dfs(xp + move[i][0], yp + move[i][1]);
}

void ReadIn() {
	int x, y, l, t, q = 0;
	memset(f, 0, sizeof(f));
	memset(cnt, 0, sizeof(cnt));
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= M; ++ i) {
		scanf("%d%d%d%d", &x, &y, &l, &t);
		if (l == 0)
			for (int j = x; j < x + t; ++ j) {
				f[j][y][0] = 1;
				f[j][y - 1][1] = 1;
			}
		else
			for (int j = y; j < y + t; ++ j) {
				f[x][j][2] = 1;
				f[x - 1][j][3] = 1;
			}
	}
//边界处理
	for (int i = 0; i <= 201; ++ i)
		f[0][i][2] = f[201][i][3] = f[i][0][0] = f[i][201][1] = 1;

//缩点
	tot = 0;
	for (int i = 0; i <= 201; ++ i)
		for (int j = 0; j <= 201; ++ j)
			if (!cnt[i][j]) {
				++ tot;
				Dfs(i, j);
			}

	for (int i = 1; i <= N; ++ i) {
		scanf("%d%d%d", &x, &y, &l);
		if (l == 0) {
			edge[++ q] = (Edge) {
				cnt[x][y - 1], head[cnt[x][y]]
			};
			head[cnt[x][y]] = q;
			edge[++ q] = (Edge) {
				cnt[x][y], head[cnt[x][y - 1]]
			};
			head[cnt[x][y - 1]] = q;
		} else {
			edge[++ q] = (Edge) {
				cnt[x - 1][y], head[cnt[x][y]]
			};
			head[cnt[x][y]] = q;
			edge[++ q] = (Edge) {
				cnt[x][y], head[cnt[x - 1][y]]
			};
			head[cnt[x - 1][y]] = q;
		}
	}
	scanf("%lf%lf", &sx, &sy);
}

void Bfs() {
//数据可能存在Nemo的位置在墙坐标范围之外，所以取min
	int t = cnt[0][0], s = cnt[min((int)sx, 200)][min((int)sy, 200)];

	if (s == t) {
		printf("0\n");
		return;
	}
	queue<Data> Q;
	Q.push((Data) {
		s, 0
	});
	vis[s] = 1;
	while (!Q.empty()) {
		Data x = Q.front();
		Q.pop();
		for (int i = head[x.u]; i; i = edge[i].next) {
			int v = edge[i].go;
			if (!vis[v]) {
				if (v == t) {
					printf("%d\n", x.step + 1);
					return;
				}
				Q.push((Data) {
					v, x.step + 1
				});
				vis[v] = 1;
			}
		}
	}
	printf("-1\n");
}

int main() {
	while (scanf("%d%d", &M, &N) == 2) {
		if (M == -1 && N == -1)
			break;
		ReadIn();
		Bfs();
	}

	return 0;
}
