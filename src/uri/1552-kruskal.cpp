/**
 * Descrição   : BEECROWD 1552 - Resgate em Queda Livre
 * Autor(a)    : Izaias Machado
 * Data        : 25/10/2023
 */

#include <bits/stdc++.h>
#define MAXN 501

using namespace std;

typedef struct {
    int x, y;
    int idx;
} Point;

typedef struct {
    Point *a, *b;
    double w;
} Edge;

int C, n, s;

int parent[MAXN];
Point points[MAXN];
Edge edges[MAXN * (MAXN - 1) / 2];

void setDistance(Edge *e) {
    e->w = sqrt(pow(e->a->x - e->b->x, 2) + pow(e->a->y - e->b->y, 2));
}

Edge createEdge(Point *a, Point *b) {
    Edge e;
    e.a = a;
    e.b = b;
    setDistance(&e);
    return e;
}

void make_sets() {
    for (int i = 0; i < n; i++) {
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

double kruskal() {
    sort(edges, edges + s, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    make_sets();

    double res = 0, size = 0;

    for (int i = 0; i < s; i++) {
        if (size == n - 1) break;

        Point *a = edges[i].a;
        Point *b = edges[i].b;

        if (union_sets(a->idx, b->idx)) {
            res += edges[i].w;
            size++;
        }
    }

    return res / 100.0;
}

int main() {
    Point p;

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> C;

    while (C--) {
        s = 0;

        cin >> n;
        // FILE *fp = fopen("1552.txt", "a");

        for (int i = 0; i < n; i++) {
            cin >> p.x >> p.y;
            p.idx = i;

            points[i] = p;

            for (int j = 0; j < i; j++) {
                edges[s++] = createEdge(&points[i], &points[j]);
            }
        }

        cout << fixed << setprecision(2) << kruskal() << endl;

        // fprintf(fp, "%.2lf\n", kruskal());
        // fclose(fp);
    }

    return 0;
}