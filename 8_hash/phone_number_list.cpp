// 전화번호 목록 - 정렬로 푼 내용

#include <bits/stdc++.h>
using namespace std;

/*
주석 코드는 해시 테이블로 푼 코드입니다.

1. map<string, int>에 문자열 저장
2. for문 돌려서 phone_book 순회
2-1. 만약 phone의 한글자씩 +=했을 때, 이게 map상에 있고, 자기 자신이 아니라면 -> 바로 false 리턴
3. true 리턴

bool solution(vector<string> phone_book) {
    unordered_map<string,int> hash;
    for (string& phone:phone_book) hash[phone]=1;
    
    for (string phone:phone_book) {
        string str="";
        for (char s:phone) {
            str+=s;
            if (hash.find(str)!=hash.end() && str!=phone) return false;
        }
    }

    return true;
}
*/

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    // for (string phone:phone_book) std::cout<<phone<<" ";
    // std::cout<<std::endl;
    for (int i=0;i<phone_book.size()-1;i++){
        if (phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())) return false;
    }
    bool answer = true;
    return answer;
}

