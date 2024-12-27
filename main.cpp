#include "src/shapeClasses.hpp"
#include "src/sort.hpp"
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main(){

    vector<Shapes*> array;

    array.push_back(new Circle(5.0));               // 78.5
    array.push_back(new Rectangle(4.0, 6.0));       // 24
    array.push_back(new Triangle(3.0, 8.0));        // 12
    array.push_back(new Circle(2.0));               // 12.56
    array.push_back(new Rectangle(7.0, 2.0));       // 14

    cout << "Initial array: \n";

    printArray(array);

    thread quick(quick_sort, ref(array));
    thread merget(merge_sort, ref(array));
    thread bubble(bubble_sort, ref(array));

    quick.join();
    merget.join();
    bubble.join();

    for (Shapes* shape : array){
        delete shape;
    }

    return 0;
}
