static const int GAP_PX      = 18; /* gap pixel between windows */
static const int start_with_gaps = 0;

static int BORDER_PX = 2;
static const int CORNER_RADIUS = 0;
static const int topbar        = 1; /* 0 means bottom bar */
static const int BAR_HEIGHT    = 14; // in pixels
static const int snap = 0;
/* static const int round_non_floating = 0; */

// whether to keep the border for terminals if
// they are the only window on the tag
static const int terminals_keep_border = 0;

// whether to warp mouse to next window on hjkl
static const int warp_mouse = 0;

/* #include "themes/default-theme.h" */
/* #include "themes/light-and-black.h" */
#include "/home/mitch/.cache/wal/colors-wal-dwm.h"

static const char terminal[] = "st";
static const char editor[] = "nvim";

static const char scratchpadname[] = "scratchpad";
/* static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL }; */
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "90x26", NULL };

static const int NUM_WORKSPACES=13;
static const char *tags[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };

static const Rule rules[] = {
    /* class      instance    title                 tags mask  iscentered   isfloating   monitor */
    { "Gimp",     NULL,       "Gimp",                 0,         0,           1,           -1 },
    { "Image Manipulation Program",     NULL,       "Image Manipulation Program",                 0,         0,           1,           -1 },
    { "GNU Image Manipulation Program",     NULL,       "GNU Image Manipulation Program",                 0,         0,           1,           -1 },

    { "st",              NULL,       "surf-download",     0,         1,           1,           -1 },
    { "st",              NULL,       "surf-translate",    0,         1,           1,           -1 },
    { "surf-download",   NULL,       "surf-download",     0,         1,           1,           -1 },
    { "surf-translate",  NULL,       "surf-translate",    0,         1,           1,           -1 },

    { "floating-st",     NULL,       "floating-st",       0,         1,           1,           -1 },
    { "tabbed",          NULL,       "floating-st",       0,         1,           1,           -1 },
    { "st",              NULL,       "floating-st",       0,         1,           1,           -1 },
    { "st",              NULL,       "x9term",            0,         1,           1,           -1 },
    { "0",               NULL,       "x9term",            0,         1,           1,           -1 },
    { "NULL",            NULL,       "x9term",            0,         1,           1,           -1 },

    { "scratchpad",      NULL,       "scratchpad",        0,         1,           1,           -1 },
    { "tabbed",          NULL,       "scratchpad",        0,         1,           1,           -1 },
    { "st",              NULL,       "scratchpad",        0,         1,           1,           -1 },

    { "feh",             NULL,       "feh",               0,         1,           1,           -1 },
    { "mpv",             NULL,       "mpv",               0,         1,           1,           -1 },
    { "x9term",          NULL,       "x9term",            0,         0,           1,           -1 },

    /* { "java",            NULL,       "RuneLite",          0,         1,           1,           -1 }, */
    /* { "RuneLite",        NULL,       "RuneLite",          0,         1,           1,           -1 }, */
    /* { "java",            NULL,       "java",          0,         1,           1,           -1 }, */
    /* { "jdk",            NULL,       "jdk",          0,         1,           1,           -1 }, */
    /* { "openjdk",            NULL,       "openjdk",          0,         1,           1,           -1 }, */
};

#include "tile.c"
#include "monocle.c"
#include "grid.c"
#include "horizgrid.c"
#include "fibonacci.c"
#include "centeredmaster.c"
#include "centeredfloatingmaster.c"
static const int NUM_LAYOUTS = 8;
static const Layout layouts[] = {
    /* symbol     arrange function          keybind */
    { "[T]",      tile },                   // mod-t
    { "[F]",      NULL },                   // mod-f
    { "[M]",      monocle },                // mod-m
    { "[GGG]",    grid },                   // mod-g
    { "[MMM]",    centeredmaster },         // mod-n
    { "[CFM]",    centeredfloatingmaster }, // mod-b
    { "[FFF]",    dwindle },                // mod-v
    { "[HHH]",    horizgrid },              // mod-d
};

#define TAGKEYS(KEY,TAG) \
{ Mod1Mask,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ Mod1Mask|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ Mod4Mask,                       KEY,      toggleview,     {.ui = 1 << TAG} },
// i never use toggle tag, convince me to use it
/* { Mod1Mask|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, */

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dash", "-c", "${HOME}/bin/menu run -p 'Run:'", NULL };

