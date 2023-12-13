#include <array>
#include <fstream>
#include <iostream>
#include <libconfig.h++>
#include <string>

#include "../lib/Commands.hpp"
#include "../lib/Environment.hpp"
#include "../lib/Task.hpp"

std::string GetTaskPathFromConfigFile() {
    libconfig::Config cfg;
    try {
        cfg.readFile(GetCurrentExecutablePath() + "/doc/config.cfg");
    } catch (const libconfig::FileIOException &fioex) {
        std::cout << "I/O error while reading file.\n";
        return "ERROR!";
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << '\n';
        return "ERROR!";
    }
    try {
        std::string path = cfg.lookup("task_path");
        return path + '/';
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'Task Path' setting in configuration file.\n";
        return "ERROR!";
    }
}

void SetupUserEnvironment(std::array<std::string, 2> &envSettingsArray) {
    libconfig::Config cfg;
    std::string exec_path = GetCurrentExecutablePath();
    std::string path      = exec_path + "/doc/config.cfg";
    std::ofstream configFile(path);

    // Libconfig is easier to write, and easier to expand, but it
    // reads really bad.
    //
    // I prefere to write fstreams insted of libconfig expecially for something
    // this small

    if (configFile.is_open()) {
        configFile << "executable_path = \"" << exec_path << "\"\n";
        configFile << "task_path = \"" << envSettingsArray[0] << "\"\n";
        configFile << "date_format = \"" << envSettingsArray[1] << "\"\n";

        configFile.close();
        return;
    }
    std::cout << "\n Error trying to create or open config file.\n"
              << "There is a big chance its caused by the path.\n"
              << "Verify if the \"doc\" directory exists in \n"
              << "the project build.\n"
              << "Run \"set\" command or run the application again\n"
              << "to try rebuilding the config file\n\n";
    return;
};
