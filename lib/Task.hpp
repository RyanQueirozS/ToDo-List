#pragma once

#include <string>

class Task {
    public:
        Task(std::string label,
             uint id,
             std::string name,
             std::string date,
             std::string description);
        ~Task();

    private:
        void SaveTask();
        std::string LABEL;
        uint id;
        std::string name;
        std::string dueDate;
        std::string description;
};

uint GenerateTaskID();
