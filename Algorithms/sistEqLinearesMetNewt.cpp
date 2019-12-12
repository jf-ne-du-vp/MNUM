#include <iostream>
#include<cmath>

using namespace std;

//exame 2016/2017   ex:2

double f1(double x, double y){
    return pow(x,2)-y-1.2;
}

double f2(double x, double y){
    return -x+pow(y,2)-1;
}

double f1x(double x, double y){
    return 2*x;
}

double f1y(double x, double y){
    return -1;
}

double f2x(double x, double y){
    return -1;
}

double f2y(double x, double y){
    return 2*y;
}

void newton(double x0, double y0, double numIt){
    double x = x0;
    double y = y0;


    for(int i  = 1; i <= numIt; i++){
        x0 = x;
        y0 = y;
        y -= ((f2(x0,y0) * f1x(x0,y0) - f1(x0,y0) * f2x(x0,y0)) / (f1x(x0,y0) * f2y(x0,y0) - f2x(x0,y0) * f1y(x0,y0)));
        x -= ((f1(x0,y0) * f2y(x0,y0) - f2(x0,y0) * f1y(x0,y0)) / (f1x(x0,y0) * f2y(x0,y0) - f2x(x0,y0) * f1y(x0,y0)));
        cout << "it: " << i << "   x: " << x << "    y: " << y << endl;
    }
}

int main() {
    newton(1,1,2);
    return 0;
}