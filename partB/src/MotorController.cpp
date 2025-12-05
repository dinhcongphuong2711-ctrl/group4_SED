#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

#include "OUSB.cpp"

class MotorController
{
private:
    OUSB usb;
    int pwm = 0;
    int target;

public:
    MotorController(int targetADC = 500)
    {
        target = targetADC;
        usb.setPWMFreq(1, 46);
        usb.setPWM(1, 0);
    }

    void startLoop()
    {
        ofstream log("data/motor_log.csv");
        log << "Time,PWM,ADC,Error\n";

        cout << "Starting feedback loop… (target = " << target << ")\n";

        for (int t = 0; t < 40; t++)
        {
            int adc = usb.readADC(0);

            int error = target - adc;

            if (error > 0)
                pwm += 2;
            else
                pwm -= 2;

            if (pwm < 0)
                pwm = 0;
            if (pwm > 100)
                pwm = 100;

            usb.setPWM(1, pwm);

            cout << "[t=" << t << "] PWM=" << pwm
                 << "% | ADC=" << adc
                 << " | error=" << error << endl;

            log << t << "," << pwm << "," << adc << "," << error << "\n";

            this_thread::sleep_for(chrono::milliseconds(500));
        }
        log.close();

        cout << "Loop finished. Log saved.\n";
    }
};
