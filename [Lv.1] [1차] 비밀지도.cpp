#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0; i<n; i++){
        int first = arr1[i];
        int second = arr2[i];
        string s;
        for(int j=n-1; 0<=j; j--) {
            int cnt = pow(2, j);
            if (first / cnt == 1 || second / cnt == 1)
                s = s+'#';
            else s= s+' ';
            
            first %= cnt;
            second %= cnt;
        }
        answer.push_back(s);
    }


    return answer;
}
