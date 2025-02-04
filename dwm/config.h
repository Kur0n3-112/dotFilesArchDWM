/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

//Gruvbox Colors
static const char bg[]              = "#282828";
static const char red[]             = "#cc241d";
static const char green_1[]         = "#98971a";
static const char yellow_1[]        = "#d79921";
static const char blue_1[]          = "#458588";
static const char purple_1[]        = "#b16286";
static const char aqua_1[]          = "#689d6a";
static const char gray_1[]          = "#a89984";

static const char gray_2[]          = "#928374";
static const char red_2[]           = "#fb4934";
static const char green_2[]         = "#b8bb26";
static const char yellow_2[]        = "#fabd2f";
static const char blue_2[]          = "#83a598";
static const char purple_2[]        = "#d3869b";
static const char aqua_2[]          = "#8ec07c";
static const char fg[]              = "#ebdbb2";

static const char bg0_h[]           = "#1d2021";
static const char bg0[]             = "#282828";
static const char bg1[]             = "#3c3836";
static const char bg2[]             = "#504945";
static const char bg3[]             = "#665c54";
static const char bg4[]             = "#7c6f64";
static const char gray_3[]          = "#928374";
static const char orange_1[]        = "#d65d0e";

static const char bg0_s[]           = "#32302f";
static const char fg4[]             = "#a89984";
static const char fg3[]             = "#bdae93";
static const char fg2[]             = "#d5c4a1";
static const char fg1[]             = "#ebdbb2";
static const char fg0[]             = "#fbf1c7";
static const char orange_2[]        = "#fe8019";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { fg,        bg,        bg0 },
	[SchemeSel]  = { fg1,       bg1,       orange_2 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "nm-connection-editor",
                  NULL,       NULL,       0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask //Windows key
#define ALTMODKEY Mod1Mask //Alt key
#define CTRLMODKEY ControlMask //Control key
#define SHIFTMODKEY ShiftMask //Shift key
#define TAGKEYS(KEY,TAG) \
	{ ALTMODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ALTMODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ ALTMODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ALTMODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg, "-nf", fg, "-sb", fg, "-sf", bg, NULL };
static const char *termcmd[]  = { "kitty", NULL };

static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ALTMODKEY,             XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|SHIFTMODKEY,           XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY|ALTMODKEY,             XK_l,      setlayout,      {0} },
    { MODKEY|SHIFTMODKEY,           XK_f,      togglefloating, {0} },
    { MODKEY|CTRLMODKEY,            XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|SHIFTMODKEY,           XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|SHIFTMODKEY,           XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|SHIFTMODKEY,           XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|CTRLMODKEY,            XK_Delete, quit,           {0} },
    { MODKEY,                       XK_s,      togglesticky,   {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

