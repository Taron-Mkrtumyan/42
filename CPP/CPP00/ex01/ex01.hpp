#ifndef EX01_HPP
# define EX01_HPP

# include "color_escape_codes.h"

# define MAX_CONTACT 8
# define LENGTH_LIMIT 10
# define INFO_MASSAGE BCYAN "\nUsage:\n" BYELLOW "\
ADD	" RESET BRIGHT_CYAN ":	add a new contact\n" BYELLOW "\
SEARCH" RESET BRIGHT_CYAN "	:	display a specific contact\n" BYELLOW "\
EXIT	" RESET BRIGHT_CYAN ":	quit the program\n" RESET

#define WRONG_SEARCH_MESSAGE BRED "\nNo matching contact found.\n" RESET

enum RETURN_VALUE{
	FALSE,
	TRUE,
	CTRL_D
};

#endif
