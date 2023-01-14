#include <iostream>

using namespace std;

#define MAX_SPEED 200

class cruise_control {
private:
    float mem_speed;
    float now_speed;
public:
    cruise_control(float init_speed); //Constructor 
    ~cruise_control();  //Destructor
    void set_speed(float tar_speed);
    float get_now_speed(void);
    float get_mem_speed(void);
    void recovery_speed();
};

cruise_control::cruise_control(float init_speed)
{
    if (init_speed <= MAX_SPEED) {
        mem_speed = init_speed;
        now_speed = init_speed;
    } else {
        mem_speed = 0;
        now_speed = 0;
    }
}

cruise_control::~cruise_control()
{
}

void cruise_control::set_speed(float tar_speed)
{
    if (tar_speed <= MAX_SPEED) {
        mem_speed = now_speed;
        now_speed = tar_speed;
    }
}

float cruise_control::get_now_speed(void)
{
    return now_speed;
}

float cruise_control::get_mem_speed(void)
{
    return mem_speed;
}

void cruise_control::recovery_speed(void)
{
    now_speed = mem_speed;
}

int main(void)
{
    cruise_control commander(30);

    commander.set_speed(50);
    cout << "mem_speed:" << commander.get_mem_speed() << endl;
    cout << "now_speed:" << commander.get_now_speed() << endl;

    commander.set_speed(120);
    cout << "mem_speed:" << commander.get_mem_speed() << endl;
    cout << "now_speed:" << commander.get_now_speed() << endl;

    commander.recovery_speed();
    cout << "mem_speed:" << commander.get_mem_speed() << endl;
    cout << "now_speed:" << commander.get_now_speed() << endl;

    return 0;
}
