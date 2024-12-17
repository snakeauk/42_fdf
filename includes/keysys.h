#ifndef KEYSYS_H
# define KEYSYS_H

#if defined(__APPLE__) && defined(__MACH__)
	# define WIDTH 900
	# define HEIGHT 700
	#include "keysys_mac.h"
#else
	# define WIDTH 1920
	# define HEIGHT 1080
	# include <X11/keysym.h>
#endif

#endif