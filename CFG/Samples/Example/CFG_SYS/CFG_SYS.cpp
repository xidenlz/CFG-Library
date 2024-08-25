/*
                                 MIT License

                           Copyright (c) 2024 xdenlz

      Permission is hereby granted, free of charge, to any person obtaining a copy
      of this software and associated documentation files (the "Software"), to deal
      in the Software without restriction, including without limitation the rights
      to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
      copies of the Software, and to permit persons to whom the Software is
      furnished to do so, subject to the following conditions:

      The above copyright notice and this permission notice shall be included in all
      copies or substantial portions of the Software.

      Kindly do not remove the copyright notice from any copies of the Software.

      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
      IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
      FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
      AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
      LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
      SOFTWARE.

*/


#include "cfg_system.h"


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
