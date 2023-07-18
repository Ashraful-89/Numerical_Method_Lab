#include<bits/stdc++.h>
using namespace std;

class curvefitting{
    public:
    double size;
    double a,b;
    double x[100],y[100];
    curvefitting(){
        cin >> size;
        for(int i = 0; i < size; i++){
            cin >> x[i] >> y[i];
        } 
    }
    void solve() {
        double sumX = 0, sumY = 0, sumXX = 0, sumXY = 0;
        for(int i = 0 ; i < size; i++){
            sumX += x[i];
            sumY += y[i];
            sumXX += x[i] * x[i];
            sumXY += x[i] * y[i];
        }
        b = ((size * sumXY - sumY * sumX)/(size * sumXX - sumX * sumX));
        a = (sumY - b * sumX)/size;
        cout << "Y = " << a << " + ()" << b << ")x" << endl;
    }
    
};

int main() {
    curvefitting b = curvefitting();
    b.solve();
    return 0;
}