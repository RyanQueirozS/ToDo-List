#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "Task.hpp"

Task::Task(std::string label,
           std::string name,
           std::string dueDate,
           std::string description)
    : LABEL(label), name(name), dueDate(dueDate), description(description) {
  saveTask();
};

Task::~Task(){};

void Task::saveTask() {
  if (LABEL == "all" || LABEL == "IDFILE" || LABEL == "-a") {
    std::cout
        << "Invalid label\n";  // This inflicts with the "show all" command;
    return;
  }
  std::string path = "./Tasks/";
  std::filesystem::create_directory(path);
  std::fstream myFile(path + LABEL + ".txt", std::ios::app);
  std::fstream idFile(path + "IDFILE");

  int id;
  if (myFile.is_open() && idFile.is_open()) {
    idFile >> id;
    myFile << "{ID: " << id++ << ", Name: " << name << ", DueDate: " << dueDate
           << ", Description: " << description << "}\n";
    idFile << id++;
    myFile.close();
    idFile.close();
    return;
  }
  std::cout << "Error opening file\n";
  myFile.close();
  idFile.close();
  return;
}

std::array<std::string, 5> Task::getObjectsAsVector() {
  std::array<std::string, 5> taskVector = {LABEL, name, dueDate, description};

  return taskVector;
}
