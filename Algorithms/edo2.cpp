#include <iostream>
#include<cmath>

using namespace std;

double f(double t, double y, double z){
    return 0.5 + pow(t,2) +t*z;
}

double euler2(double t0, double y0, double z0, double h){
    double t = t0, y = y0, z = z0;
    double old_z;

    cout << "n: 0   " << "t: " << t << "   y: " << y << "    z: " << z << endl;
    for(int i = 1; i <= 2; i++){           //aqui e dois porque queremos n de 0 a 2
        old_z = z;
        z += h* f(t,y,z);
        y+= h * old_z;
        t += h;
        cout << "n: " << i << "     t: " << t << "   y: " << y << "    z: " << z << endl;
    }

    cout << endl << endl;
    return y;
}


double rk4ordem2(double t0, double y0, double z0, double h){
    double t = t0, y = y0, z = z0;
    double dz1, dz2, dz3, dz4, dy1, dy2, dy3, dy4;
    double old_z;

    cout << "n: 0   " << "t: " << t << "   y: " << y << "    z: " << z << endl;
    for(int i = 1; i <= 2; i++ ){
        old_z = z;

        dz1 = h * f(t,y,z);
        dy1 = h* old_z;

        dz2 = h* f(t+h/2, y +dy1/2, z + dz1/2);
        dy2 = h * (old_z+dz1/2);

        dz3 = h* f(t + h/2, y +dy2/2, z+dz2/2);
        dy3 = h* (old_z+dz2/2);

        dz4 = h*f(t+h,y+dy3,z+dz3);
        dy4 = h*(old_z+dz3);


        z += dz1/6 + dz2/3 + dz3/3 + dz4/6;
        y += dy1/6 + dy2/3 + dy3/3 + dy4/6;
        t += h;

        cout << "n: " << i << "    t: " << t << "   y: " << y << "    z: " << z << endl;
    }

    return y;
}


int main() {
    euler2(0,0,1,0.25);
    rk4ordem2(0,0,1,0.25);

    return 0;
}