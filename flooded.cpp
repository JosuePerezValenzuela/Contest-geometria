#include <bits/stdc++.h>

using namespace std;

int main() {
    int numeroRegion = 1, n, m, elevacion, volumenAgua;

    while (cin >> n >> m && n != 0 && m != 0) {
        vector<int> elevaciones;
        for (int i = 0; i < n * m; ++i) {
            cin >> elevacion;
            elevaciones.push_back(elevacion);
        }
        cin >> volumenAgua;
        sort(elevaciones.begin(), elevaciones.end());
        double nivelAgua = elevaciones[0];
        int celdasSumergidas = 0;
        double volumenRestante = volumenAgua;
        int lim = n * m;
        for (int i = 1; i < lim; ++i) {
            double volumenNecesario = (elevaciones[i] - elevaciones[i - 1]) * i * 100.0;
            if (volumenRestante >= volumenNecesario) {
                volumenRestante -= volumenNecesario;
                nivelAgua = elevaciones[i];
                celdasSumergidas = i;
            } else {
                nivelAgua += volumenRestante / (i * 100.0);
                celdasSumergidas = i;
                volumenRestante = 0;
                break;
            }
        }
        if (volumenRestante > 0) {
            nivelAgua += volumenRestante / (n * m * 100.0);
            celdasSumergidas = n * m;
        }
        double porcentajeSumergido = (double) celdasSumergidas / (n * m) * 100.0;
        cout << "Region " << numeroRegion++ << endl;
        cout <<fixed << setprecision(2) << "Water level is " << nivelAgua << " meters." << endl;
        cout << porcentajeSumergido << " percent of the region is under water." << endl << endl;
    }
    return 0;
}