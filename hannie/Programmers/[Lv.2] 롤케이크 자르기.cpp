#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

/*
 * 1 ≤ 길이 ≤ 1,000,000
 * 1 ≤ 원소 ≤ 10,000
 * */

int solution(vector<int> topping) {
    int answer = 0;
    string s;

    map<int, int> m; 
    for(int t:topping){
        if(m.find(t)==m.end())
            m.insert({t,1});
        else
            m[t]++;
    } // map에 {topping 값, topping 개수} 채워주기 ex.{1:4, 2:3, 3:1, 4:1}

//    for(auto a:m)
//        cout << a.first << ' '<< a.second << endl;

    vector<int> v;
    for(auto t: topping){
        m[t]--; 
        if(m[t]==0)
            m.erase(t);
        
        if(find(v.begin(), v.end(), t)==v.end())
            v.push_back(t);
        if(m.size()==v.size())
            answer++;
        if(m.size()<v.size()) 
            break;
    }
    cout << answer << endl;

    return answer;
}
