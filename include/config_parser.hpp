#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "interpreter.hpp"

#include "widgets/widget.hpp"
#include "types.h"
#include "json.hpp"

#define CONFIG_ROOT "/EdiZon/editor/"

using json = nlohmann::json;

class Interpreter;

class ConfigParser {
public:
    ConfigParser() = delete;

    static s8 hasConfig(u64 titleId);
    static s8 loadConfigFile(u64 titleId, std::string filepath, Interpreter **interpreter);
    static void unloadConfigFile();
    static void createWidgets(WidgetItems &widgets, Interpreter &interpreter, u8 configIndex);

    static inline std::unordered_map<u64, bool> g_editableTitles;
    static inline std::unordered_map<u64, bool> g_betaTitles;
    static inline std::string g_currConfigAuthor = "";

    template<typename T>
    static inline T getOptionalValue(json j, std::string key, T elseVal) {
        return j.find(key) != j.end() ? j[key].get<T>() : elseVal;
    }

    static inline json& getConfigFile() {
      return m_configFile;
    }

private:
    static inline json m_configFile;
    static inline u8 m_useInsteadTries;

};
