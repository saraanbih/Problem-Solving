class KthLargest {
public:
    vector<int> stream;
    int var = 0;
    //2 4 5 8
    int GetIndex(int num)
    {
        int start=0,end = stream.size()-1;
        int mid;
        while(start <= end)
        {
            mid = (start + end) /2;
            if(stream[mid] == num) return mid;
            if(stream[mid] > num)
                 end = mid-1;
            else
                start = mid+1;
        }
        return start;
    }

    KthLargest(int k, vector<int>& nums) 
    {
        var =k;

        for(auto &num:nums) 
            stream.push_back(num);
        
        sort(stream.begin(),stream.end());
        
    }
    
    int add(int val) 
    {
        int Index = GetIndex(val);
        stream.insert(stream.begin()+Index,val);

        return stream[stream.size()-var];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */