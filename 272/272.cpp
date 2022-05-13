#include <cstdio>

int main(int argc, char	*argv[])
{
	bool close = false;
	int c;
	while((c = std::getc(stdin)) != EOF) {
		if (c == '"') {        		
			std::printf(close ? "''" : "``");
			close = !close;
		} else {
			std::putc(c, stdout);
		}
	}
	
	return 0;
}
