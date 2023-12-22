#pragma once

#include <string>

std::string GetTaskPathFromCfg();
std::string GetDateTimeFormatFromCfg();

void SetupUserEnvironment(std::array<std::string, 2>);
