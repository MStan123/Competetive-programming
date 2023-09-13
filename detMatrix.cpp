#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Matrix{
	int n;
	double **data;
	public:
	Matrix(int N){
		n = N;
		data = new double *[n];
		for (int i = 0; i < n; i++)
        data[i] = new double[n];
	}
	
	~Matrix(){
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
    }

	void scan()
	{
		cout<<"Input "<<n * n<<" numbers\n";

	    for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
	        cin>>data[i][j];}
		}
		cout<< endl;
	}
	
    void display()
	{
		for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
				cout<<data[i][j]<<" ";}
				cout << "\n";
		}
		cout<< endl;
	}
	
	Matrix(const Matrix &ob)
	{
	    n=ob.n;
		
	    data = new double *[n];
		for (int i = 0; i < n; i++)
        data[i] = new double[n];
        
	    for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			data[i][j]=ob.data[i][j];
			}
		}
	}
	
float determinant() {
    double det = 1, pivot;

    for (int i = 0; i < n; i++) {
        pivot = data[i][i];
        if (pivot == 0) {
            return 0;
        }
        for (int j = i+1; j < n; j++) {
            double factor = data[j][i] / pivot;
            for (int k = i; k < n; k++) {
                data[j][k] -= factor * data[i][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        det *= data[i][i];
    }

    return det;
}
};

int main(){
	int n;
	cout << "Size of matrix is:" << endl;
	cin >> n;

	Matrix ob1(n);
	ob1.scan();
	ob1.display();    
	float det = ob1.determinant();
    cout << "Determinant of matrix is: " << fixed << setprecision(0) <<det << endl;

    return 0;
}
