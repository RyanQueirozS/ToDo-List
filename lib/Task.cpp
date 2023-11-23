
#include <array>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

#include "Commands.hpp"
#include "Environment.hpp"
#include "Task.hpp"

Task::Task(std::string label, unsigned int id, std::string name,
           std::string dueDate, std::string description)
    : LABEL(label),
      id(id),
      name(name),
      dueDate(dueDate),
      description(description) {
  saveTask();
};

unsigned int generateTaskId() {
  std::fstream idFile(getCurrentExecutablePath() + "/doc/IDFILE");
  if (!idFile.is_open()) {
    std::cout << "Error getting id for task\n";
    return 2147483647;  // Dummy value just to know ID doesnt exist
  }
  uint generatedID;
  idFile >> generatedID;
  idFile << generatedID++;
  idFile.close();
  return generatedID++;
}

Task::~Task(){};

void Task::saveTask() {
  if (LABEL == "all" || LABEL == "IDFILE" ||
      LABEL == "-a") {  // This may inflict with the "show" command;
    std::cout << "Invalid label\n";
    return;
  }

  std::string path = getTaskPathFromConfigFile();
  bool directory = std::filesystem::create_directory(path) ||
                   std::filesystem::is_directory(path);
  if (!directory) {
    std::cout << "Error creating directory: " << path << '\n';
  }
  std::fstream myFile(path + LABEL + ".txt", std::ios::app);

  if (myFile.is_open()) {
    std::cout << "Storing task in: " << path << "\n\n";
    myFile << id << "= {\n"
           << "\t" << name << '\n'
           << "\t" << dueDate << '\n'
           << "\t" << description << "\n"
           << "}\n";
    myFile.close();
    return;
  }
  std::cout << "Error opening file\n";
  myFile.close();
}

std::array<std::string, 5> Task::getObjectsAsVector() {
  std::array<std::string, 5> taskVector = {LABEL, std::to_string(id), name,
                                           dueDate, description};

  return taskVector;
}
