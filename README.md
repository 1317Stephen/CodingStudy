# STL
## Pair
* 라이브러리 : utility
* 정의
* 함수
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

```
bool desc(int a, int b){
    return a > b;
}
sort(a.begin(), a.end(), desc);
```
