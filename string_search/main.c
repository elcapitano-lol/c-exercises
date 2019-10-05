#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 2048

int strsearch (char * filename, char * string, int n_long_strings) {

	FILE *fpin, *fpout, *fptemp;
	int num, numchars, h, i, j, lensubstr, lenstrline, foundoccurence, size_string;
	char strline[LINE_SIZE];
	char substring[LINE_SIZE];
	char ch;
	char * index;

	printf("Searching for %s in file %s...\n", string, filename);

	/* open input file and two files for work purposes */
	if((fpin = fopen(filename,"r")) == NULL)
	{
		printf("Couldn't open file.\n");   
		return 0;             
	}

	if((fpout = fopen("output.log","w+")) == NULL)
	{
		printf("Couldn't open file.\n");  
		return 0;             
	}

	if((fptemp = fopen("temp.log","w+")) == NULL)
	{
		printf("Couldn't open file.\n");  
		return 0;             
	}

	/* copy entire input file to output work file */
	while ((ch = fgetc(fpin)) != EOF)
      fputc(ch, fpout);
  	rewind(fpout);

	size_string = strlen(string);

	/* cycle through all possible substring combinations larger than n_long_strings */
	for (numchars=size_string; numchars >= n_long_strings; numchars--) {		
		for (h=0; h <= size_string - numchars; h++) {

			strncpy (substring, string + h, numchars);
			substring[numchars]='\0';			
			/* found substring to search */
			
			foundoccurence = 0;

			/* cycle through all lines of the file */
			while(fgets(strline, LINE_SIZE, fpout) != NULL) {

				lenstrline = strlen(strline);

				/* while it can find substring */
				while((index = strstr(strline, substring)) != NULL) {
					foundoccurence ++;

					/* replace substring with some characters */
					for (i=0; i<numchars; i++) {
						index[i]='*';
					}
				}

				/* write original or substituted line into fptemp */
				fputs(strline, fptemp);
			}

			printf("String %s\t\tfound %d times\n", substring, foundoccurence);
			rewind(fpout);
			rewind(fptemp);

			/* copy contents of fptemp (containing eliminations) to fpout for new round of search */
			while ((ch = fgetc(fptemp)) != EOF)
      			fputc(ch, fpout);

      		/* get back to start of stream */
      		rewind(fpout);
      		rewind(fptemp);
		}
	}

	fclose(fpin);
	fclose(fpout);
	fclose(fptemp);

	remove("output.log");
	//remove("temp.log"); // may be removed if user doesn't wish to keep the striked-through file
	return 1;
}


int main () {

	char filename[] = "serial.log";
	char string[] = "abcdefghijklmnopqrstuvw";
	char n_long_strings = 1;

	strsearch(filename, string, n_long_strings);

	return 1;
}
