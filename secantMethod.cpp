#include<bits/stdc++.h>
using namespace std;

class SecantMethod{

    public :
        double a,b, epsilon = 0.0001;
        double function_value(double x) {
            return pow(x,3) + 2 * x + 5;
        }
        double secant(double a , double b) {
            return a - (function_value(a) * (a -b)) /(function_value(a) - function_value(b));
        }
        double root;
        void solve(){
            while(1) {
                srand(time(0));
                a = rand()% 10 -9;
                b = rand() % 10;
                if(function_value(a) * function_value(b) < 0) break;
            }

            root  = secant(a,b);
            while(1) {
                printf(" a = %9f  b =  %9f    root = %9f\n " , a, b,root);

                if(function_value(root) == 0.0) break;
                if(abs(root - secant(root , a)) < epsilon) break;
                if(function_value(root) * function_value(a) > 0)
                    a = root;
                else b = root;
                root = secant(a,b);

            }
            root = secant(root,a);
            printf(" a = %9f  b =  %9f    root = %9f\n " , a, b,root);
            cout << "The root is : " << root;
        }


};
int main() {
    SecantMethod se = SecantMethod();
    se.solve();
    return 0;
}