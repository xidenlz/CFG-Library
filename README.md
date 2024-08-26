<div align="center">

[![License](https://img.shields.io/badge/License-MIT-blue)](#license)
[![NuGet - CFG-Library v1.00](https://img.shields.io/badge/NuGet-CFG--Library_v1.00-blue?logo=nuget)](https://)
[![GitHub release](https://img.shields.io/github/release/xidenlz/CFG-Library?include_prereleases=&sort=semver&color=green)](https://github.com/xidenlz/CFG-Library/releases/)
[![issues - CFG-Library](https://img.shields.io/github/issues/xidenlz/CFG-Library)](https://github.com/xidenlz/CFG-Library/issues)
</div>

<div align="center">
     
[![Quilty - Built with Highly Optimized C++](https://img.shields.io/badge/Quilty-Built_with_Highly_Optimized_C%2B%2B-blue?logo=github)](https://)
</div>

### Table of Contents
1. Content
     - [Introduction](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#introduction)
     - [Overview](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#overview)
     - [Compatibility](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#compatibility)
     - [Usage](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#usage)
     - [Examples](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#examples)
     - [Data types](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#data-types)
     - [Installation](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#installation)
     - [Build](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#build)
     - [Buggs](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#buggs)
     - [Support My Work](https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#support-my-work)
     - [License](https://github.com/xidenlz/CFG-Library/blob/main/LICENSE)
     - [Samples](https://github.com/xidenlz/CFG-Library/blob/main/Samples/Examples/CFG.h)
     - [Release](https://github.com/xidenlz/CFG-Library/releases)
  


## Introduction
A simple settings library for use in different types of applications. Whether you're working with ImGui, a console app, or any other program that needs to handle user settings, this library uses the nlohmann::json library for storage. It creates a folder named MySettings in `C:\Users\User\AppData\Roaming`, where it saves a file called `Settings.json`.





### Overview
The library has 4 major functions:
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


- And the same goes for all data types. Please read the [samples](https://github.com/xidenlz/CFG-Library/blob/main/Samples/Examples/CFG.h)

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


### Build
- CMake
1. Create a new folder.
2. Open CMake and set the source folder to `CFG-Lib\Build`.
3. Configure the project, then generate the solution.

- Visual Studio
1. Navigate to the build folder.
2. Open the CFG_SYS.sln file.


### Buggs
If you encounter any bugs or issues, please create an issue [here](https://github.com/xidenlz/cfg_system/issues/new) and describe the problem.

### Support My Work
As a solo developer, I appreciate your support. If you find my work useful, a donation would be greatly valued.

<div align="center">
     
[![Donate - Bitcoin](https://img.shields.io/static/v1?label=Donate&message=Bitcoin&color=%23F7931A&logo=bitcoin)](https://raw.githubusercontent.com/xidenlz/CFG-Library/main/Assets/Donation/BTC.png?token=GHSAT0AAAAAACPJSWJTJTVRINRQD3ZIXQ4UZWLW3EQ)
[![Donate - Monero](https://img.shields.io/static/v1?label=Donate&message=Monero&color=%23FF6600&logo=monero)](https://raw.githubusercontent.com/xidenlz/CFG-Library/main/Assets/Donation/XMR.png?token=GHSAT0AAAAAACPJSWJTE6LKQZPU44ZMFQS2ZWLW2RQ)
[![Donate - USDT](https://img.shields.io/static/v1?label=Donate&message=USDT&color=%2350AF95&logo=tether)](https://raw.githubusercontent.com/xidenlz/CFG-Library/main/Assets/Donation/USDT_TRX.png?token=GHSAT0AAAAAACPJSWJTDNFZL6NSP3VI6D72ZWLW3JQ)
</div>

### License 
Released under [MIT](/LICENSE) by [@xidenlz](https://github.com/xidenlz).

