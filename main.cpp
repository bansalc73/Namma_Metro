#include <iostream>
#include<stdio.h>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iomanip>
#include<queue>
#include <cstdio>
#include "graph.cpp"

int main() {
    Graph g;

    cout << "\t\t\t****WELCOME TO THE NAMMA METRO*****\n";

    while (true) {
        cout << "\t\t\t\t~~LIST OF ACTIONS~~\n\n";
        cout << "1. LIST ALL THE STATIONS IN THE MAP\n";
        cout << "2. GET MINIMUM COST FROM A 'SOURCE' STATION TO 'DESTINATION' STATION\n";
        cout << "3. GET SHORTEST TIME TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION\n";
        cout << "4. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION\n";
        cout << "5. GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION\n";
        cout << "6. EXIT THE MENU\n";
        cout << "\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 6): ";

        int choice;
        string src,dest,temp_str;
        char src_char[35],dest_char[35];
        cin >> choice;
        cout << "\n***********************************************************\n";

        if (choice == 6) {
            break;
        }

        switch (choice) {
            case 1:
                // Implement logic for listing all stations
                g.displayStation();
                break;

            case 2:
                // Implement logic for displaying the metro map
                cout<<"\n1. TO ENTER SERIAL NO. OF STATIONS\n2.  TO ENTER NAME OF STATIONS \n3. TO ENTER CODE OF STATIONS\n";
                cout<<"ENTER YOUR CHOICE: ";
                int ch;
                cin>>ch;
                cout << "\n***********************************************************\n";
                if(ch==1){
                    int src_serial,dest_serial;
                    cout<<"ENTER SOURCE STATION SERIAL NUMBER: ";
                    cin>>src_serial;
                    cout<<"ENTER DESTINATIOM STATION SERIAL NUMBER: ";
                    cin>>dest_serial;
                    if(src_serial<1 || dest_serial<1 || dest_serial>128 || src_serial>128){
                        cout<<"INVALID CHOICE\n";
                        break;
                    }
                    else{
                        unordered_map<string,string> parent;
                        unordered_set<string> vis;
                        int interchanges;
                        auto it_src = g.vertices.begin();
                        advance(it_src,src_serial-1);
                        auto it_dest = g.vertices.begin();
                        advance(it_dest,dest_serial-1);
                        int min_dist = g.dijkstra_shortest_dist(it_src->first,
                        it_dest->first,vis,parent,interchanges);
                        cout << "\n***********************************************************\n";
                        cout<<"MINIMUM STATIONS: "<<min_dist<<endl;
                        cout<<"MINIMUM COST: "<<min_dist*10<<endl;
                        cout<<"INTERCHANGES: "<<interchanges;
                        cout << "\n***********************************************************\n";
                    }
                }
                else if(ch==2){

                    cout<<"ENTER SOURCE STATION: ";
                    scanf(" %[^\n]", src_char);
                    src = charArrayToString(src_char);
                    // cin.ignore();
                    cout<<"ENTER DESTINATION STATION NAME: ";
                    scanf(" %[^\n]", dest_char);
                    dest = charArrayToString(dest_char);
                    
                    if(!(g.containsVertex(src) && g.containsVertex(dest))){
                        cout<<src<<" "<<dest<<endl;
                        cout<<"INVALID CHOICE\n";
                        break;
                    }
                    else{
                        unordered_map<string,string> parent;
                        unordered_set<string> vis;
                        int interchanges;
                        int min_dist = g.dijkstra_shortest_dist(src,
                        dest,vis,parent,interchanges);
                        cout << "\n***********************************************************\n";
                        cout<<"MINIMUM STATIONS FROM : "<<min_dist<<endl;
                        cout<<"MINIMUM COST: "<<min_dist*10<<endl;
                        cout<<"INTERCHANGES: "<<interchanges;
                        cout << "\n***********************************************************\n";
                    }
                }
                else if(ch==3){

                }
                else{
                    cout<<"INVALID CHOICE\n";
                    break;
                }
                break;

            case 3:
                // Implement logic for getting shortest distance
                break;

            case 4:
                // Implement logic for getting shortest time
                break;

            case 5:
                // Implement logic for getting shortest path (distance wise)
                break;

            case 6:
                // Implement logic for getting shortest path (time wise)
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }






   // Accessing vertices
    // cout << g.vertices.size() << " hi" << endl;
    // cout<<g.countEdges()<<endl;
    // g.displayMap();
    // cout<<g.countVertex()<<endl;
    // g.displayStation();
    // unordered_set<string> vis;
    // cout<<g.hasPath("kundalahalli","peenya",vis)<<endl;
    // unordered_map<string,int> vis_mp;
    // cout<<g.dijkstra_shortest_time("kundalahalli","peenya",vis_mp)<<endl;
    // cout<<g.dijkstra_shortest_time("halasuru","national military school",vis_mp)<<endl;

    return 0;
}