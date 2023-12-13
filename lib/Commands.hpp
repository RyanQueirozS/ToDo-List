#pragma once

#include <string>
#include <vector>

void ExecuteCommands();

void cmdShow();
void cmdHelp();
void cmdCreate();
void cmdDelete();
void cmdEdit();

void GetUserInput();
std::string GetCurrentExecutablePath();
