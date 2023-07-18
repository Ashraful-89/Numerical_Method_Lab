#include<bits/stdc++.h>
using namespace std;

class NewtonRaphsonMethod{
    public :
        double root, epsilon = 0.0001;

        double functionValue(double x) {
            return pow(x,3) + 2 * x + 5;
        }
        double DerivativeValue(double x) {
            return 3 * x * x + 2;
        }
        void solve() {
            srand(time(0));
            while(1){
                root = rand() % 10;
                if(DerivativeValue(root) != 0) break;
            }
            double newRoot;
            int k = 1;
            while(1) {
                printf("Iteration : %d  and Root = %9f \n" , k++,root);
                
                if(functionValue(root) == 0.00) break;
                newRoot = root - (functionValue(root) / DerivativeValue(root));
                if(abs(root - newRoot) < epsilon) break;
                root = newRoot;
                if(DerivativeValue(root) == 0) root++;
            }

            printf("Iteration : %d  and Root = %9f \n" , k++,newRoot);
            cout << "The root value is : " << newRoot << endl;
        }

};
int main() {
    NewtonRaphsonMethod newTon = NewtonRaphsonMethod();
    newTon.solve();
}