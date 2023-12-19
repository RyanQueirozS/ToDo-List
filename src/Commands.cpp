#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <libconfig.h++>
#include <ostream>
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
        void PrintAllTasks(std::vector<std::array<std::string, 4>> taskVector) {
            std::array<int, 5> headerSize = GetHeaderSize(taskVector);
            PrintTaskLine(headerSize);
            PrintTaskHeader(headerSize);
            PrintTaskLine(headerSize);
            PrintTaskInfo(taskVector);
            PrintTaskLine(headerSize);
        };

    private:
        void PrintTaskInfo(std::vector<std::array<std::string, 4>> taskVector) {
            std::array<int, 5> headerSize = GetHeaderSize(taskVector);
            std::array<std::string, 4> headerElements{
                "ID",
                "Name",
                "Date",
                "Description",
            };

            if (taskVector.empty()) {
                PrintTaskHeader(headerSize);
                std::cout << "|      Didn't find any tasks     |\n";
                PrintTaskLine(headerSize);
                return;
            }

            for (int i = 0; i < headerElements.size(); i++) {
                std::cout << "| ";
                if ((headerSize[i + 1] - headerElements[i].size())) {
                    for (int j = 0;
                         j < headerSize[i + 1] - headerElements[i].size();
                         j++) {
                        if (j ==
                            (headerSize[i + 1] - headerElements[i].size()) /
                                2) {
                            std::cout << headerElements[i];
                            // std::cout << headerSize[5];
                        }
                        std::cout << ' ';
                    }
                } else {
                    std::cout << headerElements[i];
                }
                std::cout << ' ';
            }
            std::cout << "|\n";

            // The loop bellow is to make it so task fields add up to the size
            // neded to not break the template. eg: |   idvalue |
            for (int i = 1; i < taskVector.size(); i++) {
                std::vector<std::array<char, 20>> lineVector{};
                PrintTaskLine(headerSize);

                std::cout << "| ";
                for (int j = 0; j < taskVector[i].size(); j++) {
                    int headerSz = headerSize[j + 1],
                        taskSz = taskVector[i][j].size(), pos = 0;
                    if (headerSz - taskSz > 0) {
                        // lineVector.push_back(taskVector[i][j].substr(pos,
                        // 20));
                        for (int k = 0; k < headerSz - taskSz; k++) {
                            std::cout << ' ';
                        }
                    }
                    std::cout << taskVector[i][j];
                    std::cout << " | ";
                }
                std::cout << "\n";
            }
        }

        std::array<int, 5> GetHeaderSize(
            std::vector<std::array<std::string, 4>> taskVector) {
            std::array<int, 5> elementsSize{
                0,
                2,
                4,
                4,
                11,
            };  // If it doesnt get initialized it breaks, for some reason
            int result = 0;

            if (taskVector.empty()) {
                return {32};
            }
            for (int i = 0; i < taskVector.size(); i++) {
                for (int j = 0; j < taskVector[i].size(); j++) {
                    if (taskVector[i][j].size() > elementsSize[j + 1]) {
                        elementsSize[j + 1] = taskVector[i][j].size();
                    }
                }
            }
            for (int x : elementsSize) {
                result += x;
            }
            result += 11;  // Amount of spaces and |
            elementsSize[0] = result;

            return elementsSize;
        }
        void PrintTaskLine(std::array<int, 5> lineSize) {
            std::cout << "+";
            if (lineSize[0] < 32) {
                lineSize[0] = 32;
            }
            for (int i = 0; i < lineSize[0]; i++) {
                std::cout << "-";
            }
            std::cout << "+\n";
        }

        void PrintTaskHeader(std::array<int, 5> headerSize) {
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
    // For the time being this application doesn't work on windows due
    // to the binaries for cmake and the compiler not existing in the
    // same path as it is on linux.This function has virtually no value
    // until I fix it.

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
    std::cout << "Set Date/Time Format: [a^]DD/MM [b]MM/DD [c]custom\n> ";
    char dateTimeFormat;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("stty raw");  // Sets term to raw
    dateTimeFormat = getchar();
    system("stty cooked");  // Resets term

    envSettingsArray[1] = "DD/MM";
    if (dateTimeFormat == 'b') {
        envSettingsArray[1] = "MM/DD";
    }
    if (dateTimeFormat == 'c') {
        std::cout << "Set your custom Date/Time format: ";
        std::cin >> (envSettingsArray[1]);
    }
    SetupUserEnvironment(envSettingsArray);
    std::cout << '\n';
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
              << "Check if \"helpCommand.txt\" exists in the /doc "
                 "directory\n";
    helpText.close();
    return;
}

void cmdShow() {
    libconfig::Config cfg;
    std::string path = GetTaskPathFromCfg();
    std::vector<std::array<std::string, 4>> taskVector{
        {"", "", "", ""}
    };

    std::string taskPath = GetTaskPathFromCfg();
    outputTemplate print;

    // ----------------------------------
    if (Tokens.size() < 2) {
        int taskName = taskPath.find_last_of("/");
        std::cout << "Possible Labels:\n";
        for (const auto &entry :
             std::filesystem::directory_iterator(taskPath)) {
            std::cout << " - " << entry.path().string().substr(taskName + 1)
                      << "\n";
        }
        std::cout << "NOTE:You do not need to include '.cfg' when using this "
                     "command\n";
        return;
    }

    // ----------------------------------
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
        print.PrintAllTasks(taskVector);
        return;
    }

    // ----------------------------------
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
    print.PrintAllTasks(taskVector);
    return;

    // ----------------------------------
    std::cout << "Wrong use of command\n";
    return;
    // ----------------------------------
}

void cmdCreate() {
    std::array<std::string, 4> taskObjectsArray;
    const std::array<std::string, 4> textArray = {
        "Label:\n> ",
        "Name:\n> ",
        "",
        "Description:\n> ",
    };
    const uint id = GenerateTaskID();

    if (id == 0) {  // This is just a way to get a invalid ID, check the
        return;     // generateTaskID function
    }

    for (int i = 0; i < textArray.size(); i++) {
        if (i == 2) {
            char _input, date[6]{"DD/MM"};
            for (int j = 0; j < sizeof(date) - 1; j++) {
                std::cout << "\b\bEnter Date in the given format: " << date
                          << "\n> ";
                if (j == 2) {
                    j++;  // char |
                }
                {
                    // This is to get the date in a format in real time
                    system("stty raw");  // Sets term to raw
                    _input = getchar();
                    system("stty cooked");  // Resets term
                    std::cout << "\x1b[1A"
                              << "\x1b[2K"
                              << "\b";
                }
                date[j] = _input;
            }
            std::cout << "\b\bEnter Date in the given format:\n> " << date
                      << "\n";
            i++;
            taskObjectsArray[2] = date;
        }

        std::cout << "Enter the Task's " << textArray[i];
        std::getline(std::cin, taskObjectsArray[i]);
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
    std::string path = GetTaskPathFromCfg();
    if (Tokens[1] == "all") {
        std::string ans;
        std::cout << "Are you sure you want to delete all tasks?[y/n]\n> ";
        std::getline(std::cin, ans);
        if (ans == "y" || ans == "yes") {
            std::cout << "Type in all caps \"i want to delete all "
                         "tasks\"\n> ";
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
            std::cout << "Type in all caps \"i want to delete all "
                         "tasks\"\n> ";
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

    const std::string path = GetTaskPathFromCfg() + Tokens[1] + ".cfg";
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
        } else if (Tokens[0] == "clear") {
            std::cout << "\033[2J\033[1;1H";
        }
    }
}
