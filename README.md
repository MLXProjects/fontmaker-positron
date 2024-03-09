# fontmaker-positron
Generate [Positron BASIC](https://sites.google.com/view/rosetta-tech/home) font code from PNG ASCII map
## Description
Written in C, it uses [libaroma](https://github.com/MLXProjects/libaroma) for simple image parsing.  
This program parses PNG images and creates a .bas include file containing font pixel data.  
## Input image specs
- background color: white (any bright enough color should work)
- character color: black (any dark enough color should work)
- first character: space (yes, it's just an empty rectangle)
- padding between characters: 5x4 (5 horizontal, 4 vertical)
- max width: 32 (Positron BASIC doesn't support bigger variable sizes)
- last character: automatically found, if you specify `-a` parameter it'll try to parse until ~ character
## Output file specs
The generated file takes adavantage of the Positron's preprocessor to provide font info, it sets the following defines:  
- `FONT_WIDTH` constant value containing font's character width
- `FONT_HEIGHT` constant value containing font's character height
- `PLATFORM_FONT` constant that prevents multiple fonts to be defined if included.
- `str_font` flash memory address where the font data starts

In addition, every character has it's ASCII representation alongside it's offset (relative to the str_font address).
## Creating a font include file
Draw a PNG file containing all ASCII characters, ordered from top-left to bottom-right, respecting font image specs.  
Name it `"<width>x<height>.png"` (e.g. 5x9.png) and run fontmaker using it's size as parameter, e.g. `./fontmaker 5x9`  
If everything works, you should see a `"<width>x<height>.inc"` (e.g. 5x9.inc) file in the folder you ran fontmaker.  
Include that file on your source code and use it :D  
## How to compile
Just build/install libaroma and use the following command:  
`gcc main.c -o mkfont -laroma`
## Command-line help
```
Usage: fontmaker [OPTION] [WxH]

Options:
  -a		Stop parsing image after last ASCII character (~)
  -h		Shows this help message
  WxH		Sets the font width and height to use
		Defaults to 5x10

Examples:
  fontmaker -a 5x9
  fontmaker 4x7
```
## TODO:
- finish implementing ttf-to-bas (using libaroma font rendering)
- explain this all better pls
- add more customization?
## License
As always, my beloved Apache 2.0 license covers this code, just like libaroma :)
