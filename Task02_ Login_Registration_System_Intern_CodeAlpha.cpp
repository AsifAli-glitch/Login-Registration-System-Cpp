#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool userExists(string username)
{
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p)
    {
        if (u == username)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Registration function
void registerUser()
{
    string username, password;

    cout << "\n--- Registration ---" << endl;
    cout << "Enter username: ";
    cin >> username;

    if (userExists(username))
    {
        cout << "Username already exists!" << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

// Login function
void loginUser()
{
    string username, password;
    string u, p;
    bool found = false;

    cout << "\n--- Login ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> u >> p)
    {
        if (u == username && p == password)
        {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "login successful! Welcome " << username << endl;
    else
        cout << "Invalid username or password!" << endl;
}

// Main menu
int main()
{
    int choice;

    cout << "==== LOGIN & REGISTRATION SYSTEM ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        registerUser();
    else if (choice == 2)
        loginUser();
    else
        cout << "Invalid choice!" << endl;

    return 0;
}
