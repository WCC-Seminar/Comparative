#include <AL/alut.h>

#pragma comment( lib, "OpenAL32.lib" )
#pragma comment( lib, "alut.lib" ) 

#define LNG 0.075

int Enter_Mrs(char* mrs,int focus,char* string){
	int fstr=0;
	while(string[fstr]!='\0'){
		if(string[fstr]==' '){
			mrs[focus]=0;focus++;
		}else if(string[fstr]=='.'){
			mrs[focus]=1;focus++;
			mrs[focus]=0;focus++;
		}else if(string[fstr]=='_'){
			mrs[focus]=3;focus++;
			mrs[focus]=0;focus++;
			mrs[focus]=0;focus++;
			mrs[focus]=0;focus++;
		}
		fstr++;
	}
	mrs[focus]=0;focus++;
	mrs[focus]=0;focus++;
	mrs[focus]=0;focus++;
	return focus;
}

int atom(char* mrs,char* word){
	int focus=0;
	for(int i=0;i<256;i++){
		switch(word[i]){
		case ' ':
		case '_':
			focus = Enter_Mrs(mrs,focus," ");break;
		case '-':
			focus = Enter_Mrs(mrs,focus,"_...._");break;
		case ',':
			focus = Enter_Mrs(mrs,focus,"__..__");break;
		case '.':
			focus = Enter_Mrs(mrs,focus,"._._._");break;
		case '!':
			focus = Enter_Mrs(mrs,focus,"_..._._");break;
		case '?':
			focus = Enter_Mrs(mrs,focus,"..__..");break;
		case '(':
			focus = Enter_Mrs(mrs,focus,"_.__._");break;
		case ')':
			focus = Enter_Mrs(mrs,focus,"_.__.");break;
		case '=':
			focus = Enter_Mrs(mrs,focus,"_..._");break;
		case '@':
			focus = Enter_Mrs(mrs,focus,".__._.");break;
		case '+':
			focus = Enter_Mrs(mrs,focus,"._._.");break;
		case '/':
			focus = Enter_Mrs(mrs,focus,"_.._.");break;
		case 0x27:
			focus = Enter_Mrs(mrs,focus,".____.");break;
		case 0x3a:
			focus = Enter_Mrs(mrs,focus,"___...");break;
		case '0':
			focus = Enter_Mrs(mrs,focus,"_____");break;
		case '1':
			focus = Enter_Mrs(mrs,focus,".____");break;
		case '2':
			focus = Enter_Mrs(mrs,focus,"..___");break;
		case '3':
			focus = Enter_Mrs(mrs,focus,"...__");break;
		case '4':
			focus = Enter_Mrs(mrs,focus,"...._");break;
		case '5':
			focus = Enter_Mrs(mrs,focus,".....");break;
		case '6':
			focus = Enter_Mrs(mrs,focus,"_....");break;
		case '7':
			focus = Enter_Mrs(mrs,focus,"__...");break;
		case '8':
			focus = Enter_Mrs(mrs,focus,"___..");break;
		case '9':
			focus = Enter_Mrs(mrs,focus,"____.");break;
		case 0x08:
			focus = Enter_Mrs(mrs,focus,"........");break;
		case 'a':
		case 'A':
			focus = Enter_Mrs(mrs,focus,"._");break;
		case 'b':
		case 'B':
			focus = Enter_Mrs(mrs,focus,"_...");break;
		case 'c':
		case 'C':
			focus = Enter_Mrs(mrs,focus,"_._.");break;
		case 'D':
		case 'd':
			focus = Enter_Mrs(mrs,focus,"_..");break;
		case 'E':
		case 'e':
			focus = Enter_Mrs(mrs,focus,".");break;
		case 'F':
		case 'f':
			focus = Enter_Mrs(mrs,focus,".._.");break;
		case 'G':
		case 'g':
			focus = Enter_Mrs(mrs,focus,"__.");break;
		case 'H':
		case 'h':
			focus = Enter_Mrs(mrs,focus,"....");break;
		case 'I':
		case 'i':
			focus = Enter_Mrs(mrs,focus,"..");break;
		case 'J':
		case 'j':
			focus = Enter_Mrs(mrs,focus,".___");break;
		case 'k':
		case 'K':
			focus = Enter_Mrs(mrs,focus,"_._");break;
		case 'L':
		case 'l':
			focus = Enter_Mrs(mrs,focus,"._..");break;
		case 'M':
		case 'm':
			focus = Enter_Mrs(mrs,focus,"__");break;
		case 'N':
		case 'n':
			focus = Enter_Mrs(mrs,focus,"_.");break;
		case 'O':
		case 'o':
			focus = Enter_Mrs(mrs,focus,"___");break;
		case 'P':
		case 'p':
			focus = Enter_Mrs(mrs,focus,".__.");break;
		case 'Q':
		case 'q':
			focus = Enter_Mrs(mrs,focus,"__._");break;
		case 'R':
		case 'r':
			focus = Enter_Mrs(mrs,focus,"._.");break;
		case 'S':
		case 's':
			focus = Enter_Mrs(mrs,focus,"...");break;
		case 'T':
		case 't':
			focus = Enter_Mrs(mrs,focus,"_");break;
		case 'U':
		case 'u':
			focus = Enter_Mrs(mrs,focus,".._");break;
		case 'V':
		case 'v':
			focus = Enter_Mrs(mrs,focus,"..._");break;
		case 'W':
		case 'w':
			focus = Enter_Mrs(mrs,focus,".__");break;
		case 'X':
		case 'x':
			focus = Enter_Mrs(mrs,focus,"_.._");break;
		case 'Y':
		case 'y':
			focus = Enter_Mrs(mrs,focus,"_.__");break;
		case 'Z':
		case 'z':
			focus = Enter_Mrs(mrs,focus,"__..");break;
		}
	}
	return focus;
}

int main(int argc, char *argv[]) {
	alutInit( &argc, argv );
	char HW[256]="Hello World";
	char MORSE[2048]={0};
	int focusmax=atom(MORSE,HW);
	ALuint buffer, buffer2, source, source2;
	alGenBuffers( 1, &buffer );
	alGenSources( 1, &source );
	alGenBuffers( 1, &buffer2 );
	alGenSources( 1, &source2 );
	buffer = alutCreateBufferWaveform(ALUT_WAVEFORM_SINE,880,0,LNG);
	buffer2 = alutCreateBufferWaveform(ALUT_WAVEFORM_SINE,880,0,LNG*3);
	alSourcei( source, AL_BUFFER, buffer );
	alSourcei( source2, AL_BUFFER, buffer2 );
	for(int focus=0;focus<focusmax;focus++){
		if(MORSE[focus]&1){ 
			if(MORSE[focus]&2){ 
				alSourcePlay( source2 );
			}else{
				alSourcePlay( source );
			}
		}
		alutSleep(LNG);
	}
	alutSleep(LNG*3);
	alutExit(); 
	return 0;
}