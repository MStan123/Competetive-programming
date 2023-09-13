#include <iostream>
#include <cmath>
using namespace std;


int sign_func(int x)
{
	return (x > 0) - (x < 0);
}

class Sto{

	int *data;
	int size, sign;
	public:
    
	Sto(int asize)
	{ 
	size=asize; 
	data = new int[size];
	sign=1;
	}
	
	~Sto(){ delete[] data; }

	Sto& operator=(const Sto& ob)
	{
			
		if (this == &ob)
		return *this;
			
		if (data) delete[] data;
			
		size=ob.size;
		sign=ob.sign;
			
		data=new int[size]; 
		for(int i=0;i<size;i++)
		data[i]=ob.data[i];

		return *this;
	}
	    
	friend Sto operator+(const Sto &x, const Sto &y);
	friend Sto operator*(const Sto &x, const int &chislo);
	friend int compare(const Sto &x,const Sto &y);
			
void scan()
	{	
	    cout<<"Vvedite "<<size<<" cifri\n";

	    for(int i=0; i<size; i++){
	        cin>>*(data+i);}
	  	
		if(data[0]==0) sign=1;
		else 
		{
		sign = sign_func(data[0]);
		data[0]=abs(data[0]);
		}
	}
	    
	void print(){
		int x_p=0;
	    while(data[x_p]==0) x_p++; 

		cout<<sign*data[x_p]<<" ";
		for(int i=x_p+1; i<size; i++) 
			cout<<data[i]<<" ";
	}
};

int compare(const Sto &x,const Sto &y){
		int major = 1;  
		
		if(x.sign != y.sign)
		{
			if(x.size < y.size) major = -1;
			if(x.size == y.size)
			{
				for(int i = 0; i < x.size; i++) 
					if(x.data[i] != y.data[i]) 
					{
						if(x.data[i] < y.data[i]) major = -1; 
						break;
					}
			}
		}
	return major;
}

Sto operator+(const Sto &x, const Sto &y){
	Sto z(max(x.size,y.size)+1); 
	int x_i=x.size-1, y_i=y.size-1, z_i=max(x_i, y_i)+1, tmp=0, major;

    major = compare(x,y);
	
	if((x.sign==-1 && major==1) || (y.sign==-1 && major==-1)) z.sign=-1;

	while(z_i>=0)
	{
		z.data[z_i] =0;
		
		if(x.sign==y.sign)
		{
			if(x_i>=0) z.data[z_i] += x.data[x_i];
			if(y_i>=0) z.data[z_i] += y.data[y_i];
			
			z.data[z_i]+= tmp;
			if(z.data[z_i] >= 100) {z.data[z_i]-=100; tmp = 1;} else tmp=0;
		}
		else
		{
			if(x_i>=0) z.data[z_i] += major * x.data[x_i];
			if(y_i>=0) z.data[z_i] -= major * y.data[y_i];
			
			z.data[z_i]-=tmp;	
			if(z.data[z_i] < 0) {z.data[z_i]+=100; tmp = 1;} else tmp=0;
		}

		x_i--; y_i--;z_i--;
	}
return z;
}

Sto operator*(const Sto &x, const int &chislo){

Sto z(x.size + 1 + log(abs(chislo))/log(100) + 1);
int x_i=x.size-1, z_i=z.size-1, temp=0;

z.sign=1;
if(x.sign * chislo < 0) z.sign=-1;

while(z_i>=0)
{
	z.data[z_i] = temp;
	if(x_i>=0) z.data[z_i] += x.data[x_i]*abs(chislo);

	temp = z.data[z_i]/100;
	z.data[z_i] = z.data[z_i]%100;
	x_i--; z_i--;
}
return z;
}

int main(){
	int size_x,size_y, number;
    
    cout<<"Vvedite razmer 1-go massiva"<<endl;
	cin>>size_x;
	Sto ob1(size_x);
	ob1.scan();
	
	cout<<"\nVvedite razmer 2-go massiva"<<endl;
	cin>>size_y;
    Sto ob2(size_y);
	ob2.scan();
	Sto ob3(max(size_x,size_y)+1);
	ob3 = ob1 + ob2;

	cout<<"\nVvedite konstantu"<<endl;
	cin>>number;

	Sto ob4(size_x + 1 + log(abs(number))/log(100)+1);
	ob4 = ob1 * number;
	
	cout<<"\nSlojeniye dvux storichnix chisel: "; ob3.print();
	cout<<"\nUmnojeniye ob1 na konstantu: "; ob4.print();
return 0;
}
