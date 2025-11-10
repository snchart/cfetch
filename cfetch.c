#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qu fflush(stdout)
#define GREEN "\x1b[37m"
#define RESET "\x1b[0m"
#define MAX 128

int main(){
	char ascia[] = "     .--.     ";
	char ascib[] = "    |o_o |    ";
	char ascic[] = "    |:_/ |    ";
	char ascid[] = "   //   \\ \\   ";
	char ascie[] = "  (|     | )  ";
	char ascif[] = " /'\\_   _/'\\  ";
	char ascig[] = " \\___)=(___/  ";
	FILE *fb;
	char buffer[MAX];
	int len;

	fb = popen("uname -s", "r");
	if (fb == NULL){
		return 1;
	}
	if (fgets(buffer, sizeof(buffer), fb) != NULL) {
		len = strlen(buffer);
			if (len > 0 && buffer[len - 1] == '\n') {
				buffer[len - 1] = '\0';
			}
		if(strcmp(buffer, "FreeBSD") == 0) {
			char ascia[] = " /\\,-'''''-,/\\  ";
			char ascib[] = " \\_)	   (_/  ";
			char ascic[] = " |	     |  ";
			char ascid[] = " |	     |  ";
			char ascie[] = "  ;	    ;   ";
			char ascif[] = "   '-_____-'    ";
			char ascig[] = "	        ";
			printf("%s", ascia);
                        printf(GREEN "OS:     " RESET);
                        qu;
                        system("cat /etc/os-release | grep PRETTY_NAME | awk -F '=' '{print $2}' | tr -d '\"\'");
                        printf("%s", ascib);
                        printf(GREEN "Host:   " RESET);
                        qu;
                        system("hostname");
                        printf("%s", ascic);
                        printf(GREEN "Kernel: " RESET);
                        qu;
                        system("uname -sr");
                        printf("%s", ascid);
                        printf(GREEN "Shell:  " RESET);
                        qu;
                        system("echo $SHELL");
                        printf("%s", ascie);
                        printf(GREEN "CPU:    " RESET);
                        qu;
                        system("sysctl -n hw.model");
                        printf("%s", ascif);
                        printf(GREEN "Memory: " RESET);
                        qu;
                        system("freecolor -mo | awk 'NR==2{print $3\"MiB\" \" / \" $2\"MiB\"}'");
                        printf("%s", ascig);
                        printf(GREEN "Disk:   " RESET);
                        qu;
                        system("df -h / | awk 'NR==2 {print $2 \" / \" $3}'");
                        printf("\n");
                        return 0;

		} else if(strcmp(buffer, "Linux") == 0) {
		        char ascia[] = "     .--.     ";
	        	char ascib[] = "    |o_o |    ";
        		char ascic[] = "    |:_/ |    ";
		        char ascid[] = "   //   \\ \\   ";
		        char ascie[] = "  (|     | )  ";
		        char ascif[] = " /'\\_   _/'\\  ";
		        char ascig[] = " \\___)=(___/  ";
		        printf("%s", ascia);
		        printf(GREEN "OS:     " RESET);
        		qu;
		        system("cat /etc/os-release | grep PRETTY_NAME | awk -F '=' '{print $2}' | tr -d '\"\'");
		        printf("%s", ascib);
		        printf(GREEN "Host:   " RESET);
		        qu;
		        system("hostname");
		        printf("%s", ascic);
		        printf(GREEN "Kernel: " RESET);
		        qu;
		        system("uname -sr");
		        printf("%s", ascid);
		        printf(GREEN "Shell:  " RESET);
		        qu;
		        system("echo $SHELL");
		        printf("%s", ascie);
		        printf(GREEN "CPU:   " RESET);
		        qu;
		        system("grep 'model name' /proc/cpuinfo | uniq | cut -d ':' -f 2");
		        printf("%s", ascif);
		        printf(GREEN "Memory: " RESET);
		        qu;
		        system("free -m | awk 'NR==2{print $3 \"MiB\" \" / \" $2 \"MiB\"}'");
		        printf("%s", ascig);
		        printf(GREEN "Disk:   " RESET);
		        qu;
		        system("df -h / | awk 'NR==2 {print $2 \" / \" $3}'");
		        printf("\n");
			return 0;
		}
	}
	pclose(fb);
	return 0;
}



