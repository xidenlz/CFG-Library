# Config System 
Straightforward settings system that can be integrated into various types of applications, whether you're using ImGui, a console program, or any other application that requires user settings management, It utilizes the nlohmann::json library for storage and provides features for exporting and importing settings.
### Briefing
The system has three major functions:
- **Load:** Loads the configuration file when the program runs
- **Attempt Save:** Saves the current configuration when a button is clicked or when the function is called. This function can also be used in a thread to keep the configuration file up to date as the user makes changes
- **Delete CFG:** Deletes the saved configuration file when called




## Usage example 
I have already provided some samples [here](https://github.com/xidenlz/CONFIG_SYSTEM/blob/3f8e04b782009b3f0a5b5c3eebb12f13fe71aa05/CFG/Samples/Example/CFG_SYS/CONFIG.h#L82) to give an overview of the usage, and I will explain it briefly here.
