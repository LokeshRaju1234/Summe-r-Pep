class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int AAM = stoi(arriveAlice.substr(0, 2));
        int AAD = stoi(arriveAlice.substr(3, 2));

        int ALM = stoi(leaveAlice.substr(0, 2));
        int ALD = stoi(leaveAlice.substr(3, 2));

        int BAM = stoi(arriveBob.substr(0, 2));
        int BAD = stoi(arriveBob.substr(3, 2));

        int BLM = stoi(leaveBob.substr(0, 2));
        int BLD = stoi(leaveBob.substr(3, 2));

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        //converting the dates to days so it will be easier to compare
        auto convert = [&](int M,int d){
            int total = d;
            for(int i = 0;i < M - 1;i++){
                total += days[i];
            }
            return total;
        };
        
        //max becuase to count the days when the both are in Roman
        int start = max(convert(AAM,AAD),convert(BAM,BAD));

        //min because once one of the people leaves earlier they are no longer in roman
        int end  = min(convert(ALM,ALD),convert(BLM,BLD));

        //to count the day inclusive we use +1 to count the day started
        //if they will never met then the answer can goes to negative thats why we use max
        int totalDays = max(0,end - start + 1);
        return totalDays;
    }
};