class Solution {
public:
    int findMaximizedCapital(int k, int& w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> proj;
        for(int i = 0;i < profits.size();i++)
        {
            proj.push_back({capital[i],profits[i]});
        }

        //sort it based on capital to make or arrange the projects sequentially 
        //according to the capital w
        sort(proj.begin(),proj.end());
        priority_queue<int> mxpq;
        int cost = 0;

        int i = 0;
        while(k--)
        {
            //i need to check that how many projects that i can complete within my
            //w capital
            while(i < capital.size() && proj[i].first <= w)
            {
                //push the project that is under my capital to finish the project
                mxpq.push(proj[i].second);
                i++;
            }
            
            //handle the case where we didnt got any projects with our w capital
            if(mxpq.empty())
            {
                break;
            }
            //increase our capital by choosing the project that gives max profit
           
                w += mxpq.top();
                mxpq.pop();
        }

        return w;
    }
};