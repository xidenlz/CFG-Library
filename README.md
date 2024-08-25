## Config Library
A straightforward settings library designed for integration into various types of applications, Whether you're working with ImGui, a console program, or any other application requiring user settings management, this library relies on the [nlohmann::json](https://github.com/nlohmann/json) library for storage and creates a folder called MySettings in `C:\Users\User\AppData\Roaming` with a `Settings.json` file

### Table of Contents
1. Content
     - [Overview](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#overview)
     - [Compatibility](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#compatibility)
     - [Usage](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#usage)
     - [Examples](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#examples)
     - [Installation](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#installation)
     - [Buggs](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#buggs)
     - [License](https://github.com/xidenlz/cfg_system/tree/main?tab=readme-ov-file#license)
     - [Release]()



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



| **Data type** | **Export** | **Import** |
| :---         | :---       | :---  |
| bool   | Output    | Input    |
| int   | Export    | Import    |
| float   | Export    | Import    |
| string   | Export    | Import    |
| ImColor   | Export    | Import    |

- Full output
```json
{
    "CFG": {
        "C_Boolean": false,
        "C_Float": 15.0,
        "C_ImColor": [
            255.0,
            0.0,
            0.0,
            1.0
        ],
        "C_Int": 0,
        "C_String": "Default"
    }
}
```
### Examples 
- If you are working with a console program or a GUI program, simply include the `cfg_system` in your initialization header, then create a new instance and call it with the following function as shown:
```cpp
// Instance
MySettings Settings;

// Your init function
Settings.Load();


// ImGui
if (ImGui::Button("Save Settings"))
{
   // And the same goes to Delete_CFG, Load_CFG
   Settings.Save_CFG();
}
```

### Installation
1. Install [nlohmann json](https://github.com/nlohmann/json) via NuGet or simply include this header
2. You can install the library via NuGet, download it from the releases page, or include it by adding this header


### Buggs
If you encounter any bugs or issues, please create an issue [here](https://github.com/xidenlz/cfg_system/issues/new) and describe the problem.


### License 
This project is licensed under the [MIT License](https://github.com/xidenlz/cfg_system/blob/main/LICENSE).

