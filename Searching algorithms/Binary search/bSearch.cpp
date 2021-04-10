#include<iostream>
#include<vector>

bool bSearch(std::vector<int>& vec, int key, int s, int e){
    int mid = (s+e)/2;
    if(key==vec[mid]){
        return true;
    }
    if(s==mid && key<vec[mid]){
        return false;
    }
    else if(key>vec[mid]){
        return bSearch(vec, key, mid+1, e);
    }
    else{
        return bSearch(vec, key, s, mid-1);
    }
}

int main(){
    int n=0,k=0,val=0;
    std::cin>>n;
    std::cin>>k;
    std::vector<int> vec;
    for(int i=0;i<n;i++){
        std::cin>>val;
        vec.push_back(val);
    }
    for(int i=0;i<k;i++){
        std::cin>>val;
        bSearch(vec,val,0,vec.size()-1) ? std::cout<<"YES"<<"\n" : std::cout<<"NO"<<"\n";
    }
}

/*

For test case -
10 10
1 61 126 217 2876 6127 39162 98126 712687 1000000000
100 6127 1 61 200 -10000 1 217 10000 1000000000

Output-
NO
YES
YES
YES
NO
NO
YES
YES
NO
YES

*/
