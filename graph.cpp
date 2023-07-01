#include <iostream>
#include<stdio.h>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iomanip>
#include<stack>
#include<queue>
#include <cstdio>

using namespace std;
typedef pair<int,string> dij_pair;
enum Line {Purple,Green,Yellow,Pink,Blue};
#define MAX_STATIONS 126;

class Vertex {
public:
    map<string, int> adj_nodes;
    Line line_code;
    int station_code;
};

class Graph {
public:
    map<string, Vertex> vertices;

public:
    Graph() {
        createStations();
        createLinks();
    }

    void createStations(){
        //purple line
        this->addVertex("whitefield",Purple,1);
        this->addVertex("channasandra",Purple,2);
        this->addVertex("kadugodi",Purple,3);
        this->addVertex("pattandur agrahara",Purple,4);
        this->addVertex("sri sathya sai hospital",Purple,5);
        this->addVertex("nallurhalli",Purple,6);
        this->addVertex("kundalahalli",Purple,7);
        this->addVertex("sitharama Palya",Purple,8);
        this->addVertex("hoodi junction",Purple,9);
        this->addVertex("garudacharapalya",Purple,10);
        this->addVertex("mahadevapura",Purple,11);
        this->addVertex("krishnarajapuram",Purple,12);
        this->addVertex("benniganahalli",Purple,13);
        this->addVertex("baiyappanahalli",Purple,14);
        this->addVertex("swami vivekananda road",Purple,15);
        this->addVertex("indiranagar",Purple,16);
        this->addVertex("halasuru",Purple,17);
        this->addVertex("trinity",Purple,18);
        this->addVertex("mg road",Purple,19);
        this->addVertex("cubbon park",Purple,20);
        this->addVertex("vidhana soudha",Purple,21);
        this->addVertex("central college",Purple,22);
        this->addVertex("kempegowda majestic",Purple,23);
        this->addVertex("ksr city railway station",Purple,24);
        this->addVertex("magadi road",Purple,25);
        this->addVertex("hosahalli",Purple,26);
        this->addVertex("vijayanagar",Purple,27);
        this->addVertex("attiguppe",Purple,28);
        this->addVertex("deepanjali nagar",Purple,29);
        this->addVertex("mysuru Road",Purple,30);
        this->addVertex("nayandahalli",Purple,31);
        this->addVertex("rajarajeshwari nagar",Purple,32);
        this->addVertex("jnanabharathi",Purple,33);
        this->addVertex("pattanagere",Purple,34);
        this->addVertex("kengeri bus terminal",Purple,35);
        this->addVertex("kengeri",Purple,36);
        this->addVertex("challaghatta",Purple,37);

        // //green line
        this->addVertex("madavara",Green,38);
        this->addVertex("chikkabidarakallu",Green,39);
        this->addVertex("manjunathanagar",Green,40);
        this->addVertex("nagasandra",Green,41);
        this->addVertex("dasarahalli",Green,42);
        this->addVertex("jalahalli",Green,43);
        this->addVertex("peenya industry",Green,44);
        this->addVertex("peenya",Green,45);
        this->addVertex("goraguntepalya",Green,46);
        this->addVertex("yeshwanthpur",Green,47);
        this->addVertex("sandal soap factory",Green,48);
        this->addVertex("mahalakshmi",Green,49);
        this->addVertex("rajaji nagar",Green,50);
        this->addVertex("mahakavi kuvempu road",Green,51);
        this->addVertex("srirampura",Green,52);
        this->addVertex("sampige road",Green,53);
        this->addVertex("chickpete",Green,54);
        this->addVertex("krishna rajendra market",Green,55);
        this->addVertex("national college",Green,56);
        this->addVertex("lalbagh",Green,57);
        this->addVertex("south end circle",Green,58);
        this->addVertex("jayanagar",Green,59);
        this->addVertex("rashtreeya vidyalaya road",Green,60);
        this->addVertex("banashankari",Green,61);
        this->addVertex("jaya prakash nagar",Green,62);
        this->addVertex("yelachenahalli",Green,63);
        this->addVertex("doddakallasandra",Green,64);
        this->addVertex("konankunte cross",Green,65);
        this->addVertex("vajarahalli",Green,66);
        this->addVertex("talaghattapura",Green,67);
        this->addVertex("silk institute",Green,68);

        //pink line
        this->addVertex("kalena agrahara",Pink,69);
        this->addVertex("hulimavu",Pink,70);
        this->addVertex("iimb",Pink,71);
        this->addVertex("jp nagar 4th phase",Pink,72);
        this->addVertex("jayadeva hospital",Pink,73);
        this->addVertex("tavarekere",Pink,74);
        this->addVertex("dairy circle",Pink,75);
        this->addVertex("lakkasandra",Pink,76);
        this->addVertex("langford town",Pink,77);
        this->addVertex("national military school",Pink,78);
        this->addVertex("shivajinagar",Pink,79);
        this->addVertex("cantonment",Pink,80);
        this->addVertex("pottery town",Pink,81);
        this->addVertex("tannery road",Pink,82);
        this->addVertex("venkateshpura",Pink,83);
        this->addVertex("kadugundanahalli",Pink,84);
        this->addVertex("nagawara",Pink,85);

        //Yellow Lin;
        this->addVertex("ragigudda",Yellow,86);
        this->addVertex("btm layout",Yellow,87);
        this->addVertex("central silk board",Yellow,88);
        this->addVertex("bommanahalli",Yellow,89);
        this->addVertex("hongasandra",Yellow,90);
        this->addVertex("kudlu gate",Yellow,91);
        this->addVertex("singasandra",Yellow,92);
        this->addVertex("hosa road",Yellow,93);
        this->addVertex("beratena agrahara",Yellow,94);
        this->addVertex("konappana agrahara",Yellow,95);
        this->addVertex("electronic city",Yellow,96);
        this->addVertex("huskur road",Yellow,97);
        this->addVertex("hebbagodi",Yellow,98);
        this->addVertex("bommasandra",Yellow,99);
    
        //Blue Line
        this->addVertex("hsr layout",Blue,100);
        this->addVertex("agara lake",Blue,101);
        this->addVertex("ibbaluru",Blue,102);
        this->addVertex("bellanduru",Blue,103);
        this->addVertex("kadubeesanahalli",Blue,104);
        this->addVertex("kodibeesanahalli",Blue,105);
        this->addVertex("marathahalli",Blue,106);
        this->addVertex("isro",Blue,107);
        this->addVertex("doddanekundi",Blue,108);
        this->addVertex("drdo sports complex",Blue,109);
        this->addVertex("sarasvathi nagara",Blue,110);
        this->addVertex("kasturinagara",Blue,111);
        this->addVertex("horamavu",Blue,112);
        this->addVertex("hrbr layout",Blue,113);
        this->addVertex("kalyan nagara",Blue,114);
        this->addVertex("hbr layout",Blue,115);
        this->addVertex("veerannapalya",Blue,116);
        this->addVertex("kempapura",Blue,117);
        this->addVertex("hebbala",Blue,118);
        this->addVertex("kodigehalli",Blue,119);
        this->addVertex("jakkuru cross",Blue,120);
        this->addVertex("yelahanka",Blue,121);
        this->addVertex("bagaluru cross",Blue,122);
        this->addVertex("bettahalasuru",Blue,123);
        this->addVertex("doddajala",Blue,124);
        this->addVertex("airport city",Blue,125);
        this->addVertex("kial terminals",Blue,126);
    }

