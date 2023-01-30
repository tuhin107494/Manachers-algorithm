#include<bits/stdc++.h>
using namespace std;

int main() {


   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif 


   int t;
    cin>>t;
    while(t--)
    {

  int i, j, k, n, m;
  string s;
  cin >> s;
  n = s.size();
int st=0,end=n;
  for(int i=0;i<(n/2);i++)
  {
    if(s[i]==s[n-i-1])
    {
        st++;
        end--;
    }
    else break;
  }

  vector<int> d1(n);  // maximum odd length palindrome centered at i
  // here d1[i]=the palindrome has d1[i]-1 right characters from i
  // e.g. for aba, d1[1]=2;
  for (int i = st, l = st, r = st-1; i < end; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
    while (st<= i - k && i + k < end && s[i - k] == s[i + k]) {
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
  for (int i = st, l = st, r = st-1; i < end; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (st <= i - k - 1 && i + k < end && s[i - k - 1] == s[i + k]) {
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

int  odd=0,even=0,odd_id=0,even_id=0;
  for(int i=st;i<end;i++)
  {

      if(i+1==d1[i]+st)
      {
        if(odd<d1[i])
        {
            odd_id=i;
            odd=d1[i];
        }

      }
      if(i==(end-d1[i]))
      {
        if(odd<d1[i])
        {
            odd_id=i;
            odd=d1[i];
        }
      }
  }

//cout<<odd<<" "<<odd_id<<endl;
   for(int i=st;i<end;i++)
  {

      if(i==d2[i]+st)
      {
        if(even<d2[i])
        {
            even_id=i;
            even=d2[i];
        }

      }
      if(i==(end-d2[i]))
      {
        if(even<d2[i])
        {
            even_id=i;
            even=d2[i];
        }
      }
  }
//cout<<even<<" "<<even_id<<endl;
   i=0;
  while(i<st){cout<<s[i];i++;}
  if(odd<=even)
  {
    // cout<<even_id-even<<" "<<even_id+even<<endl;
     for(int i=even_id-even;i<even_id+even;i++)cout<<s[i];

  }
else
{        
  // cout<<odd_id-odd+1<<" "<<odd_id+odd-1<<endl;                 
     for(int i=odd_id-odd+1;i<odd_id+odd;i++)cout<<s[i]; 
}

   i=end;
  while(i<=n-1)
  {
    cout<<s[i];
    i++;
  }
  cout<<endl;
  // number of palindromes
 /* long long ans = 0;
  for(i = 0; i < n; i++) {
    ans += 1LL * d1[i];
    ans += 1LL * d2[i];
  }
 
   */

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
