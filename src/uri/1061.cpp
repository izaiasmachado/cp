/**
 * Descrição   : BEECROWD 1061 - Tempo de um Evento
 * Autor(a)    : Izaias Machado
 * Data        : 18/04/2019
 */
 
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string aux;
    int diaAntes, horasAntes, minutosAntes, segundosAntes;
    int diaDepois, horasDepois, minutosDepois, segundosDepois;

    cin >> aux >> diaAntes;
    cin >> horasAntes >> aux >> minutosAntes >> aux >> segundosAntes;

    cin >> aux >> diaDepois;
    cin >> horasDepois >> aux >> minutosDepois >> aux >> segundosDepois;

    int segundosTotaisAntes = diaAntes * 86400 + horasAntes * 3600 + minutosAntes * 60 + segundosAntes;
    int segundosTotaisDepois = diaDepois * 86400 + horasDepois * 3600 + minutosDepois * 60 + segundosDepois;
    int segundosTotais = segundosTotaisDepois - segundosTotaisAntes;

    int dias = segundosTotais / 86400;
    segundosTotais = segundosTotais % 86400;
    int horas = segundosTotais / 3600;
    segundosTotais = segundosTotais % 3600;
    int minutos = segundosTotais / 60;
    segundosTotais = segundosTotais % 60;
    int segundos = segundosTotais;

    cout << dias << " dia(s)" << endl;
    cout << horas << " hora(s)" << endl;
    cout << minutos << " minuto(s)" << endl;
    cout << segundos << " segundo(s)" << endl;

    return 0;
}
