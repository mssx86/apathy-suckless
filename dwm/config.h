/* include for xf86 keys */
#include <X11/XF86keysym.h>

/* -- bar -- */
static const int showbar            = 1;
static const int topbar             = 1;
static const char *tags[]           = { "1", "2", "3", "4", "5" };
static const char *fonts[]          = { "xos4 Terminus:size=9" };
static const Layout layouts[]       = {
	{ "T",     tile    },
	{ "F",     NULL    },
	{ "M",     monocle },
};

/* -- colors -- */
static const char dummy[]	    = "#ff00ff";
static const char *colors[][3]      = {
	[SchemeLayout]              = { "#f7f7f7", "#000000",  dummy     }, /* layout selector         */
	[SchemeStatus]              = { "#ababab", "#000000",  dummy     }, /* statusbar               */
	[SchemeTagsSel]             = { "#6d7373", "#000000",  dummy     }, /* tags, focused           */
	[SchemeTagsNorm]            = { "#ababab", "#000000",  dummy     }, /* tags, inactive          */
	[SchemeInfoSel]             = { "#555555", "#000000",  dummy     }, /* window title, focused   */
	[SchemeInfoNorm]            = { "#464646", "#000000",  dummy     }, /* window title, inactive  */
	[SchemeBorderSel]           = {  dummy,     dummy,     "#252525" }, /* window border, focused  */
	[SchemeBorderNorm]          = {  dummy,     dummy,     "#101010" }, /* window border, inactive */
};

/* -- window rules -- */
static const Rule rules[] = {
	{ "Xmessage", NULL, 0, 0, 1, -1 },
	{ "feh",      NULL, 0, 0, 1, -1 },
};

/* -- window sizing -- */
static const unsigned int borderpx  = 1;    /* border thickness            */
static const unsigned int gappx     = 0;    /* gaps                        */
static const unsigned int snap      = 2;    /* snap pixel                  */
static const float mfact            = 0.60; /* factor of master area size  */
static const float smfact           = 0.0f; /* factor of tiled clients     */
static const unsigned int minwsz    = 30;   /* min height for smfact       */
static const int nmaster            = 1;    /* number of clients in master */
static const int resizehints        = 0;    /* do not respect rezie hints  */

