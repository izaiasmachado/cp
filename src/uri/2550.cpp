/**
 * Descrição   : BEECROWD 2550 - Novo Campus
 * Autor(a)    : Izaias Machado
 * Data        : 27/10/2023
 */
 
#include <bits/stdc++.h>
#define MAXN 1001

using namespace std;

typedef struct {
    int a, b;
    double w;
} Edge;

Edge edges[MAXN * (MAXN - 1) / 2];
int parent[MAXN];
bool visited[MAXN];

int n, m;
int s, res;

void make_sets() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int find_set(int v) {
    if (v == parent[v]) return v;
    parent[v] = find_set(parent[v]);
    return parent[v];
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        parent[b] = a;
        return true;
    }

    return false;
}

void kruskal() {
    res = 0;
    s = 0;

    sort(edges, edges + m, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    make_sets();

    for (int i = 0; i < m; i++) {
        if (s >= n - 1) break;

        if (union_sets(edges[i].a, edges[i].b)) {
            res += edges[i].w;
            s++;
        }
    }
}

int main() { 
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int u, v;
    double w;

    Edge e;

    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            cin >> e.a >> e.b >> e.w;
            edges[i] = e;            
        }

        kruskal();

        if (s != n - 1) {
            cout << "impossivel" << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}