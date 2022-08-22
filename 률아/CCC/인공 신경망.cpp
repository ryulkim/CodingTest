#include <iostream>
#include <vector>
using namespace std;

int n,m;
int v[2002][4005]; //은닉층
int z[2005]; //출력층
int hap[2005];
int h=0;

void cal(){
  long long ans=0;
  int x;
  int input[2005];

  for(int j=0;j<n;j++){
    cin>>x;
    ans+=hap[j]*x;
  }

  ans+=h;
  cout<<ans<<'\n';
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  
  int q,c,p,w,b,x;
  
  
  cin>>n>>m>>q;

  for(int i=0;i<m;i++){
    cin>>c;
    v[i][0]=c;
    int sz=2*c;
    for(int j=0;j<=sz;j++){
      cin>>p;
      v[i][1+j]=p;
    }
  }

  for(int i=0;i<=m;i++){
    cin>>w;
    z[i]=w;
  }

  
  for(int i=0;i<m;i++){
    int a=v[i][0];
    for(int j=1;j<=a;j++){
      hap[v[i][j]-1]+=v[i][j+a]*z[i];
    }
    h+=v[i][2*a+1]*z[i];
  }
  h+=z[m];
  
  for(int i=0;i<q;i++){
    cal();
  }

}