    void createLinks(){
        //purple line
        this->addEdge("whitefield","channasandra",7);
        this->addEdge("channasandra","kadugodi",12);
        this->addEdge("kadugodi","pattandur agrahara",8);
        this->addEdge("pattandur agrahara","sri sathya sai hospital",10);
        this->addEdge("sri sathya sai hospital","nallurhalli",15);
        this->addEdge("nallurhalli","kundalahalli",5);
        this->addEdge("kundalahalli","sitharama Palya",5);
        this->addEdge("sitharama Palya","hoodi junction",7);
        this->addEdge("hoodi junction","garudacharapalya",7);
        this->addEdge("garudacharapalya","mahadevapura",5);
        this->addEdge("mahadevapura","krishnarajapuram",5);
        this->addEdge("krishnarajapuram","benniganahalli",10);
        this->addEdge("benniganahalli","baiyappanahalli",5);
        this->addEdge("baiyappanahalli","swami vivekananda road",10);
        this->addEdge("swami vivekananda road","indiranagar",5);
        this->addEdge("indiranagar","halasuru",10);
        this->addEdge("halasuru","trinity",5);
        this->addEdge("trinity","mg road",5);
        this->addEdge("mg road","cubbon park",10);
        this->addEdge("cubbon park","vidhana soudha",5);
        this->addEdge("vidhana soudha","central college",8);
        this->addEdge("central college","kempegowda majestic",7);
        this->addEdge("kempegowda majestic","ksr city railway station",7);
        this->addEdge("ksr city railway station","magadi road",5);
        this->addEdge("magadi road","hosahalli",10);
        this->addEdge("hosahalli","vijayanagar",5);
        this->addEdge("vijayanagar","attiguppe",10);
        this->addEdge("attiguppe","deepanjali nagar",5);
        this->addEdge("deepanjali nagar","mysuru Road",5);
        this->addEdge("mysuru Road","nayandahalli",10);
        this->addEdge("nayandahalli","rajarajeshwari nagar",5);
        this->addEdge("rajarajeshwari nagar","jnanabharathi",10);
        this->addEdge("jnanabharathi","pattanagere",10);
        this->addEdge("pattanagere","kengeri bus terminal",7);
        this->addEdge("kengeri bus terminal","kengeri",10);
        this->addEdge("kengeri","challaghatta",5);



        //green line
        this->addEdge("madavara","chikkabidarakallu",8);
        this->addEdge("chikkabidarakallu","manjunathanagar",5);
        this->addEdge("manjunathanagar","nagasandra",5);
        this->addEdge("nagasandra","dasarahalli",10);
        this->addEdge("dasarahalli","jalahalli",7);
        this->addEdge("jalahalli","peenya industry",10);
        this->addEdge("peenya industry","peenya",5);
        this->addEdge("peenya","goraguntepalya",10);
        this->addEdge("goraguntepalya","yeshwanthpur",10);
        this->addEdge("yeshwanthpur","sandal soap factory",5);
        this->addEdge("sandal soap factory","mahalakshmi",5);
        this->addEdge("mahalakshmi","rajaji nagar",10);
        this->addEdge("rajaji nagar","mahakavi kuvempu road",5);
        this->addEdge("mahakavi kuvempu road","srirampura",5);
        this->addEdge("srirampura","sampige road",10);
        this->addEdge("sampige road","kempegowda majestic",5);
        this->addEdge("kempegowda majestic","chickpete",5);
        this->addEdge("chickpete","krishna rajendra market",5);
        this->addEdge("krishna rajendra market","national college",10);
        this->addEdge("national college","lalbagh",7);
        this->addEdge("lalbagh","south end circle",7);
        this->addEdge("south end circle","jayanagar",8);
        this->addEdge("jayanagar","rashtreeya vidyalaya road",5);
        this->addEdge("rashtreeya vidyalaya road","banashankari",5);
        this->addEdge("banashankari","jaya prakash nagar",5);
        this->addEdge("jaya prakash nagar","yelachenahalli",10);
        this->addEdge("yelachenahalli","doddakallasandra",5);
        this->addEdge("doddakallasandra","konankunte cross",5);
        this->addEdge("konankunte cross","vajarahalli",10);
        this->addEdge("vajarahalli","talaghattapura",5);
        this->addEdge("talaghattapura","silk institute",10);

        // //pink line
        this->addEdge("kalena agrahara","hulimavu",7);
        this->addEdge("hulimavu","iimb",5);
        this->addEdge("iimb","jp nagar 4th phase",5);
        this->addEdge("jp nagar 4th phase","jayadeva hospital",5);
        this->addEdge("jayadeva hospital","tavarekere",10);
        this->addEdge("tavarekere","dairy circle",7);
        this->addEdge("dairy circle","lakkasandra",5);
        this->addEdge("lakkasandra","langford town",10);
        this->addEdge("langford town","national military school",5);
        this->addEdge("national military school","mg road",10);
        this->addEdge("mg road","shivajinagar",5);
        this->addEdge("shivajinagar","cantonment",7);
        this->addEdge("cantonment","pottery town",10);
        this->addEdge("pottery town","tannery road",5);
        this->addEdge("tannery road","venkateshpura",5);
        this->addEdge("venkateshpura","kadugundanahalli",7);
        this->addEdge("kadugundanahalli","nagawara",5);


        //Yellow Line
        this->addEdge("rashtreeya vidyalaya road","ragigudda",5);
        this->addEdge("ragigudda","jayadeva hospital",5);
        this->addEdge("jayadeva hospital","btm layout",7);
        this->addEdge("btm layout","central silk board",5);
        this->addEdge("central silk board","bommanahalli",5);
        this->addEdge("bommanahalli","hongasandra",5);
        this->addEdge("hongasandra","kudlu gate",7);
        this->addEdge("kudlu gate","singasandra",5);
        this->addEdge("singasandra","hosa road",8);
        this->addEdge("hosa road","beratena agrahara",5);
        this->addEdge("beratena agrahara","konappana agrahara",7);
        this->addEdge("konappana agrahara","electronic city",5);
        this->addEdge("electronic city","huskur road",5);
        this->addEdge("huskur road","hebbagodi",7);
        this->addEdge("hebbagodi","bommasandra",5);

        //Blue line
        this->addEdge("central silk board","hsr layout",5);
        this->addEdge("hsr layout","agara lake",5);
        this->addEdge("agara lake","ibbaluru",7);
        this->addEdge("ibbaluru","bellanduru",5);
        this->addEdge("bellanduru","kadubeesanahalli",5);
        this->addEdge("kadubeesanahalli","kodibeesanahalli",5);
        this->addEdge("kodibeesanahalli","marathahalli",7);
        this->addEdge("marathahalli","isro",5);
        this->addEdge("isro","doddanekundi",8);
        this->addEdge("doddanekundi","drdo sports complex",5);
        this->addEdge("drdo sports complex","sarasvathi nagara",7);
        this->addEdge("sarasvathi nagara","krishnarajapuram",5);
        this->addEdge("krishnarajapuram","kasturinagara",5);
        this->addEdge("kasturinagara","horamavu",7);
        this->addEdge("horamavu","hrbr layout",5);
        this->addEdge("hrbr layout","kalyan nagara",7);
        this->addEdge("kalyan nagara","hbr layout",5);
        this->addEdge("hbr layout","nagawara",5);
        this->addEdge("nagawara","veerannapalya",7);
        this->addEdge("veerannapalya","kempapura",5);
        this->addEdge("kempapura","hebbala",7);
        this->addEdge("hebbala","kodigehalli",5);
        this->addEdge("kodigehalli","jakkuru cross",5);
        this->addEdge("jakkuru cross","yelahanka",5);
        this->addEdge("yelahanka","bagaluru cross",5);
        this->addEdge("bagaluru cross","bettahalasuru",5);
        this->addEdge("bettahalasuru","doddajala",5);
        this->addEdge("doddajala","airport city",5);
        this->addEdge("airport city","kial terminals",5);
    }

