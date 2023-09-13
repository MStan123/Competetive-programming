#include <iostream>
using namespace std;

class Qu{
private:
double a,b,c,d;
public:
Qu(){a=0; b=0; c=0; d=0;}
Qu(double n, double w, double z, double m){a=n; b=w; c=z; d=m;}
friend Qu operator*(const Qu &x, const Qu &y);
void print(){
cout<< a <<" "<< b <<" "<< c <<" "<< d <<endl;	
}
};
Qu operator*(const Qu &x, const Qu &y){
Qu temp;
temp.a = (x.a)*(y.a)-(x.b)*(y.b)-(x.c)*(y.c)-(x.d)*(y.d);
temp.b = (x.a)*(y.b)-(x.b)*(y.a)+(x.c)*(y.d)+(x.d)*(y.c);
temp.c = (x.a)*(y.c)-(x.b)*(y.d)+(x.c)*(y.a)-(x.d)*(y.b);
temp.d = (x.a)*(y.d)-(x.b)*(y.c)+(x.c)*(y.b)+(x.d)*(y.a);
return temp;
}

int main(){
Qu a(1.1, 1.2, 1.3, 1.4), b(2.1, 2.2, 2.3, 2.4);
Qu s;
s= a*b;
s.print();
}
