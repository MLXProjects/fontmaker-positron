# pbasic-mkfont
Generate PositronBASIC font from PNG ASCII map
## Info
Written in C, it uses [libaroma](https://github.com/MLXProjects/libaroma) for simple image parsing.  
## Creating a font include file
Draw a PNG file containing all ASCII characters, ordered from top-left to bottom-right, respecting font image specs.  
Name it `"<width>x<height>.png"` and run fontmaker using it's size as parameter, e.g. `./fontmaker 5x9`  
If everything works, you should see a `"<width>x<height>.inc"` file in the folder you ran fontmaker.  
Include that file on your source code and use it :D  
## Font image specs
- background color: white (any bright enough color should work)
- character color: black (any dark enough color should work)
- first character: space (yes, it's just an empty rectangle)
- padding between characters: 5x4 (5 horizontal, 4 vertical)
- max width: 32 (Positron BASIC doesn't support bigger variable sizes)
- last character: ~ (you can keep drawing after this one, just make sure to enable custom chars)
## How to compile
Just build/install libaroma and use the following command:  
`gcc main.c -o mkfont -laroma`
## Command-line help
```
Usage: fontmaker [OPTION] [WxH]

Options:
  -c		Generate custom characters using values after last ASCII character (~)
  WxH		Sets the font width and height to use
		Defaults to 5x10
  -h		Shows this help message

Examples:
  fontmaker -c 5x9
  fontmaker 4x7
```
## TODO:
- explain this all better pls
- add a few command line parameters? idk
## License
As always, my beloved Apache 2.0 license covers this code, just like libaroma :)