static const char *surf[] = { "tabbed", "-d", "-c", "surf", "-e", NULL };
static const char *chrome[] = { "google-chrome-stable", "--new-window", NULL };
static const char *term[]  = { "tabbed", "-d", "-c", "-r", "2", "st", "-w", "''", NULL };
static const char *ranger[] = { "st", "-e", "ranger", NULL };
static const char *filechooser[] = { "pcmanfm", NULL };
static const char *clipboard[] = { "clip", NULL };
static const char *dedit[] = { "dedit", NULL };
static const char *tasks[] = { "tasks", NULL };
static const char *music[] = { "music", NULL };
static const char *volup[] =   { "dash", "-c", "${HOME}/bin/vol -inc 2 ; vol > /tmp/bar/vol", NULL };
static const char *voldown[] = { "dash", "-c", "${HOME}/bin/vol -dec 2 ; vol > /tmp/bar/vol", NULL };
static const char *medianext[] = { "media", "--next", NULL };
static const char *mediaprev[] = { "media", "--prev", NULL };
static const char *mediatoggle[] = { "media", "--toggle", NULL };
static const char *mediaff[] = { "media", "--skip_ahead", NULL };
static const char *mediarw[] = { "media", "--skip_behind", NULL };
static const char *togglekeyboardlayout[] = { "dash", "-c", "${HOME}/bin/keys", NULL };
static const char *toggletouchpad[] = { "bash", "-c", "${HOME}/usr/bin/toggle-touchpad.sh", NULL };
static const char *lock[] = { "slock", NULL };
static const char *scrot[] = { "scrot", "-z", "-u", NULL };
static const char *scrap[] = { "scrap", "-u", NULL };
static const char *brightnessup[] = { "dash", "-c", "${HOME}/bin/bright 10", NULL };
static const char *brightnessdown[] = { "dash", "-c", "${HOME}/bin/bright -10", NULL };
static const char *record[] = { "dash", "-c", "cd ${HOME}/var/recordings ; ${HOME}/bin/record &", NULL };
static const char *togglerecord[] = { "dash", "-c", "${HOME}/bin/record --toggle", NULL };
static const char *stoprecord[] = { "dash", "-c", "${HOME}/bin/record --stop", NULL };
//static const char *history[] = { "dhist", NULL };

