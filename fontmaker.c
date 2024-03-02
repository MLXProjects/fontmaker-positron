#include <aroma.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FONT_WPAD		(font_width+5)
#define FONT_HPAD		(font_height+4)
#define CHAR_NEWLINE	"\r\n"

int main(int argc, char **argv){
	char file_name[32] = {0};
	char *font_name = "5x10", *font_type = "Flash8";
	int font_width, font_height;
	byte char_islast;
	if (argc>1 && !strcmp(argv[1], "-h")){
		printf("Usage: %s [OPTION] [WxH]\n"
				"Generate PositronBASIC font from PNG ASCII map.\n"
				"\n"
				"Options:\n"
				"  -c\t\t"		"Generate custom characters using values after last ASCII character (~)\n"
				"  WxH\t\t"		"Sets the font width and height to use\n"
				"\t\t"			"Defaults to 5x10\n"
				"  -h\t\t"		"Shows this help message\n"
				"\n"
				"Examples:\n"
				"  %s -c 5x9\n"
				"  %s 4x7\n"
				"\n",
				argv[0], argv[0], argv[0]);
		return 0;
	}
	if (argc>2) font_name = argv[2];
	else if (argc>1) font_name = argv[1];
	int font_namelen = strlen(font_name) + 7;
	byte ascii_continue = (argc > 2) && !strcmp(argv[1], "-c");
	sscanf(font_name, "%dx%d", &font_width, &font_height);
	if (font_width > 32){
		printf("font too wide (%d), max width: 32\n", font_width);
		return 1;
	}
	else if (font_width >24) font_type = "Flash32";
	else if (font_width >16) font_type = "Flash24";
	else if (font_width > 8) font_type = "Flash16";
	snprintf(file_name, font_namelen, "./%s.inc", font_name);
	FILE *out = fopen(file_name, "wb");
	if (!out){
		printf("failed to create out file\n");
		return 1;
	}
	snprintf(file_name, font_namelen, "./%s.png", font_name);
	LIBAROMA_CANVASP image = libaroma_image_file(file_name, 0);
	if (!image){
		printf("failed to open image\n");
		fclose(out);
		return 1;
	}
	printf("Parsing %dx%d font\n", font_width, font_height);
	fprintf(out, "$ifndef PLATFORM_FONT" CHAR_NEWLINE
				 "$define PLATFORM_FONT" CHAR_NEWLINE
				 CHAR_NEWLINE
				 "$define FONT_WIDTH\t%d" CHAR_NEWLINE
				 "$define FONT_HEIGHT\t%d" CHAR_NEWLINE
				 CHAR_NEWLINE,
				 font_width, font_height);
	fprintf(out, "Dim str_font As %s=", font_type);
	if (!strcmp(font_type, "Flash8")) fprintf(out, "\t", font_type);
	int offset, char_ascii=' ', char_index=0;
	int x, y, char_x, char_y, char_w=font_width, char_h=font_height;
	word pixel_color;
	for (char_y=0; char_y<image->h; char_y+=FONT_HPAD){
		for (char_x=0; char_x<image->w; char_x+=FONT_WPAD){
			if (char_y == 0 && char_x == 0){
				char_ascii++;
				continue; //just another hack, skip space char w/o increasing index
			}
			char_islast = ((char_ascii == '~' && !ascii_continue) || (char_x+FONT_WPAD >= image->w && char_y+FONT_HPAD >= image->h));
			for (y=0; y<char_h; y++){
				/* parse character row */
				offset=((char_y+y)*image->w)+char_x;
				fprintf(out, "%%");
				for (x=0; x<char_w; x++){
					/* use color to determine pixel value */
					pixel_color = image->data[offset+x];
					if (libaroma_color_isdark(pixel_color))
						fprintf(out, "1");
					else fprintf(out, "0");
				}
				/* separate non-last rows with comma */
				if (y+1<char_h) fprintf(out, ", ");
			}
			fprintf(out, (char_islast)?"\t\t":",_\t");
			if (char_ascii > '~'){
				fprintf(out, "' custom char (%d)", char_index);
			}
			else fprintf(out, "' char %c (%d)" CHAR_NEWLINE, char_ascii, char_index);
			/* exit loop if last (standard) ASCII character & limit not disabled by argument */
			if (char_islast)
				goto done;
			/* add padding at start of next line */
			fprintf(out, "\t\t\t\t\t\t");
			/* increase offsets */
			++char_ascii;
			char_index += font_height;
		}
	}
done:
	fprintf(out,CHAR_NEWLINE
				"$endif 'PLATFORM_FONT"
				CHAR_NEWLINE);
	fclose(out);
	libaroma_canvas_free(image);
	return 1;
}
