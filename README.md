# My Personalized dwm Build

This is my customized suckless [dwm](https://dwm.suckless.org/) build.

Most of the patches has been choosen with [flexipatch](https://github.com/bakkeby/dwm-flexipatch).

# Important note on xrdb patch

The xrdb patch only works if we edit [`patches/xrdb.c`](patches/xrdb.c), comment out the original load function, as in:
```c++
			/**     XRDB_LOAD_COLOR("dwm.normfgcolor", normfgcolor); */
```

and replace them with

```c++
				XRDB_LOAD_COLOR("dwm.color6", normfgcolor);
```

The code to replace with is:

```c++
			if (xrdb != NULL) {
				XRDB_LOAD_COLOR("dwm.color6", normfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbordercolor);
				XRDB_LOAD_COLOR("dwm.color4", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0" , selfgcolor);
				XRDB_LOAD_COLOR("dwm.color8" , selbgcolor);
				XRDB_LOAD_COLOR("dwm.color14", selbordercolor);
				XRDB_LOAD_COLOR("dwm.color7", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.color6", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.titlenormfloatcolor", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0" , titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.color8" , titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.color14", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.titleselfloatcolor", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color6", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfloatcolor", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0" , tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.color8" , tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.color14", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsselfloatcolor", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.hidnormfgcolor", hidnormfgcolor);
				XRDB_LOAD_COLOR("dwm.hidnormbgcolor", hidnormbgcolor);
				XRDB_LOAD_COLOR("dwm.hidselfgcolor", hidselfgcolor);
				XRDB_LOAD_COLOR("dwm.hidselbgcolor", hidselbgcolor);
				XRDB_LOAD_COLOR("dwm.color6", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.color2", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.urgbordercolor", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.urgfloatcolor", urgfloatcolor);
                XRDB_LOAD_COLOR("color0", termcol0);
                XRDB_LOAD_COLOR("color1", termcol1);
                XRDB_LOAD_COLOR("color2", termcol2);
                XRDB_LOAD_COLOR("color3", termcol3);
                XRDB_LOAD_COLOR("color4", termcol4);
                XRDB_LOAD_COLOR("color5", termcol5);
                XRDB_LOAD_COLOR("color6", termcol6);
                XRDB_LOAD_COLOR("color7", termcol7);
                XRDB_LOAD_COLOR("color8", termcol8);
                XRDB_LOAD_COLOR("color9", termcol9);
                XRDB_LOAD_COLOR("color10", termcol10);
                XRDB_LOAD_COLOR("color11", termcol11);
                XRDB_LOAD_COLOR("color12", termcol12);
                XRDB_LOAD_COLOR("color13", termcol13);
                XRDB_LOAD_COLOR("color14", termcol14);
                XRDB_LOAD_COLOR("color15", termcol15);

				XrmDestroyDatabase(xrdb);
			}
```
