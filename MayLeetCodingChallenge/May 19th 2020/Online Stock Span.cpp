class StockSpanner {
public:
    vector<pair<int, int>> map;
    
    int next(int price) {
        int span = 1;
        int index = map.size() - 1;
        while(index >= 0 && price >= map[index].first){
            span += map[index].second;
            index -= map[index].second;
        }
        map.push_back(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
