#include <filesystem>
#include <fstream>
#include <iostream>
#include <libconfig.h++>
#include <string>

#include "../lib/Commands.hpp"
#include "../lib/Environment.hpp"
#include "../lib/Task.hpp"

Task::Task(std::string label,
           uint id,
           std::string name,
           std::string dueDate,
           std::string description)
    : LABEL(label),
      id(id),
      name(name),
      dueDate(dueDate),
      description(description) {
    SaveTask();
};

uint GenerateTaskID() {
    uint generatedID       = 0;
    const std::string path = GetCurrentExecutablePath() + "/doc/config.cfg";
    libconfig::Config cfg;

    try {
        cfg.readFile(path);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file.\n";
        return generatedID;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << "\n";
        return generatedID;
    }

    libconfig::Setting &root = cfg.getRoot();
    if (!root.exists("ID")) {
        root.add("ID", libconfig::Setting::TypeString) =
            std::to_string(generatedID);
    }
    generatedID = atoi(root.lookup("ID")) + 1;
    root.remove("ID");
    root.add("ID", libconfig::Setting::TypeString) =
        std::to_string(generatedID);

    try {
        cfg.writeFile(path);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while writing id to file.\n";
        return 0;
    }

    return generatedID;
}

Task::~Task(){};

void Task::SaveTask() {
    if (LABEL == "all" ||
        LABEL == "-a") {  // This may inflict with the "show" command;
        std::cout << "Invalid label\n";
        return;
    }

    std::string path       = GetTaskPathFromConfigFile();
    std::string outputFile = path + LABEL + ".cfg";
    bool directory         = std::filesystem::create_directory(path) ||
                     std::filesystem::is_directory(path);
    if (!directory) {
        std::cout << "Error creating directory: " << path << '\n';
        return;
    }
    std::fstream myFile(path + LABEL + ".cfg", std::ios::app);
    myFile.close();  // This is so it creates the file before cfg tries to read
                     // it else it throws fioex

    libconfig::Config cfg;
    cfg.setOptions(libconfig::Config::OptionFsync |
                   libconfig::Config::OptionSemicolonSeparators |
                   libconfig::Config::OptionColonAssignmentForGroups |
                   libconfig::Config::OptionOpenBraceOnSeparateLine);

    try {
        cfg.readFile(outputFile);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return;
    }
    libconfig::Setting &root = cfg.getRoot();
    if (!root.exists("Tasks")) {
        root.add("Tasks", libconfig::Setting::TypeList);
    }

    libconfig::Setting &tasks = root["Tasks"];
    libconfig::Setting &task  = tasks.add(libconfig::Setting::TypeGroup);

    task.add("ID", libconfig::Setting::TypeString)      = std::to_string(id);
    task.add("name", libconfig::Setting::TypeString)    = name;
    task.add("dueDate", libconfig::Setting::TypeString) = dueDate;
    task.add("description", libconfig::Setting::TypeString) = description;

    try {
        cfg.writeFile(outputFile);
        std::cerr << "Succesfully saved task\n";
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "Error" << outputFile << '\n';
        return;
    }
}
