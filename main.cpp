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

class Node {
public:
    int value;
    Node* left; 
    Node* right;

    Node(int num) {
        this->value=num;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// 벡터 노드?
// 이진 트리 만들기 함수
void compare(Node* &node, int num) {
    if (num<node->value) {
        if (node->left==nullptr) {
            Node* newNode=new Node(num);
            node->left=newNode;
            return;
        } else compare(node->left,num); // 이상함-노드 자체를 넣어야 하는데, 포인터를 넣고 있음
    } else {
        if (node->right==nullptr) {
            Node* newNode=new Node(num);
            node->right=newNode;
            return;
        } else compare(node->right,num);
    }
    return;
}

bool search(Node* &node, int num) {
    if (num==node->value) return true;
    else if (num<node->value) {
        if (node->left==nullptr) return false;
        else search(node->left,num);
    } 
    else if (num>node->value) {
        if (node->right==nullptr) return false;
        else search(node->right,num);
    }
    return false;
}

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
    vector<bool> ans;
    return ans;
}


int main () {
    Node* root=new Node(5);
    vector<int> lst={5,3,8,4,2,1,7,10};
    vector<int> search_lst={1,2,5,6};
    for (int value:lst){
        if (value==5) continue;
        else compare(root,value);
    }

    vector<bool> answer;
    for (int value:search_lst) {
        bool ans=search(root,value);
        answer.push_back(ans);
    }

    for (bool ans:answer) std::cout<<ans<<" ";
    std::cout<<std::endl;

    return 0;
}