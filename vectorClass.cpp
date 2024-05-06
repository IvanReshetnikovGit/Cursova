#include<iostream>

using namespace std;

template <typename T> class vectorClass 
{
    T* arr;
    int capacity;
    int current;
 
public:
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    ~vectorClass() { delete[] arr; }
 
    void push(T data)
    {
        if (current == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }
 
    void push(T data, int index)
    {
 
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
 
    T get(int index)
    {
        return arr[index];
    }
    T &operator [](int index)
    {
        return arr[index];
    }
    void pop() { current--; }
 
    int size() { return current; }
 
    int getcapacity() { return capacity; }
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    typedef T* iterator;

    // Method to get the begin iterator
    iterator begin() {
        return arr;
    }

    // Method to get the end iterator
    iterator end() {
        return arr + current;
    }

};

