#include <aroma.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FONT_WPAD		(font_width+5)
#define FONT_HPAD		(font_height+4)
#define CHAR_NEWLINE	"\r\n"

//extern byte font_render(char *name, char *namelen, char *path);

char file_name[32];
int font_width, font_height;

int main(int argc, char **argv){
	char *font_name, *font_type = "Flash8";
	byte char_islast, ascii_stop;
	int i, font_namelen;
	LIBAROMA_CANVASP image;
	if ((argc>1 && !strcmp(argv[1], "-h")) || argc == 1){
		printf("Usage: %s [OPTION] [WxH]\n"
				"Generate PositronBASIC font from PNG ASCII map.\n"
				"\n"
				"Options:\n"
				"  -a\t\t"		"Stop parsing after last ASCII character (~)\n"
				//"  -r <font>\t"	"Render the specified font file for use with this tool (DISABLED!)\n"
				"  WxH\t\t"		"Sets the font width and height to use\n"
				"  -h\t\t"		"Shows this help message\n"
				"\n"
				"Examples:\n"
				"  %s -c 5x9\n"
				"  %s -r myfont.ttf 5x9\n"
				"  %s 4x7\n"
				"\n",
				argv[0], argv[0], argv[0], argv[0]);
		return 0;
	}
	/* last argument as font size */
	font_name = argv[argc-1];
	font_namelen = strlen(font_name) + 7;
	sscanf(font_name, "%dx%d", &font_width, &font_height);
	snprintf(file_name, font_namelen, "./%s.png", font_name);
	//if ((argc > 3) && !strcmp(argv[1], "-r")) return font_render(font_name, font_namelen, argv[2], font_width, font_height);
	ascii_stop = (argc > 2) && !strcmp(argv[1], "-a");
	if (font_width > 32){
		printf("font too wide (%d), max width: 32\n", font_width);
		return 1;
	}
	else if (font_width >24) font_type = "Flash32";
	else if (font_width >16) font_type = "Flash24";
	else if (font_width > 8) font_type = "Flash16";
	image = libaroma_image_file(file_name, 0);
	if (!image){
		printf("failed to open image\n");
		return 1;
	}
	snprintf(file_name, font_namelen, "./%s.inc", font_name);
	FILE *out = fopen(file_name, "wb");
	if (!out){
		printf("failed to create out file\n");
		libaroma_canvas_free(image);
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
	int x, y, char_x, char_y, row_off,
		row_charn = (image->w+5) / FONT_WPAD;
	word pixel_color;
	char *row_buffer = malloc(((font_width + 3) * row_charn) * font_height);
	for (char_y=0; char_y<image->h; char_y+=FONT_HPAD){
		for (char_x=0; char_x<image->w; char_x+=FONT_WPAD){
			if (char_y == 0 && char_x == 0){
				char_ascii++;
				continue; //skip space char w/o increasing index
			}
			char_islast = ((char_ascii == '~' && ascii_stop) || (char_x+FONT_WPAD >= image->w && char_y+FONT_HPAD >= image->h));
			row_off = 0;
			for (y=0; y<font_height; y++){
				/* parse character row */
				offset=((char_y+y)*image->w)+char_x;
				row_buffer[row_off++] = '%';
				for (x=0; x<font_width; x++){
					/* use color to determine pixel value */
					pixel_color = image->data[offset+x];
					if (libaroma_color_isdark(pixel_color))
						row_buffer[row_off++] = '1';
					else row_buffer[row_off++] = '0';
				}
				/* separate non-last rows with comma */
				if (y+1<font_height){
					row_buffer[row_off++] = ',';
					row_buffer[row_off++] = ' ';
				}
			}
			row_buffer[row_off] = 0;
			if (!strstr(row_buffer, "1")){
				/* empty char, end & add unused value to respect previous line's ",_" */
				fprintf(out, "0 ' unused value" CHAR_NEWLINE);
				goto done;
			}
			fwrite(row_buffer, 1, row_off, out);
			fprintf(out, (char_islast)?"\t\t":",_\t");
			if (char_ascii > '~'){
				fprintf(out, "' custom char (%d)" CHAR_NEWLINE, char_index);
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

/*byte font_render(char *name, char *namelen, char *path){
	if (!libaroma_start()){ //font rendering does some DPI calculations (I know, that should be optional! Amarullz...)
		printf("Failed initializing libaroma\n");
		return 11;
	}
	libaroma_font_ex(0, libaroma_stream_file(path), 7);
	LIBAROMA_CANVASP cv = libaroma_canvas(FONT_WPAD * 16, FONT_HPAD * 6);
	if (!cv){
		printf("Failed creating cv\n");
		return 12;
	}
	libaroma_canvas_fillcolor(cv, 0xFFFFFF);
	//text=" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	char *text =" !\"#$%&'()*+,-./"	"\n"
				"0123456789:;<=>?"	"\n"
				"@ABCDEFGHIJKLMNO"	"\n"
				"PQRSTUVWXYZ[\\]^_"	"\n"
				"`abcdefghijklmno"	"\n"
				"pqrstuvwxyz{|}~"	"\n";
	LIBAROMA_TEXT txt = libaroma_text(text, 0, cv->w, LIBAROMA_TEXT_SINGLELINE|LIBAROMA_TEXT_NOHR, cv->h);
	if (!txt){
		printf("Fail allocating txt\n");
		return 13;
	}
	libaroma_text_draw(cv, txt, 0, 0);
	libaroma_text_free(txt);
	libaroma_png_save(cv, file_name);
	libaroma_canvas_free(cv);
	libaroma_end();
	return 0;
}*/