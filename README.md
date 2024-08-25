## Config Library
A straightforward settings library designed for integration into various types of applications, Whether you're working with ImGui, a console program, or any other application requiring user settings management, this library relies on the [nlohmann::json](https://github.com/nlohmann/json) library for storage and creates a folder called MySettings in `C:\Users\User\AppData\Roaming` with a `Settings.json` file

### Overview
The library has three major functions:
| Function  | Description |
| ------------- | ------------- |
| Load | Loads the configuration file when the program runs  |
| Attempt_Save  |  Saves the current configuration when a button is clicked or when the function is called, This function can also be used in a thread to keep the configuration file up to date as the user makes changes  |
| Delete_Config  | Deletes the saved configuration file when called  |
| FromJson  | Exports the settings  |
| ToJson  | Imports the settings   |


### Compatibility 
- [x] ImGui
- [x] C++ Console Programs
- [x] GLFW
- [x] Qt 
- [x] wxWidgets
- [x] Win32 Gui

### Usage 
- Pass variables according to their definition type, For example, if you need to pass a variable of type bool, use it as shown below:
```cpp
    void ImportSettings(const nlohmann::json& j)
    {
        C_Boolean = j.at("CFG").at("C_Boolean").get<bool>(); 
    }

    nlohmann::json ExportSettings()
    {
        return nlohmann::json
        {
            {"CFG", {
                // bool 
                {"C_Boolean", C_Boolean}
            }}
        };
    }
```


- And the same goes for all data types. Please read the samples:
1. Import ImColor
2. Import bool
3. Import float
4. Import int
5. import string

### Installation
Install [nlohmann json](https://github.com/nlohmann/json) via NuGet or simply include this header THIS IS REQIRED 
include this header into your project or install it via NuGet from here

### Buggs
If you encounter any bugs or issues, please create an issue here and describe the problem.
### License 
This project is licensed under the MIT License.

