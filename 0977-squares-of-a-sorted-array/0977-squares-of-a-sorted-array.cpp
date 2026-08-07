class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int nt = nums.size();

        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < nt; i++) {

            if(nums[i] >= 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        if(pos.size() == 0) {

            for(int i = 0; i < neg.size(); i++)
                neg[i] *= neg[i];

            reverse(neg.begin(), neg.end());

            return neg;
        }

        if(neg.size() == 0) {

            for(int i = 0; i < pos.size(); i++)
                pos[i] *= pos[i];

            return pos;
        }

        int n = pos.size();
        int m = neg.size();

        for(int i = 0; i < n; i++)
            pos[i] *= pos[i];

        for(int i = 0; i < m; i++)
            neg[i] *= neg[i];

        reverse(neg.begin(), neg.end());

        int i = 0;
        int j = 0;
        int id = 0;

        vector<int> res(n + m);

        while(i < n && j < m) {

            if(neg[j] <= pos[i]) {

                res[id++] = neg[j++];
            }
            else {

                res[id++] = pos[i++];
            }
        }

        while(i < n)
            res[id++] = pos[i++];

        while(j < m)
            res[id++] = neg[j++];

        return res;
    }
};