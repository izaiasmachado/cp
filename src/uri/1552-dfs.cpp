/**
 * Descrição   : BEECROWD 1552 - Resgate em Queda Livre
 * Autor(a)    : Izaias Machado
 * Data        : 25/10/2023
 */

#include <bits/stdc++.h>
#define MAXN 10001

using namespace std;

typedef struct {
    int x, y;
} Point;

typedef struct {
    int idxA, idxB;
    double w;
} Edge;

int C, n;
bool picked[MAXN][MAXN];
vector<Point> points;
vector<Edge> edges;
vector<int> graph[MAXN];

double getDistance(Edge e) {
    int idxA = e.idxA;
    int idxB = e.idxB;
    Point a = points[idxA];
    Point b = points[idxB];
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Edge createEdge(int a, int b) {
    Edge e;
    e.idxA = a;
    e.idxB = b;
    return e;
}

bool visited[10];

bool dfs_rec(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];

        if (!visited[u]) {
            bool cycle = dfs_rec(u, v);

            if (cycle) {
                return true;
            }
        } else if (u != parent) {
            return true;
        }
    }

    return false;
}

bool dfs(int v) {
    memset(visited, false, sizeof(bool) * points.size());
    return dfs_rec(v, -1);
}

double kruskal() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return getDistance(a) < getDistance(b);
    });

    double res = 0, size = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (size == n - 1) break;
        int idxA = edges[i].idxA;
        int idxB = edges[i].idxB;

        graph[idxA].push_back(idxB);
        graph[idxB].push_back(idxA);

        if (dfs(idxA)) {
            graph[idxA].pop_back();
            graph[idxB].pop_back();
            continue;
        }
        
        res += getDistance(edges[i]);
        size++;
    }
    
    for (int i = 0; i < MAXN; i++) {
        graph[i].clear();
    }

    return res / 100.0;
}

int main() {
    Edge e;

    cin >> C;

    while (C--) {
        cin >> n;
        Point p;
        // FILE *fp = fopen("1552.txt", "a");

        memset(picked, false, sizeof(bool) * MAXN * MAXN);

        for (int i = 0; i < n; i++) {
            cin >> p.x >> p.y;

            if (picked[p.x][p.y]) continue;
            picked[p.x][p.y] = true;

            int size = points.size();
            for (int j = 0; j < size; j++) {
                e = createEdge(size, j);
                edges.push_back(e);
            }

            points.push_back(p);
        }

        cout << fixed << setprecision(2) << kruskal() << endl;

        // fprintf(fp, "%.2lf\n", kruskal());
        // printf("%.2lf\n", kruskal());
        // fclose(fp);

        edges.clear();
        points.clear();
    }

    return 0;
}