#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static const char kProgramName[] = "unix2dos";
int main(int argc, char** argv)
{
    char *base_name = 0;
    FILE *in = 0;
    int ch;
    int cr_flag;

    if ((base_name = strrchr(argv[0],'/')) != 0)
        base_name++;
    else
        base_name = argv[0];
    
    if (argc != 2) {
        fprintf(stderr,"Missing input file!\n");
        return 1;
    }

    if(!(in = fopen(argv[1],"r"))) {
        fprintf(stderr,"Cannot open input file!\n");
        return 2;
    }

    if (strncmp(base_name, kProgramName, strlen(kProgramName)) == 0) {
        puts("UNIX2DOS...");
        while ((ch = fgetc(in)) != EOF)
        {
            if(ch == '\n')
                putchar('\r');
            putchar(ch);
        } 
    } else {
        puts("DOS2UNIX...");
        cr_flag = 0; 
        while ((ch = fgetc(in) != EOF))
        {
            if (cr_flag && ch != '\n')
                putchar('\r');
            if (!(cr_flag = (ch == '\r')))
                putchar(ch);
        } 
    }

    fclose(in);
    return 0;
}
