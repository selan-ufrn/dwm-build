/* See LICENSE file for copyright and license details. */
/*
 *  You obviously need the X11 development package installed, but here is the upstream copy
 *  of this header if you can't bother using the contents of your own hard drive. ;-P
 *  https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h
 */
#include <X11/XF86keysym.h>

#define DEFAULT_TERM "st"


/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 1;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 6;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 4;  /* vert inner gap between windows */
static const unsigned int gappoh         = 6;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 6;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 24;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 6;  /* vertical padding of bar */
static const int sidepad                 = 6;  /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const int horizpadbar             = 0;   /* horizontal padding for statusbar */
static const int vertpadbar              = 2;   /* vertical padding for statusbar */
static const unsigned int systrayspacing = 4;   /* systray spacing */
static const int showsystray             = 0;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
/* Mononoki Nerd Font must be installed from AUR nerd-fonts-complete.
 * Otherwise, your default font will be Hack which is found in the standard
 * Arch repos and is listed as a dependency for this build. JoyPixels is also
 * a hard dependency and makes colored fonts and emojis possible.
 */
// Global list of fonts to choose from.
static const char *fonts[]     = {
    "JetBrainsMono Nerd Font:style=Medium:pixelsize=14:antialias=true:autohint=true",
    "Fira Code:style=Medium:pixelsize=18:antialias=true:autohint=true",
    "VictorMono Nerd Font:style=Medium:pixelsize=18:antialias=true:autohint=true",
    "3270medium nerd font:weight=bold:size=12:antialias=true:hinting=true",
    "SauceCodePro Nerd Font:weight=bold:size=18:antialias=true:hinting=true",
    "SauceCodePro Nerd Font Mono:weight=bold:size=14:antialias=true:hinting=true",
    "Terminus:size=18:weight=bold:size=18:antialias=true:hinting=true",
    "Mononoki:size=12:antialias=true:autohint=true",

    "Hack:size=12:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true",
    "Mononoki:size=12:antialias=true:autohint=true",
    "fontawesome:size=14", 
    "monospace:size=10"
};
static const char dmenufont[]       = "JetBrainsMono Nerd Font:style=Medium:pixelsize=18:antialias=true:autohint=true";
// static const char dmenufont[]       = "Fira Code:style=Medium:pixelsize=18:antialias=true:autohint=true";
// static const char dmenufont[]       = "VictorMono Nerd Font:style=Medium:pixelsize=18:antialias=true:autohint=true";
// static const char dmenufont[]       = "monospace:size=10";
// static const char dmenufont[]       = "fontawesome:size=12";
// static const char dmenufont[]       = "Hack:size=12:antialias=true:autohint=true";
// static const char dmenufont[]       = "Mononoki:size=12:antialias=true:autohint=true";
// static const char dmenufont[]       = "Terminus:size=18:weight=bold:size=18:antialias=true:hinting=true";
// static const char dmenufont[]       = "SauceCodePro Nerd Font Mono:weight=bold:size=18:antialias=true:hinting=true";
// static const char dmenufont[]       = "3270medium nerd font:weight=bold:size=12:antialias=true:hinting=true";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";


// static const unsigned int baralpha = 0xd0; // 208
static const unsigned int baralpha = 0x64; // 100
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};




const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
    [DEFAULT_TAGS]        = { " ", " ", " ", "ﭮ ", " ", " ", " ", " ", " "},
	[ALTERNATIVE_TAGS]    = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
    // No specific tag
	RULE(.class= "zoom", .isfloating = 1)
	RULE(.title = "System Logout", .isfloating = 1)
	RULE(.class= "Blueman-manager", .isfloating = 1)
    // Specific tag
	RULE(.title = "Brave",              .tags = 1 << 1)
	RULE(.class = "telegram-desktop",   .tags = 1 << 2)
	RULE(.class = "discord",            .tags = 1 << 3)
	RULE(.class = "Gimp",               .tags = 1 << 4)
	RULE(.class = "Mailspring",         .tags = 1 << 6)
	RULE(.class = "Thunderbird",        .tags = 1 << 6)
	RULE(.class = "KeePassXC",          .tags = 1 << 7)
	RULE(.title = "Spotify",            .tags = 1 << 8)
	RULE(.class = "VirtualBox Manager", .isfloating = 1, .tags = 1 << 7)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{'A',        0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_status2d,          "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ ":::",      gaplessgrid },
	{ NULL,       NULL },
};


