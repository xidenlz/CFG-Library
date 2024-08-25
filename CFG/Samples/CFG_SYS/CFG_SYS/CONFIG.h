#pragma once
#include "Json.h"
#include "Globals.h"
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>

namespace CONFIG
{
    void validate_path(std::filesystem::path path)
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
        auto file_path = std::filesystem::path(std::getenv("appdata")); // C:\Users\User\AppData\Roaming
        file_path /= "MySettings";

        validate_path(file_path);

        return file_path;
    }
}



struct MySettings
{
public:
    nlohmann::json default_options;
    nlohmann::json options;

    bool DeepCompare(nlohmann::json& current_settings, const nlohmann::json& default_settings, bool compare_value = false)
    {
        bool should_save = false;

        for (auto& e : default_settings.items())
        {
            const std::string& key = e.key();

            if (current_settings.count(key) == 0 || (compare_value && current_settings[key] != e.value()))
            {
                current_settings[key] = e.value();
                should_save = true;
            }
            else if (current_settings[key].is_object() && e.value().is_object())
            {
                if (DeepCompare(current_settings[key], e.value(), compare_value))
                    should_save = true;
            }
            else if (!current_settings[key].is_object() && e.value().is_object())
            {
                current_settings[key] = e.value();
                should_save = true;
            }
        }

        return should_save;
    }

    std::filesystem::path Get_Path()
    {
        auto file_path = CONFIG::GetAppdataFolder();
        file_path /= "Settings.json";
        return file_path;
    }



    void FromJson(const nlohmann::json& j)
    {
        try
        {
            // Pass our settings 
            Vars.C_Aimbot = j.at("CFG").at("C_Aimbot").get<bool>(); // Since C_Aimbot is a boolean, we retrieve and assign it as such.
            Vars.C_Smooth = j.at("CFG").at("C_Smooth").get<float>(); // Similarly, C_Smooth is a float, so we retrieve and assign it accordingly.
           

            // Color Example 
            auto EspColor = j.at("CFG").at("C_Color").get<std::vector<float>>();
            if (EspColor.size() == 3)
            {
                Vars.C_Color[0] = EspColor[0];
                Vars.C_Color[1] = EspColor[1];
                Vars.C_Color[2] = EspColor[2];
            }
        }
        catch (nlohmann::json::exception& Json_Exception)
        {
            std::cerr << "Error parsing JSON: " << Json_Exception.what() << std::endl;
        }
    }



    nlohmann::json ToJson()
    {
        return nlohmann::json{
            {"CFG",
            {
                // Pass our settings
                {"C_Aimbot", Vars.C_Aimbot},
                {"C_Smooth", Vars.C_Smooth},
                {"C_Color", {Vars.C_Color[0], Vars.C_Color[1], Vars.C_Color[2]}} 
            }}
        };
    }





    bool Save()
    {
        auto file_path = Get_Path();
        try
        {
            std::ofstream file(file_path, std::ios::out | std::ios::trunc);
            if (!file)
            {
                std::cerr << "Unable to open file for saving: " << file_path << std::endl;
                return false;
            }
            file << ToJson().dump(4);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error saving file: " << e.what() << std::endl;
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

        auto file_path = Get_Path();
        std::ifstream file(file_path);

        if (!file.is_open())
        {
            std::cerr << "File not found, Creating new CFG File." << std::endl;
            Save();
            file.open(file_path);
        }

        try
        {
            file >> options;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error loading JSON: " << e.what() << std::endl;
            file.close();
            Save();
            return Load();
        }

        file.close();

        bool should_save = DeepCompare(options, default_options);
        FromJson(options);

        if (should_save)
        {
            Save();
        }

        return true;
    }



    void Delete_Config()
    {
        std::filesystem::path config_path = Get_Path();

        if (std::filesystem::exists(config_path))
        {
            std::filesystem::remove(config_path);
        }
    }
};