    int countVertex(){
        return vertices.size();
    }

    bool containsVertex(string v_name){
        transform(v_name.begin(), v_name.end(), v_name.begin(), ::tolower);
        return vertices.find(v_name) != vertices.end();
    } 

    void addVertex(string vname,Line code,int st_code){
        Vertex temp;
        temp.line_code = code;
        temp.station_code = st_code;
        vertices[vname] = temp;
    }   

    void removeVertex(string v_name){
        Vertex temp = vertices[v_name];
        for(auto it:temp.adj_nodes){
            Vertex nbr_temp = vertices[it.first];
            nbr_temp.adj_nodes.erase(v_name);
        }
        vertices.erase(v_name);
    }

    int countEdges(){
        int count = 0;
        for(auto it:vertices){
            Vertex temp = it.second;
            count += temp.adj_nodes.size();
        }
        return count/2;
    }

    bool containsEdge(string v_name1,string v_name2){
        if(vertices.find(v_name1)==vertices.end() || vertices.find(v_name2)==vertices.end()){
            return false;
        }
        Vertex v1 = vertices[v_name1];
        if(v1.adj_nodes.find(v_name2)==v1.adj_nodes.end()){
            return false;
        }
        return true;
    }

    void addEdge(string v_name1,string v_name2,int val){
        if(vertices.find(v_name1)==vertices.end() || vertices.find(v_name2)==vertices.end()){
            return;
        }
        Vertex v1 = vertices[v_name1];
        Vertex v2 = vertices[v_name2];

        if(v1.adj_nodes.find(v_name2)==v1.adj_nodes.end()){
            v1.adj_nodes[v_name2] = val;
            v2.adj_nodes[v_name1] = val;
            vertices[v_name1] = v1;
            vertices[v_name2] = v2;
        }

    }

