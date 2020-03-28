#include <iostream>
#include <fstream>

using namespace std;

struct Val {
    int nr;
    string um;
}mat[100][100];

int n = 0;


int srch(string um) {
    for(int i = 1; i <= n; i++) {
        if(mat[i][0].um == um) {
            return i;
        }
    }
    return -1;
}

void bfs(int start, int n, int v[100], int& nrEl) {
    int p = 1, u = 1, q[100], viz[100], x;

    for(int i = 0; i <= n; i++) {
        viz[i] = 0;
    }

    q[1] = start;
    viz[start] = 1;
    while(p <= u) {
        x = q[p];
        p++;
        for(int i = 1; i <= n; i++) {
            if(viz[i] == 0 && (mat[x][i].nr != 0 || mat[i][x].nr != 0)) {
                u++;
                q[u] = i;
                viz[i] = 1;
            }
        }
    }

    nrEl = u;
    for(int i = 1; i <= nrEl; i++) {
        v[i] = q[i];
    }

}

void citire() {
int nr1, nr2;
string um1, um2, egal;
ifstream fin("test.txt");

while(fin >> nr1 >> um1 >> egal >> nr2 >> um2) {
    cout << nr1 << ' ' << um1 << ' ' << egal << ' ' << nr2 << ' ' << um2 << endl;

    if(nr1 > nr2) {
        int aux;
        aux = nr1;
        nr1 = nr2;
        nr2 = aux;
        string aux1;
        aux1 = um1;
        um1 = um2;
        um2 = aux1;
    }

    nr2 = nr2/nr1;
    nr1 = 1;

    if(srch(um1) == -1) {
        n++;
        mat[n][0].um = um1;
    }

    if(srch(um2) == -1) {
        n++;
        mat[n][0].um = um2;
    }

    mat[srch(um1)][srch(um2)].nr = nr2;

}

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            mat[i][j].um = mat[i][0].um;
        }
    }

    string umStart, umFinal;
    int nrUm;

    cout << "Introduceti valoarea unitatii de masura din care doriti sa convertiti, unitatea de masura din care doriti sa convertiti si unitatea de masura in care doriti sa convertiti\n";
    cin >> nrUm >> umStart >> umFinal;

    int v[100], nrEl = 0;
    float link = 1;
    bfs(srch(umStart), n, v, nrEl);
    int ok = 0;

    for(int i = 2; i <= nrEl; i++) {
        if(v[i] == srch(umFinal)) {
            ok = 1;
        }
        if(mat[v[i-1]][v[i]].nr != 0) {
             link = link * mat[v[i-1]][v[i]].nr;
        }
        else if(mat[v[i]][v[i-1]].nr != 0) {
             link = link / mat[v[i]][v[i-1]].nr;
        }
        if(ok == 1) {
            break;
        }
    }

    if(ok == 1) {
        cout << nrUm << ' ' << umStart << " = " << link * nrUm << ' ' << umFinal << endl;
    }
    else {
        cout << "Nu se poate face conversia!\n";
    }

}



int main()
{


    citire();

    return 0;
}
