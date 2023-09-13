#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class peresec {
public:
    double x, y;
};

bool intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double v1, v2, v3, v4;
    v1 = (x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3);
    v2 = (x4 - x3)*(y2 - y3) - (y4 - y3)*(x2 - x3);
    v3 = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
    v4 = (x2 - x1)*(y4 - y1) - (y2 - y1)*(x4 - x1);
    if ((v1*v2 <= 0) && (v3*v4 <= 0)) return true;
    else return false;
}

void f(peresec *a, int n)
{
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 2; j < n - 1; j++)
        {
            if (intersect(a[i].x, a[i].y, a[i + 1].x, a[i + 1].y, 
                          a[j].x, a[j].y, a[j + 1].x, a[j + 1].y))
            {
                fout << 1;
                return;
            }
        }
    fout << 0;
    return;
}

int main()
{
	long long count;
	peresec *a;
     if( !(fin >> count)){fout<<0; return 0;}
     fin.seekg(0);
    
    
     fin >> count;
     if(count == 0) {fout<<0; return 0;}
    
     a = new peresec[count];
	for(int  i = 0; i < count; i++){ fin >> a[i].x; fin >> a[i].y;}

    f(a,count);

    return 0;
}
