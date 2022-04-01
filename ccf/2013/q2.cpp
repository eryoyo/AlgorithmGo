//
// Created by eryo on 2021/9/23.
//

#include<bits/stdc++.h>

using namespace std;

int main(){
    char str[15];
    scanf("%s", str);
    int sum = (str[0] - '0') * 1
            + (str[2] - '0') * 2
            + (str[3] - '0') * 3
              + (str[4] - '0') * 4
                + (str[6] - '0') * 5
                  + (str[7] - '0') * 6
                    + (str[8] - '0') * 7
                      + (str[9] - '0') * 8
                        + (str[10] - '0') * 9;
    int carry = sum % 11;
    char ans = carry == 10 ? 'X' : (carry + '0');
    if(str[12] == ans){
        printf("Right");
    }else{
        str[12] = ans;
        printf("%s", str);
    }
}