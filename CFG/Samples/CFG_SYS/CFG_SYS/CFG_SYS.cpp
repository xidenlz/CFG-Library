
#include "cfg_system.h"


// Instance 
MySettings Setttings;

int main()
{
    // We call Settings.Load_CFG() to check if there is a CFG file that needs to be loaded, If it's not found, we will create one with the default settings
    Setttings.Load_CFG();
    system("pause");
}
