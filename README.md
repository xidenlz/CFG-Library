# Config System 
Straightforward settings system that can be integrated into various types of applications, whether you're using ImGui, a console program, or any other application that requires user settings management, It utilizes the nlohmann::json library for storage and provides features for exporting and importing settings.
### Briefing
**The system have 3 major functions**

1. **Load:** This function loads the CFG once the cheat runs.
```cpp
    bool Load()
    {
        default_options = ToJson();

        auto file_path = Get_Path();
        std::ifstream file(file_path);

        if (!file.is_open())
        {
            std::cerr << "File not found, Creating new CFG File." << std::endl;
            Save();
            file.open(file_path);
        }
```




2. **Attempt Save:** Once the user clicks a button in ImGui, it will save the current CFG, you can also use it in a thread to keep the CFG always up to date whenever the user changes something in their CFG
```cpp
    void Attempt_Save()
    {
        const nlohmann::json& j = ToJson();
        if (DeepCompare(options, j, true))
            Save();
    }
```


3. **Delete CFG:** Once this function is called, it will delete the saved CFG
```cpp
    void Delete_Config()
    {
        std::filesystem::path config_path = Get_Path();

        if (std::filesystem::exists(config_path))
        {
            std::filesystem::remove(config_path);
        }
    }
```



## Usage example 
I have already provided some samples [here](https://github.com/xidenlz/CONFIG_SYSTEM/blob/3f8e04b782009b3f0a5b5c3eebb12f13fe71aa05/CFG/Samples/Example/CFG_SYS/CONFIG.h#L82) to give an overview of the usage, and I will explain it briefly here.
