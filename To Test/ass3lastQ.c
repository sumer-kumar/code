#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *input = fopen("fileInput.txt","r");
    
    if(!input){
        printf("FIle cannot be opened\n");
        return 0; //end 
    }
    
    FILE *output = fopen("fileOutput.txt","w");
    char ch;
    while(fscanf(input,"%c",&ch)==1){
        if(ch>='a'&& ch<='z') //if character is small alphabet
        {
            ch = ch - 32; //to convert into Upper case as 'a' - 32 = 'A'
        }

        //writing into file output
        fprintf(output,"%c",ch); 
    }


    return 0;
}