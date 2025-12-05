#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Intersection.cpp"
#include "User.cpp"

class SystemManager
{
private:
    vector<Intersection> list;

public:
    SystemManager() { load(); }

    void load()
    {
        list.clear();
        ifstream f("data/intersections.txt");

        string name;
        while (getline(f, name))
        {
            if (!name.empty())
                list.push_back(Intersection(name));
        }
    }

    void save()
    {
        ofstream f("data/intersections.txt");
        for (auto &i : list)
            f << i.getName() << "\n";
    }

    void add(const string &name)
    {
        list.push_back(Intersection(name));
        save();
    }

    void show()
    {
        for (auto &i : list)
            i.show();
    }

    void tick()
    {
        for (auto &i : list)
            i.tickAll();
    }
};
