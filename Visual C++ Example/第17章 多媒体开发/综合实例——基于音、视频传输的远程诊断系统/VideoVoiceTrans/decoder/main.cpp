


#include<stdio.h>
#include "tmndec.h"
#include "conio.h"


#define IMAGE_SIZE  76032
#define FILE_SIZE   76086
#define IMAGE_WIDTH  176
#define IMAGE_HEIGHT 144


unsigned char rgbdata[80000];

struct bmpfileheader
{
int fsize;
int reserved;
int offset;
}bfh;

struct bmpinfoheader
{
int bisize;
int biwidth;
int biheight;
short biplanes;
short bibitcount;
int bicompression;
int bisizeimage;
int bixpixelspermeter;
int biypixelspermeter;
int biclrused;
int biclrimp;
}bih;

void main()
{
unsigned char data[5000] ;
int i;
int n,size=2130;
FILE *f,*bmp;
char tstr[]="BM";

	
   InitH263Decoder();
  
   
   //Read from the file
		
   f=fopen("h263","rb");
  
   if(f==NULL)
   {
   printf("error in opening file");
   return;
   }

    n=fread(data,sizeof(char),size,f);
	if(n<size)
	{
	printf("total data read...%d \n terminating...",n);
	return;
	}
  

   
 
  
	for(i=0;i<5;i++)
	{

		printf("\ndecompressing frame...%d",i);
  
		int ret=DecompressFrame(data,size,rgbdata,80000);
		
		if(ret)
			printf("\n success");
		else
		{
			printf("\n failure");
			continue;
		}
  
    

			//Create bitmap file.....
			bmp=fopen("my.bmp","wb");

		  if(bmp==NULL)
		  {
			 printf("unable to create bmp file");
			return;
		  }

		  // Write 2 standard bytes .."BM"
		  fwrite(tstr,1,2,bmp);
		
		  // create and write file header
		  bfh.fsize=FILE_SIZE;
		  bfh.reserved=0;
		  bfh.offset=40+14;

	      fwrite(&bfh,1,sizeof(bfh),bmp);

		  //create and write bmp header
		  bih.bibitcount=24;
		  bih.biclrimp=0;
		  bih.biclrused=0;
		  bih.bicompression=0;
		  bih.biheight=IMAGE_HEIGHT;
		  bih.biplanes=1;  //if does not work change it to 0
		  bih.bisize=40;
		  bih.bisizeimage=0;
		  bih.biwidth=IMAGE_WIDTH;
		  bih.bixpixelspermeter=0;
		  bih.biypixelspermeter=0;

		  fwrite(&bih,1,sizeof(bih),bmp);


		  // now write image data.....
		  fwrite(rgbdata,1,IMAGE_SIZE,bmp);

		  // close the file safely...
		  fclose(bmp);

	}
  
 // Finaly close the decoder safely....
  ExitH263Decoder();
  

  fclose(f);

  
}