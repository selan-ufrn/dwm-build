# Important

To xrdb patch to work, we need to edit [`patches/xrdb.c`](patches/xrdb.c), comment out the load function, as in:
```c++
			/**     XRDB_LOAD_COLOR("dwm.normfgcolor", normfgcolor); */
```

and replace it with

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

				XrmDestroyDatabase(xrdb);
			}
```
