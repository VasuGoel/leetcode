class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkIns;             // card id -> {stationName, time}
    unordered_map<string, pair<double, int>> avgTimes;          // route -> {avg time, count of such routes}
    
public:
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkIns[id];
        checkIns.erase(id);
        
        string startStation = checkIn.first;
        int startTime = checkIn.second;
        
        string route = startStation + "_" + stationName;
        int timeTaken = t - startTime;
        
        if(!avgTimes.count(route))
            avgTimes[route] = {timeTaken, 1};
        else {
            auto &cur = avgTimes[route];
            cur.first = ((cur.first * cur.second) + timeTaken) / ++cur.second;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avgTimes[startStation + "_" + endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
