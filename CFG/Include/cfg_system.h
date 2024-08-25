/*
                                 MIT License

                           Copyright (c) 2024 xdenlz
                      https://github.com/xidenlz/cfg_system
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



/*
 * NOTE
 * This won't work without nlohmann json.
 * Please install it and then include the header.
 */



#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>

namespace CONFIG
{
    void ValidatePath(std::filesystem::path path)
    {
        if (!std::filesystem::exists(path))
        {
            std::filesystem::create_directory(path);
        }
        else if (!std::filesystem::is_directory(path))
        {
            std::filesystem::remove(path);
            std::filesystem::create_directory(path);
        }
    }

    std::filesystem::path GetAppdataFolder()
    {
#pragma warning(disable : 4996)
        auto File_Path = std::filesystem::path(std::getenv("appdata")); // C:\Users\User\AppData\Roaming
        File_Path /= "MySettings"; // Settings folder name

        ValidatePath(File_Path);

        return File_Path;
    }
}



struct MySettings
{
public:
    nlohmann::json default_options;
    nlohmann::json options;

    bool DeepCompare(nlohmann::json& current_settings, const nlohmann::json& default_settings, bool compare_value = false)
    {
        bool Should_Save = false;

        for (auto& e : default_settings.items())
        {
            const std::string& Key = e.key();

            if (current_settings.count(Key) == 0 || (compare_value && current_settings[Key] != e.value()))
            {
                current_settings[Key] = e.value();
                Should_Save = true;
            }
            else if (current_settings[Key].is_object() && e.value().is_object())
            {
                if (DeepCompare(current_settings[Key], e.value(), compare_value))
                    Should_Save = true;
            }
            else if (!current_settings[Key].is_object() && e.value().is_object())
            {
                current_settings[Key] = e.value();
                Should_Save = true;
            }
        }

        return Should_Save;
    }

    std::filesystem::path Get_Path()
    {
        auto File_Path = CONFIG::GetAppdataFolder();
        File_Path /= "Settings.json"; // Settings file name
        return File_Path;
    }


    // Export Settings to  C:\Users\ * User * \AppData\Roaming\MySettings\Settings.json
    void FromJson(const nlohmann::json& j)
    {
        try
        {
            // Export Example 
            // Vars.C_Aimbot = j.at("CFG").at("C_Aimbot").get<bool>(); // Since C_Aimbot is a boolean, we retrieve and assign it as such.

           

            // Color Example Export
            //auto EspColor = j.at("CFG").at("C_Color").get<std::vector<float>>();
            //if (EspColor.size() == 3)
            //{
            //    Vars.C_Color[0] = EspColor[0];
            //    Vars.C_Color[1] = EspColor[1];
            //    Vars.C_Color[2] = EspColor[2];
            //}
        }
        catch (nlohmann::json::exception& j)
        {
            std::cerr << "Error parsing JSON: " << j.what() << std::endl;
        }
    }



    // Import our settings 
    nlohmann::json ToJson()
    {
        return nlohmann::json
        {
            {"CFG",{ // Namespace 

                    // Import Example
                    // 
                    // {"C_Aimbot", Vars.C_Aimbot},
                    // 
                    // Color Import 
                    // {"C_Color", {Vars.C_Color[0], Vars.C_Color[1], Vars.C_Color[2]}} 
            }}
        };
    }





    bool Save()
    {
        auto File_Path = Get_Path();
        try
        {
            std::ofstream File(File_Path, std::ios::out | std::ios::trunc);
            if (!File)
            {
                std::cerr << "Unable to open File for saving: " << File_Path << std::endl;
                return false;
            }
            File << ToJson().dump(4);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error saving File: " << e.what() << std::endl;
            return false;
        }
        return true;
    }

    void Attempt_Save()
    {
        const nlohmann::json& j = ToJson();
        if (DeepCompare(options, j, true))
            Save();
    }

    bool Load()
    {
        default_options = ToJson();

        auto File_Path = Get_Path();
        std::ifstream File(File_Path);

        if (!File.is_open())
        {
            std::cerr << "File not found, Creating new CFG File." << std::endl;
            Save();
            File.open(File_Path);
        }

        try
        {
            File >> options;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error loading JSON: " << e.what() << std::endl;
            File.close();
            Save();
            return Load();
        }

        File.close();

        bool Should_Save = DeepCompare(options, default_options);
        FromJson(options);

        if (Should_Save)
        {
            Save();
        }

        return true;
    }



    void Delete_Config()
    {
        std::filesystem::path CFG_Path = Get_Path();

        if (std::filesystem::exists(CFG_Path))
        {
            std::filesystem::remove(CFG_Path);
        }
    }
};