#include <iostream>
#include <cmath>
using namespace std;

class Product{
	int rows, cols, data[10][10];
	public:
	Product(int arows, int acols){
		rows = arows;
		cols = acols;
	}
	
	friend Product operator*(const Product& ob1, const Product& ob2);

	void scan()
	{
		cout<<"Vvedite "<<cols * rows<<" cifri\n";

	    for(int i=0; i< rows; i++){
			for(int j=0; j< cols; j++){
	        cin>>data[i][j];}
		}
		cout<< endl;
	}
	
	void print()
	{
		for(int i=0; i< rows; i++){
			for(int j=0; j< cols; j++){
				cout<<data[i][j]<<" ";}
				cout << "\n";
		}
		cout<< endl;
	}
};

Product operator*(const Product& ob1, const Product& ob2)
{
	Product temp(ob1.rows,ob2.cols);
		
	for (int i = 0; i < ob1.rows; i++) 
	{
      for (int j = 0; j < ob2.cols; j++)
      {
        temp.data[i][j] = 0;
		for (int k=0; k< ob2.rows; k++)
		{
			temp.data[i][j] += ob1.data[i][k]*ob2.data[k][j];
		}
	  }
	}
	return temp;
}

int main(){
	int r1, r2, c1, c2;
	cout << "Parameters of 1st matrix" << endl;
	cin >> r1 >> c1;
	cout << "Parameters of 2st matrix" << endl;
	cin >> r2 >> c2;

	Product ob1(r1,c1), ob2(r2,c2), ob3(r1,c2);
	ob1.scan(); ob1.print(); 
	ob2.scan();ob2.print(); 
	ob3 = ob1*ob2;
	ob3.print();
}
