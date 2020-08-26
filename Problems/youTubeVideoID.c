/*
You and your friends like to share YouTube links all throughout the day. 
You want to keep track of all the videos you watch in your own personal notepad, 
but you find that keeping the entire link is unnecessary. 
Keep the video ID (the combination of letters and numbers at the end of the link) in your notepad to slim down the URL.

Task: 
Create a program that parses through a link, extracts and outputs the YouTube video ID.

Input Format: 
A string containing the URL to a YouTube video. The format of the string can be in 
"https://www.youtube.com/watch?v=kbxkq_w51PM" or the shortened 
"https://youtu.be/KMBBjzp5hdc" format.

Output Format: 
A string containing the extracted YouTube video id.

Sample Input: 
https://www.youtube.com/watch?v=RRW2aUSw5vU

Sample Output: 
RRW2aUSw5vU
*/

#include <stdio.h>
#include <string.h>
int main(void){
    char str1[100];
	scanf("%[^\n]s",str1);
	int size=strlen(str1);
	for(int i=size-11;i<=size;i++){
           printf("%c",str1[i]);
	}
return 0;
}
/*
ip:
https://www.youtube.com/watch?v=Exk34o-MMIE
op:
Exk34o-MMIE
*/
