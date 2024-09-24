#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        int XLL1, YLL1, XUR1, YUR1;
        int XLL2, YLL2, XUR2, YUR2;

        cin >> XLL1 >> YLL1 >> XUR1 >> YUR1;
        cin >> XLL2 >> YLL2 >> XUR2 >> YUR2;
        
        int XLL_overlap = max(XLL1, XLL2);
        int YLL_overlap = max(YLL1, YLL2);
        int XUR_overlap = min(XUR1, XUR2);
        int YUR_overlap = min(YUR1, YUR2);

        if (XLL_overlap < XUR_overlap && YLL_overlap < YUR_overlap) {
            cout << XLL_overlap << " " << YLL_overlap << " " << XUR_overlap << " " << YUR_overlap << endl;
        } else {
            cout << "No Overlap" << endl;
        }

        if (tc > 0) {
            cout << endl;
        }
    }
    return 0;
}