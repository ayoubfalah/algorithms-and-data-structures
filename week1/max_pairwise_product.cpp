#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

int FindMaxIndex(vector<int> numbers, int to){
    int n = numbers.size();
    int maxIndex = 0;
    for(int i = 1; i < to; i++)
      if(numbers[i] > numbers[maxIndex])
        maxIndex = i;
    return maxIndex;
}

long long MaxPairwiseProduct(vector<int> numbers)
{
   int n = numbers.size();
   int maxIndex1 = FindMaxIndex(numbers, n);
   swap(numbers[maxIndex1], numbers[n-1]);
   int maxIndex2 = FindMaxIndex(numbers, n-1);
   swap(numbers[maxIndex2], numbers[n-2]);
   long long result = ((long long)numbers[n-1]) * numbers[n-2];
   return result;
}

int main()
{
  int n;
  cin>>n;
  vector<int> numbers(n);
  for(int i = 0; i < n; i++) cin>>numbers[i];
  long long result = MaxPairwiseProduct(numbers);
  std::cout<<result << "\n";
  return 0;
}

