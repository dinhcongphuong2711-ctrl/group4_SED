#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class OUSB
{
public:
    string runCommand(const string &cmd)
    {
        FILE *pipe = popen(cmd.c_str(), "r");
        if (!pipe)
            return "ERR";

        char buffer[128];
        string result = "";
        while (fgets(buffer, 128, pipe) != NULL)
            result += buffer;

        pclose(pipe);
        return result;
    }

    int readADC(int channel)
    {
        string cmd = "ousbMotorSim.exe -r adc " + to_string(channel);
        string out = runCommand(cmd);
        try
        {
            return stoi(out);
        }
        catch (...)
        {
            return -1;
        }
    }

    void setPWM(int channel, int duty)
    {
        string cmd = "ousbMotorSim.exe -r pwm " + to_string(channel) + " " + to_string(duty);
        runCommand(cmd);
    }

    void setPWMFreq(int channel, int freq)
    {
        string cmd = "ousbMotorSim.exe -r pwm-freq " + to_string(channel) + " " + to_string(freq);
        runCommand(cmd);
    }
};