    void removeEdge(string v_name1,string v_name2){
        if(vertices.find(v_name1)==vertices.end() || vertices.find(v_name2)==vertices.end()){
            return;
        }
        Vertex v1 = vertices[v_name1];
        Vertex v2 = vertices[v_name2];
        if(v1.adj_nodes.find(v_name2)!=v1.adj_nodes.end()){
            v1.adj_nodes.erase(v_name2);
            v2.adj_nodes.erase(v_name1);
            vertices[v_name1] = v1;
            vertices[v_name2] = v2;
        }
    }

    void displayMap(){
        cout<<"\t Namma Metro Map";
        cout<<"\t------------------\n";
        // cout<<"----------------------------------------------------\n";
        for(auto it:vertices){
            string temp = it.first;
            string str = temp + " =>\n";
            Vertex v_temp = it.second;
            for(auto itr:v_temp.adj_nodes){
                str += "\t" + itr.first + "\t";
                if (temp.length()<16) str = str + "\t";    			
                if (temp.length()<8) str = str + "\t";    			
                str = str + to_string(itr.second )+ "\n";
            }
            cout<<str<<endl;
        }
        cout<<"\t------------------------------------\n";
        // cout<<"----------------------------------------------------\n";
    }

    string getLineString(Line temp){
        if(temp==Purple) return "Purple";
        else if(temp==Green) return "Green";
        else if(temp==Yellow) return "Yellow";
        else if(temp==Pink) return "Pink";
        else return "Blue";
    }

