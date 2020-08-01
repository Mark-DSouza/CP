#include <iostream>
#include <map>
using namespace std;

int main() {
    // empty map container
    map<int, int> map1;

    // insert elements in random order
    map1.insert(pair<int, int> (1, 40));
    map1.insert(pair<int, int> (2, 30));
    map1.insert(pair<int, int> (3, 60));
    map1.insert(pair<int, int> (4, 20));
    map1.insert(pair<int, int> (5, 50));
    map1.insert(pair<int, int> (6, 50));
    map1.insert(pair<int, int> (7, 10));

    // printing map map1
    cout << "\nThe map map1 is:\n";
    cout << "\tKEY\tELEMENT\n";
    for (auto it = map1.begin(); it != map1.end(); it++) 
        cout << '\t' << it -> first << '\t' << it -> second << endl;
    cout << endl;

    // assigning the elements from map1 to map2
    map<int, int> map2(map1.begin(), map1.end());

    // print all elements of the map map2
    cout << "\nThe map map2 after"
        << " assign from map1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto pair : map2)
        cout << '\t' << pair.first << '\t' << pair.second << endl;
    cout << endl;

    // remove all elements up to element with key=3 in map2
    cout << "\nmap2 after removal of"
            " elements with key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    map2.erase(map2.begin(), map2.find(3));
    for(auto pair : map2) 
        cout << '\t' << pair.first << '\t' << pair.second << endl;
    cout << endl;


    // remove all elements with key = 4
    int num;
    num = map2.erase(4);
    cout << "\nmap2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto pair : map2) 
        cout << '\t' << pair.first << '\t' << pair.second << endl;
    cout << endl;

    // lower bound and upper bound for map map1 key = 5
    cout << "map1.lower_bound(5) : "
         << "\tKEY = "; 
    cout << map1.lower_bound(5)->first << '\t'; 
    cout << "\tELEMENT = "
         << map1.lower_bound(5)->second << endl; 
    cout << "map1.upper_bound(5) : "
         << "\tKEY = "; 
    cout << map1.upper_bound(5)->first << '\t'; 
    cout << "\tELEMENT = "
         << map1.upper_bound(5)->second << endl;

    return 0;
}