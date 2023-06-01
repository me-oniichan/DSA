#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> person; // {id, [station, time]}
    unordered_map<string, pair<double, int>> avgtime;
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        if(!person.count(id)) person[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &details = person[id];
        string stations = details.first + " " + stationName;
        auto &avgdetails = avgtime[stations];
        avgtime[stations] = {avgdetails.first+ t-details.second, avgdetails.second+1};
        person.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& details = avgtime[startStation+" "+endStation];
        return details.first/details.second;
    }
};
