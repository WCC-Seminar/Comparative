#define _INOVERWRITABLITY 0

#define OVERWRIGHT_ERROR EEXIST
#define OPEN_ERROR ENOENT
#define SIZE_ERROR EFBIG
#define DATANM 8388608
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


char DATA[DATANM];
int GetFileSize(FILE* _FILEP){
	int _size;
	fseek(_FILEP,0,SEEK_END);
	_size=ftell(_FILEP);
	fseek(_FILEP,0,SEEK_SET);
	return _size;
}


errno_t _mycp(const char* fromfile,const char* tofile){
	FILE *frfp,*tofp;
	int max,times;
#if _INOVERWRITABLITY
	if ((tofp = fopen(tofile, "rb")) != NULL){return OVERWRIGHT_ERROR;}
#endif
	fopen_s(&frfp,fromfile,"rb");
	fopen_s(&tofp,tofile,"wb");
	if(frfp==NULL||tofp==NULL){return OPEN_ERROR;}
	max=GetFileSize(frfp);
	if(max>sizeof(DATA)){return SIZE_ERROR;}
	times=max/sizeof(char);
	times=fread_s(DATA,sizeof(DATA),sizeof(char),times,frfp);
	fwrite(DATA,sizeof(char),times,tofp);
	_fcloseall();
	return EXIT_SUCCESS;
}

errno_t _mycp_only_from(const char* fromfile){
	char tofile[128],tmp[16],ext[16];
	FILE* fp;
	errno_t err;
	strcpy_s(tofile,sizeof(tofile),fromfile);
	char* extp;
	extp=strchr(tofile,'.');
	strcpy_s(ext,sizeof(ext),extp);
	extp[0]='_';extp++;
	int n=0;
	do{
		n++;
		_itoa_s(n,tmp,sizeof(tmp),10);
		strcat_s(tmp,ext);
		strcpy_s(extp,sizeof(tofile)-(extp-tofile),tmp);	

	}while((err=fopen_s(&fp,tofile,"rb"))==0);

	printf("%s\n",tofile);
	return _mycp(fromfile,(const char*)tofile);
}
int main(int argc,char* argv[]){


	if(argv[1]!=NULL){
		if(argc>2&&argv[2]!=NULL){
			_mycp(argv[1],argv[2]);
		}else if(argc>1){
			_mycp_only_from(argv[1]);
		}
	}
	return 0;
}
