#include <bits/stdc++.h>

using namespace std;

/**
실패율 정의: 스테이지 도달했지만 클리어 X / 스테이지 도달 플레이어 수
만약 실패율이 같은 스테이지 잇을 경우 낮은 번호 스테이지가 먼저
스테이지에 도달한 유저가 없으면 해당 실패율은 0
1. N만큼 반복 (스테이지 1->2->3...->N)
2. 해당 스테이지에 대한 실패율 정의
3. pair를 사용해서 실패율과 해당 스테이지를 집어넣음
4. map.first(실패율) 기준으로 내림차순 정렬 및 map.second -> result에 넣기
*/

bool compare(pair<int,double>& a,pair<int,double>& b) {
    if (a.second==b.second) return a.first<b.first;
    return a.second>b.second; // 내림차순 정렬 방법
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double failrate;
    vector<pair<int,double>> fail(N); // 실패율 pair
    int size=stages.size(); // 8
    for (int i=1;i<=N;i++) { // 스테이지 1->2->3->4->5
        int cnt=count(stages.begin(),stages.end(),i); // 
        fail[i-1].first=i;
        // 실패율 정의
        if (size!=0) failrate=cnt/(double)size; // 
        else failrate=0.0;
        fail[i-1].second=failrate;
        size-=cnt;
    }
    
    // pair 기준 정렬
    sort(fail.begin(),fail.end(),compare);
    for (int i=0;i<fail.size();i++) {
        answer.push_back(fail[i].first);
    }
    
    return answer;
}