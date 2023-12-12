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

void GetUserInput();
std::string GetCurrentExecutablePath();
