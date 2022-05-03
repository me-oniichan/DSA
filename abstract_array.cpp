#include <iostream>
using namespace std;

template <class T>
class AbstractArr
{
    T *arr = (T *)malloc(sizeof(T));

public:
    int size = 0;
    void push_back(T);
    T at(int);
    void pop(int index = -1);
    int find(T);
};

template <class T>
void AbstractArr<T>::push_back(T value)
{
    size++;
    arr = (T *)realloc(arr, size * sizeof(T));
    arr[size-1] = value;
}

template <class T>
T AbstractArr<T>::at(int index)
{
    return arr[index];
}

template <class T>
void AbstractArr<T>::pop(int index)
{
    if (index == -1) index = size;
    size--;
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr = (T *)realloc(arr, size * sizeof(T));
}

template <class T>
int AbstractArr<T> :: find(T value){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value) return i;
    }
    return -1;   
}

int main()
{
    AbstractArr<float> obj;
    obj.push_back(1.3);
    obj.push_back(2.0);
    obj.push_back(3.5);
    obj.push_back(4);
    obj.push_back(5);
    obj.pop();
    
    for (int i = 0; i < 4; i++){
        cout<<obj.at(i)<<" ";
    }
    cout<<endl<<obj.find(2.0);
    return 0;
}