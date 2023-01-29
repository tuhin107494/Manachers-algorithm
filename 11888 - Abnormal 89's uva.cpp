#include<bits/stdc++.h>
using namespace std;

int main() {


   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif 


   int t;
   vector<long long int >v_odd,v_ev;
    v_odd.push_back(0);
    for(long long int i=1,j=1;i<=1000;i+=2,j++)
    {
       long long int d=v_odd[j-1]+(i*i*i);
       v_odd.push_back(d);
    }
     v_ev.push_back(0);
    for(long long int i=2,j=1;i<=1000;i+=2,j++)
    {
      long long int  d=v_ev[j-1]+(i*i*i);
       v_ev.push_back(d);
    }

    cin>>t;
    while(t--)
    {

  int i, j, k, n, m;
  string s;
  cin >> s;
  n = s.size();
  vector<int> d1(n);  // maximum odd length palindrome centered at i
  // here d1[i]=the palindrome has d1[i]-1 right characters from i
  // e.g. for aba, d1[1]=2;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  vector<int> d2(n);  // maximum even length palindrome centered at i
  // here d2[i]=the palindrome has d2[i]-1 right characters from i
  // e.g. for abba, d2[2]=2;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }
 
 /* for(i = 0; i < n; i++) cout << d1[i] << ' ';
  cout << endl;
  for(i = 0; i < n; i++) cout << d2[i] << ' ';
  cout << endl;*/
  
  // number of palindromes
 /* long long ans = 0;
  for(i = 0; i < n; i++) {
    ans += 1LL * d1[i];
    ans += 1LL * d2[i];
  }
 
   */
int ok=0;
  for(int i=0;i<n;i++)
  {
    //cout<<i<<" ";
    if((i+1)==d1[i])
    {
        int  sz=(i+1)*2 -1;
        int baki=n-sz;
        //cout<<"baki "<<baki<<endl;
        if(baki%2==1)
        {
            if(d1[sz+(baki/2)]==((baki+1)/2))
            {
                ok=1;
                cout<<"alindrome"<<'\n';
                break;
            }
        }
        else if(baki==0)
        {
            ok=2;
            break;
        }
        else
        {
            if(d2[sz+(baki/2)]==(baki/2))
            {
                cout<<"alindrome"<<'\n';
                ok=1;
                break;
            }

        }

    }

  }
  if(ok==1)continue;
    for(int i=1;i<n;i++)
  {
    //cout<<i<<" ";
    if((i)==d2[i])
    {
        int  sz=(i)*2;
        int baki=n-sz;
       // cout<<"baki "<<baki<<endl;
        if(baki%2==1)
        {
            if(d1[sz+(baki/2)]==((baki+1)/2))
            {
                ok=1;
                cout<<"alindrome"<<'\n';
                break;
            }
        }
        else if(baki==0)
        {
            ok=2;
            break;
        }
        else
        {
            if(d2[sz+(baki/2)]==(baki/2))
            {
                cout<<"alindrome"<<'\n';
                ok=1;
                break;
            }

        }

    }

  }
  if(ok==0)cout<<"simple"<<endl;
  else if(ok==2)cout<<"palindrome"<<endl;


 

}
  return 0;
}



/*

aaaaabbbbaaaa

output:
1 2 3 2 1 1 2 2 1 1 2 2 1 
0 1 2 2 1 0 1 6 1 0 1 2 1 
39
*/
