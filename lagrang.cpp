#include<bits/stdc++.h>
using namespace std;

class lagrangInterpolation{
    public :
        int n;
        double  x[10],y[10], given_x;
        void solve() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                cin >> x[i] >> y[i];
            }
           cin >> given_x ;
          // given_x = exp(given_x);
           double ans = 0;
           double temp;
           for(int i = 0; i < n; i++) {
            temp = y[i];
            for(int j = 0; j < n; j++) {
                if(i != j)
                temp *= (given_x - x[j]) / (x[i] - x[j]);
            }
            ans += temp;
           }
           cout << "The ans is : " << ans << endl;
        }
};
int main() {
  lagrangInterpolation lg = lagrangInterpolation();
  lg.solve();
  return 0;
}
