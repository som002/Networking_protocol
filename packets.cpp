#include <stdio.h>
#include <iostream>
#include <cstring>

typedef struct frame{
    int no;
    int len;
    char des;
    char source;
    char data[9];
    int checksum;
}F;

int main(){
    // string take from user
    // pad them with '$' sign as bit stuffing
    // number of frames with size 8 are to be made 
    F f[5];
    int frame_size {8};
    int num_frames {0};
    // char str[50] ="hello World how r you!";
    char str[50] ;
    printf("put the string to send: ");
    gets(str);
   
    int size = static_cast<int>(strlen(str));
    
    
    int i;
    if(size % frame_size != 0){
    int r = frame_size - (size % frame_size); 
    for(i = size; i < size+r;i++){
        str[i] = '$';
    }
    str[i] = '\0';
    }
    printf("\ndata to transmit is: %s\n", str);
    printf("\nbits to transmit is: %lld\n", strlen(str));

    // making packets of 8 frames
    size = static_cast<int>(strlen(str));
    num_frames = size/frame_size;
    printf("\n num_frames is: %d\n", num_frames);
    int m =0; 
    for(i = 0;i < num_frames;i++){
    int sum=0, k;
        printf("\nframe number %d \n", i);
        f[i].no = i;
        f[i].len = frame_size;
        printf("\nframe des: ");
        scanf(" %c",&(f[i].des));
        printf("\nframe source: ");
        scanf(" %c",&(f[i].source));
        
        for(k=0;k<frame_size;k++){
            f[i].data[k] = str[k+m];
            sum +=str[k+m]; 
        }
        f[i].data[k] = '\0';
        printf("\n sum: %d ",sum);
        f[i].checksum = sum;
        m+=frame_size;
    }

        printf("\n\tno.\tlen\tsource\tdes\tdata\tchecksum");
    for(int k = 0;k<num_frames;k++){
        printf("\n\t%d\t%d\t%c\t%c\t%s\t%d",
                f[k].no,f[k].len,f[k].source,f[k].des,f[k].data,f[k].checksum);
    }
    
    return 0;
}