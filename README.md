# pbasic-mkfont
Make ProtonBASIC font data from PNG ASCII map

## Info
Written in C, uses [libaroma](https://github.com/MLXProjects/libaroma) for simple image parsing.  
This program uses alpha channel for defining character bits used.  
Hardcoded defaults:
- font PNG must be called image.png and will output code to font.bas
- font size fixed to 5x10
- uses byte variables for each character row
- spacing between characters: 5x4
## NOTE
After generating the font.bas file, MAKE SURE to remove the comma at the last byte variable so it compiles. This isn't automatic since I didn't find a decent way to do that, it oculd be done using the ftruncate function but I have no time to test that.
## How to compile
Just install libaroma and use the following command:  
`gcc main.c -o mkfont -laroma`
## Command-line parameters
The only supported parameter is `-c`, which makes program continue parsing after ~ character (last printable in ASCII code). It's useful to add custom characters/glyphs to your font.
## TODO:
- make all hardcoded things configurable please
- add lots of command-line parameters
- cleanup? idk
## License
As always, my beloved Apache 2.0 license covers this code, just like libaroma :)
