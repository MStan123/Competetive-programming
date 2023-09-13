#include <iostream>
using namespace std;

class Transpose{
	int cols, rows, *data;
public:
	Transpose(int acols, int arows)
	{
		acols = cols;
		arows = rows;
	}
	void scan()
	{	
	    cout<<"Vvedite "<<cols * rows<<" cifri\n";

	    for(int i=0; i< cols * rows; i++){
	        cin>>*(data+i);}
	}
	
	void print()
	{
		for(int i=0; i<cols * rows; i++) 
			cout<<data[i]<<" ";
	}
	
	int **transpose(const int * const * m, int rows, int cols){
	int** data = new int*[cols];
    for (int i = 0; i != cols; ++i)
        data[i] = new int[rows];
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            data[i][j] = m[j][i];
        }
    }
    return data;}
};

int main(){
	int num_of_cols, num_of_rows;
	cin>> num_of_cols >> num_of_rows;
	
	Transpose ob(num_of_cols, num_of_rows);
	
	ob.scan();
	ob.transpose(*data, num_of_rows, num_of_cols);
	ob.print();
}
