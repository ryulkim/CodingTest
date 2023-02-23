#include <cmath>
#include <iostream>
using namespace std;

int num = 1000000;
int arr[1000005] = {
    0,
}; //남동생 수
int b[1000005] = {
    0,
}; //막내


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m;

  cin >> t;
  //남동생 구하기
  for (int i = 2; i <= sqrt(num); i++) {
    for (int j = i*i; j <= num; j += i) {
      arr[j] += 1;
      if((j/i)!=i){
        arr[j]+=1;
      }
      if(b[j]==0){
        b[j] = i;
      }
    }
  }


  for (int k = 1; k <= t; k++) {
    cin >> n >> m;

    int ans = 0;

    int bro = arr[n];
    int v[1000005] = {
        0,
    };
    int idx = 0;

    if (bro == 0) {
      cout << "Case #" << k << ": " << ans << '\n';
      continue;
    }

    for (int i = 2; i < n; i++) {
      if (arr[i] == bro) {
        v[idx] = i;
        idx += 1;
      }
    }

    /*for(int i=0;i<=n;i++){
      cout<<v[i]<<' ';
    }*/

    for (int i = 0; i < n; i++) {
      if (b[v[i]] >= m) {
        ans += 1;
      }
    }
    cout << "Case #" << k << ": " << ans << '\n';
  }
}
