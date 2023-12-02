#pragma once

#include <string>
#include <vector>

void ExecuteCommands();

void cmdShow();
void cmdHelp();
void cmdSet();
void cmdCreate();
void cmdDelete();
void cmdEdit();

std::vector<std::string> GetUserInput();
std::string GetCurrentExecutablePath();
