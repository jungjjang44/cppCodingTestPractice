// 오픈 채팅방 문제
#include <bits/stdc++.h>
using namespace std;

/*
1. hash 테이블 쓰는 게 일단 맞는 것 같다.
2. user id와 닉네임을 매칭시켜줘야 할 듯
3. record를 순회하는데, 일단 hash 테이블을 완성하는 것이 중요함 -> 그 이후에 Enter, Leave에 해당하는 아이디에 맞는 닉네임을 출력하면 됨.
3-1. Enter일 경우, (hash에 값 저장)
3-2. Leave일 경우,
*/
vector<string> split(string str) {
    vector<string> sp;
    stringstream ss(str);
    string st;
    while (ss >> st) sp.push_back(st);
    return sp;
}

vector<string> solution(vector<string> record) {
    unordered_map<string, string> hash;
    vector<string> st;
    vector<string> answer;
    for (int i=0;i<record.size(); i++){ // const auto&으로 바꾸면 더 빨라질듯?
        st=split(record.at(i));
        if (st.at(0)=="Enter" || st.at(0)=="Change") hash[st.at(1)]=st.at(2);
    }
    for (string& s:record) {
        st=split(s); // s: Enter->id->닉네임
        if (st.at(0)=="Enter") {
            string message=hash[st.at(1)]+"님이 들어왔습니다.";
            answer.push_back(message);
        } else if (st.at(0)=="Leave") {
            string message=hash[st.at(1)]+"님이 나갔습니다.";
            answer.push_back(message);            
        }
    }
    // for (const auto& [key,value]:hash) 
    //     std::cout<<key<<": "<<value<<std::endl;
    // std::cout<<hash["uid1234"]<<std::endl;

    return answer;
}