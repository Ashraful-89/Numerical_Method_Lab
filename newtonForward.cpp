#include<bits/stdc++.h>
using namespace std;


class NewtonForwardInterpolation{
    public:
        int n;
        double x[10],y[10][10];
        double ans, given_x ;
        NewtonForwardInterpolation() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                cin >> x[i] >> y[i][0];
            }
            cin >> given_x ;
        }

        int factorial(int n) {
            if(n){
                return n * factorial(n-1);
            }
            else 
                return 1;
        }
        double multply(double u, int n) {
            double value = u;
            for(int i = 1; i < n; i++) {
                value = value * (u-i);
            }
            return value;
        }

        void solve() {
            for(int col = 1; col < n; col++) {
                for(int row = 0; row < n - col ; row++) {
                    y[row][col] = y[row+1][col-1] - y[row][col-1];
                }
            }

            ans = y[0][0];
            double h = (x[1] - x[0]);
            double u = (given_x - x[0]) / h;

            for(int i = 1 ; i < n; i++) {
                ans += (multply(u,i) * y[0][i]) / factorial(i); 
            }
            cout << "Output is = " << ans << endl;
        }

};

int main() {
    NewtonForwardInterpolation nfi = NewtonForwardInterpolation();
    nfi.solve();
    return 0;
}