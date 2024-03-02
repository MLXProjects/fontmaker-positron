$ifndef PLATFORM_FONT
$define PLATFORM_FONT

$define FONT_WIDTH	5
$define FONT_HEIGHT	10

Dim str_font as Flash8=	%00110, %00110, %00110, %00110, %00110, %00110, %00110, %00000, %00110, %00110,_	' char ! (0)
						%11011, %11011, %11011, %11011, %00000, %00000, %00000, %00000, %00000, %00000,_	' char " (10)
						%01010, %01010, %11111, %11111, %01010, %11111, %11111, %01010, %01010, %00000,_	' char # (20)
						%00100, %01110, %10100, %10100, %01110, %00101, %00101, %00101, %01110, %00100,_	' char $ (30)
						%01001, %10101, %01010, %00010, %00100, %00100, %01000, %01010, %10101, %10010,_	' char % (40)
						%00100, %01010, %10001, %10001, %01010, %00100, %01101, %10010, %10101, %01001,_	' char & (50)
						%00110, %00110, %00110, %00110, %00000, %00000, %00000, %00000, %00000, %00000,_	' char ' (60)
						%00001, %00010, %00010, %00100, %00100, %00100, %00100, %00010, %00010, %00001,_	' char ( (70)
						%10000, %01000, %01000, %00100, %00100, %00100, %00100, %01000, %01000, %10000,_	' char ) (80)
						%00100, %10101, %01110, %01010, %10001, %00000, %00000, %00000, %00000, %00000,_	' char * (90)
						%00000, %00100, %00100, %00100, %11111, %11111, %00100, %00100, %00100, %00000,_	' char + (100)
						%00000, %00000, %00000, %00000, %00000, %00000, %00000, %00110, %00010, %00100,_	' char , (110)
						%00000, %00000, %00000, %00000, %11111, %11111, %00000, %00000, %00000, %00000,_	' char - (120)
						%00000, %00000, %00000, %00000, %00000, %00000, %00000, %00000, %00110, %00110,_	' char . (130)
						%00001, %00001, %00010, %00010, %00100, %00100, %01000, %01000, %10000, %10000,_	' char / (140)
						%01110, %11011, %11011, %11011, %11011, %11011, %11011, %11011, %11011, %01110,_	' char 0 (150)
						%00110, %01110, %11110, %00110, %00110, %00110, %00110, %00110, %00110, %00110,_	' char 1 (160)
						%01110, %11011, %10001, %00001, %00011, %00110, %01100, %11000, %11000, %11111,_	' char 2 (170)
						%01110, %10011, %00011, %00011, %01110, %00011, %00011, %10011, %10011, %01110,_	' char 3 (180)
						%11011, %11011, %11011, %11011, %01111, %00011, %00011, %00011, %00011, %00011,_	' char 4 (190)
						%11111, %11000, %11000, %11000, %11110, %00111, %00011, %00011, %11011, %01110,_	' char 5 (200)
						%01110, %11011, %10001, %10000, %11110, %11011, %11011, %11011, %11011, %01110,_	' char 6 (210)
						%11111, %00011, %00011, %00110, %00110, %00110, %01100, %01100, %01100, %01100,_	' char 7 (220)
						%01110, %11011, %11011, %11011, %01110, %11011, %11011, %11011, %11011, %01110,_	' char 8 (230)
						%01110, %11011, %11011, %11011, %11011, %01111, %00011, %00011, %00111, %11110,_	' char 9 (240)
						%00000, %00000, %00000, %00110, %00110, %00110, %00000, %00110, %00110, %00110,_	' char : (250)
						%00000, %00000, %00000, %00110, %00110, %00110, %00000, %00110, %00010, %00100,_	' char ; (260)
						%00000, %00000, %00000, %00001, %00010, %00100, %01000, %00100, %00010, %00001,_	' char < (270)
						%00000, %00000, %00000, %00000, %11111, %11111, %00000, %11111, %11111, %00000,_	' char = (280)
						%00000, %00000, %00000, %01000, %00100, %00010, %00001, %00010, %00100, %01000,_	' char > (290)
						%01110, %11011, %10001, %00011, %00110, %00100, %00100, %00000, %00100, %00100,_	' char ? (300)
						%00110, %01001, %10001, %10011, %10101, %10101, %10011, %10000, %01001, %00110,_	' char @ (310)
						%00100, %01110, %11011, %10001, %10001, %10001, %11111, %11111, %10001, %10001,_	' char A (320)
						%11110, %11001, %11001, %11001, %11110, %11001, %11001, %11001, %11001, %11110,_	' char B (330)
						%01110, %11011, %10001, %10000, %10000, %10000, %10000, %10001, %11011, %01110,_	' char C (340)
						%11110, %01011, %01001, %01001, %01001, %01001, %01001, %01001, %01011, %11110,_	' char D (350)
						%11111, %11111, %10000, %10000, %11110, %11110, %10000, %10000, %11111, %11111,_	' char E (360)
						%11111, %11111, %10000, %10000, %11110, %11110, %10000, %10000, %10000, %10000,_	' char F (370)
						%01110, %11011, %10001, %10000, %10000, %10011, %10001, %10001, %11011, %01110,_	' char G (380)
						%10001, %10001, %10001, %10001, %11111, %11111, %10001, %10001, %10001, %10001,_	' char H (390)
						%11111, %11111, %00100, %00100, %00100, %00100, %00100, %00100, %11111, %11111,_	' char I (400)
						%11111, %11111, %00001, %00001, %00001, %00001, %00001, %10001, %11011, %01110,_	' char J (410)
						%10001, %10001, %10010, %10100, %11000, %11000, %10100, %10010, %10001, %10001,_	' char K (420)
						%10000, %10000, %10000, %10000, %10000, %10000, %10000, %10000, %11111, %11111,_	' char L (430)
						%10001, %11011, %11011, %10101, %10101, %10001, %10001, %10001, %10001, %10001,_	' char M (440)
						%10001, %11001, %11001, %10101, %10101, %10011, %10011, %10001, %10001, %10001,_	' char N (450)
						%01110, %11011, %10001, %10001, %10001, %10001, %10001, %10001, %11011, %01110,_	' char O (460)
						%11110, %11001, %11001, %11001, %11110, %11000, %11000, %11000, %11000, %11000,_	' char P (470)
						%01110, %11011, %10001, %10001, %10001, %10001, %10001, %10101, %01110, %00001,_	' char Q (480)
						%11110, %10011, %10001, %10011, %11110, %11100, %10110, %10010, %10011, %10001,_	' char R (490)
						%01110, %11011, %10001, %10000, %11110, %01111, %00001, %10001, %11011, %01110,_	' char S (500)
						%11111, %11111, %00100, %00100, %00100, %00100, %00100, %00100, %00100, %00100,_	' char T (510)
						%10001, %10001, %10001, %10001, %10001, %10001, %10001, %10001, %11011, %01110,_	' char U (520)
						%10001, %10001, %10001, %10001, %01010, %01010, %01010, %01010, %00100, %00100,_	' char V (530)
						%10001, %10001, %10001, %10001, %10001, %10101, %10101, %11011, %11011, %10001,_	' char W (540)
						%10001, %10001, %01010, %01010, %00100, %00100, %01010, %01010, %10001, %10001,_	' char X (550)
						%10001, %10001, %10001, %01010, %01010, %00100, %00100, %00100, %00100, %00100,_	' char Y (560)
						%11111, %11111, %00001, %00010, %00100, %01000, %10000, %10000, %11111, %11111,_	' char Z (570)
						%11110, %10000, %10000, %10000, %10000, %10000, %10000, %10000, %10000, %11110,_	' char [ (580)
						%10000, %10000, %01000, %01000, %00100, %00100, %00010, %00010, %00001, %00001,_	' char \ (590)
						%01111, %00001, %00001, %00001, %00001, %00001, %00001, %00001, %00001, %01111,_	' char ] (600)
						%00100, %00100, %01010, %01010, %10001, %10001, %00000, %00000, %00000, %00000,_	' char ^ (610)
						%00000, %00000, %00000, %00000, %00000, %00000, %00000, %00000, %00000, %11111,_	' char _ (620)
						%10000, %10000, %01000, %01000, %00000, %00000, %00000, %00000, %00000, %00000,_	' char ` (630)
						%00000, %00000, %00000, %01110, %00001, %00001, %01111, %10001, %10001, %01111,_	' char a (640)
						%00000, %10000, %10000, %11110, %10001, %10001, %10001, %10001, %10001, %11110,_	' char b (650)
						%00000, %00000, %00000, %01110, %10001, %10000, %10000, %10000, %10001, %01110,_	' char c (660)
						%00000, %00001, %00001, %01111, %10001, %10001, %10001, %10001, %10001, %01111,_	' char d (670)
						%00000, %00000, %00000, %01110, %10001, %10001, %11111, %10000, %10000, %01111,_	' char e (680)
						%00000, %00110, %01001, %01000, %01000, %01000, %11110, %01000, %01000, %01000,_	' char f (690)
						%00000, %00000, %00000, %01111, %10001, %10001, %01111, %00001, %10001, %01110,_	' char g (700)
						%00000, %10000, %10000, %11110, %10001, %10001, %10001, %10001, %10001, %10001,_	' char h (710)
						%00000, %01000, %00000, %01000, %01000, %01000, %01000, %01000, %01000, %00100,_	' char i (720)
						%00000, %00010, %00000, %01110, %00010, %00010, %00010, %00010, %10010, %01100,_	' char j (730)
						%00000, %10000, %10000, %10000, %10010, %10100, %11000, %10100, %10010, %10010,_	' char k (740)
						%00000, %01000, %01000, %01000, %01000, %01000, %01000, %01000, %01000, %00110,_	' char l (750)
						%00000, %00000, %00000, %11010, %10101, %10101, %10101, %10001, %10001, %10001,_	' char m (760)
						%00000, %00000, %00000, %11110, %10001, %10001, %10001, %10001, %10001, %10001,_	' char n (770)
						%00000, %00000, %00000, %01110, %10001, %10001, %10001, %10001, %10001, %01110,_	' char o (780)
						%00000, %00000, %00000, %10110, %11001, %10001, %11001, %10110, %10000, %10000,_	' char p (790)
						%00000, %00000, %00000, %01101, %10011, %10001, %10011, %01101, %00001, %00001,_	' char q (800)
						%00000, %00000, %00000, %10110, %11001, %10000, %10000, %10000, %10000, %10000,_	' char r (810)
						%00000, %00000, %00000, %01111, %10000, %10000, %01110, %00001, %00001, %11110,_	' char s (820)
						%00000, %01000, %01000, %11110, %01000, %01000, %01000, %01000, %01000, %00111,_	' char t (830)
						%00000, %00000, %00000, %10001, %10001, %10001, %10001, %10001, %10001, %01111,_	' char u (840)
						%00000, %00000, %00000, %10001, %10001, %10001, %01010, %01010, %01010, %00100,_	' char v (850)
						%00000, %00000, %00000, %10001, %10001, %10001, %10001, %10101, %10101, %01011,_	' char w (860)
						%00000, %00000, %00000, %10001, %10001, %01010, %00100, %01010, %10001, %10001,_	' char x (870)
						%00000, %00000, %00000, %10001, %10001, %10001, %01111, %00001, %10001, %01110,_	' char y (880)
						%00000, %00000, %00000, %11111, %00001, %00010, %00100, %01000, %10000, %11111,_	' char z (890)
						%00011, %00100, %01000, %01000, %01000, %10000, %01000, %01000, %00100, %00011,_	' char { (900)
						%00100, %00100, %00100, %00100, %00100, %00100, %00100, %00100, %00100, %00100,_	' char | (910)
						%11000, %00100, %00010, %00010, %00010, %00001, %00010, %00010, %00100, %11000,_	' char } (920)
						%00000, %00000, %00000, %01001, %10101, %10010, %00000, %00000, %00000, %00000		' char ~ (930)

$endif 'PLATFORM_FONT