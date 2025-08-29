#include <bits/stdc++.h>

using namespace std;
// 배열 정렬하기

void print(vector<int> arr) {
    for (int v:arr) {
        std::cout<<v<<" ";
    } std::cout<<std::endl;
}

/**
 * 
vector<int> solution(vector<int> numbers) { // 2중 for문 사용, set 컨테이너 사용해서 자동으로 중복 방지
    set<int> sum;

    for (int i=0; i<numbers.size(); ++i) {
        for (int j=i+1; j<numbers.size(); ++j) {
            sum.insert(numbers[i]+numbers[j]);
        }
    }

    vector<int> ans(sum.begin(),sum.end());
    return ans;
}
 * 
 */
vector<int> solution(vector<int> numbers) {

    vector<int> ans;
    int n=numbers.size();
    int r=2;

    vector<int> mask(n,0); // 0 0 0 0 0
    fill(mask.begin(),mask.begin()+r,1); // 1 1 0 0 0 (fill->지정된 범위까지 특정 숫자로 채운다.)

    do {
        int count=0;
        for (int i=0; i<n; i++) {
            if (mask[i]) count+=numbers[i];
        } ans.push_back(count);
    } while (prev_permutation(mask.begin(),mask.end())); // 5 펙토리얼 -> [1,0,0,1,0]...

    // ans 벡터 정렬 및 중복 제거
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());

    return ans;
}

int main() {
    vector<int> arr={2,1,3,4,1};

    vector<int> sol=solution(arr);
    print(sol);
    
    return 0;
}
