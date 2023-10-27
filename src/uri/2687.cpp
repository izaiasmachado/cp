/**
 * Descrição   : BEECROWD 2687 - Dominação Bacteriana
 * Autor(a)    : Izaias Machado
 * Data        : 26/10/2023
 */
 
#include <bits/stdc++.h>
#define MAXN 101

using namespace std;

int q, l;

int nextL[] = { -1, 1, 0, 0 };
int nextC[] = { 0, 0, -1, 1 };

int mtx[MAXN][MAXN];
bool visited[MAXN][MAXN];

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nextX = x + nextL[i];
        int nextY = y + nextC[i];

        if (nextX >= 0 && nextX < l && nextY >= 0 && nextY < l) {
            if (!visited[nextX][nextY] && mtx[nextX][nextY] == 0) {
                mtx[nextX][nextY] = 2;
                dfs(nextX, nextY);
            }
        }
    }
}

int main() {
    int perim, island;
    int startX = 0, startY = 0;

    cin >> q;

    while (q--) {
        perim = 0;
        island = 0;


        cin >> l;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                visited[i][j] = false;


                cin >> mtx[i][j];

                if (mtx[i][j] == 1) {
                    perim++;
                }
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if ((i == 0 || i == (l - 1) || j == 0 || j == (l - 1)) && mtx[i][j] == 0 && !visited[i][j]) {
                    mtx[i][j] = 1;
                    dfs(i, j);
                }

                if (mtx[i][j] == 0) {
                    island++;
                }
            }
        }

        // for (int i = 0; i < l; i++) {
        //     for (int j = 0; j < l; j++) {
        //         cout << mtx[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << setprecision(2) << fixed << ((perim + island) / 2.0) << endl;
    }

    return 0;
}