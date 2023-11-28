#pragma once

#include <string>
#include <vector>

std::string getCurrentExecutablePath();

void show_command();

void help_command();

void searchTasks();

void filterTasks();

void sortTasks();

void create_command();

void setUserSettings();

std::vector<std::string> getUserInput();

void executeCommands();
