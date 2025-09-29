// 트리 순회 (이진 트리-전위,중위,후위 순회)

#include <bits/stdc++.h>
using namespace std;

/*
전위 순회: 부모->왼쪽->오른
중위 순회: 왼쪽->부모->오른
후위 순회: 왼쪽->오른->부모
*/
vector<string> l;

void preorder(int index) {
    if (index>7) return;
    l.push_back(to_string(index));
    preorder(index*2);
    preorder(index*2+1);
}

void inorder(int index) {
    if (index>7) return;
    inorder(index*2);
    l.push_back(to_string(index));
    inorder(index*2+1);
}

void postorder(int index) {
    if (index>7) return;
    postorder(index*2);
    postorder(index*2+1);
    l.push_back(to_string(index));
}

vector<string> solution(vector<int> nodes) {
    // preorder(nodes[0]);
    // inorder(nodes[0]);
    postorder(nodes[0]);
    

    return l;
}

int main () {
    vector<string> ans;
    vector<int> nodes={1,2,3,4,5,6,7};
    ans=solution(nodes);

    for (string str:ans){
        std::cout<<str<<" ";
    } std::cout<<std::endl;

    return 0;
}