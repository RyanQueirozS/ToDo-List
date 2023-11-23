#pragma once

#include <string>
#include <vector>

class CommandParams {
 public:
  std::vector<std::string> tokens;

 private:
};

std::string getCurrentExecutablePath();

void show_command(CommandParams);

void help_command(CommandParams);

void searchTasks(CommandParams);

void filterTasks(CommandParams);

void sortTasks(CommandParams);

void create_command(CommandParams);

void setUserSettings(CommandParams);

std::vector<std::string> getUserInput();

void executeCommands();