    void displayStation(){
        int i = 1;
        cout << "\n***********************************************************\n";
        cout << "SNo. "
        << setw(3) << "STATION NAME"
        << setw(17) << "LINE"
        << setw(17) << "STATION CODE\n";
        for(auto it:vertices){
            Vertex station_vertex = it.second;
            string station_name = it.first;
            Line station_line = station_vertex.line_code;
            transform(station_name.begin(), station_name.end(), station_name.begin(), ::toupper);
            cout << left << setw(5) << i 
            << setw(25) << station_name
            << setw(8) << getLineString(station_line)
            << setw(6) << station_vertex.station_code << endl;
            i++;
        }
        cout << "\n***********************************************************\n";

    }

    bool hasPath(string v_name1,string v_name2,unordered_set<string>& vis){
        Vertex temp = vertices[v_name1];
        if(temp.adj_nodes.find(v_name2)!=temp.adj_nodes.end()){
            return true;
        }
        vis.insert(v_name1);
        for(auto it:temp.adj_nodes){
            if(vis.find(it.first)==vis.end()){
                if(hasPath(it.first,v_name2,vis)) return true;
            }
        }
        return false;
    }


    int countInterchanges(unordered_map<string,string> parent,string dest){
        int count = 0;
        string temp = dest;
        while(parent[temp]!=temp){
            Vertex v1 = vertices[temp];
            Vertex v2 = vertices[parent[temp]];
            if(v1.line_code!=v2.line_code){
                count++;
            }
            temp = parent[temp];
        }
        return count;
    }
    string tranformToUpper(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }

