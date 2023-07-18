#include<bits/stdc++.h>
using namespace std;
class Curvefitting {
    public:
        int n;
        double x[10],y[10],a,b;
        double sumX = 0, sumY = 0, sumXX = 0, sumXY = 0;
        void solve() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                cin >> x[i] >> y[i];
            }

            for(int i = 0; i < n; i++) {
                sumX += x[i];
                sumXX += x[i] * x[i];
                sumY += y[i];
                sumXY += x[i] * y[i];
            }
            b = ((sumXY - (sumX * sumY) / n) / (sumXX - (sumX * sumX)/n));
            a = (sumY - b * sumX) / n;
            cout << "Y = " << a << " +  " << b << "x" << endl;
        

        }

};

int main() {
  Curvefitting c = Curvefitting();
  c.solve();
    return 0;
}