#include <iostream>
#include <vector>

using namespace std;

void function1() {
    vector<int> v;

    for (int i = 1; i <= 5; i++)
        v.push_back(i);

    cout << "Output of begin and end: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Output of rbegin and rend: ";
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Output of cbegin and cend: ";
    for (auto it = v.cbegin(); it != v.cend(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Output of crbegin and crend: ";
    for (auto it = v.crbegin(); it != v.crend();it++) 
        cout << *it << " ";
    cout << endl;

    return;
}

void function2() {
    vector<int> v;
    for (int i = 1; i <= 5; i++)
        v.push_back(i);

    cout << "\nSize: " << v.size();
    cout << "\nCapacity: " << v.capacity();
    cout << "\nMax Size: " << v.max_size();

    // resize the vector to 4 elements
    v.resize(4);
    cout << "\nSize: " << v.size();
    
    // shrink capacity of vector to size i.e. 4
    v.shrink_to_fit();

    // check if the vector is empty
    if (v.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    cout << "\nThe elements of the vector are: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return;
}

void function3() {
    vector<int> v;

    for (int i = 1; i <= 5; i++) 
        v.push_back(i);
    
    cout << "\nReference operator [n] : v[2] = " << v[2];
    cout << "\nat : v.at(4) = " << v.at(4);
    cout << "\nfront() : v.front() = " << v.front();
    cout << "\nback() : v.back() = " << v.back();

    // pointer to the first element
    int* pos = v.data();

    cout << "\nThe first element is " << *pos; 
    return;
}

void function4() {
    // Assign vector
    vector<int> v;

    // fill the array with 10 five times
    v.assign(5, 10);

    cout << "\nThe vector elements are: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    
    v.push_back(15);
    int n = v.size();
    cout << "\nThe last element is: " << v[n-1];

    // remove last element
    v.pop_back();

    // prints the vector
    cout << "\nThe vector elements are: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    
    // inserts 5 at the beginning
    v.insert(v.begin(), 5);

    cout << "\nThe first element is: " << v[0];

    // removes the first element
    v.erase(v.begin());

    cout << "\nThe first element is: " << v[0];

    // inserts at the beginning
    v.emplace(v.begin(), 5);
    cout << "\nThe first element is: " << v[0];

    // inserts 20 at the end
    v.emplace_back(20);
    n = v.size();
    cout << "\nThe last element is: " << v[n-1];

    // erases the vector
    v.clear();
    cout << "\nVector size after clear(): " << v.size();

    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    
    cout << "\nVector 2: ";
    for (int i: v2)
        cout << i << " ";
    
    // Swaps v1 and v2
    v1.swap(v2);

    cout << "\nAfter Swap \nVector 1: ";
    for (int i:v1)
        cout << i << " ";

    cout << "\nVector 2: ";
    for (int i:v2)
        cout << i << " ";
    
}

int main() {
    // function1();
    // function2();
    // function3();
    function4();
    return 0;
}