/* -- key definitions -- */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,    view,          {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,    toggleview,    {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,    tag,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,    toggletag,     {.ui = 1 << TAG} },

/* -- shell command spawner -- */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* -- pre-defined commands -- */
static const char *termcmd[]  = { "st", NULL };
static const char *tmuxcmd[]  = { "st", "-e", "tmux", NULL };

/* -- keyboard binds -- */
static Key keys[] = {
	/* script invocation */
	{ MODKEY,              XK_b,                       spawn,    SHCMD("/mss/bin/switchcompositor novsync")                  },
	{ MODKEY|ShiftMask,    XK_b,                       spawn,    SHCMD("/mss/bin/switchcompositor vsync")                    },
	{ Mod1Mask,            XK_t,                       spawn,    SHCMD("/mss/bin/switchkb")                                  },
	{ MODKEY,              XK_p,                       spawn,    SHCMD("/mss/bin/maimscrot")                                 },
	{ MODKEY|ShiftMask,    XK_p,                       spawn,    SHCMD("/mss/bin/maimclip")                                  },
	{ MODKEY,              XK_o,                       spawn,    SHCMD("/mss/bin/maimcrop")                                  },
	{ MODKEY,              XK_d,                       spawn,    SHCMD("dmenu_run -b")                                       },
	{ MODKEY|ShiftMask,    XK_d,                       spawn,    SHCMD("/home/mss/.config/scripts/menuboi")                  },
	{ MODKEY,              XK_c,                       spawn,    SHCMD("/home/mss/.config/scripts/chrootmenu")               },
	/* misc */
	{ MODKEY,              XK_n,                       spawn,    SHCMD("xtrlock")                                            },
	{ MODKEY,              XK_m,                       spawn,    SHCMD("feh --bg-fill --randomize /home/mss/cust/chan")      },
	{ MODKEY|ShiftMask,    XK_m,                       spawn,    SHCMD("feh --bg-fill /home/mss/cust/other/black.png")       },
	{ Mod1Mask,            XK_m,                       spawn,    SHCMD("/home/mss/.fehb.def")                                },
	{ MODKEY,              XK_w,                       spawn,    SHCMD("pkill -RTMIN+3 dwmblocks")                           },
	/* alsa */
	{ 0,                   XF86XK_AudioRaiseVolume,    spawn,    SHCMD("amixer -q set Master 3dB+")                          },
	{ 0,                   XF86XK_AudioLowerVolume,    spawn,    SHCMD("amixer -q set Master 3dB-")                          },
	{ MODKEY|ShiftMask,    XF86XK_AudioRaiseVolume,    spawn,    SHCMD("amixer -q set Capture 3dB+")                         },
	{ MODKEY|ShiftMask,    XF86XK_AudioLowerVolume,    spawn,    SHCMD("amixer -q set Capture 3dB-")                         },
	{ 0,                   XF86XK_AudioMute,           spawn,    SHCMD("amixer -q set Master toggle")                        },
	/* mpd */
	{ 0,                   XF86XK_AudioPlay,           spawn,    SHCMD("mpc -q toggle;    pkill -RTMIN+1 dwmblocks")         },
	{ 0,                   XF86XK_AudioStop,           spawn,    SHCMD("mpc -q stop;      pkill -RTMIN+1 dwmblocks")         },
	{ 0,                   XF86XK_AudioNext,           spawn,    SHCMD("mpc -q next;      pkill -RTMIN+1 dwmblocks")         },
	{ 0,                   XF86XK_AudioPrev,           spawn,    SHCMD("mpc -q prev;      pkill -RTMIN+1 dwmblocks")         },
	{ MODKEY,              XF86XK_AudioRaiseVolume,    spawn,    SHCMD("mpc -q vol +5")                                      },
	{ MODKEY,              XF86XK_AudioLowerVolume,    spawn,    SHCMD("mpc -q vol -5")                                      },

	/* tag count */
	TAGKEYS(		XK_1,	0)
	TAGKEYS(		XK_2,	1)
	TAGKEYS(		XK_3,	2)
	TAGKEYS(		XK_4,	3)
	TAGKEYS(		XK_5,	4)

	/* dwm functions */
	{ MODKEY,               XK_Return,    spawn,             {.v = termcmd }    }, /* spawn term                */
	{ MODKEY|ShiftMask,     XK_Return,    spawn,             {.v = tmuxcmd }    }, /* spawn tmux                */
	{ MODKEY|ShiftMask,     XK_q,         killclient,        {0}                }, /* kill window               */
	{ MODKEY|ShiftMask,     XK_0,         tag,               {.ui = ~0 }        }, /* move window to ws         */
	{ MODKEY,               XK_j,         focusstack,        {.i = +1 }         }, /* focus to stack            */
	{ MODKEY,               XK_k,         focusstack,        {.i = -1 }         }, /* focus to master           */
	{ MODKEY,               XK_i,         incnmaster,        {.i = +1 }         }, /* move window to master     */
	{ MODKEY,               XK_u,         incnmaster,        {.i = -1 }         }, /* remove window from master */
	{ MODKEY,               XK_l,         setmfact,          {.f = +0.01}       }, /* +master size              */
	{ MODKEY,               XK_h,         setmfact,          {.f = -0.01}       }, /* -^^^^^^^^^^^              */
	{ MODKEY|ShiftMask,     XK_h,         setsmfact,         {.f = +0.01}       }, /* +^^^^^^ height            */
	{ MODKEY|ShiftMask,     XK_l,         setsmfact,         {.f = -0.01}       }, /* -^^^^^^^^^^^^^            */
	{ MODKEY,               XK_minus,     setgaps,           {.i = -1 }         }, /* +gap size                 */
	{ MODKEY,               XK_equal,     setgaps,           {.i = +1 }         }, /* -^^^^^^^^                 */
	{ MODKEY|ShiftMask,     XK_equal,     setgaps,           {.i = 0  }         }, /* toggle gaps               */
	{ MODKEY,               XK_t,         setlayout,         {.v = &layouts[0]} }, /* enable tiling             */
	{ MODKEY,               XK_g,         setlayout,         {.v = &layouts[2]} }, /* enable monacle            */
	{ Mod1Mask,             XK_Tab,       zoom,              {0}                }, /* swap 1st stack with main  */
	{ MODKEY,               XK_space,     setlayout,         {0}                }, /* switch between layouts    */
	{ MODKEY|ShiftMask,     XK_space,     togglefloating,    {0}                }, /* toggle floating           */
	{ MODKEY,               XK_f,         togglefullscr,     {0}                }, /* toggle fullscreen         */
	{ MODKEY,               XK_comma,     focusmon,          {.i = -1 }         }, /* focus to other monitor    */
	{ MODKEY,               XK_period,    focusmon,          {.i = +1 }         }, /* ^^^^^^^^^^^^^^^^^^^^^^    */
	{ MODKEY|ShiftMask,     XK_comma,     tagmon,            {.i = -1 }         }, /* move tag to monitor       */
	{ MODKEY|ShiftMask,     XK_period,    tagmon,            {.i = +1 }         }, /* remove tag from monitor   */
	{ MODKEY|ShiftMask,     XK_r,         quit,              {0}                }, /* end it all                */
};

/* -- mouse button binds -- */
/* actions are: ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, ClkRootWin */
static Button buttons[] = {
	/* mpd and alsa control */
	{ ClkStatusText,    0,         Button1,    spawn,            SHCMD("mpc -q next;   pkill -RTMIN+1 dwmblocks") },
	{ ClkStatusText,    0,         Button3,    spawn,            SHCMD("mpc -q prev;   pkill -RTMIN+1 dwmblocks") },
	{ ClkStatusText,    0,         Button2,    spawn,            SHCMD("mpc -q toggle; pkill -RTMIN+1 dwmblocks") },
	{ ClkStatusText,    0,         Button4,    spawn,            SHCMD("mpc -q vol +5")                           },
	{ ClkStatusText,    0,         Button5,    spawn,            SHCMD("mpc -q vol -5")                           },
	{ ClkStatusText,    MODKEY,    Button2,    spawn,            SHCMD("amixer -q set Master toggle")             },
	{ ClkStatusText,    MODKEY,    Button4,    spawn,            SHCMD("amixer -q set Master 3dB+")               },
	{ ClkStatusText,    MODKEY,    Button5,    spawn,            SHCMD("amixer -q set Master 3dB-")               },
	/* base dwm binds */
	{ ClkLtSymbol,      0,         Button1,    setlayout,        {0}                                              },
	{ ClkLtSymbol,      0,         Button3,    setlayout,        {.v = &layouts[2]}                               },
	{ ClkWinTitle,      0,         Button2,    zoom,             {0}                                              },
	{ ClkClientWin,     MODKEY,    Button1,    movemouse,        {0}                                              },
	{ ClkClientWin,     MODKEY,    Button2,    togglefloating,   {0}                                              },
	{ ClkClientWin,     MODKEY,    Button3,    resizemouse,      {0}                                              },
	{ ClkTagBar,        0,         Button1,    view,             {0}                                              },
	{ ClkTagBar,        0,         Button3,    toggleview,       {0}                                              },
	{ ClkTagBar,        MODKEY,    Button1,    tag,              {0}                                              },
	{ ClkTagBar,        MODKEY,    Button3,    toggletag,        {0}                                              },
};
