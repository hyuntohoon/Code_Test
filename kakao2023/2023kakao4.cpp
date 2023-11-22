 #include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define endl "\n"

using namespace std;

bool isAllzero(string binary){
    FOR(i,binary.size()){
        if(binary[i] == '1'){
            return false;
        }
    }
    return 1;
}

bool isValidBinaryTree(string binary) {
    if (binary.empty()) return true;

    // 첫 번째 노드가 1이 아니면, 무조건 유효한 트리로 간주
    if (isAllzero(binary)) return true;

    // 왼쪽과 오른쪽 서브트리로 나누기
    int mid = binary.length() / 2;
    string left = binary.substr(0, mid);
    string right = binary.substr(mid + 1);
    if(binary[mid] == '1' && isValidBinaryTree(left) && isValidBinaryTree(right)) return true;
    else return false;

}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
        
        FOR(j, numbers.size()){
            
            long long decimal = numbers[j];
            string binary = bitset<64>(decimal).to_string();
            binary = binary.substr(binary.find('1')); 
            int length = binary.length();
            int height = ceil(log2(length + 1));
            int totalNodes = pow(2, height) - 1;
            string temp = "";
            FOR(i, totalNodes-binary.size()){
                temp+='0';
            }
            temp+=binary;
            cout<<temp<<endl;
            answer.push_back(isValidBinaryTree(temp));
            bool check = 0;
    }
    FOR(i,answer.size()){
        cout<<answer[i]<<endl;
    }
    return answer;
}
int main(){
    vector <long long> numbers;
    numbers.push_back(24);
    solution(numbers);
}
/*
1000000000000000
/=> 모든 수를 이진트리를 통한 이진수로 만들기 => 불가능
어떠한 수를 이진트리를 통한 이진수 만들기
1. 먼저 10진수 수를 2진수로 만들기
2. 2진수를 트리로 만들기 
01 10 11 100 101
111 => 
    포화 이진 트리 => 1, 3, 7, 15, 31, 63,*/