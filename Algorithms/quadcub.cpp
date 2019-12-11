#include <iostream>
#include<cmath>
#include<iomanip>

#define PI 3.14159265359

using namespace std;


double f1(double x){
    return sqrt(1+1.5*exp(1.5*x)*1.5*exp(1.5*x));
}


double trapezio(double a, double b, double n){
    int trapProcessados = 0;
    double h = (b-a)/n;
    double x  = a;
    double area = 0;

    while(trapProcessados < n) {
        area += (f1(x) + f1(x + h)) * h / 2;
        x += h;
        trapProcessados++;
    }

    return area;
}


double simpson(double a, double b, double n){
    int trapProcessados = 1;
    double area = 0;
    double h = (b-a)/n;
    double x = a+h;

    while(trapProcessados < n){
        if(trapProcessados%2 == 0){
            area += 2*f1(x);
        }
        else{
            area += 4*f1(x);
        }
        x += h;
        trapProcessados++;
    }

    area  = (f1(a)+f1(b) +area) * (h/3);

    return area;
}


void QC(string tipo) {

    if (tipo == "trapezio") {

    double r1 = trapezio(0, 2, 4);
    double r2 = trapezio(0, 2, 8);
    cout << "r2: " << r2 << endl;
    double r3 = trapezio(0, 2, 16);
    cout << "r3: " << r3 << endl;

    cout << "QC: " << (r2 - r1) / (r3 - r2) << endl;

    double erro = (r3 - r2) / 3;
    cout << "Erro: " << erro << endl << endl;
    }
    else if (tipo == "simpson") {

        double r1 = simpson(0, 2, 4);
        double r2 = simpson(0, 2, 8);
        cout<< "r2: " << r2 << endl;
        double r3 = simpson(0, 2, 16);
        cout << "r3: " << r3 << endl;

        cout << "QC: " << (r2 - r1) / (r3 - r2) << endl;

        double erro = (r3 - r2) / 15;
        cout << "Erro: " << erro << endl << endl;
    }


}


/*
 cubTrapezio:
 (hx*hy/4)*(sum0+2*sum1+4*sum2);

 cubSimpson:
 (hx*hy/9)*(1sum0+4*sum1+16*sum2);


 sum0: vertices
 sum1: arestas
 sum2: centro
 */


int main() {
    string a = "trapezio", b = "simpson";

    cout << "Trapazio: " << setprecision(7 ) << trapezio(0, 2, 4) << endl;
    QC(a);

    cout << "Simpson: " << setprecision(7) <<simpson(0, 2, 4) << endl;
    QC(b);

    return 0;
}