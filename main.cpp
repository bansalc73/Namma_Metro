#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iomanip>
#include <queue>
#include <cstdio>
#include "graph.cpp"

std::string charArrayToString(const char *charArray)
{
    std::string str(charArray);
    return str;
}

string tranformToUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}
string tranformToLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
void printInBox(string& text) {
    cout << "\n*****************************PATH IS******************************\n";
    cout<<text<<endl;
    cout << "\n******************************************************************\n";
}

void printMinStation(string src, string dest, int min_dist, int interchanges)
{
    cout << "\n***********************************************************\n";
    cout << "Minimum cost from " << tranformToUpper(src) << " ==> " << tranformToUpper(dest) << " is " << min_dist * 10 << endl;
    cout << "Minimum stations from " << tranformToUpper(src) << " ==> " << tranformToUpper(dest) << " is " << min_dist << endl;
    cout << "Interchanges in this path from " << tranformToUpper(src) << " ==> " << tranformToUpper(dest) << " is " << interchanges;
    cout << "\n***********************************************************\n";
}

int main()
{
    Graph g;

    cout << "\t\t\t****WELCOME TO THE NAMMA METRO*****\n";

    while (true)
    {
        cout << "\t\t\t\t~~LIST OF ACTIONS~~\n\n";
        cout << "1. LIST ALL THE STATIONS IN THE MAP\n";
        cout << "2. GET MINIMUM COST BETWEEN TWO STATIONS\n";
        cout << "3. GET SHORTEST TIME BETWEEN TWO STATIONS\n";
        cout << "4. GET MINIMUM COST PATH BETWEEN TWO STATIONS\n";
        cout << "5. GET SHORTEST TIME PATH BETWEEN TWO STATIONS\n";
        cout << "6. EXIT THE MENU\n";
        cout << "\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 6): ";

        int choice;
        string src, dest, temp_str;
        char src_char[35], dest_char[35];
        cin >> choice;
        cout << "\n***********************************************************\n";

        if (choice == 6)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            // Implement logic for listing all stations
            g.displayStation();
            break;

        case 2:
            // Implement logic for min cost
            cout << "\n1. TO ENTER SERIAL NO. OF STATIONS\n2.  TO ENTER NAME OF STATIONS \n3. TO ENTER CODE OF STATIONS\n";
            cout << "ENTER YOUR CHOICE: ";
            int ch;
            cin >> ch;
            cout << "\n***********************************************************\n";
            if (ch == 1)
            {
                int src_serial, dest_serial;
                cout << "\nENTER SOURCE STATION SERIAL NUMBER: ";
                cin >> src_serial;
                cout << "ENTER DESTINATIOM STATION SERIAL NUMBER: ";
                cin >> dest_serial;
                if (src_serial < 1 || dest_serial < 1 || dest_serial > 128 || src_serial > 128)
                {
                    cout << "INVALID CHOICE\n";
                    break;
                }
                else
                {
                    unordered_map<string, string> parent;
                    unordered_set<string> vis;
                    int interchanges;
                    auto it_src = g.vertices.begin();
                    advance(it_src, src_serial - 1);
                    auto it_dest = g.vertices.begin();
                    advance(it_dest, dest_serial - 1);
                    string path_str;
                    int min_dist = g.dijkstra_shortest_dist(it_src->first,
                                                            it_dest->first, vis, parent, interchanges,false,path_str);
                    printMinStation(it_src->first, it_dest->first, min_dist, interchanges);
                }
            }
            else if (ch == 2)
            {
                cout << "\nENTER SOURCE STATION: ";
                scanf(" %[^\n]", src_char);
                src = charArrayToString(src_char);
                src = tranformToLower(src);

                // cin.ignore();
                cout << "ENTER DESTINATION STATION NAME: ";
                scanf(" %[^\n]", dest_char);
                dest = charArrayToString(dest_char);
                dest = tranformToLower(dest);

                if (!(g.containsVertex(src) && g.containsVertex(dest)))
                {
                    cout << src << " " << dest << endl;
                    cout << "INVALID CHOICE\n";
                    break;
                }
                else
                {
                    unordered_map<string, string> parent;
                    unordered_set<string> vis;
                    int interchanges;
                    string path_str;
                    int min_dist = g.dijkstra_shortest_dist(src,
                                                            dest, vis, parent, interchanges,false,path_str);
                    printMinStation(src, dest, min_dist, interchanges);
                }
            }
            else if (ch == 3)
            {
            }
            else
            {
                cout << "INVALID CHOICE\n";
                break;
            }
            break;

        case 3:
            // Implement logic for getting shortest time

            break;

        case 4:
            // Implement logic for getting shortest ditsnace path
            cout << "\n1. TO ENTER SERIAL NO. OF STATIONS\n2.  TO ENTER NAME OF STATIONS \n3. TO ENTER CODE OF STATIONS\n";
            cout << "ENTER YOUR CHOICE: ";
            // int ch;
            cin >> ch;
            cout << "\n***********************************************************\n";
            if (ch == 1)
            {
                int src_serial, dest_serial;
                cout << "\nENTER SOURCE STATION SERIAL NUMBER: ";
                cin >> src_serial;
                cout << "ENTER DESTINATIOM STATION SERIAL NUMBER: ";
                cin >> dest_serial;
                if (src_serial < 1 || dest_serial < 1 || dest_serial > 128 || src_serial > 128)
                {
                    cout << "INVALID CHOICE\n";
                    break;
                }
                else
                {
                    unordered_map<string, string> parent;
                    unordered_set<string> vis;
                    int interchanges;
                    auto it_src = g.vertices.begin();
                    advance(it_src, src_serial - 1);
                    auto it_dest = g.vertices.begin();
                    advance(it_dest, dest_serial - 1);
                    string path_str;
                    int min_dist = g.dijkstra_shortest_dist(it_src->first,
                                                            it_dest->first, vis, parent, interchanges,true,path_str);

                    printMinStation(it_src->first, it_dest->first, min_dist, interchanges);
                    printInBox(path_str);
                    // cout<<"PATH IS : \n"<<path_str<<endl;
                }
            }
            else if (ch == 2)
            {
                cout << "\nENTER SOURCE STATION: ";
                scanf(" %[^\n]", src_char);
                src = charArrayToString(src_char);
                src = tranformToLower(src);

                // cin.ignore();
                cout << "ENTER DESTINATION STATION NAME: ";
                scanf(" %[^\n]", dest_char);
                dest = charArrayToString(dest_char);
                dest = tranformToLower(dest);

                if (!(g.containsVertex(src) && g.containsVertex(dest)))
                {
                    cout << src << " " << dest << endl;
                    cout << "INVALID CHOICE\n";
                    break;
                }
                else
                {
                    unordered_map<string, string> parent;
                    unordered_set<string> vis;
                    int interchanges;
                    string path_str;
                    int min_dist = g.dijkstra_shortest_dist(src,dest, vis, parent, interchanges,true,path_str);
                    printMinStation(src, dest, min_dist, interchanges);
                    printInBox(path_str);
                    // cout<<"PATH IS : \n"<<path_str<<endl;
                }
            }
            else if (ch == 3)
            {
            }
            else
            {
                cout << "INVALID CHOICE\n";
                break;
            }
            break;

            break;

        case 5:
            // Implement logic for getting shortest path (distance wise)
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}