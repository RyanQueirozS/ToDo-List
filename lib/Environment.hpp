#pragma once

#include <string>

std::string GetTaskPathFromCfg();
char* GetDateTimeFormatFromCfg();

void SetupUserEnvironment(std::array<std::string, 2>);
