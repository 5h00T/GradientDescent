#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_TIMES 1000
#define EPSILON 0.01
#define ALPHA 0.05

using namespace std;

double f(double x){
    return pow(x, 4) / 4 + pow(x, 3) / 3 - 3 * pow(x, 2);
}

double df(double x){
    return pow(x, 3) + pow(x, 2) - 6 * x;
}

int main(void){
    double x[MAX_TIMES];
    double grad[MAX_TIMES];
    double y[MAX_TIMES];
    double alpha;
    
    cout << "初期点x0:"; cin >> x[0];
    cout << "学習率α:"; cin >> alpha;

    for(int i = 0; i < MAX_TIMES ; i++){

        grad[i] = df(x[i]);
        y[i] = f(x[i]);
        cout << fixed;
        cout << "i:" << i << '\t' << "x[i]:" << x[i] << '\t' << "df[i]:" << grad[i] << '\t' << "f[i]:" << y[i] <<endl;
        if(abs(grad[i]) < EPSILON){
            break;
        }

        x[i+1] = x[i] - alpha * grad[i];
    }

    return 0;
}
