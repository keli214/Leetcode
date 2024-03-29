#include <vector>
#include <iostream>

using namespace std;

int numRabbits(vector<int>& answers) {
    sort(answers.begin(), answers.end());
    int res = 0, n = answers.size(), i = 0;
    while(i < n){
        // if i == j 
        // we count how many same rabbits has the same answer 
        // if answer[i] > count
        //  res += answer[i] + 1;
        // else
        //  group = count / (answer+1);
        //  res += group * ( answer[i] + 1)
        int maxPossibleRabbit = answers[i] + 1;
        if(i < n-1 && answers[i] == answers[i+1]){
            int j = i, count = 0;
            while(j < n && answers[j]== answers[i]){
                count ++;
                j++;
            }
            if(maxPossibleRabbit > count) 
                res += maxPossibleRabbit;
            else{
                int group =  count/(maxPossibleRabbit);
                group += count%(maxPossibleRabbit) ? 1 : 0;
                res += group * (maxPossibleRabbit);
            }
            i = j;
        }
        else {
            res += maxPossibleRabbit;
            i++;
        }
    }
    return res;
}

int main(){
    vector<int> answers {0,0,1,1,1};
    cout<<numRabbits(answers);
    return 0;
}