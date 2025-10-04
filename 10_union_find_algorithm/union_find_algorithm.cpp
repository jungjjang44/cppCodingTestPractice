/**
 * 유니온-파인드 알고리즘
*/

#include <bits/stdc++.h>
using namespace std;

int findRootNode(int parents[], int x){
    if (parents[x] == x) return x;
    return parents[x]=findRootNode(parents, parents[x]); // ★ 경로 압축
}


void unionFunc(int parents[],int ranks[],const vector<string>& oper){
    int p1=findRootNode(parents,stoi(oper[1])); // 3
    int p2=findRootNode(parents,stoi(oper[2])); // 1
    if (ranks[p1]==ranks[p2]){ // 1 and 0
        parents[p1]=p2; // 4의 루트 노드가 3이 되는 것.
        ranks[p2]++; // 이제 3인덱스에 해당하는 랭크가 하나 증가됨
    } else if (ranks[p1]>ranks[p2]) parents[p2]=p1; // 여기 -> parents[1]=3;
    else parents[p1]=p2;
}

bool findFunc(int parents[],const vector<string>& oper){
    int p1=findRootNode(parents,stoi(oper[1])); // 3
    int p2=findRootNode(parents,stoi(oper[2])); // 2   
    if (p1==p2) return true;
    else return false; 
}

vector<bool> solution(int parents[],int ranks[],const vector<vector<string>>& operations){
    vector<bool> answer;
    for (const vector<string>& oper:operations) {
        if (oper[0]=="u") unionFunc(parents,ranks,oper);
        else {bool ans=findFunc(parents,oper); answer.push_back(ans);}
    }
    return answer;
}

int main(){
    int parents[10];
    int ranks[10];
    std::fill(std::begin(ranks),std::end(ranks),0);
    std::iota(std::begin(parents),std::end(parents),0);
    vector<vector<string>> operations={{"u","4","3"},{"u","3","2"},{"u","2","1"},{"u","1","0"},{"f","0","2"}};
    // vector<vector<string>> operations={{"u","4","3"},{"u","3","2"},{"u","2","1"}};
    // vector<vector<string>> operations={{"u","0","1"},{"u","2","3"},{"f","0","1"},{"f","0","2"}};
    
    vector<bool> answer=solution(parents,ranks,operations);

    for (bool ans:answer) std::cout<<ans<<" ";
    std::cout<<std::endl;

    for (int parent:parents) std::cout<<parent<<" ";
    std::cout<<std::endl;
    for (int rank:ranks) std::cout<<rank<<" ";
    std::cout<<std::endl;

    return 0;
}