/* key definitions */
// #define MODKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
    "-l" , "15",
    "-c" , NULL,
	NULL
};
static const char *termcmd[]  = { "st", NULL };
//== alacritty
static const char *term2cmd[]  = { "alacritty", NULL };
//== kitty
static const char *term3cmd[]  = { "kitty", NULL };
//== firefox
// static const char *firefox_cmd[]  = { "firefox", NULL };
//== brave
static const char *brave_cmd[]  = { "brave", NULL };
//== pcmanfm 
// static const char *filemgr_cmd[]  = { "pcmanfm", NULL };
static const char *filemgr_cmd[]  = { "thunar", NULL };
//== thunderbird
// static const char *mail_cmd[]  = { "thunderbird", NULL };
static const char *mail_cmd[]  = { "mailspring", NULL };
//== discord
static const char *discord_cmd[]  = { "discord", NULL };
//== keepassxc
static const char *keepass_cmd[]  = { "keepassxc", NULL };
//== spotify
static const char *spotify_cmd[]  = { "spotify", NULL };
//== sxiv to change background and dwm's colorscheme:
// After app runs, choose the new background and then type
// Ctrl-x + Ctrl-w
// This calls a script that calls pywall and sets background with xwallpaper.
// After that, press MODKEY+Fn+F5 to reload color scheme based on xrbd
// static const char *sxiv_cmd[]  = { "sxiv -t /home/selan/Pictures/wallpapers", NULL };



