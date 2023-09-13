#include <iostream>
using namespace std;

class vector{
public:
	double x,y,z;
vector(){x=0; y=0; z=0;}
vector(double X, double Y, double Z){x=X; y=Y; z=Z;}
};

class Product : public vector{
	public:
	Product(){x=0; y=0; z=0;}
	Product(double X, double Y, double Z){x=X; y=Y; z=Z;}

void print(){
	cout<<"The Product of 2 vectors is:"<< x <<" "<< y <<" "<< z <<endl;
}
};

Product operator*(const Product &a, const Product &b){
	Product temp;
	temp.x=(a.y)*(b.z)-(a.z)*(b.y);
	temp.y=(a.z)*(b.x)-(a.x)*(b.z);
	temp.z=(a.x)*(b.y)-(a.y)*(b.x);
	return temp;
}	

int main(){
Product a(1.1,1.2,1.3), b(2.1,2.2,2.3); 
Product s;
s=a*b;
s.print();
}
