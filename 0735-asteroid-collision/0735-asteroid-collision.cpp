class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;

        stack<int>st;

        for(int &ele : asteroids)
        {
            bool des = false;
            //then collision happens
            while(!st.empty() && st.top() > 0 && ele < 0)
            {
                if(abs(st.top()) < abs(ele))
                {
                    st.pop();
                    continue;
                }
                else if(abs(st.top()) == abs(ele))
                {
                    st.pop();
                }

                des =true;
                break;
            }

            if(!des)
            {
                st.push(ele);
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }        

        reverse(ans.begin(),ans.end());
        return ans;
    }
};