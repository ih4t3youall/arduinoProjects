#include <stdio.h>


int encoding(*char);


int main(){
FILE *fileptr;
char *buffer;
long filelen;

fileptr = fopen("testfile.txt", "rb");  // Open the file in binary mode
fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
filelen = ftell(fileptr);             // Get the current byte offset in the file
rewind(fileptr);                      // Jump back to the beginning of the file

buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
fread(buffer, filelen, 1, fileptr); // Read in the entire file
fclose(fileptr); // Close the file

FILE *my_file = fopen("nuevoFile.txt", "wb");
float x = 3.1415;
fwrite(&buffer, sizeof buffer, 1, my_file);
fclose(my_file);


}
int encoding(*char a){

  FILE *fp=NULL;
        int c;
        int a[2];
        int i;
        fp=fopen($a,"rb");

        if (fp != NULL)
        {
            while (i<=3)
            {
                        c = fgetc(fp);    
                        printf("%d",c);
                            if(c==254)
                            {
                                printf("Unicode Big Endian File");
                            }
                            else if(c==255)
                            {
                                printf("Unicode Little Endian File");
                            }
                            else if(c==239)
                            {
                                printf("UTF8  file");
                            }
                            else 
                            {
                                printf("ANSI File");
                            }

              }
              fclose(fp);

       }


        getchar();

    return 0;


}
