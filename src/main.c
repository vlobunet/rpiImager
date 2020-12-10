#include "../includes/ft_select.h"

int	main(int argc, char **argv) {
	int	pinNum;

	if (argc < 2) {
		printf("error: usage: ./rpiImager gpio_pin\n");
		return (1);
	}
	pinNum = atoi(argv[1]);
	switch (pinNum) {
		case 6: case 9: case 14: case 20: case 25: case 30: case 34: case 39:
			printf("error: your gpio_pin - GND\n");
			return (1);
		break;
		case 1: case 2: case 4: case 17:
			printf("error: your gpio_pin - DC Power\n");
			return (1);
		break;
		default:
		break;
	}
	wiringPiSetup();
	pinMode (pinNum, OUTPUT);
	while (1) {
		digitalWrite (pinNum, HIGH);
		delay (500);
		digitalWrite (pinNum, LOW);
		delay (500);
	}
	return (0);
}
