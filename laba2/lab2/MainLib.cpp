#include "MainLib.h"

void writeToFile(const string& filename, const Train& train)
{
    ofstream file(filename, ios::app | ios::binary);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&train), sizeof(Train));
    file.close();
}

void printTitle(const string& schedule)
{
    cout << schedule << endl;
}

string inputForFile()
{
    char choice = 'y';
    std::string filename;
    Train train;

    std::cout << "Please enter the name of the file you want to create/open:" << std::endl;
    std::getline(std::cin, filename);

    do
    {
        train.scheduleInput();
        writeToFile(filename, train);

        std::cout << "Enter 'n' if you want to stop providing input" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
    } while (choice != 'n');

    std::cout << std::endl;
    return filename;
}

void readFile(const string& filename, string schedule)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    file.seekg(0, ios::end);
    size_t countStruct = file.tellg() / sizeof(Train);
    file.seekg(0, ios::beg);

    Train* trains = nullptr;
    try {
        trains = new Train[countStruct];
    }
    catch (const bad_alloc& e)
    {
        cout << "Error allocating memory: " << e.what() << endl;
        delete[] trains;
        file.close();
        return;
    }

    printTitle(schedule);
    for (size_t i = 0; i < countStruct && !file.eof(); i++)
    {
        file.read(reinterpret_cast<char*>(&trains[i]), sizeof(Train));
        trains[i].printSchedule();
    }
    cout << endl << endl;
    file.close();
    delete[] trains;
}

void winterSchedule(const string& filename)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    file.seekg(0, ios::end);
    size_t countStruct = file.tellg() / sizeof(Train);
    file.seekg(0, ios::beg);

    Train* trains = nullptr;
    try
    {
        trains = new Train[countStruct];
    }
    catch (const bad_alloc& e)
    {
        cout << "Error allocating memory: " << e.what() << endl;
        delete[] trains;
        file.close();
        return;
    }

    for (size_t i = 0; i < countStruct && !file.eof(); i++)
    {
        file.read(reinterpret_cast<char*>(&trains[i]), sizeof(Train));
    }
    file.close();

    string time;
    string newFilename = "winter_" + filename;    //create new file
    ofstream winterFile(newFilename, ios::binary);
    if (!winterFile.is_open()) {
        cout << "Error opening file" << endl;
        delete[] trains;
        return;
    }

    for (size_t i = 0; i < countStruct; i++) {
        time = trains[i].departureTime.substr(0, 2);
        if (stoi(time) < 10 || stoi(time) >= 18) {
            winterFile.write(reinterpret_cast<char*>(&trains[i]), sizeof(Train));
        }
    }
    winterFile.close();
    delete[] trains;
    readFile(newFilename, "Winter Schedule");
}
