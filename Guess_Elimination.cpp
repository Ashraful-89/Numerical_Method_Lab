#include<bits/stdc++.h>
using namespace std;

class Elimination{
    public : 
        double x[10],M[10][10];
        int n;
        void solve() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= n; j++) {
                    cin >> M[i][j];
                }
            }
            for(int i = 0; i < n -1 ; i++) {
                if(M[i][i] == 0) {
                    cout << " Error ";
                    break;
                }
                for(int j = i + 1; j < n; j++) {
                    double ratio = M[j][i] / M[i][i];
                    for(int k = 0; k <= n; k++) {
                        M[j][k] -= M[i][k] * ratio;
                    } 
                }
            }

            x[n-1] = M[n-1][n] / M[n-1][n-1];
            for(int i = n -2 ; i >= 0; i--) {
                x[i] = M[i][n];
                for(int j = i + 1; j < n ; j++) {
                    x[i] -= M[i][j] * x[j];
                }
                x[i] = x[i] / M[i][i];
            }
            for(int i = 0; i <n; i++) {
                cout << "x" << i + 1 << "  = "<< x[i] << endl;
            }

        }

};
int main() {
    Elimination b = Elimination();
    b.solve();
    return 0;
}