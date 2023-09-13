#include <iostream>
using namespace std;
class Loman
{
private:
	int i=0;
    int size;
    int* data;
public:
    Loman(int asize) {
        size = 2*asize;
        data = new int[size];
    }
    ~Loman(){
        delete[] data;
        cout<<"Object destroyed\n";
    }
    Loman(const Loman &ob)
    {
        size = ob.size;
        data = new int [size];
        for(int i=0; i<ob.size; i++)
            data[i] = ob.data[i];
    }
    void print(){
        for(i=0; i<size; i++){
            cout<<*(data+i)<<" ";
        }
        cout<<endl;
    }
 
    void scan(){
        cout<<"Input "<<size/2<<" coordinates\n";
        for(int i=0; i<size; i++){
            cin>>*(data+i);
        }
    }
    Loman operator+(Loman& ob){
        this->size = size;
        Loman tmp((size + ob.size)/2);
        for(i=0; i<size; i++)
        {
            tmp.data[i]=*(data + i);//this->data[i]=data[i];
        }
        for(i=size; i<size + ob.size; i++) tmp.data[i] = ob.data[i-size];
        return tmp;
    }
    void swap(Loman& a) {
        std::swap(size, a.size);
        std::swap(data, a.data);
    }
 
    Loman& operator=(const Loman& a)
    {
            Loman tmp(a);
            swap(tmp);
        return *this;
    }
};
int main(){
    Loman first(3);
    Loman second(2);
    first.scan();
    second.scan();
    Loman third(5);
    third=first+second;
    third.print();
    return 0;
}
