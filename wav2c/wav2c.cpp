//////////////////////////////////////////////////////////////////////////////
// wav2c.cpp                                                                //
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// includes                                                                 //
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////////
// main                                                                     //
//////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	printf("wav2c v1.00 by Dark Fader / BlackThunder\n");
	if (argc < 2) { printf("Syntax: %s <input.wav>\n", argv[0]); return -1; }
	char buf[1024], *s = buf;
	strcpy(s, argv[1]);
	char *p = strstr(s, ".wav");
	if (!p) { printf("Please specify a 8KHz, 8-bit wav file!\n"); return -1; }
	
	FILE *fi = fopen(s, "rb");
	if (!fi) { printf("Could not open input file!\n"); return -1; }
	strcpy(p, ".c");
	FILE *fo = fopen(s, "wt");
	if (!fo) { printf("Could not open output file!\n"); return -1; }

	fseek(fi, 0x28, SEEK_SET);
	p = strrchr(s, '\\'); if (p) s = p+1;
	p = strrchr(s, '/'); if (p) s = p+1;
	p = strrchr(s, '.'); if (p) *p = 0;
	fprintf(fo, "const unsigned char %s[] =\n{", s);
	
	int l=0;
	while (1)
	{
		if (l++ % 100 == 0) { fprintf(fo, "\n\t"); }
		int a = fgetc(fi); if (a == EOF) break;
		fprintf(fo, "%d,", a);
	}

	fprintf(fo, "\n};\n");	

	fclose(fi);
	fclose(fo);
	return 0;
}