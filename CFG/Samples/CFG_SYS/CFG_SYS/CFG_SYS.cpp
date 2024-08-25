
#include "CONFIG.h"


// Instance 
MySettings Setttings;

int main()
{
    // We call Settings.Load() to check if there is a CFG file that needs to be loaded, If it's not found, we will create one with the default settings
    Setttings.Load();
    system("pause");


    // If the user wants to save their config, there will be an ImGui button that, when clicked, will call Settings.Attempt_Save();
    /*
        if (ImGui::Button("Save current config"))
            Settings.Attempt_Save();
    */

    // To load the config, we will use Settings.Load();

    // To delete the config, we will use Settings.Delete_Config();

}
