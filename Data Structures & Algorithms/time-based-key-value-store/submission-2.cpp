class TimeMap {

    unordered_map< string, vector<pair<string,int>> > mapping;


public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mapping[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {

        if(mapping.find(key) == mapping.end()) return "";
        
        int size = mapping[key].size();


        auto &vec = mapping[key];

        int low = 0;
        int high = size-1;

        int current = size;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(vec[mid].second<=timestamp)
            {
                current = mid;
                low = mid + 1;
                continue;
            }

            high = mid - 1;
            
        }

        if(current==size) return "";

        return vec[current].first;
        
    }
};
