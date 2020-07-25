#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Student {
    public:
        int value;
        Student(): value(0) {}
        Student(int val): value(val) {}
};

bool comp(const Student &x, const Student &y) {
    return x.value < y.value;
}

// int main() {
//     vector<Student> Class;
//     for (int i = 0; i < 10; i++ ) {
//         Class.push_back(Student(rand()));
//     }

//     vector<Student>::iterator it;
//     for (it = Class.begin(); it != Class.end(); it++)
//         cout << it -> value << " ";
//     cout << endl;

//     sort(Class.begin(), Class.end(), comp);
//     for (it = Class.begin(); it != Class.end(); it++)
//         cout << it -> value << " ";
//     cout << endl;

//     return 0;
// }

int main() {
    vector<Student> Class;
    for (int i = 0; i < 10; i++) {
        Class.push_back(Student(rand() / 100000));
    }

    for (const Student &x: Class)
        cout << x.value << " ";
    cout << endl;

    sort(Class.begin(), Class.end(), comp);
    for (const Student &x: Class)
        cout << x.value << " ";
    cout << endl;

    return 0;
}