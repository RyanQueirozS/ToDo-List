#include <array>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <libconfig.h++>
#include <string>
#include <unordered_map>
#include <vector>

#include "../lib/Commands.hpp"
#include "../lib/Environment.hpp"
#include "../lib/Task.hpp"

std::vector<std::string> Tokens;

void GetUserInput() {
    std::string userInput;
    std::cout << "> ";
    std::getline(std::cin, userInput);

    std::stringstream ss(userInput);
    const std::istream_iterator<std::string> begin(ss);
    const std::istream_iterator<std::string> end;
    const std::vector<std::string> tokens(begin, end);

    Tokens = tokens;
}

struct outputTemplate {
    public:
        void PrintTaskInfo(
            const std::vector<std::array<std::string, 4>> taskVector) {
            std::vector<int> headerSize = GetHeaderSize(taskVector);
            if (taskVector.empty()) {
                PrintTaskHeader(headerSize);
                std::cout << "|      Didn't find any tasks     |\n";
                PrintTaskLine(headerSize);
                return;
            }

            PrintTaskLine(headerSize);
            PrintTaskHeader(headerSize);
            PrintTaskLine(headerSize);
            std::cout << "| ID | Name | Date | Description |\n";

            for (int i = 0; i < taskVector.size(); i++) {
                PrintTaskLine(headerSize);
                for (int j = 0; j < taskVector[i].size(); j++) {
                    std::cout << "| ";
                    if (j == 0 && taskVector[i][j].size() == 1) {
                        std::cout << " ";
                    }
                    if (j == 1 && taskVector[i][j].size() < 4) {
                        for (int k = 0; k < 4 - taskVector[i][j].size(); k++) {
                            std::cout << " ";
                        }
                    }
                    if (j == 2 && taskVector[i][j].size() < 4) {
                        for (int k = 0; k < 4 - taskVector[i][j].size(); k++) {
                            std::cout << " ";
                        }
                    }
                    if (j == 3 && taskVector[i][j].size() < 11) {
                        for (int k = 0; k < (11 - taskVector[i][j].size());
                             k++) {
                            std::cout << " ";
                        }
                    }
                    std::cout << taskVector[i][j] << " ";
                }
                std::cout << '|';
                std::cout << '\n';
            }
            PrintTaskLine(headerSize);
        }

    private:
        std::vector<int> GetHeaderSize(
            std::vector<std::array<std::string, 4>> taskVector) {
            std::vector<int> elementsSize;
            if (taskVector.empty()) {
                return {32};
            }
            int headerSize = 0, lineSize = 0, index = 0;
            for (int i = 0; i < taskVector.size(); i++) {
                lineSize = 0;
                for (std::string y : taskVector[i]) {
                    lineSize += y.size();
                }
                if (lineSize > headerSize) {
                    headerSize = lineSize;
                    index      = i;
                }
            }
            elementsSize[0] = taskVector[index][0].size();
            elementsSize[1] = taskVector[index][1].size();
            elementsSize[2] = taskVector[index][2].size();
            elementsSize[3] = taskVector[index][3].size();
            // Note: The code above can be easily improved

            if (taskVector[index][0].size() < 2) {
                headerSize++;
            }
            if (taskVector[index][1].size() < 4) {
                headerSize += 4 - taskVector[index][1].size();
            }
            if (taskVector[index][2].size() < 4) {
                headerSize += 4 - taskVector[index][2].size();
            }
            if (taskVector[index][3].size() < 11) {
                headerSize += 11 - taskVector[index][3].size();
            }
            headerSize += 11;  // Value of spaces and '|'
            return {headerSize};
        }
        void PrintTaskLine(std::vector<int> &lineSize) {
            std::cout << "+";
            for (int i = 0; i < lineSize[0]; i++) {
                std::cout << "-";
            }
            std::cout << "+\n";
        }

        void PrintTaskHeader(std::vector<int> &headerSize) {
            if (headerSize[0] < 32) {
                headerSize[0] = 32;  // Note: Possible error
            }
            int labelSize = 5;
            int labelPos  = (headerSize[0] - labelSize) / 2;

            std::cout << "|";
            for (int i = 0; i < headerSize[0] - 5; i++) {
                std::cout << " ";
                if (i == labelPos) {
                    std::cout << "LABEL";
                }
            }
            std::cout << "|\n";
        }
};

