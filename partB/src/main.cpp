#include <iostream>
#include <string>
using namespace std;

#include "SystemManager.cpp"
#include "MotorController.cpp"

int main()
{
    SystemManager traffic;
    MotorController motor(500);

    while (true)
    {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Traffic System - Show\n";
        cout << "2. Traffic System - Tick 1s\n";
        cout << "3. Traffic System - Add Intersection\n";
        cout << "4. Motor Control - Start Loop\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";

        int c;
        cin >> c;

        if (c == 1)
            traffic.show();
        else if (c == 2)
        {
            traffic.tick();
            cout << "Simulated 1s.\n";
        }
        else if (c == 3)
        {
            cout << "Enter name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            traffic.add(name);
        }
        else if (c == 4)
        {
            motor.startLoop();
        }
        else if (c == 0)
            break;
    }

    return 0;
}
