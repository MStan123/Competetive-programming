#include <iostream>
using namespace std;

int main()
{
    int Fibo1 = 1, Fibo2 = 2, Fibo3 = 0;
    int sum = 0;
    
	while (Fibo2 <= 4000000){
        Fibo3 = Fibo1 + Fibo2;
        if (Fibo2 % 2 == 0)
			sum += Fibo2;
        Fibo1 = Fibo2;
        Fibo2 = Fibo3;
    }
    cout << sum;
    return 0;
}
