#include<bits/stdc++.h>
using namespace std;

class NewtonForwardInterpolation{
    public :
        double x[10],y[10][10], given_x, ans = 0;
        int n;
        NewtonForwardInterpolation() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                cin >> x[i] >> y[i][0];
            }
            cin >> given_x ;

        }
        int factorialFunction(int n) {
            if(n)  
                return n * factorialFunction(n-1);
            else 
                return 1;
        }
        double multiply(double u , int n) {
                double value = u;
                for(int i = 1; i < n; i++) {
                    value = value * (u-i);
                }
                return value;
        }
        void solve() {
            for(int col = 1; col < n; col++){
                for(int row = 0; row < n - col; row++) {
                    y[row][col] = y[row+1][col-1] - y[row][col-1];
                }
            }
            ans = y[0][0];
            double h = x[1] - x[0];
            double u = (given_x - x[0])/h;
            for(int i = 1; i < n; i++) {
                ans += (multiply(u,i)*y[0][i])/ factorialFunction(i);
            }
            cout << "The output is : " << ans << endl;
        }
};
int main() {
    NewtonForwardInterpolation n = NewtonForwardInterpolation();
    n.solve();
    return 0;
}