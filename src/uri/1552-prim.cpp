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

int s, n, c;
Point p;

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
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> c;

    // FILE *fp = fopen("1552-prim.txt", "w");

    while (c--) {
        s = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p.x >> p.y;
            p.idx = i;
            points[i] = p;

            for (int j = 0; j < i; j++) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        double res = prim() / 100.0;

        cout << fixed << setprecision(2) << res << endl;
        // fprintf(fp, "%.2lf\n", res);

        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }
    }

    // fclose(fp);

    return 0;
}