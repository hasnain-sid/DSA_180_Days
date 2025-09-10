class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<vector<int>>> mp;
        
        // Group points by their squared distance from origin
        for(auto& point : points) {
            int x = point[0], y = point[1];
            int distanceSquared = x * x + y * y;
            mp[distanceSquared].push_back({x, y});
        }
        
        vector<vector<int>> result;
        
        // Since map is sorted by key (distance), iterate and collect k points
        for(auto& entry : mp) {
            for(auto& point : entry.second) {
                if(result.size() < k) {
                    result.push_back(point);
                } else {
                    return result;  // We've collected k points
                }
            }
        }
        
        return result;
    }
};