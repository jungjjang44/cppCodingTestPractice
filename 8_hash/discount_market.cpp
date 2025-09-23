#include <bits/stdc++.h>
using namespace std;

/*
1. want,number 기반으로 해시 테이블 구성
2. for문 순회 0,10->1,11->2,12...99,990,100,000
3. 만약 해시 테이블의 모든 숫자가 0이라면, count++ / 아니면 skip
*/

int check(unordered_map<string,int>& hash, vector<string>& want) {
    for (string _want:want) 
        if (hash[_want]!=0) {
            return 0;
        } 
    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // 해시 테이블 구성
    unordered_map<string,int> hash;
    for (int i=0;i<=discount.size()-10;i++){
        for (int i=0;i<want.size();i++) hash[want[i]]=number[i];
        for (int j=0;j<10;j++)
            if (hash.find(discount[i+j])!=hash.end()) hash[discount[i+j]]--;
        int add=check(hash,want);
        answer+=add;
    }

    return answer;
}