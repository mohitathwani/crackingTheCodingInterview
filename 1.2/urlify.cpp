#include <iostream>
#include <string>
#include <string.h>

using namespace std;
char* urlify(char *str, int actualLen);
int main() {
  string inputString;
  getline(cin, inputString);
  char *str = new char[inputString.length() + 1];
  strcpy(str, inputString.c_str());
  char *urlString = urlify(str, inputString.length());
  cout << urlString << endl;
  delete urlString;
  delete str;
  return 0;
}

char* urlify(char *str, int actualLen) {
  int paddedLen = actualLen;
  for (int i = 0; i < actualLen; i++) {
    if (str[i] == ' ') {
      paddedLen += 2;
    }
  }

  char *tempStr = new char[paddedLen];

  for (int i = actualLen - 1; i >= 0 && paddedLen >= 0; i--) {
    if (str[i] != ' ') {
      tempStr[paddedLen - 1] = str[i];
      paddedLen--;
    }
    else {
      tempStr[paddedLen - 3] = '%';
      tempStr[paddedLen - 2] = '2';
      tempStr[paddedLen - 1] = '0';
      paddedLen -= 3;
    }
  }

  return tempStr;
}
