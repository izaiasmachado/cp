/**
 * Descrição   : BEECROWD 2522 - Rede do DINF
 * Autor(a)    : Izaias Machado
 * Data        : 26/10/2023
 */

#include <bits/stdc++.h>
#define MAXN 501

using namespace std;

typedef struct {
    int x, y;
    int idx;
} Point;

struct Edge {
    Point *a, *b;
    double w;
};

class Comparator {
	public:
		bool operator() (const Edge& e1, const Edge& e2){
			return e1.w > e2.w;
		}
};

Point points[MAXN];
vector<int> graph[MAXN];
bool belongsToMST[MAXN];

Edge createEdge(Point *a, Point *b) {
    Edge e;
    e.a = a;
    e.b = b;
    e.w = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
    return e;
}

int s, n;

double prim() {
    priority_queue<Edge, vector<Edge>, Comparator> pq;

    memset(belongsToMST, false, sizeof(bool) * n);

    double res = 0, size = 0;
    pq.push(createEdge(&points[0], &points[0]));

    while (!pq.empty()) {
        if (size == n) break;

        Edge e = pq.top();
        pq.pop();

        if (belongsToMST[e.a->idx] && belongsToMST[e.b->idx]) continue;

        Point *out = belongsToMST[e.a->idx] ? e.b : e.a;

        belongsToMST[e.a->idx] = true;
        belongsToMST[e.b->idx] = true;
        res += e.w;
        size++;

        int idx = out->idx;

        for (int i = 0; i < graph[idx].size(); i++) {
            if (!belongsToMST[graph[idx][i]]) {
                pq.push(createEdge(out, &points[graph[idx][i]]));
            }
        }
    }
 
    return res;
}

int main() {
    Point p;

    while (cin >> n) {
        s = 0;

        for (int i = 0; i < n; i++) {
            cin >> p.x >> p.y;
            p.idx = i;
            points[i] = p;

            for (int j = 0; j < i; j++) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        cout << fixed << setprecision(2) << prim() << endl;
    }

    return 0;
}