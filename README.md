
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/xidenlz/CFG-Library?tab=MIT-1-ov-file)
![Version](https://img.shields.io/badge/version-1.0.0-blue)
[![NuGet](https://badgen.net/badge/icon/nuget?icon=nuget&label)](https://https://nuget.org/)
[![Windows](https://badgen.net/badge/icon/windows?icon=windows&label)](https://microsoft.com/windows/)
![Issues](https://img.shields.io/github/issues/xidenlz/CFG-Library.svg)
[![GitHub release](https://img.shields.io/github/release/xidenlz/CFG-Library?include_prereleases=&sort=semver&color=blue)](https://github.com/xidenlz/CFG-Library/releases/tag/CFG-Lib)
![Forks](https://img.shields.io/github/forks/xidenlz/CFG-Library.svg)
![Followers](https://img.shields.io/github/followers/xidenlz.svg?style=social&label=Follow&maxAge=2592000)


## Introduction
A straightforward settings library designed for integration into various types of applications, Whether you're working with ImGui, a console program, or any other application requiring user settings management, this library relies on the [nlohmann::json](https://github.com/nlohmann/json) library for storage and creates a folder called MySettings in `C:\Users\User\AppData\Roaming` with a `Settings.json` file

### Table of Contents
1. Content
     - [Introduction](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#introduction)
     - [Overview](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#overview)
     - [Compatibility](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#compatibility)
     - [Usage](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#usage)
     - [Examples](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#examples)
     - [Data types](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#data-types)
     - [Installation](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#installation)
     - [Buggs](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#buggs)
     - [License](https://github.com/xidenlz/CFG-Library/blob/main/LICENSE)
     - [Samples]()
     - [Release]()
     - [NuGet]()



### Overview
The library has three major functions:
| Function  | Description |
| ------------- | ------------- |
| Load_CFG | Loads the configuration file when the program runs  |
| Save_CFG  |  Saves the current configuration when a button is clicked or when the function is called, This function can also be used in a thread to keep the configuration file up to date as the user makes changes  |
| Delete_CFG  | Deletes the saved configuration file when called  |
| ImportSettings  | Import the settings  |
| ExportSettings  | Exports the settings   |


### Compatibility 
- [x] ImGui                          
- [x] C++ Console Programs
- [x] GLFW
- [x] Qt 
- [x] wxWidgets
- [x] Win32 Gui

| **Data types support** |
| :---         |
| bool   |
| int   |
| float   |
| string   |
| ImColor   |


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

- Output
```json
{
    "CFG": {
        "C_Boolean": false,
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
### Data types 
- Exporting bool
```cpp
// bool 
{"C_Boolean", C_Boolean},
```

- Importing bool 
```cpp
// bool 
{"C_Boolean", C_Boolean},
```

- Exporting RGBA Values
```cpp
 {"C_ImColor", { C_ImColor.R, C_ImColor.G, C_ImColor.B, C_ImColor.A }} 
```

- Importing RGBA Values
 ```cpp
if (j.at("CFG").contains("C_ImColor"))
{
    const auto& color = j.at("CFG").at("C_ImColor");
    if (color.is_array() && color.size() == 4)
    {
        C_ImColor.R = color[0].get<float>();
        C_ImColor.G = color[1].get<float>();
        C_ImColor.B = color[2].get<float>();
        C_ImColor.A = color[3].get<float>();
    }
}
```


### Installation
1. Install [nlohmann json](https://github.com/nlohmann/json) via NuGet or simply include this header
2. You can install the library via NuGet, download it from the releases page, or include it by adding this header


### Buggs
If you encounter any bugs or issues, please create an issue [here](https://github.com/xidenlz/cfg_system/issues/new) and describe the problem.


### License 
This project is licensed under the [MIT License](https://github.com/xidenlz/cfg_system/blob/main/LICENSE).

