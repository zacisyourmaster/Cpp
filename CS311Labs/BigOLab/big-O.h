/**********************************
CS311 Kazumi Slott

Your name:
Your program number:
Hours spent:
Describe any difficulties here: 
*********************************/

/********************************************************************
//Make your own test client and test your functions thorougly.
//You will submit this header file only. My test client will test your functions.
********************************************************************/


//What is the runtime complexity of this algorithm? O(n^3)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above.
int algoA(const int a[], int sz)//Don't change the function headers
{
  int maxSum = 0;
  for (int sArr = 1; sArr <= sz; sArr++) {
    for (int i = 0; i <= sz - sArr; i++) {
      int currentSum = 0;

      for (int j = i; j < i + sArr; j++) {
	currentSum += a[j];
      }

      if (currentSum > maxSum) {
	maxSum = currentSum;
      }
    }
  }
  return maxSum;
}

//What is the runtime complexity of this algorithm? O(n^2)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above..
int algoB(const int a[], int sz)
{
    int maxSum = 0;

    for (int i = 0; i < sz; i++) {
      int currentSum = 0;

      for (int j = i; j < sz; j++) {
	currentSum += a[j];

	if (currentSum > maxSum) {
	  maxSum = currentSum;
	}
      }
    }

    return maxSum;
}

//What is the runtime complexity of this algorithm? O(n)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above..
int algoC(const int a[], int sz)
{
  int maxSum = 0; 
  int start = 0;

  while (start < sz) {
    int currentSum = 0;
    for (int end = start; end < sz; end++) {
      currentSum += a[end];
      if (currentSum < 0) {
	start = end + 1;
	currentSum = 0;
	break;
      }
      if (currentSum > maxSum) {
	maxSum = currentSum;
      }
    }
    if (start == sz) {
      break;
    }
  }
  return maxSum;
}
