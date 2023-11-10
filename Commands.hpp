#pragma once

#include <string>
#include <vector>

void showCommand(std::vector<std::string>);

void helpCommand(std::vector<std::string>);

void searchTasks(std::vector<std::string>);

void filterTasks(std::vector<std::string>);

void sortTasks(std::vector<std::string>);

std::vector<std::string> getUserInput();

void executeCommands();
