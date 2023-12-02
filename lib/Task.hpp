#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

class Task {
    public:
        void SaveTask();
        Task(std::string label,
             unsigned int id,
             std::string name,
             std::string date,
             std::string description);
        ~Task();

    private:
        const std::string LABEL;
        const unsigned int id;
        const std::string name;
        const std::string dueDate;
        const std::string description;
};

unsigned int GenerateTaskID();
