#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int SIZE = 0;
int numOfRecords=0;

struct Rooms
{
    int roomNumber;
    double cost;
};
struct Guest
{
    int id;
    string Fname;
    string Lname;
    string phone;
    Rooms room;
};
// prototypes
void updateGuest(Guest g[]);
void display(Guest g[]);
void toContinue();
void displaySearch(Guest g[]);
int search(Guest g[]);
void saveToFile(Guest g[]);
int getData(Guest g[]);
void addGuest(Guest g[]);
void removeGuest(Guest g[], int index);
void deleteGuest(Guest g[]);
void sortGuest(Guest g[]);
void changGuests(Guest g[], int i, int j);
void Records(int numOfRecords);
//----------------------------------------------------------------

void Records(int numOfRecords)
{
	time_t my_time = time(NULL);
	ofstream file;
	file.open("Records.txt", ios::app);
	file << numOfRecords<< " Guests has been added to the system on " << " --> " << ctime(&my_time) << endl;
}
void updateGuest(Guest g[])
{
    int newID, newRoomNumber;
    string newFname, newLname, newPhone;
    double newCost;
    cout << "|============= Update Guest =============|\n";
    int index = search(g);
    if (index == -9)
    {
        cout << "user not found" << endl;
    }
    else
    {
        cout << "Enter The Guest new Id : ";
        cin >> newID;
        cout << "Enter The Guest new First Namw : ";
        cin >> newFname;
        cout << "Enter The Guest new Last Name : ";
        cin >> newLname;
        cout << "Enter The Guest new Phone : ";
        cin >> newPhone;
        cout << "Enter The Guest new Room number : ";
        cin >> newRoomNumber;
        cout << "Enter The Guest new Cost : ";
        cin >> newCost;

        g[index].id = newID;
        g[index].Fname = newFname;
        g[index].Lname = newLname;
        g[index].phone = newPhone;
        g[index].room.roomNumber = newRoomNumber;
        g[index].room.cost = newCost;
    }
    cout << "The Data has been successfully updated for the Guest" << endl;
    toContinue();
}
void display(Guest g[])
{
    int count = 1;
    for (int i = 0; i < SIZE - 1; i++)
    {
        if (g[i].id != -9)
        {
            cout << "|============= Guest " << count << "  =============|" << endl;
            cout << "Guest ID :" << g[i].id << endl;
            cout << "Guest First Name :" << g[i].Fname << endl;
            cout << "Guest Last Name :" << g[i].Lname << endl;
            cout << "Guest Phone Number :" << g[i].phone << endl;
            cout << "Guest Room Number :" << g[i].room.roomNumber << endl;
            cout << "Guest Total Cost :" << g[i].room.cost << endl;
            cout << "|===================================================|" << endl;
            count++;
        }
    }
    toContinue();
}
void toContinue()
{
    cout << "press any key to continue..." << endl;
    cin.ignore();
    cin.ignore();
}
void displaySearch(Guest g[])
{
    cout << "|============= Search for Guest =============|\n";
    int index = search(g);
    if (index == -9)
    {
        cout << "User not found" << endl;
    }
    else
    {
        cout << "Guest ID :" << g[index].id << endl;
        cout << "Guest First Name :" << g[index].Fname << endl;
        cout << "Guest Last Name :" << g[index].Lname << endl;
        cout << "Guest Phone Number :" << g[index].phone << endl;
        cout << "Guest Room Number :" << g[index].room.roomNumber << endl;
        cout << "Guest Total Cost :" << g[index].room.cost << endl;
    }
    toContinue();
}
int search(Guest g[])
{
    int id;
    int i;
    bool found = false;
    cout << "Enter the ID of the Guest --> ";
    cin >> id;
    for (i = 0; i < SIZE; i++)
    {

        if (g[i].id == id)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        return i;
    }
    else
    {
        return -9;
    }
}
void saveToFile(Guest g[])
{
    ofstream outputFile;
    outputFile.open("Guests.txt", ios::out);
    if (outputFile.is_open())
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            if (g[i].id != -9)
            {
                outputFile
                    << g[i].id
                    << " " << g[i].Fname
                    << " " << g[i].Lname
                    << " " << g[i].phone
                    << " " << g[i].room.roomNumber
                    << " " << g[i].room.cost << endl;
            }
        }
    }
    else
        cout << "File does not exist";
    outputFile.close();
    cout << "The Data has been successfully saved to the file." << endl;
    toContinue();
}
int getData(Guest g[])
{
    ifstream file;
    file.open("Guests.txt");
    if (file.is_open())
    {
        int i = 0;
        while (!file.eof())
        {
            file >> g[i].id >> g[i].Fname >> g[i].Lname >> g[i].phone >> g[i].room.roomNumber >> g[i].room.cost;
            i++;
        }
        return i;
    }

    else
        cout << "File does not exist" << endl;
    return 0;
}
void addGuest(Guest g[])
{
    int num;
    cout << "|============= Adding Guest =============|\n";
    cout << "  How many Guest do you want to add?" << endl;
    cin >> num;
    cout << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "|============= Guest " << i+1 << "  =============|" << endl;
        cout << "Enter the Guest #" << i + 1 << " ID : ";
        cin >> g[SIZE - 1].id;
        cout << "Enter the Guest #" << i + 1 << " First Name : ";
        cin >> g[SIZE - 1].Fname;
        cin.ignore(80, '\n');
        cout << "Enter the Guest #" << i + 1 << " Last Name : ";
        cin >> g[SIZE - 1].Lname;
        cin.ignore(80, '\n');
        cout << "Enter the Guest #" << i + 1 << " Phone : ";
        cin >> g[SIZE - 1].phone;
        cout << "Enter the Guest #" << i + 1 << " Room number : ";
        cin >> g[SIZE - 1].room.roomNumber;
        cout << "Enter the Guest #" << i + 1 << " Total cost : ";
        cin >> g[SIZE - 1].room.cost;
        cout << "The Guest has been successfully added to the system." << endl;
        SIZE++;
        numOfRecords++;
        cout << endl;
    }
    toContinue();
}
void removeGuest(Guest g[], int index)
{
    g[index].id = -9;
}
void deleteGuest(Guest g[])
{
    char chr;
    cout << "|============= Remove Guest =============|\n";
    int index = search(g);
    if (index == -9)
    {
        cout << "Guest not found" << endl;
    }
    else
    {
        cout << "are you sure you want to delete this Guest (y/n): ";
        cin >> chr;
        if (chr == 'y' || chr == 'Y')
        {
            removeGuest(g, index);
            cout << "The Guest has been deleted successfully." << endl;
        }
    }
    toContinue();
}
void sortGuest(Guest g[])
{
    int i, j;
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (g[i].id < g[j].id)
                changGuests(g, i, j);
        }
    }
    cout << "sort is done" << endl;
    toContinue();
}
void changGuests(Guest g[], int i, int j)
{
    int tempID;
    tempID = g[i].id;
    g[i].id = g[j].id;
    g[j].id = tempID;

    string tempFName;
    tempFName = g[i].Fname;
    g[i].Fname = g[j].Fname;
    g[j].Fname = tempFName;

    string tempLName;
    tempLName = g[i].Lname;
    g[i].Lname = g[j].Lname;
    g[j].Lname = tempLName;

    string tempPhone;
    tempPhone = g[i].phone;
    g[i].phone = g[j].phone;
    g[j].phone = tempPhone;

    int tempRoom;
    tempRoom = g[i].room.roomNumber;
    g[i].room.roomNumber = g[j].room.roomNumber;
    g[j].room.roomNumber = tempRoom;

    double tempCost;
    tempCost = g[i].room.cost;
    g[i].room.cost = g[j].room.cost;
    g[j].room.cost = tempCost;
}

int main()
{
    int option;
    Guest g[100];
    SIZE = getData(g);

    while (1)
    {
        cout << "==================================================================" << endl;
        cout << "                     Welcome to our hotel" << endl;
        cout << "==================================================================" << endl;
        cout << "1. Add a Guest to the System " << endl;
        cout << "2. Search for Guest in the System " << endl;
        cout << "3. Update Guest in the System " << endl;
        cout << "4. Delete Guest from the System " << endl;
        cout << "5. Sort the Guests" << endl;
        cout << "6. Display the Guests " << endl;
        cout << "7. Save the data to the file" << endl;
        cout << "0. to exit the program" << endl;
        cout << "==================================================================" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            addGuest(g);
            break;
        case 2:
            displaySearch(g);
            break;
        case 3:
            updateGuest(g);
            break;
        case 4:
            deleteGuest(g);
            break;
        case 5:
            sortGuest(g);
            break;
        case 6:
            display(g);
            break;
        case 7:
            saveToFile(g);
            Records(numOfRecords);
            break;
        case 0:
            exit(0);
        defult:
            cout << "Enter a valid number." << endl;
            break;
        }
    }
    return 0;
}