    void setPath(string& path_str,unordered_map<string,string>& parent,string dest){
        string temp = dest;
        stack<string> str_stack;
        while(parent[temp]!=temp){
            str_stack.push(tranformToUpper(temp));
            Vertex v1 = vertices[temp];
            Vertex v2 = vertices[parent[temp]];
            if(v1.line_code!=v2.line_code){
                string inter_temp = " Interchange from " + getLineString(v1.line_code) + " <==> " + getLineString(v2.line_code) + " Line";
                str_stack.push(inter_temp);
            }
            temp = parent[temp];
        }
        str_stack.push(tranformToUpper(temp));
        while(!str_stack.empty()){
            path_str += str_stack.top();
            path_str+=" => ";
            str_stack.pop();
        }
        path_str += "REACHED";
    }


    int dijkstra_shortest_dist(string src,string dest,unordered_set<string>& vis,
    unordered_map<string,string>& parent,int& interchange_count,bool toPrintPath,string& path_str){
        queue<dij_pair> q;
        
        //Set parent initialll as vertex itself
        for(auto it:vertices){
            parent[it.first] = it.first;
        }

        dij_pair dij_p;
        dij_p.first = 0;
        dij_p.second = src;
        q.push(dij_p);
        vis.insert(src);
        while(!q.empty()){
            string temp = q.front().second;
            Vertex node = vertices[temp];
            int dist = q.front().first;
            q.pop();
            if(temp==dest) {
                interchange_count = countInterchanges(parent,dest);
                if(toPrintPath==true) {
                    setPath(path_str,parent,dest);
                }
                return dist;
            }
            for(auto it:node.adj_nodes){
                if(vis.find(it.first)==vis.end()){
                    parent[it.first] = temp;
                    vis.insert(it.first);
                    dij_p.first = dist+1;
                    dij_p.second = it.first;
                    q.push(dij_p);
                }
            }
        }
        return 0;
    }
    int dijkstra_shortest_time(string src,string dest,unordered_map<string,int>& time,
    unordered_map<string,string>& parent,int& interchange_count,bool toPrintPath,string& path_str){
        priority_queue<dij_pair,vector<dij_pair>,greater<dij_pair> > q;
        //Set parent initialll as vertex itself
        for(auto it:vertices){
            parent[it.first] = it.first;
        }

        for(auto it:vertices){
            time[it.first] = 1e9;
            if(it.first==src){
                time[it.first] = 0;
            }
        }
        dij_pair dij_p;
        dij_p.first = 0;
        dij_p.second = src;
        q.push(dij_p);
        while(!q.empty()){
            string temp = q.top().second;
            Vertex node = vertices[temp];
            int time_temp = q.top().first;
            q.pop();
            if(temp==dest){
                interchange_count = countInterchanges(parent,dest);
                if(toPrintPath==true) {
                    setPath(path_str,parent,dest);
                }
                return time_temp;
            } 
            for(auto it:node.adj_nodes){
                if(time[it.first] > time_temp + it.second){
                    parent[it.first] = temp;
                    time[it.first] = time_temp+it.second;
                    dij_p.first = time[it.first];
                    dij_p.second = it.first;
                    q.push(dij_p);
                }
            }
        }
        return 0;
    }

};

