#include <iostream>
#include <string>
using namespace std;

#include "TrafficLight.cpp"

class Intersection
{
private:
    string name;

public:
    TrafficLight north, south, east, west;

    Intersection(string n = "Unknown")
        : north(5, 2, 5), south(5, 2, 5), east(5, 2, 5), west(5, 2, 5)
    {
        name = n;
    }

    string getName() const { return name; }

    void tickAll()
    {
        north.tick();
        south.tick();
        east.tick();
        west.tick();
    }

    void show() const
    {
        cout << "\n===== Intersection: " << name << " =====\n";
        cout << "North : " << north.getStateString() << endl;
        cout << "South : " << south.getStateString() << endl;
        cout << "East  : " << east.getStateString() << endl;
        cout << "West  : " << west.getStateString() << endl;
    }
};
