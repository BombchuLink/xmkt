X Modifier Key Tester

xmkt is a program to test if modifier keys are held

pipe the keysys ID into xmkt to get a result:

Example

	echo "0xFFE1" | xmkt

To get the keysys of your desired key, just run xev and look at the keysys when you press the key you want to get the ID to.

