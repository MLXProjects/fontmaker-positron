#include <aroma.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
	if (argc>1 && strcmp(argv[1], "-c")){
		printf("Usage: %s [OPTION]\n"
				"Generate ProtonBASIC font from PNG ASCII map.\n"
				"\n"
				"Options:\n"
				"  -c"		"\t\tDon't stop parsing at last ASCII character (~).\n",
				argv[0]);
		return 0;
	}
	byte ascii_continue = (argc > 1) && !strcmp(argv[1], "-c");
	FILE *out = fopen("./font.bas", "w+");
	if (!out){
		printf("failed to open out file\n");
	}
	LIBAROMA_CANVASP image = libaroma_image_file("./image.png", 0);
	if (!image){
		printf("failed to open image\n");
		fclose(out);
		return 0;
	}
	fprintf(out, "LData\t");
	int offset, char_ascii=' ', char_index=0;
	int x, y, char_x, char_y, char_w=5, char_h=10;
	for (char_y=0; char_y<image->h; char_y+=14){
		for (char_x=0; char_x<image->w; char_x+=10){
			for (y=0; y<char_h; y++){
				offset=((char_y+y)*image->w)+char_x;
				fprintf(out, "%%");
				for (x=0; x<char_w; x++){
					if (image->alpha[offset+x] > 0){
						fprintf(out, "1");
					}
					else fprintf(out, "0");
				}
				fprintf(out, ",");
				if (y+1<char_h) fprintf(out, " ");
			}
			if (char_ascii > '~'){
				fprintf(out, "_\t\t\t\t\' Code for custom char %d\n\t\t", char_index);
			}
			else if (char_ascii > '@'){
				fprintf(out, "_\t\t\t\t\' Code for char %c %d\n\t\t", char_ascii, char_index);
			}
			else fprintf(out, "_\t\t\t\t\' Code for char %c\n\t\t", char_ascii);
			/* exit loop if last (standard) ASCII character & limit not disabled by argument */
			if (char_ascii == '~' && !ascii_continue) goto done;
			++char_ascii;
			char_index += 10;
		}
	}
done:
	fclose(out);
	libaroma_canvas_free(image);
	return 1;
}
