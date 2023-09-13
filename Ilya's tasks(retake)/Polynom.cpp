#include<iostream>
using namespace std;

class Polynom{
int x, n, *data{}, result; 
public:
Polynom(){
	x = 0; n = 0;
	}
Polynom(int N, int X){
	n = N;
	x = X;
	data = new int[n];
	}
	
~Polynom(){
	delete[] data;
	}

void scan(){
	
	cout << "Input coeff:"<<endl;
	for(int i = 0; i < n; i++){
		cin >> data[i];
	} 
}

void print(){
		cout << result;
}

Polynom &operator =(const Polynom &ob){
	if(this == &ob) return *this;
	
	if(data) delete[] data;
	
	n = ob.n;
	x = ob.x;
	result = ob.result;
	
	data = new int[n];
	for(int i = 0; i < n; i++)
		data[i] = ob.data[i];

	return *this;
}

/*int poli(){
	result = data[0];
	
	for(int i = n-1; i > 0; i--){
		result=result*x + data[i];
	}
	return result;
}*/

Polynom poli(){
	Polynom temp(n,x);
	
	result = data[0];
	
	for(int i = 1; i < n; i++){
		temp.result=result*x + data[i];
	}
	return temp;
}

friend Polynom operator -=(const Polynom &ob1, const Polynom &ob2);
};
Polynom operator -=(const Polynom &ob1, const Polynom &ob2){
	Polynom temp(max(ob1.n,ob2.n), ob2.x);
	for(int i = 0; i < max(ob1.n,ob2.n); i++)
		temp.data[i] = 0;
	
	for(int i = 0; i < max(ob1.n,ob2.n); i++){
		temp.data[i] += ob1.data[i];
		temp.data[i] -= ob2.data[i];}
			for(int i = 0; i < max(ob1.n,ob2.n); i++){
		cout << temp.data[i] << endl;}
	return temp;
}


int main(){
	int n, x, n1, x1;
	cout << "Input n and x for ob1:";
	cin >> n >> x;
	
	Polynom ob1(n,x); 
	
	cout << "Input n and x for ob2:";
	cin >> n1 >> x1;
	
	Polynom ob2(n1,x1), ob3, ob4;
	ob1.scan();ob2.scan();
	ob2-=ob1;
	ob3 = ob2.poli();
	ob3.print();
	//ob3 = ob1.poli();
	//ob3.print();
}
