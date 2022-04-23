
 ///*#####KMP        ?? Knuth Morris Pratt
 #define MAX 1000006
int failure[MAX];

void build_failure_function(string &pattern, int m) {
  failure[0] = 0;
  failure[1] = 0; //base case

  for(int i = 2; i <= m; i++) {  //i is length of the prefix we are dealing with
    // j is the index of the largest next partial match
    // (the largest suffix/prefix) of the string under index i - 1
    int j = failure[i - 1];
    while(true) {
      // check if the last character of prefix of length i "expands" the current "candidate"
      if(pattern[j] == pattern[i - 1]) {
        failure[i] = j + 1;
        break;
      }
      // if we cannot "expand" even the empty string
      if(j == 0) {
          failure[i] = 0;
          break;
      }
      // else go to the next best "candidate" partial match
      j = failure[j];
    }
  }
}
 int kmp(string &text, string &pattern)
{
  int cnt = 0;
  int n = text.size();
  int m = pattern.size();
  build_failure_function(pattern, m);
  int i = 0;
  int j = 0;
  while(true) {
    if(j == n) {
        return cnt;
    }
    if(text[j] == pattern[i]) {
      i++;j++;
      if(i == m) {
          cnt++;
          i = failure[i];
          //j -= (m-1);
      }
    } else {
        if (i == 0) {
            j++;
        }
        else {
            i = failure[i];
        }
    }
  }
  return cnt;
}

//*/
