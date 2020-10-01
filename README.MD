X Modifier Key Tester

xmkt is a program to test if modifier keys are held

pipe, or add as the first argument, the keysys ID into xmkt to get a result:

Example

	xmkt 0xFFE1
	echo "0xFFE1" | xmkt

The program will output a 1 or 0 telling if the current key is held.

To get the keysys of your desired key, just run xev and look at the keysys when you press the key you want to get the ID to.
