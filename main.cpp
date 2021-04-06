#include <iostream>
#include<vector>
#include <sstream>

#include "Markup.h"

using namespace std;

struct User {
    int id = 0;
    string username = "";
    string password = "";
};
struct UsersIncome {
    int userId = 0;
    int incomeId = 0;
    string incomeLabel = "";
    float incomeValue = 0.0;
};
string convertFloat2String( float );

int main() {
//    User users[3];
//    users[0].id = 1;
//    users[0].username = "ziomek";
//    users[0].password = "asdf";
//    users[1].id = 2;
//    users[1].username = "2ziomek";
//    users[1].password = "2asdf";
//    users[2].id = 3;
//    users[2].username = "3ziomek";
//    users[2].password = "3asdf";
//
//    CMarkup xml;
//    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
//    xml.AddElem( "root" );
//    xml.IntoElem();
//
//    for (int i = 0; i < 3; i++)
//    {
//        xml.AddElem( "USER" );
//        xml.IntoElem();
//        xml.AddElem( "ID", users[i].id );
//        xml.AddElem(  "USERNAME", users[i].username);
//        xml.AddElem( "PASSWORD", users[i].password );
//        xml.OutOfElem();
//    }
//
//    xml.Save("users.xml");
//    string xmlStr = xml.GetDoc();
//    cout << "First xml File created!" << endl;
//    cout << "What include string generated from object: \n" << xmlStr << endl;
//
//    float incomeValue = 2450.7827;
//    ostringstream ss;
//    ss << incomeValue;
//    string s(ss.str());
//    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
//    xml.AddElem( "root" );
//    xml.IntoElem();
//    xml.AddElem( "INCOME" );
//    xml.IntoElem();
//    xml.AddElem( "USER_ID", 1 );
//    xml.AddElem( "INCOME_ID", 1 );
//    xml.AddElem( "INCOME_LABEL", "Pensja" );
//    xml.AddElem( "INCOME_VALUE", convertFloat2String( incomeValue ) );
//    xml.Save("incomes.xml");

    CMarkup xml;
    xml.Load( "users.xml" );
//    string xmlStr = xml.GetDoc();
//    cout << "What include string generated from object: \n" << xmlStr << endl;

    xml.FindElem();
    xml.IntoElem();
    User user;
    vector<User> users;
    while ( xml.FindElem( "USER" ) ) {
        xml.IntoElem();
        xml.FindElem( "ID" );
        user.id = stoi( xml.GetData() );
        xml.FindElem( "USERNAME" );
        user.username = xml.GetData();
        xml.FindElem( "PASSWORD" );
        user.password = xml.GetData();
        users.push_back(user);
        xml.OutOfElem();
    }
    for (vector<User>::iterator itr = users.begin(), finish = users.end();
            itr != finish; itr++) {
        cout << "User:\n";
        cout << "ID: " << itr->id;
        cout << "\nUsername: " << itr->username;
        cout << "\nPassword: " << itr->password;
        cout << "\n\n";
    }

    int loggedUserId = users[1].id;
    cout << "Signed user's id: " << loggedUserId << endl;
    xml.Load( "incomes - Kopia.xml" );

    xml.FindElem();
    xml.IntoElem();
    UsersIncome income;
    vector<UsersIncome> user2incomeArray;
    while ( xml.FindElem( "INCOME" ) ) {
        xml.IntoElem();
        xml.FindElem( "USER_ID" );
        int loadedId;
        loadedId = stoi( xml.GetData() );
        if ( loadedId == 2 ) {
            xml.FindElem( "INCOME_ID" );
            income.incomeId = stoi( xml.GetData() );
            xml.FindElem( "INCOME_LABEL" );
            income.incomeLabel = xml.GetData();
            xml.FindElem( "INCOME_VALUE" );
            income.incomeValue = stof( xml.GetData() );
            user2incomeArray.push_back(income);
        }
        xml.OutOfElem();
    }
    cout << "User 2 incomes:\n";
    for (vector<UsersIncome>::iterator itr = user2incomeArray.begin(), finish = user2incomeArray.end();
            itr != finish; itr++) {
        cout << "\nID: " << itr->incomeId;
        cout << "\t| : " << itr->incomeLabel;
        cout << "\t| : " << itr->incomeValue;
        cout << "\n";
    }

    xml.ResetPos();

    loggedUserId = users[2].id;
    cout << "Signed user's id: " << loggedUserId << endl;

    xml.FindElem();
    xml.IntoElem();
    vector<UsersIncome> user3incomeArray;
    while ( xml.FindElem( "INCOME" ) ) {
        xml.IntoElem();
        xml.FindElem( "USER_ID" );
        int loadedId;
        loadedId = stoi( xml.GetData() );
        if ( loadedId == 3 ) {
            xml.FindElem( "INCOME_ID" );
            income.incomeId = stoi( xml.GetData() );
            xml.FindElem( "INCOME_LABEL" );
            income.incomeLabel = xml.GetData();
            xml.FindElem( "INCOME_VALUE" );
            income.incomeValue = stof( xml.GetData() );
            user3incomeArray.push_back(income);
        }
        xml.OutOfElem();
    }
    cout << "User 3 incomes:\n";
    for (vector<UsersIncome>::iterator itr = user3incomeArray.begin(), finish = user3incomeArray.end();
            itr != finish; itr++) {
        cout << "\nID: " << itr->incomeId;
        cout << "\t| : " << itr->incomeLabel;
        cout << "\t| : " << itr->incomeValue;
        cout << "\n";
    }

    return 0;
}

string convertFloat2String( float number ) {
    ostringstream ss;
    ss << number;
    return ss.str();
}
