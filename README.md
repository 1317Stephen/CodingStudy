# STL
## Pair
* 라이브러리 : utility
* 정의: 2개의 데이터(다른 자료형 가능)을 쌍으로 취급할 때 이용한다. first값이 정렬되면, second 값이 이에 따라 정렬된다. 
* 선언: pair<string, int> alphabet       
    vector<pair<int, int>>같은 경우, make_pair(1,2) 로 값을 추가할 수 있다.
* 이용 예제
```
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<v.size(); i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << "\n";
    
    }
    return 0;
}

```


## Algorithm
### sort
* 라이브러리: algorithm
* 정의: vector 등 여러 자료형을 정렬해 준다. (추정)복잡도는 logN
* 함수: sort(v.begin(), v.end(), option). option에 사용자 지정 설정을 넣을 수 있다. 오름차순, 내림차순을 설정할 때 사용할 수도 있다.
```
bool desc(int a, int b){
    return a > b;
}
sort(a.begin(), a.end(), desc);
```