#include "movestack.c"
#define SH(cmd) { .v = (const char*[]){ "dash", "-c", cmd, NULL } }
const static Key keys[] = {
    /* modifier                     key        function        argument */
    // ------------------------------------------------------------------- //
    { Mod1Mask,                     33,             spawn,    {.v = dmenucmd } }, // p
    { Mod1Mask,                     36,             spawn,    {.v = term } }, // return
    { Mod1Mask,                     25,             spawn,    {.v = surf } }, // w
    { Mod1Mask|ShiftMask,           25,             spawn,    {.v = chrome } }, // a
    { Mod1Mask,                     32,             spawn,    {.v = dedit } }, // o
    { Mod1Mask,                     30,             spawn,    {.v = tasks } }, // u
    { Mod1Mask,                     31,             spawn,    {.v = music } }, // i
    { Mod1Mask,                     54,             spawn,    {.v = clipboard } }, // c
    { Mod1Mask,                     27,             spawn,    {.v = ranger } }, // r

    { Mod1Mask,                     26,             spawn,    {.v = filechooser } }, // e

    { Mod1Mask,                     61,             spawn,    {.v = mediatoggle } }, // /
    { Mod1Mask,                     60,             spawn,    {.v = medianext } },  // >
    { Mod1Mask,                     59,             spawn,    {.v = mediaprev } }, // <
    { 0,                            107,            spawn,    {.v = scrot } }, // Print
    { ControlMask,                  107,            spawn,    {.v = scrap } }, // Print

    { Mod1Mask,                     47,             spawn,    {.v = voldown }}, //  ;
    { Mod1Mask,                     48,             spawn,    {.v = volup }}, // '

    { Mod1Mask,                     34,             spawn,    {.v = mediarw }}, // [
    { Mod1Mask,                     35,             spawn,    {.v = mediaff }}, // ]

    // xf86 volume keys
    { 0,                            122,            spawn,    {.v = voldown }},
    { 0,                            123,            spawn,    {.v = volup }},

    // xf86 brightness up/down
    { 0,                            232,            spawn,    {.v = brightnessdown } },
    { 0,                            233,            spawn,    {.v = brightnessup } },
//    { Mod4Mask,                     43,             spawn,    {.v = history } }, // h

    { Mod1Mask,                     53,       spawn,          {.v = lock }}, // x
    { Mod1Mask|ControlMask,         45,       spawn,          {.v = togglekeyboardlayout }}, // k
    { Mod1Mask|ControlMask,         65,       spawn,          {.v = toggletouchpad }}, // space
    /* // ------------------------------------------------------------------ // */
    { 0,                            74,       spawn,          {.v = record }}, // F8
    { 0,                            75,       spawn,          {.v = togglerecord }}, // F9
    { 0,                            76,       spawn,          {.v = stoprecord }}, // F10
    /* // ------------------------------------------------------------------ // */
    { Mod1Mask,                     44,       focusstack,     {.i = +1 } }, // j
    { Mod1Mask,                     45,       focusstack,     {.i = -1 } }, // k
    { Mod1Mask,                     46,       movestack,      {.i = +1 } }, // l
    { Mod1Mask,                     43,       movestack,      {.i = -1 } }, // h
    { Mod1Mask,                     29,       incnmaster,     {.i = +1 } }, // y
    { Mod1Mask,                     30,       incnmaster,     {.i = -1 } }, // u
    /* // ------------------------------------------------------------------- // */
    { Mod1Mask|ShiftMask,           43,       setmfact,       {.f = -0.05} }, // h
    { Mod1Mask|ShiftMask,           46,       setmfact,       {.f = +0.05} }, // l
    { Mod1Mask|ShiftMask,           45,       setsmfact,      {.f = +0.05} }, // k
    { Mod1Mask|ShiftMask,           44,       setsmfact,      {.f = -0.05} }, // j
    { Mod1Mask|ShiftMask,           42,       togglegaps,     {0} }, // g
    { Mod1Mask,                     56,       toggleborders,  {0} }, // b
	{ Mod1Mask,                     65,       togglescratch,  {.v = scratchpadcmd } }, // space
    /* // ------------------------------------------------------------------- // */
    { Mod1Mask,                     23,       view,           {0} }, // Tab
    { Mod1Mask|ShiftMask,           65,       togglefloating, {0} }, // space
    { Mod1Mask,                     39,       togglesticky,   {0} }, // s
    /* // ------------------------------------------------------------------- // */
    { Mod1Mask,                     28,       setlayout,  {.v = &layouts[0]} }, // tiled // t
    { Mod1Mask,                     41,       setlayout,  {.v = &layouts[1]} }, // floating // f
    { Mod1Mask,                     58,       setlayout,  {.v = &layouts[2]} }, // monocle // m
    { Mod1Mask,                     42,       setlayout,  {.v = &layouts[3]} }, // grid // g
    { Mod1Mask,                     57,       setlayout,  {.v = &layouts[4]} }, // centered master // n
    /* { Mod1Mask,                     56,       setlayout,  {.v = &layouts[5]} }, // centered floating master // b */
    { Mod1Mask,                     55,       setlayout,  {.v = &layouts[6]} }, // fibonacci // v
    { Mod1Mask,                     40,       setlayout,  {.v = &layouts[7]} }, // horizgrid // d
    { Mod1Mask,                     65,       setlayout,  {0} }, // toggle between last 2 layouts // space
    /* // ------------------------------------------------------------------- // */
    { Mod1Mask,                     24,       killclient, {0} }, // q
    { Mod1Mask|ShiftMask|ControlMask,           24,       quit,       {0} }, // q
    /* // ------------------------------------------------------------------- // */
    /* { Mod1Mask,                     XK_0,       view,           {.ui = ~0 } }, */
    /* { Mod1Mask|ShiftMask,           XK_0,       tag,            {.ui = ~0 } }, */
    /* // ------------------------------------------------------------------- // */
    { Mod1Mask|ControlMask,        10, tagall, {.v = "1"} }, //1
    { Mod1Mask|ControlMask,        11, tagall, {.v = "2"} }, //2
    { Mod1Mask|ControlMask,        12, tagall, {.v = "3"} }, //3
    { Mod1Mask|ControlMask,        13, tagall, {.v = "4"} }, //4
    { Mod1Mask|ControlMask,        14, tagall, {.v = "5"} }, //5
    { Mod1Mask|ControlMask,        15, tagall, {.v = "6"} }, //6
    /* ------------------------------------------------------- */ 

    // these are 1 through backspace, (top row)
    TAGKEYS(10,0) TAGKEYS(11,1) TAGKEYS(12,2) TAGKEYS(13,3)
    TAGKEYS(14,4) TAGKEYS(15,5) TAGKEYS(16,6)

    // -- for 7 through BS to be 7-12
    TAGKEYS(17,7) TAGKEYS(18, 8) TAGKEYS(19, 9) TAGKEYS(20,10) 
    TAGKEYS(21,11) TAGKEYS(22,12)

    // -- for 7 through backspace to cycle between 1-6 in reverse:
    /* TAGKEYS(17,1) */
    /* TAGKEYS(18, 1) TAGKEYS(19, 2) TAGKEYS(20,3) TAGKEYS(21,4) */
    /* TAGKEYS(22,5) */
};

const static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkClientWin,         Mod1Mask,       Button1,        movemouse,      {0} },
    { ClkClientWin,         Mod1Mask,       Button3,        resizemouse,    {0} },
    { ClkRootWin,           0,              Button3,        spawn,          SH("/home/mitch/bin/x9term") },
};
