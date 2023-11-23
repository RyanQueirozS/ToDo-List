#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

class Task {
 private:
  const std::string LABEL;
  unsigned int id;
  std::string name;
  std::string dueDate;
  std::string description;

 public:
  void createTask();
  void deleteTask();
  void editTask();
  Task(std::string label, unsigned int id, std::string name, std::string date,
       std::string description);
  ~Task();

 private:
  void saveTask();
  std::array<std::string, 5> getObjectsAsVector();
};

unsigned int generateTaskId();
