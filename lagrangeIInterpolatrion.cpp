#include<bits/stdc++.h>
using namespace std;

class LagrangeInterpolation{
    public:
        int n;
        double x[10],y[10];
        double ans, given_x;

        LagrangeInterpolation() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                cin >> x[i] >> y[i];
            }
            cin >> given_x;
        }
        void solve() {
            for(int i = 0; i < n; i++) {
                double temp_ans = y[i];
                for(int j = 0; j < n; j++) {
                    if(i != j)
                    temp_ans *= (given_x - x[j]) / (x[i] - x[j]);
                }
                ans = ans + temp_ans;
            }
            cout << ans << endl;
        }
        

};
int main() {
    LagrangeInterpolation b = LagrangeInterpolation();
    b.solve();
    return 0;
}