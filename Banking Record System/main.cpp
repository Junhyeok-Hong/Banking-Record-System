//
//  main.cpp
//  Banking Record System
//
//  Created by Michael Hong on 2021-01-08.
//

//
//  main.cpp
//  Banking Record System
//
//  Created by Michael Hong on 2021-01-08.
//

#include<iostream>
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
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
};

void account_query::read_data()
{

}

void account_query::show_data()
{

}

void account_query::write_rec()
{
    std::ofstream file("database.txt", std::ios::out|std::ios::app);
    if(!file) cout << "Cannot open file" << endl;
    
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
    cout << endl;
    
    file.close();
}

void account_query::read_rec()
{
    cout << "read rec" << endl;
}

void account_query::search_rec()
{
    cout << "search rec" << endl;
}

void account_query::edit_rec()
{
    cout << "edit rec" << endl;
}

void account_query::delete_rec()
{
    cout << "delete rec" << endl;
}

int main()
{
    cout << "===Banking Record System===" << endl;
    account_query query;
    int choice;
    
    while(1)
    {
        cout << "\t1-->Add record to file" << endl;
        cout << "\t2-->Show record from file" << endl;
        cout << "\t3-->Search Record from file" << endl;
        cout << "\t4-->Update Record" << endl;
        cout << "\t5-->Delete Record" << endl;
        cout << "\t6-->Quit" << endl;
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
                query.edit_rec();
                break;
            case 5:
                query.delete_rec();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"\nERROR: Choice MUST be between 1...6";
                exit(0);
        }
    }
    return 0;
}


