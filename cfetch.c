#include <stdio.h>
#include <stdlib.h>
#define qu fflush(stdout)
#define GREEN "\x1b[37m"
#define RESET "\x1b[0m"

int main(){
	char ascia[] = "     .--.     ";
	char ascib[] = "    |o_o |    ";
	char ascic[] = "    |:_/ |    ";
	char ascid[] = "   //   \\ \\   ";
	char ascie[] = "  (|     | )  ";
	char ascif[] = " /'\\_   _/'\\  ";
	char ascig[] = " \\___)=(___/  ";
	printf("%s", ascia);
	printf(GREEN "OS: " RESET);
	qu;
	system("cat /etc/os-release | grep PRETTY_NAME | awk -F '=' '{print $2}' | tr -d '\"\'");
	printf("%s", ascib);
	printf(GREEN "Host: " RESET);
	qu;
	system("hostname");
	printf("%s", ascic);
	printf(GREEN "Kernel: " RESET);
	qu;
	system("uname -sr");
	printf("%s", ascid);
	printf(GREEN "Shell: " RESET);
	qu;
	system("echo $SHELL");
	printf("%s", ascie);
	printf(GREEN "CPU: " RESET);
	qu;
	system("grep 'model name' /proc/cpuinfo | uniq | cut -d ':' -f 2");
	printf("%s", ascif);
	printf(GREEN "Memory: " RESET);
	qu;
	system("free -m | awk 'NR==2{print $3 \"MiB\" \" / \" $2 \"MiB\"}'");
	printf("%s", ascig);
	printf(GREEN "Disk: " RESET);
	qu;
	system("df -BG --output=used,size / | awk 'NR==2 {print $1\" / \"$2}'");
	printf("\n");
	return 0;
}