std::string GetCurrentExecutablePath() {
    // For the time being this application doesn't work on windows due to the
    // binaries for cmake and the compiler not existing in the same path as it
    // is on linux.This function has virtually no value until I fix it.

    // On the future I may fix this, or may simply make it only a linux
    // aplication and delete this function.

#ifdef _WIN32
#include <direct.h>
#include <limits.h>

#include <iostream>
    char buff[PATH_MAX];
    _getcwd(buff, PATH_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
#endif

#ifdef linux
#include <filesystem>
    return std::filesystem::current_path();
#endif
}

void cmdSet() {
    if (std::filesystem::exists(GetCurrentExecutablePath() +
                                "/doc/config.cfg") &&
        Tokens.empty()) {
        return;
    }
    std::array<std::string, 2> envSettingsArray;

    std::cout << "\nPlease answer to set your environment up:\n"
              << "Set Task Path:\n"
              << "Your executable path for reference: "
              << GetCurrentExecutablePath() << "\n> ";
    std::cin >> envSettingsArray[0];
    std::cout << "Set Date Format:\n> ";
    std::cin >> envSettingsArray[1];
    SetupUserEnvironment(envSettingsArray);
    return;
}

void cmdHelp() {
    std::string line;
    std::ifstream helpText;
    helpText.open("./doc/helpCommand.txt");

    if (helpText.is_open()) {
        while (std::getline(helpText, line)) {
            std::cout << line << "\n";
        }
        helpText.close();
        return;
    }
    std::cout << "Unable to display all commands\n"
              << "Check if \"helpCommand.txt\" exists in the /doc directory\n";
    helpText.close();
    return;
}

void cmdShow() {
    libconfig::Config cfg;
    std::string path = GetTaskPathFromConfigFile();
    std::vector<std::array<std::string, 4>> taskVector;
    std::string taskPath = GetTaskPathFromConfigFile();
    outputTemplate print;

    if (Tokens.size() < 2) {
        int last = taskPath.find_last_of("/");
        std::cout << "Possible Labels:\n";
        for (const auto &entry :
             std::filesystem::directory_iterator(taskPath)) {
            std::cout << " - " << entry.path().string().substr(last + 1)
                      << "\n";
        }
        std::cout << "NOTE:You do not need to include '.cfg' when using this "
                     "command\n";
        return;
    }

    if (Tokens[1] == "all") {
        for (const auto &entry :
             std::filesystem::directory_iterator(taskPath)) {
            try {
                cfg.readFile(entry.path());
            } catch (const libconfig::FileIOException &fioex) {
                std::cout << "I/O error while reading file.\n";
                return;
            } catch (const libconfig::ParseException &pex) {
                std::cerr << "Parse error at " << pex.getFile() << ":"
                          << pex.getLine() << " - " << pex.getError() << '\n';
                return;
            }
            libconfig::Setting &root = cfg.getRoot();
            if (!root.exists("Tasks")) {
                std::cout << "No tasks in Label : " << entry.path() << '\n';
                return;
            }
            libconfig::Setting &tasks = root["Tasks"];

            try {
                std::array<std::string, 4> taskFieldArray;
                for (int i = 0; i < tasks.getLength(); i++) {
                    const std::string ID      = tasks[i].lookup("ID");
                    const std::string name    = tasks[i].lookup("name");
                    const std::string dueDate = tasks[i].lookup("dueDate");
                    const std::string description =
                        tasks[i].lookup("description");
                    taskFieldArray = {ID, name, dueDate, description};
                    taskVector.push_back(taskFieldArray);
                }
            } catch (const libconfig::SettingNotFoundException &nfex) {
                std::cerr << "Didn't find Tasks\n";
                return;
            }
        }
        print.PrintTaskInfo(taskVector);
        return;
    }

    path += Tokens[1] + ".cfg";
    try {
        cfg.readFile(path);
    } catch (const libconfig::FileIOException &fioex) {
        std::cout << "I/O error while reading file.\n";
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << '\n';
        return;
    }
    libconfig::Setting &root = cfg.getRoot();
    if (!root.exists("Tasks")) {
        std::cout << "No tasks in Label : " << path << '\n';
        return;
    }
    libconfig::Setting &tasks = root["Tasks"];

    try {
        std::array<std::string, 4> taskFieldArray;
        for (int i = 0; i < tasks.getLength(); i++) {
            const std::string ID          = tasks[i].lookup("ID");
            const std::string name        = tasks[i].lookup("name");
            const std::string dueDate     = tasks[i].lookup("dueDate");
            const std::string description = tasks[i].lookup("description");
            taskFieldArray                = {ID, name, dueDate, description};
            taskVector.push_back(taskFieldArray);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Didn't find Tasks\n";
        return;
    }
    print.PrintTaskInfo(taskVector);
    return;
    std::cout << "Wrong use of command\n";
    return;
}

void cmdCreate() {
    std::array<std::string, 4> taskObjectsArray;
    const std::array<std::string, 4> textArray = {
        "Label:\n> ",
        "Name:\n> ",
        "Date(DD:MM):\n> ",
        "Description:\n> ",
    };
    const uint id = GenerateTaskID();

    if (id == 0) {  // This is just a way to get a invalid ID, check the
        return;     // generateTaskID function
    }
    for (int i = 0; i < 4; i++) {
        std::cout << "Enter the Task's " << textArray[i];
        std::cin >> taskObjectsArray[i];
    }
    Task task(taskObjectsArray[0],
              id,
              taskObjectsArray[1],
              taskObjectsArray[2],
              taskObjectsArray[3]);
}

void cmdDelete() {
    if (Tokens.size() < 2) {
        std::cout << "Wrong use of command\n";
        return;
    }
    std::string path = GetTaskPathFromConfigFile();
    if (Tokens[1] == "all") {
        std::string ans;
        std::cout << "Are you sure you want to delete all tasks?[y/n]\n> ";
        std::getline(std::cin, ans);
        if (ans == "y" || ans == "yes") {
            std::cout << "Type in all caps \"i want to delete all tasks\"\n> ";
            std::getline(std::cin, ans);

            if (ans == "I WANT TO DELETE ALL TASKS") {
                {
                    bool del;
                    for (const auto &entry :
                         std::filesystem::directory_iterator(path)) {
                        del = std::filesystem::remove(entry);
                    }
                    if (del) {
                        std::cout << "Tasks deleted sucessfully\n";
                    }
                    return;
                }
            }
        }
        std::cout << "Nothing happened\n";
        return;
    }

    path += Tokens[1] + ".cfg";
    libconfig::Config cfg;

    cmdShow();
    std::string ans;
    std::cout << "Insert the ID of the taks would you like to delete?\n> ";
    std::getline(std::cin, ans);
    if (ans == "all") {
        std::cout << "Are you sure you want to delete all tasks in this "
                     "label?[y/n]\n> ";
        std::getline(std::cin, ans);
        if (ans == "y" || ans == "yes") {
            std::cout << "Type in all caps \"i want to delete all tasks\"\n> ";
            std::getline(std::cin, ans);

            if (ans == "I WANT TO DELETE ALL TASKS") {
                const bool del = std::filesystem::remove(path);
                if (del) {
                    std::cout << "Tasks deleted sucessfully\n";
                }
                return;
            }
        }
        std::cout << "Nothing happened\n";
        return;
    }

    try {
        cfg.readFile(path);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file.\n";
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << "\n";
        return;
    }
    libconfig::Setting &root = cfg.getRoot();
    if (!root.exists("Tasks")) {
        std::cout << "Couln't locate tasks for deletion\n";
        return;
    }

    libconfig::Setting &tasks = root["Tasks"];

    try {
        for (int i = 0; i < tasks.getLength(); i++) {
            libconfig::Setting &task = tasks[i];
            std::string taskId       = task.lookup("ID");
            if (taskId == ans) {
                tasks.remove(task.getIndex());
            }
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Didn't find Tasks\n";
        return;
    }
    try {
        cfg.writeFile(path);
        std::cerr << "Sucessfuly wrote to file\n";
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "Error at: " << path << '\n';
        return;
    }
}

void cmdEdit() {
    if (Tokens.size() < 2) {
        std::cout << "Wrong use of command\n";
        return;
    }

    const std::string path = GetTaskPathFromConfigFile() + Tokens[1] + ".cfg";
    libconfig::Config cfg;

    cmdShow();
    std::string ans;
    std::cout << "Insert the ID of the taks would you like to delete?\n> ";
    std::getline(std::cin, ans);

    try {
        cfg.readFile(path);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file.\n";
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << "\n";
        return;
    }
    std::cout << "1\n";

    libconfig::Setting &root = cfg.getRoot();

    if (!root.exists("Tasks")) {
        std::cout << "Couln't locate task\n";
        return;
    }
    std::cout << "2\n";
    libconfig::Setting &tasks = root["Tasks"];

    std::array<std::string, 3> taskFieldsArray;
    std::array<std::string, 3> taskFieldsQuestions = {
        "What should the name be:\n> ",
        "What should the date be:\n> ",
        "What should the description be:\n> ",
    };
    std::string ID;

    try {
        for (int i = 0; i < tasks.getLength(); i++) {
            libconfig::Setting &task = tasks[i];
            std::string taskId       = task.lookup("ID");
            if (taskId == ans) {
                ID = tasks[i].lookup("ID").c_str();
                tasks.remove(task.getIndex());
            }
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Didn't find Tasks\n";
        return;
    }
    for (int i = 0; i < taskFieldsArray.size(); i++) {
        std::cout << taskFieldsQuestions[i];
        std::cin >> taskFieldsArray[i];
    }
    try {
        cfg.writeFile(path);
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "Error" << path << '\n';
        return;
    }
    Task task(Tokens[1],
              atoi(ID.c_str()),
              taskFieldsArray[0],
              taskFieldsArray[1],
              taskFieldsArray[2]);
}

void ExecuteCommands() {
    cmdSet();

    std::unordered_map<std::string, std::function<void()>> commandsMap{
        {"help",   cmdHelp  },
        {"h",      cmdHelp  },
        {"show",   cmdShow  },
        {"create", cmdCreate},
        {"set",    cmdSet   },
        {"delete", cmdDelete},
        {"edit",   cmdEdit  },
    };

    while (true) {
        GetUserInput();
        if (commandsMap.find(Tokens[0]) != commandsMap.end() &&
            !Tokens.empty()) {
            commandsMap[Tokens[0]]();
        } else if (Tokens[0] == "exit") {
            break;
        }
    }
}