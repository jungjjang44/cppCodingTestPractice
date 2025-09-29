// 이진 탐색 트리 구현
/**
 * lst 배열에 있는 값을 통해 이진 탐색 트리를 생성하고, 이 이진 트리 탐색으로 search_lst 배열의 각 원소가 있는지 확인합니다. 각 원소가 이진 탐색 트리에 존재하면, true
 * 없으면 false를 반환하는 함수 solution()을 작성하세요.
 * 
 * lst:[5,3,8,4,2,1,7,10]
 * search_lst:[1,2,5,6]
 * true,true,true,false
 * 
 * Node 구조체를 만들어서, value 값과 Node 포인터 (좌,우)를 구성
 * lst for문으로 일단 순회하는데, 각 원소별로 재귀함수 사용해서 탐색 
 * 5부터 시작해서 조건문 비교, 왼쪽 노드, 오른쪽 노드를 매개변수로 넣어서 다시 재귀함수 호출
 * 만약 좌,우 노드 nullptr일 경우는 해당 노드 nullptr에 노드 정보 집어넣기(value, Node 포인터 정보)
 */


#include <bits/stdc++.h>
using namespace std;


vector<bool> solution(vector<int> lst, vector<int> search_lst) {
    vector<bool> ans;
    return ans;
}


int main () {

    return 0;
}