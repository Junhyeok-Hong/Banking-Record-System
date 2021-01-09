//
//  main.cpp
//  Banking Record System
//
//  Created by Michael Hong on 2021-01-08.
//

#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class account_query
{
private:
    string first_name;
    string last_name;
    float balance;
public:
    void write_rec();
    void read_rec();
    int search_rec();
    void delete_rec();
};

void account_query::write_rec()
{
    std::ofstream file("database.txt", std::ios::out|std::ios::app);
    if(!file)
    {
        cout << "Cannot open file" << endl;
        return;
    }
    cout << "===Add New Data===" << endl;
    cout << "Enter first name: ";
    cin >> first_name;
    file << first_name;
    cout << "Enter last name: ";
    cin >> last_name;
    file << last_name;
    cout << "Enter balance: ";
    cin >> balance;
    file << balance;
    file << '\n';
    
    file.close();
}

void account_query::read_rec()
{
    std::ifstream file("database.txt");
    if(!file)
    {
        cout << "Cannot open file" << endl;
        return;
    }
    cout << "===Showing Database===" << endl;
    string data;
    while (getline (file, data))
    {
        cout << data << endl;
    }
    file.close();
}

int account_query::search_rec()
{
    cout << "Enter first name: ";
    cin >> first_name;
    cout << "Enter last name: ";
    cin >> last_name;
    
    std::ifstream file("database.txt");
    if(!file)
    {
        cout << "Cannot open file" << endl;
        return 0;
    }
    cout << "===Searching Database===" << endl;
    string data;
    while (getline (file, data))
    {
        if (data.find(first_name) != std::string::npos && data.find(last_name) != std::string::npos)
        {
            cout << data << endl;
            return 1;
        }
    }
    file.close();
    return 0;
}

void account_query::delete_rec()
{
    if (search_rec())
    {
        cout << "Deleting From Database..." << endl;
        std::ofstream tempfile("temp.txt", std::ios::out|std::ios::app);
        std::ifstream file("database.txt");
        if(!file)
        {
            cout << "Cannot open file" << endl;
        }
        string data;
        while (getline (file, data))
        {
            if (data.find(this->first_name) != std::string::npos && data.find(this->last_name) != std::string::npos)
            {
                continue;
            }
            else
            {
                tempfile << data;
                tempfile << '\n';
            }
        }
        file.close();
        tempfile.close();
        remove("database.txt");
        rename("temp.txt", "database.txt");
    }
    else
    {
        cout << "Cannot Find Name!" << endl;
        return;
    }
}

int main()
{
    cout << "=====Banking Record System=====" << endl;
    account_query query;
    int choice;
    
    while(1)
    {
        cout << "===Commands===" << endl;
        cout << "\t1-->Add record to file" << endl;
        cout << "\t2-->Show record from file" << endl;
        cout << "\t3-->Search Record from file" << endl;
        cout << "\t4-->Delete Record" << endl;
        cout << "\t5-->Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                query.write_rec();
                break;
            case 2:
                query.read_rec();
                break;
            case 3:
                query.search_rec();
                break;
            case 4:
                query.delete_rec();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"\nERROR: Choice MUST be between 1...5";
                exit(0);
        }
    }
    return 0;
}


