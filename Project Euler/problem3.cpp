#include <iostream>
using namespace std;

int main()
{
	long int num = 600851475143;
	int large = 0;

	for( int i=2; i<=num; ++i)
	{
		while(num%i==0)
		{
			num/=i;
			large = i;
		}
	}
	cout<<large;
	return 0;
}
