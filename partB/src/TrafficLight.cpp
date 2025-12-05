#include <iostream>
#include <string>
using namespace std;

enum LightState
{
    RED,
    YELLOW,
    GREEN
};

class TrafficLight
{
private:
    LightState state;
    int timeGreen, timeYellow, timeRed;
    int remaining;

public:
    TrafficLight(int g = 5, int y = 2, int r = 5)
    {
        timeGreen = g;
        timeYellow = y;
        timeRed = r;
        state = RED;
        remaining = timeRed;
    }

    void setState(LightState s)
    {
        state = s;
        if (s == GREEN)
            remaining = timeGreen;
        else if (s == YELLOW)
            remaining = timeYellow;
        else
            remaining = timeRed;
    }

    void tick()
    {
        remaining--;
        if (remaining <= 0)
        {
            if (state == GREEN)
                setState(YELLOW);
            else if (state == YELLOW)
                setState(RED);
        }
    }

    string getStateString() const
    {
        if (state == RED)
            return "RED";
        if (state == YELLOW)
            return "YELLOW";
        return "GREEN";
    }
};
