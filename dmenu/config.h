static int topbar                        = 1;
static const char *fonts[]               = { "xos4 Terminus-9:antialias=true:autohint=true"};
static const char *prompt                = NULL;
static unsigned int lines                = 0;
static const char worddelimiters[]       = " ";

static const char *colors[SchemeLast][2] = {
	[SchemeNorm] = { "#747474", "#000000" },
	[SchemeSel]  = { "#000000", "#747474" },
	[SchemeOut]  = { "#747474", "#000000" },
};
