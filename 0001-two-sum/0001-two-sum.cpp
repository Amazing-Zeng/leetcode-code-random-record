class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            // 返回的是{key,value} key是值，value是下标
            // map.find(x) 去哈希表找key=x的元素
            auto iter=map.find(target-nums[i]);
            if(iter!=map.end())
            {
                // iter是键值对的迭代器，iter->first存的是key，->second 存的是value
                return {iter->second,i};
            }
            else
            {
                // 插入键值对
                map.insert(pair<int,int>(nums[i],i));
            }
        }
        return {};
        
    }
};