class DataStream {
public:
int val, k, freq=0;
    DataStream(int value, int k) {
        this->k=k;
        this->val=value;
    }
    
    bool consec(int num) {
        if(num==val) freq++;
        if(num!=val)
        {
            freq=0;
            return false;
        }
        return (freq>=k);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
