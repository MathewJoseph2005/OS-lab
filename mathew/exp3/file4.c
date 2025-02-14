#include <sys/stat.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 void main()
 {
 char *path,path1[10];
 struct stat*nfile;
 nfile=(struct stat*)malloc(sizeof(struct stat));
 printf("Enter the file name:");
 scanf("%s",path1);
 stat(path1,nfile);
 printf( "User id :%d\n",nfile->st_uid);
 printf("Blocksize :%ld\n",nfile->st_blksize);
 printf("Last acess time:%ld\n",nfile->st_atime);
 printf("Last modified time :%ld\n",nfile->st_mtime);
 printf("Size of file:%ld\n",nfile->st_size);
 printf("Number of link :%ld\n",nfile->st_nlink);
 }
