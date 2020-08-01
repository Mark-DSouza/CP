#include <iostream>
#include <list>
using namespace std;

void showList(list <int> &l) {
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << '\t' << *it;
    }
    cout << endl;
}

int main() {
    list<int> list1, list2;

    for (int i = 0; i < 10; i++) {
        list1.push_back(i * 2);
        list2.push_front(i * 3);
    }

    cout << "List 1 (list1) is:";
    showList(list1);

    cout << "List 1 (list1) is:";
    showList(list2);

    cout << "list1.front(): ";
    cout << list1.front() << endl;

    cout << "list2.front(): ";
    cout << list2.front() << endl;

    cout << "list1.pop_front():";
    list1.pop_front();
    showList(list1);

    cout << "list2.pop_back():";
    list2.pop_back();
    showList(list2);

    cout << "list1.reverse():";
    list1.reverse();
    showList(list1);

    cout << "list2.sort():";
    list2.sort();
    showList(list2);

    return 0;
}