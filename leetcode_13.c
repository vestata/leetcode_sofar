#include <stdio.h>

int charToInt(char ch){
    switch(ch){
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return 0;
    }
}

int romanToInt(char * s){
    if(s == NULL)
        return 0;
    int index = 0; // 索引
    int result = 0;// 最後輸出結果
    while(s[index] !='\0'){
        if(charToInt(s[index]) < charToInt(s[index+1])){
            result += charToInt(s[index+1]) - charToInt(s[index]);
            index++;            
        }else{
            result += charToInt(s[index]) ;
        }
        index++;
    }
    return result;
}

int main(){
    char a[10]= "I";
    char b[10]= "II";
    char c[10]= "MCMXCIV";
    printf("%d\n", romanToInt(a));
    printf("%d\n", romanToInt(b));
    printf("%d\n", romanToInt(c));
}