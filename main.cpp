#include <iostream>
#include<vector>

#include "Markup.h"

using namespace std;

struct User
{
    int id = 0;
    string username = "";
    string password = "";
};



int main()
{
    User users[3];
    users[0].id = 1;
    users[0].username = "ziomek";
    users[0].password = "asdf";
    users[1].id = 2;
    users[1].username = "2ziomek";
    users[1].password = "2asdf";
    users[2].id = 3;
    users[2].username = "3ziomek";
    users[2].password = "3asdf";

    CMarkup xml;
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem( "root" );
    xml.IntoElem();

    for (int i = 0; i < 3; i++)
    {
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "ID", users[i].id );
        xml.AddElem(  "USERNAME", users[i].username);
        xml.AddElem( "PASSWORD", users[i].password );
        xml.OutOfElem();
    }

    xml.Save("xmlTest.xml");
    string xmlStr = xml.GetDoc();
    cout << "First xml File created!" << endl;
    cout << "What include string generated from object: \n" << xmlStr << endl;
    return 0;
}
