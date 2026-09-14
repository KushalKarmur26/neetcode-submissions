class TimeMap {

    unordered_map< string, vector<pair<string,int>> > mapping;


public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mapping[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {

        int size = mapping[key].size();

        int low = 0;
        int high = size-1;

        int current = size;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(mapping[key][mid].second<=timestamp)
            {
                current = mid;
                low = mid + 1;
                continue;
            }

            high = mid - 1;
            
        }

        if(current==size) return "";

        return mapping[key][current].first;
        
    }
};
