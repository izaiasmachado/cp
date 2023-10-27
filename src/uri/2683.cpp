/**
 * Descrição   : BEECROWD 2683 - Espaço de Projeto
 * Autor(a)    : Izaias Machado
 * Data        : 27/10/2023
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int a, b;
    double w;
} Edge;

vector<Edge> edges;
vector<int> parent;
double n;

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

Edge createEdge(int a, int b, int w) {
    Edge e;
    e.a = a;
    e.b = b;
    e.w = w;
    return e;
}

void sort_asc() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
}

void sort_desc() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w > b.w;
    });
}

double kruskal(bool min) {
    if (min) sort_asc();
    else sort_desc();

    make_sets();

    double res = 0, size = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (size == n - 1) break;

        if (union_sets(edges[i].a, edges[i].b)) {
            res += edges[i].w;
            size++;
        }
    }

    return res;
}

int main() { 
    int u, v;
    double w;

    cin >> n;

    parent = vector<int>(n + 1);
    edges = vector<Edge>(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        edges.push_back(createEdge(u, v, w));
    }

    cout << kruskal(false) << endl << kruskal(true) << endl;
}