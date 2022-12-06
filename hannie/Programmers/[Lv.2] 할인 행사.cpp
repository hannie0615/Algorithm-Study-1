#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int sum=0;
    for(int n:number)
        sum += n; // sum=10

    map<string, int> m;
    for(int i=0; i<number.size(); i++)
        m.insert({want[i], number[i]});


    for(int i=0; i<=discount.size()-sum; i++){
        map<string, int> m2(m);
        for(int j=i; j<sum+i; j++){
            if(m2.find(discount[j])!=m2.end())
                m2[discount[j]]--;
            if(m2[discount[j]]==0)
                m2.erase(discount[j]);
            if(m2.empty()){
                answer++;
                break;
            }
        }
    }

    return answer;
}