static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_d,          spawn,                  {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = term2cmd } },
	{ MODKEY|Mod1Mask,              XK_Return,     spawn,                  {.v = term3cmd } },
    { MODKEY,                       XK_c,          spawn,                  SHCMD("conky-toggle") },
	{ MODKEY|Mod1Mask,              XK_4,          spawn,                  SHCMD("scshot -s $HOME/Pictures/screenshots/") },
	{ MODKEY,                       XK_t,          spawn,                  SHCMD("picom-toggle") },

    //== Keybindings for programs using the format SUPER + ALT + "key"
	{ ControlMask|Mod1Mask,         XK_b,          spawn,                  {.v = brave_cmd } },
	{ ControlMask|Mod1Mask,         XK_c,          spawn,                  SHCMD("sxiv -t $HOME/Pictures/wallpapers") },
	{ ControlMask|Mod1Mask,         XK_d,          spawn,                  {.v = discord_cmd} },
	{ ControlMask|Mod1Mask,         XK_e,          spawn,                  SHCMD("flameshot gui -p $HOME/Pictures/screenshots/") },
	{ ControlMask|Mod1Mask,         XK_f,          spawn,                  {.v = filemgr_cmd} },
	{ ControlMask|Mod1Mask,         XK_k,          spawn,                  {.v = keepass_cmd} },
	{ ControlMask|Mod1Mask,         XK_l,          spawn,                  SHCMD("xautolock -locknow") },
	{ ControlMask|Mod1Mask,         XK_m,          spawn,                  {.v = mail_cmd} },
    { ControlMask|Mod1Mask,         XK_n,          spawn,                  SHCMD("st -e lfub") },
	// { ControlMask|Mod1Mask,         XK_n,          spawn,                  SHCMD("st -e lf") },
	{ ControlMask|Mod1Mask,         XK_o,          spawn,                  SHCMD("openboard") },
	{ ControlMask|Mod1Mask,         XK_s,          spawn,                  {.v = spotify_cmd} },
    { ControlMask|Mod1Mask,         XK_t,          spawn,                  SHCMD("system-monitoring-center") },
	{ ControlMask|Mod1Mask,         XK_v,          spawn,                  SHCMD("pavucontrol") },

    //== Brightness and volume control
    { 0,                            XF86XK_AudioLowerVolume,  spawn,       SHCMD("vol_lower") },
    { 0,                            XF86XK_AudioRaiseVolume,  spawn,       SHCMD("vol_raise") },
    { 0,                            XF86XK_AudioMute,         spawn,       SHCMD("vol_mute_toggle") },
    { 0,                            XF86XK_MonBrightnessUp,   spawn,       SHCMD("mon_brightness_up") },
    { 0,                            XF86XK_MonBrightnessDown, spawn,       SHCMD("mon_brightness_down") },
    { 0,                            XF86XK_KbdBrightnessUp,   spawn,       SHCMD("kbd_brightness_up") },
    { 0,                            XF86XK_KbdBrightnessDown, spawn,       SHCMD("kbd_brightness_down") },


    //== Client Manipulation.
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY|ControlMask,           XK_space,      focusmaster,            {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_h,          focusdir,               {.i = 0 } }, // left
	{ MODKEY,                       XK_l,          focusdir,               {.i = 1 } }, // right
	{ MODKEY|ShiftMask,             XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,          setmfact,               {.f = +0.05} },
	// { MODKEY,                       XK_Left,       focusdir,               {.i = 0 } }, // left
	// { MODKEY,                       XK_Right,      focusdir,               {.i = 1 } }, // right
	{ MODKEY,                       XK_Up,         focusdir,               {.i = 2 } }, // up
	{ MODKEY,                       XK_Down,       focusdir,               {.i = 3 } }, // down
	{ MODKEY|ControlMask,           XK_j,          rotatestack,            {.i = +1 } },
	{ MODKEY|ControlMask,           XK_k,          rotatestack,            {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_j,          pushdown,               {0} },
	{ MODKEY|Mod1Mask,              XK_k,          pushup,                 {0} },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },

	{ MODKEY,                       XK_x,          transfer,               {0} },
    { MODKEY,                       XK_m,           zoom,                   {0} },
    { MODKEY,                       XK_BackSpace,  togglefloating,         {0} },
	{ MODKEY|Mod1Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        shiftviewclients,       { .i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,        shiftviewclients,       { .i = -1 } },
	// { MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ControlMask,           XK_h,          showhideclient,         {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY,                       XK_q,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_r,          self_restart,           {0} },
	{ MODKEY|ShiftMask,             XK_q,          spawn,                  SHCMD("logout_window") },
	// { MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {1} },
	{ MODKEY,                       XK_u,          focusurgent,            {0} },
	{ MODKEY,                       XK_o,          winview,                {0} },

    //== Fn Keys.
    { MODKEY,                       XK_F1,        spawn,                  SHCMD("groff -mom -tbl $HOME/.local/share/dwm/system_help.mom -Tpdf | zathura -") },
    { MODKEY,                       XK_F2,        spawn,                  SHCMD("lockscreen_toggle") },
    { MODKEY,                       XK_F3,        spawn,                  SHCMD("blueman-manager") },
    { MODKEY,                       XK_F4,        spawn,                  SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
	{ MODKEY,                       XK_F5,         xrdb,                  {.v = NULL } },
    { MODKEY,                       XK_F6,        spawn,                  SHCMD("dmenu_displayselect") },
    { MODKEY,                       XK_F7,        spawn,                  SHCMD("networkmanager_dmenu") },
    { MODKEY,                       XK_F8,        spawn,                  SHCMD("dunst_toggle") },
    { MODKEY,                       XK_F9,        spawn,                  SHCMD("wifi_toggle") },
    { MODKEY,                       XK_F10,       spawn,                  SHCMD("dmenu_mount") },

	{ MODKEY,                       XK_space,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_space,      cyclelayout,            {.i = +1 } },
	// { MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	// { MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	// { MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	// { MODKEY,                       XK_space,      setlayout,              {0} },
	// { MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_h,          togglehorizontalmax,    {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_l,          togglehorizontalmax,    {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_j,          toggleverticalmax,      {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_k,          toggleverticalmax,      {0} },
	{ MODKEY|ControlMask,           XK_m,          togglemax,              {0} },
	{ MODKEY,                       XK_z,          togglescratch,          {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_z,          setscratch,             {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_z,          removescratch,          {.ui = 0 } },
	{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
	{ MODKEY,                       XK_f,          fullscreen,             {0} },
	{ MODKEY,                       XK_s,          togglesticky,           {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_comma,      tagallmon,              {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_period,     tagallmon,              {.i = -1 } },
	{ MODKEY,                       XK_n,          togglealttag,           {0} },
	{ MODKEY,                       XK_KP_Home,       moveplace,              {.ui = WIN_NW }},   /* XK_KP_Home,  */
	{ MODKEY,                       XK_KP_8,       moveplace,              {.ui = WIN_N  }},   /* XK_KP_Up,    */
	{ MODKEY,                       XK_KP_9,       moveplace,              {.ui = WIN_NE }},   /* XK_KP_Prior, */
	{ MODKEY,                       XK_KP_4,       moveplace,              {.ui = WIN_W  }},   /* XK_KP_Left,  */
	{ MODKEY,                       XK_KP_5,       moveplace,              {.ui = WIN_C  }},   /* XK_KP_Begin, */
	{ MODKEY,                       XK_KP_6,       moveplace,              {.ui = WIN_E  }},   /* XK_KP_Right, */
	{ MODKEY,                       XK_KP_1,       moveplace,              {.ui = WIN_SW }},   /* XK_KP_End,   */
	{ MODKEY,                       XK_KP_2,       moveplace,              {.ui = WIN_S  }},   /* XK_KP_Down,  */
	{ MODKEY,                       XK_KP_3,       moveplace,              {.ui = WIN_SE }},   /* XK_KP_Next,  */
	// { MODKEY,                       XK_Left,       viewtoleft,             {0} }, // note keybinding conflict with focusdir
	// { MODKEY,                       XK_Right,      viewtoright,            {0} }, // note keybinding conflict with focusdir
	// { MODKEY|ShiftMask,             XK_Left,       tagtoleft,              {0} },
	// { MODKEY|ShiftMask,             XK_Right,      tagtoright,             {0} },
	// { MODKEY|ControlMask,           XK_Left,       tagandviewtoleft,       {0} },
	// { MODKEY|ControlMask,           XK_Right,      tagandviewtoright,      {0} },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};



