#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;
using std::min;

int edit_distance(const string &s, const string &t) {
  int n = s.length() + 1;
  int m = t.length() + 1;
  vector<vector <int>> distance(n,vector <int>(m));
  
  for(int i = 0; i < n; i++) distance[i][0] = i;
  for(int j = 0; j < m; j++) distance[0][j] = j;
 
  for (int i = 1; i < n; ++i)
  {
  	for (int j = 1; j < m; ++j)
  	{
  		int insertion = distance[i][j-1] + 1;
  		int deletion  = distance[i-1][j] + 1;
  		int match     = distance[i-1][j-1];
  		int mismatch  = distance[i-1][j-1] + 1;
		
                if (s[i-1] == t[j-1])
  		{
  		  distance[i][j] = min(min(insertion, deletion), match);
  		}
  		else
  		{
                  distance[i][j] = min(min(insertion, deletion), mismatch);
   		}
  	}
  }

  return distance[n-1][m-1];
}

int main() {
  string s;
  string t;
  std::cin >> s >> t;
  std::cout << edit_distance(s, t) << std::endl;
  return 0;
}
