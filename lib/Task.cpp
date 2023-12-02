#include <filesystem>
#include <iostream>
#include <libconfig.h++>
#include <string>

#include "Commands.hpp"
#include "Environment.hpp"
#include "Task.hpp"

Task::Task(const std::string label,
           const unsigned int id,
           const std::string name,
           const std::string dueDate,
           const std::string description)
    : LABEL(label),
      id(id),
      name(name),
      dueDate(dueDate),
      description(description){};

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

    const std::string path       = GetTaskPathFromConfigFile();
    const std::string outputFile = path + LABEL + ".cfg";
    const bool directory         = std::filesystem::create_directory(path) ||
                           std::filesystem::is_directory(path);
    if (!directory) {
        std::cout << "Error creating directory: " << path << '\n';
        return;
    }
    // std::fstream myFile(path + LABEL + ".cfg", std::ios::app);

    libconfig::Config cfg;
    cfg.setOptions(libconfig::Config::OptionFsync |
                   libconfig::Config::OptionSemicolonSeparators |
                   libconfig::Config::OptionColonAssignmentForGroups |
                   libconfig::Config::OptionOpenBraceOnSeparateLine);

    try {
        cfg.readFile(outputFile);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
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
        std::cerr << "success\n";
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "Error" << outputFile << '\n';
        return;
    }
}
