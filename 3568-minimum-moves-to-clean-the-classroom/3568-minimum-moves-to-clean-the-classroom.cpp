class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
       int litterCount = 0;
       int n = classroom.size(),m = classroom[0].size();
       vector<vector<int>> litter(n,vector<int>(m,-1));
       int startX = -1,startY = -1;
       //we need to count how many litters are there so that we can use this info while exploring the paths so that  I can complete all litters within my capacity
       for(int i = 0;i < n;i++)
       {
        for(int j = 0;j < m;j++){
            //this is the starting point i need to start
            if(classroom[i][j] == 'S'){
                startX = i,startY = j;
            }
            else if(classroom[i][j] == 'L'){
                //we encouter a litter so increase the count of the littercount
                litter[i][j] = litterCount++;
            }
        }
       }

       //if we dont found litters then steps required is 0
       if(litterCount == 0) return 0;

       //at each level dist i need to track energy i consumed,how many litters i collected
       //so the state is (pos,energy,litterCount(represented in bits))
       queue<array<int,5>> q;
       //for every col we have energy and litterCount mask ->bcz for every pos we need to check how much energy i havee consumed and how many litters i have collected
       //for every path i need to check how much energy i have consumed and how many litters
        //->i have collected -> true or false (with this energy,litter i visited or not)
       vector<vector<vector<vector<bool>>>> vis(n,vector<vector<vector<bool>>>(m,vector<vector<bool>>(energy + 1,vector<bool>(1 << litterCount,false))));
                //example looks like:
                // │
                // ├── row 0
                // │   │
                // │   ├── col 0
                // │   │   ├── energy 0 → [F F F F]
                // │   │   ├── energy 1 → [F F F F]
                // │   │   └── energy 2 → [F F F F]
                // │   │
                // │   ├── col 1
                // │   │   ├── energy 0 → [F F F F]
                // │   │   ├── energy 1 → [F F F F]
                // │   │   └── energy 2 → [F F F F]
                // │   │
                // │   └── col 2
                // │       ├── energy 0 → [F F F F]
                // │       ├── energy 1 → [F F F F]
                // │       └── energy 2 → [F F F F]
                // │
                // └── row 1
                //     ...

       q.push({startX,startY,energy,0,0});
       vis[startX][startY][energy][0] = true;

       int dr[4] = {-1,1,0,0};
       int dc[4] = {0,0,-1,1};
       while(!q.empty()){
        auto [r,c,e,mask,steps] = q.front();
        q.pop();

        if(e == 0) continue;
        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >=0 && nc < m && classroom[nr][nc] != 'X'){
                int ne = e - 1;//consumes energy for each step
                int ne_mask = mask;

                //when litter found turn the litter position into one to represent that i have
                //processed these many litters till now 
                if(classroom[nr][nc] == 'L'){
                    ne_mask |= (1 << litter[nr][nc]);
                }

                if(ne_mask == (1 << litterCount) - 1){
                    return steps + 1;
                }
                //when we found the R (reset the energy to maximum) so we will increase it
                //to max capactity(energy)
                if(classroom[nr][nc] == 'R'){
                    ne = energy;
                }

                if(!vis[nr][nc][ne][ne_mask]){
                    vis[nr][nc][ne][ne_mask] = true;
                    q.push({nr,nc,ne,ne_mask,steps + 1});
                }
            }
        }
       }

       return -1;
    }
};