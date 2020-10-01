#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

void usage ()
{
    printf("please provide keysys arg, or pipe as standard input\nEXAMPLE: xmkt 0xFFE1");
}

int main (int argc, char *argv[])
{
	//check for passed arg, and for piped input
	if (argc == 1&& isatty(0)) {
		//printf("No input provided\n");
		usage();
	}
	else {
		char Keystring[7];
		if (argc == 1) {
			//prioritizing reading standard input over program args
			fgets (Keystring, 7, stdin);
		}
		else {
			//read from string
			for ( int a=0; a<7; a++) {
				Keystring[a] = argv[1][a] ;
			}
		}
		//convert string to int
		if (Keystring[0] == '0' && Keystring[1] == 'x') {
			unsigned int KeyValue;
			sscanf(Keystring, "%x", &KeyValue);
			//printf("0x%x %d\n", KeyValue, KeyValue);
			//check keysys
			Display* dpy = XOpenDisplay(NULL);
			char keys_return[32];
			XQueryKeymap( dpy, keys_return );
			KeyCode kc2 = XKeysymToKeycode( dpy, KeyValue );
			bool bShiftPressed = !!( keys_return[ kc2>>3 ] & ( 1<<(kc2&7) ) );
			//printf("%x is %sbeing held\n", KeyValue, bShiftPressed ? "" : "not ");
			XCloseDisplay(dpy);
			if (bShiftPressed){
				//fprintf( stdout, "1");
				puts("1");
			}
			else {
				//fprintf( stdout, "0");
				puts("0");
			}
		}
		else {
			printf("ERROR! Value must be in hex with 0x prefix!\n");
		}
	}
	return 0;
}
