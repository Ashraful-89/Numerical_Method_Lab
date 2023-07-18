#include<bits/stdc++.h>
using namespace std;

class FalsePositionMethod{
    public :
        double a , b, epsilon = 0.0001;
        double function_value(double x) {
            return pow(x,3) - 2 * x - 5;
        }
        double intersect(double a , double b) {
            return a - ((function_value(a) * ( b - a)) / (function_value(b) - function_value(a) ));
        }
        void solve() {
            srand(time(0));
            while(1) {
                a = rand() % 10 - 9;
                b = rand() % 10 ;
                if(function_value(a) * function_value(b) < 0) break;
            }

            double root;
            while (1)
            {
                 root = intersect(a,b);
                 printf("a  =  %9f  b =  %9f  and root  =  %9f\n ",a,b,root);

                 if(function_value(root) == 0.00) break;
                 if(function_value(root) * function_value(a) > 0){
                    a = root;
                 }
                 else b = root;
                 
                 if(abs(root - intersect(a,b)) < epsilon) break;
            }
            
            printf("a  =  %9f  b =  %9f  and root  =  %9f\n ",a,b,root);
            cout << " The root is : " << root << endl;
        }

};

int main() {
    FalsePositionMethod fal = FalsePositionMethod();
    fal.solve();
    return 0;
}