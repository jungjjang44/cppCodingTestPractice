#include <bits/stdc++.h>

using namespace std;
// 배열 정렬하기

void print(vector<int> arr) {
    for (int v:arr) {
        std::cout<<v<<" ";
    } std::cout<<std::endl;
}

vector<int> solution(vector<int> numbers) {
    set<int> sum;

    for (int i=0; i<numbers.size(); ++i) {
        for (int j=i+1; j<numbers.size(); ++j) {
            sum.insert(numbers[i]+numbers[j]);
        }
    }

    vector<int> ans(sum.begin(),sum.end());
    return ans;
}

int main() {
    vector<int> arr={2,1,3,4,1};

    vector<int> sol=solution(arr);
    print(sol);
    
    return 0;
}
