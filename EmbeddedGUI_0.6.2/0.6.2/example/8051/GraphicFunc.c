/*
    EmbeddedGUI Library version 0.4.2
    Copyright (C) 2009  eluneyun WangChao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation ,either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
	GraphicFunc.c
*/

#include "GraphicFunc.h"

#ifdef EG_SINGLE_COLOR

#ifdef DOT_MATRIX_LCD
	#include "LCDDriver.h"
#endif  //DOT_MATRIX_LCD

#ifdef WIN32_SIMULATE
	#include "BufferDriver.h"
#endif //WIN32_SIMULATE

void EG_Graphic_DrawHorizonLine(unsigned int x,unsigned int y,unsigned int length){
    unsigned int n=0;
    for(;n<length;n++){
        EG_Graphic_DrawBlackPoint(x+n,y);
    }
}

void EG_Graphic_DrawVerticalLine(unsigned int x,unsigned int y,unsigned int length){
    unsigned int n=0;
    for(;n<length;n++){
        EG_Graphic_DrawBlackPoint(x,y+n);
    }
}

void EG_Graphic_DrawWhiteHorizonLine(unsigned int x,unsigned int y,unsigned int length){
    unsigned int n=0;
    for(;n<length;n++){
        EG_Graphic_DrawWhitePoint(x+n,y);
    }
}

void EG_Graphic_DrawWhiteVerticalLine(unsigned int x,unsigned int y,unsigned int length){
    unsigned int n=0;
    for(;n<length;n++){
        EG_Graphic_DrawWhitePoint(x,y+n);
    }
}

void EG_Graphic_DrawLine(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,unsigned char virtualLine){
	int   dx;						//line x axie delta variable
	int   dy;          			// line y axie delta variable
	char    dx_sym;					// increase direaction of x axie    -1 or 1
	char    dy_sym;					// increase direaction of y axie 
	int   dx_x2;					//dx*2  accelarate variable
	int   dy_x2;					//dy*2  accelarate variable
	int   di;						//decide variable
	int count=0;

	dx = x1-x0;						//delta between two points.
	dy = y1-y0;
	/* whether this is a horizonal or vertical line  */
	if(dx>0){
		dx_sym = 1;					// dx>0 , dx_sym=1
	}else{
		if(dx<0){
			dx_sym = (char)-1;				//  dx<0 , dx_sym=-1
		}else{  // dx==0  vertical line
			EG_Graphic_DrawVerticalLine(x0, y0, y1-y0);
			return;
		}
	}
	if(dy>0){							// direction of y axie
		dy_sym = 1;					//dy>0,dy_sym=1
	}else{
		if(dy<0){ 
			dy_sym = (char)-1;				//dy<0,dy_sym=-1
		}else{  // dy==0, draw horizonal line
			EG_Graphic_DrawHorizonLine(x0, y0, x1-x0);
			return;
		}
	}
	/*   abs( dx and dy )  */
	dx = dx_sym * dx;
	dy = dy_sym * dy;
	dx_x2 = dx*2;
	dy_x2 = dy*2;

	/* using Bresenham to draw straight line  */
	if(dx>=dy){						//dx>=dy  use x axie as direction.
		di = dy_x2 - dx;
		while(x0!=x1){
			if (virtualLine){
				if (count==3){
					count=0;
				}else if(count==2){
					count=3;
				}else{
					count++;
					EG_Graphic_DrawBlackPoint(x0, y0);	
				}
			}else{
				EG_Graphic_DrawBlackPoint(x0, y0);	
			}
			x0 += dx_sym;
			if(di<0){
				di += dy_x2;			//dicision value of the next step
			}else{
				di += dy_x2 - dx_x2;
				y0 += dy_sym;
			}
		}
		EG_Graphic_DrawBlackPoint(x0, y0);	// show the last point
	}else{								//dx<dy  use y axie as direction.
	    di = dx_x2 - dy;
		while(y0!=y1){
			if (virtualLine){
				if (count==3){
					count=0;
				}else if(count==2){
					count=3;
				}else{
					count++;
					EG_Graphic_DrawBlackPoint(x0, y0);	
				}
			}else{
				EG_Graphic_DrawBlackPoint(x0, y0);	
			}
			y0 += dy_sym;
			if(di<0){
				di += dx_x2;
			}else{
				di += dx_x2 - dy_x2;
				x0 += dx_sym;
			}
		}
		EG_Graphic_DrawBlackPoint(x0, y0);	
	} 
}

void EG_Graphic_DrawWidthLine(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,unsigned char lineWidth){
	int   dx;						//delta value of x axie
	int   dy;          			//delta value of y axie
	char    dx_sym;					//increase direction along the x axie
	char    dy_sym;					//increase direction along the y axie
	int   dx_x2;					//equal to 2 * dx
	int   dy_x2;					//equal to 2 * dx
	int   di;						//decide variable
	int   wx, wy;					//line width
	int   draw_a, draw_b;

	//draw nothing, if width==0
	if(lineWidth==0)
	   return;
	//well, don't tell me width>50.....  if so, write a DrawStick function by yourself  :)
	if(lineWidth>50)
		lineWidth = 50;
  
	dx = x1-x0;			
	dy = y1-y0; 
	wx = lineWidth/2;
	wy = lineWidth-wx-1;

   /* set the increase direction along x axie*/
	if(dx>0){
		dx_sym = 1;					// dx>0, set dx_sym=1
	}else{
		if(dx<0){
			dx_sym = -1;				// dx<0, set dx_sym=-1
		}else{     /* dx==0,  it is a vertical line */
			wx = x0-wx;
			if(wx<0)
				wx = 0;
			wy = x0+wy;
			while(1){
				x0 = wx;
				EG_Graphic_DrawVerticalLine(x0, y0,y1-y0);
				if(wx>=wy)
					break;
				wx++;
			}
      		return;
		}
	}
   /* set the increase direction along x axie*/
	if(dy>0){
		dy_sym = 1;					// dy>0, set dy_sym=1
	}else{
		if(dy<0){
			dy_sym = -1;				// dy<0, set dy_sym=-1
		}else{
		/* dy==0  draw a horizonal line*/
			wx = y0-wx;
			if(wx<0)
				wx = 0;
			wy = y0+wy;         
			while(1){
				y0 = wx;
				EG_Graphic_DrawHorizonLine(x0, y0, x1-x0);
				if(wx>=wy)
					break;
				wx++;
			}
      		return;
		}
	}
	/*dx, dy = abs(dx,dy) */
	dx = dx_sym * dx;
	dy = dy_sym * dy;
	dx_x2 = dx*2;
	dy_x2 = dy*2;
   
	if(dx>=dy){
		di = dy_x2 - dx;
		while(x0!=x1){  
			draw_a = y0-wx;
			if(draw_a<0)
				draw_a = 0;
			draw_b = y0+wy;
			EG_Graphic_DrawVerticalLine(x0, draw_a, draw_b-draw_a);
			x0 += dx_sym;				
			if(di<0){
				di += dy_x2;			//get decide value of the next step
			}else{
				di += dy_x2 - dx_x2;
				y0 += dy_sym;
			}
		}
		draw_a = y0-wx;
		if(draw_a<0)
			draw_a = 0;
		draw_b = y0+wy;
		EG_Graphic_DrawVerticalLine(x0,draw_a,draw_b-draw_a);
	}else{
		di = dx_x2 - dy;
		while(y0!=y1){  
			draw_a =x0-wx;
			if(draw_a<0)
				draw_a = 0;
			draw_b = x0+wy;
			EG_Graphic_DrawHorizonLine(draw_a, y0, draw_b-draw_a);         
			y0 += dy_sym;
			if(di<0){
				di += dx_x2;
			}else{
				di += dx_x2 - dy_x2;
				x0 += dx_sym;
			}
		}
		draw_a = x0-wx;
		if(draw_a<0)
			draw_a = 0;
		draw_b = x0+wy;
		EG_Graphic_DrawHorizonLine(draw_a, y0, draw_b-draw_a);
	}
}

void EG_Graphic_DrawEmptyRectangle(unsigned int x,unsigned int y,unsigned int height,unsigned int width){
    unsigned int n;	
    for (n=0;n<width;n++){
		EG_Graphic_DrawVerticalLine(x,y,height);
		EG_Graphic_DrawVerticalLine(x+width,y,height);
		EG_Graphic_DrawHorizonLine(x,y,width);
		EG_Graphic_DrawHorizonLine(x,y+height,width+1);		
	}
}

void EG_Graphic_DrawFilledRectangle(unsigned int x,unsigned int y,unsigned int height,unsigned int width){
    unsigned int n;	
    for (n=0;n<height;n++){
		EG_Graphic_DrawHorizonLine(x,y+n,width);	
	}
}

void EG_Graphic_DrawWhiteFilledRectangle(unsigned int x,unsigned int y,unsigned int height,unsigned int width){
    unsigned int n;	
    for (n=0;n<height;n++){
		EG_Graphic_DrawWhiteHorizonLine(x,y+n,width);	
	}
}

void EG_Graphic_DrawEmptyCircle(unsigned int x0,unsigned int y0,unsigned int r){
	int  draw_x0, draw_y0;			//draw points
	int  draw_x1, draw_y1;	
	int  draw_x2, draw_y5;	
	int  draw_x3, draw_y3;	
	int  draw_x4, draw_y4;	
	int  draw_x6, draw_y6;	
	int  draw_x7, draw_y7;	
	int draw_x5, draw_y2;	
	int  xx, yy;					// circle control variable
	int  di;						// decide variable
	if(0==r)
		return;

	/* calculate 8 special point(0、45、90、135、180、225、270degree) display them */
	draw_x0 = draw_x1 = x0;
	draw_y0 = draw_y1 = y0 + r;
	if(draw_y0<63)
		EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);	// 90degree
	draw_x2 = draw_x3 = x0;
	draw_y2 = draw_y3 = y0 - r;
	if(draw_y2>=0)
		EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);// 270degree
	draw_x4 = draw_x6 = x0 + r;
	draw_y4 = draw_y6 = y0;
	if(draw_x4<127)
		EG_Graphic_DrawBlackPoint(draw_x4, draw_y4);// 0degree
	draw_x5 = draw_x7 = x0 - r;
	draw_y5 = draw_y7 = y0;
	if(draw_x5>=0)
		EG_Graphic_DrawBlackPoint(draw_x5, draw_y5);	// 180degree
	if(1==r)   // if the radius is 1, finished.
		return;					
	/*using Bresenham */
	di = 3 - 2*r;	
	xx = 0;
	yy = r;	
	while(xx<yy){
		if(di<0){
			di += 4*xx + 6;	      
		}else{
			di += 4*(xx - yy) + 10;
			yy--;	  
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;
			draw_x4--;
			draw_x5++;
			draw_x6--;
			draw_x7++;	 	
		}
		xx++;   
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		draw_y4++;
		draw_y5++;
		draw_y6--;
		draw_y7--;
		/*judge current point in the avaible range*/
		if( (draw_x0<=127)&&(draw_y0>=0) ){
			EG_Graphic_DrawBlackPoint(draw_x0, draw_y0);
		}	    
		if( (draw_x1>=0)&&(draw_y1>=0) ){
			EG_Graphic_DrawBlackPoint(draw_x1, draw_y1);
		}
		if( (draw_x2<=127)&&(draw_y2<=63) ){
			EG_Graphic_DrawBlackPoint(draw_x2, draw_y2);
		}
		if( (draw_x3>=0)&&(draw_y3<=63) ){ 
			EG_Graphic_DrawBlackPoint(draw_x3, draw_y3);
		}
		if( (draw_x4<=127)&&(draw_y4>=0) ){
			EG_Graphic_DrawBlackPoint(draw_x4, draw_y4);
		}
		if( (draw_x5>=0)&&(draw_y5>=0) ){
			EG_Graphic_DrawBlackPoint(draw_x5, draw_y5);
		}
		if( (draw_x6<=127)&&(draw_y6<=63) ){
			EG_Graphic_DrawBlackPoint(draw_x6, draw_y6);
		}
		if( (draw_x7>=0)&&(draw_y7<=63) ){ 
			EG_Graphic_DrawBlackPoint(draw_x7, draw_y7);
		}
	}
}

void EG_Graphic_DrawFilledCircle(unsigned int x0,unsigned int y0,unsigned int r){
	int  draw_x0, draw_y0;		
	int  draw_x1, draw_y1;	
	int  draw_x2, draw_y2;	
	int  draw_x3, draw_y3;	
	int  draw_x4, draw_y4;	
	int  draw_x5, draw_y5;	
	int  draw_x6, draw_y6;	
	int  draw_x7, draw_y7;	
	int  fill_x0, fill_y0;		
	int  fill_x1;
	int  xx, yy;				
	int  di;					
	if(0==r) return;
	draw_x0 = draw_x1 = x0;
	draw_y0 = draw_y1 = y0 + r;
	if(draw_y0<EG_ROW){
		EG_Graphic_DrawBlackPoint(draw_x0, draw_y0);	
	}
	draw_x2 = draw_x3 = x0;
	draw_y2 = draw_y3 = y0 - r;
	if(draw_y2>=0){ 
		EG_Graphic_DrawBlackPoint(draw_x2, draw_y2);
	}
	draw_x4 = draw_x6 = x0 + r;
	draw_y4 = draw_y6 = y0;
	if(draw_x4<EG_COLUMN){
		EG_Graphic_DrawBlackPoint(draw_x4, draw_y4);	
		fill_x1 = draw_x4;
	}else{
		fill_x1 = EG_COLUMN;
	}
	fill_y0 = y0;						
	fill_x0 = x0 - r;					
	if(fill_x0<0)
		fill_x0 = 0;
	EG_Graphic_DrawHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	draw_x5 = draw_x7 = x0 - r;
	draw_y5 = draw_y7 = y0;
	if(draw_x5>=0){
		EG_Graphic_DrawBlackPoint(draw_x5, draw_y5);	
	}
	if(1==r)
		return;
	di = 3 - 2*r;						
	xx = 0;
	yy = r;
	while(xx<yy){
		if(di<0){
			di += 4*xx + 6;
		}else{
			di += 4*(xx - yy) + 10;
			yy--;	  
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;
			draw_x4--;
			draw_x5++;
			draw_x6--;
			draw_x7++;		 
		}
		xx++;   
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		draw_y4++;
		draw_y5++;
		draw_y6--;
		draw_y7--;
		if( (draw_x0<=EG_COLUMN)&&(draw_y0>=0) ){
			EG_Graphic_DrawBlackPoint(draw_x0, draw_y0);
		}	    
		if( (draw_x1>=0)&&(draw_y1>=0) ){
			EG_Graphic_DrawBlackPoint(draw_x1, draw_y1);
		}
		if(draw_x1>=0){  
			fill_x0 = draw_x1;
			fill_y0 = draw_y1;
			if(fill_y0>EG_ROW)
				fill_y0 = EG_ROW;
			if(fill_y0<0)
				fill_y0 = 0; 
			fill_x1 = x0*2 - draw_x1;				
			if(fill_x1>EG_COLUMN)
				fill_x1 = EG_COLUMN;
			EG_Graphic_DrawHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
		}
		if( (draw_x2<=EG_COLUMN)
			&&(draw_y2<=EG_ROW) ){
				EG_Graphic_DrawBlackPoint(draw_x2, draw_y2);
		}
		if( (draw_x3>=0)&&(draw_y3<=EG_ROW) ){
				EG_Graphic_DrawBlackPoint(draw_x3, draw_y3);
		}
		if(draw_x3>=0){ 	
			fill_x0 = draw_x3;     
			fill_y0 = draw_y3;
		if(fill_y0>EG_ROW)
			fill_y0 = EG_ROW;
		if(fill_y0<0)
			fill_y0 = 0;
		fill_x1 = x0*2 - draw_x3;		
		if(fill_x1>EG_COLUMN)
			fill_x1 = EG_COLUMN;
		EG_Graphic_DrawHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	}
	if( (draw_x4<=EG_COLUMN)&&(draw_y4>=0) ){
		EG_Graphic_DrawBlackPoint(draw_x4, draw_y4);
	}
	if( (draw_x5>=0)&&(draw_y5>=0) ){
		EG_Graphic_DrawBlackPoint(draw_x5, draw_y5);
	}
	if(draw_x5>=0)	{
		fill_x0 = draw_x5;
		fill_y0 = draw_y5;	
		if(fill_y0>EG_ROW)
			fill_y0 = EG_ROW;
		if(fill_y0<0)
			fill_y0 = 0;							
		fill_x1 = x0*2 - draw_x5;		
		if(fill_x1>EG_COLUMN)
			fill_x1 = EG_COLUMN;
		EG_Graphic_DrawHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	}
	if( (draw_x6<=EG_COLUMN)&&(draw_y6<=EG_ROW) ){
			EG_Graphic_DrawBlackPoint(draw_x6, draw_y6);
	}
	if( (draw_x7>=0)&&(draw_y7<=EG_ROW) ){
		EG_Graphic_DrawBlackPoint(draw_x7, draw_y7);
	}
	if(draw_x7>=0)	{
		fill_x0 = draw_x7;
		fill_y0 = draw_y7;
		if(fill_y0>EG_ROW)
			fill_y0 = EG_ROW;
		if(fill_y0<0)
			fill_y0 = 0;	
		fill_x1 = x0*2 - draw_x7;			
		if(fill_x1>EG_COLUMN)
			fill_x1 = EG_COLUMN;
		EG_Graphic_DrawHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	}
	}
}

void EG_Graphic_DrawWhiteFilledCircle(unsigned int x0,unsigned int y0,unsigned int r){
	int  draw_x0, draw_y0;		
	int  draw_x1, draw_y1;	
	int  draw_x2, draw_y2;	
	int  draw_x3, draw_y3;	
	int  draw_x4, draw_y4;	
	int  draw_x5, draw_y5;	
	int  draw_x6, draw_y6;	
	int  draw_x7, draw_y7;	
	int  fill_x0, fill_y0;		
	int  fill_x1;
	int  xx, yy;				
	int  di;					
	if(0==r) return;
	draw_x0 = draw_x1 = x0;
	draw_y0 = draw_y1 = y0 + r;
	if(draw_y0<EG_ROW){
		EG_Graphic_DrawWhitePoint(draw_x0, draw_y0);	
	}
	draw_x2 = draw_x3 = x0;
	draw_y2 = draw_y3 = y0 - r;
	if(draw_y2>=0){ 
		EG_Graphic_DrawWhitePoint(draw_x2, draw_y2);
	}
	draw_x4 = draw_x6 = x0 + r;
	draw_y4 = draw_y6 = y0;
	if(draw_x4<EG_COLUMN){
		EG_Graphic_DrawWhitePoint(draw_x4, draw_y4);	
		fill_x1 = draw_x4;
	}else{
		fill_x1 = EG_COLUMN;
	}
	fill_y0 = y0;						
	fill_x0 = x0 - r;					
	if(fill_x0<0)
		fill_x0 = 0;
	EG_Graphic_DrawWhiteHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	draw_x5 = draw_x7 = x0 - r;
	draw_y5 = draw_y7 = y0;
	if(draw_x5>=0){
		EG_Graphic_DrawWhitePoint(draw_x5, draw_y5);	
	}
	if(1==r)
		return;
	di = 3 - 2*r;						
	xx = 0;
	yy = r;
	while(xx<yy){
		if(di<0){
			di += 4*xx + 6;
		}else{
			di += 4*(xx - yy) + 10;
			yy--;	  
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;
			draw_x4--;
			draw_x5++;
			draw_x6--;
			draw_x7++;		 
		}
		xx++;   
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		draw_y4++;
		draw_y5++;
		draw_y6--;
		draw_y7--;
		if( (draw_x0<=EG_COLUMN)&&(draw_y0>=0) ){
			EG_Graphic_DrawWhitePoint(draw_x0, draw_y0);
		}	    
		if( (draw_x1>=0)&&(draw_y1>=0) ){
			EG_Graphic_DrawWhitePoint(draw_x1, draw_y1);
		}
		if(draw_x1>=0){  
			fill_x0 = draw_x1;
			fill_y0 = draw_y1;
			if(fill_y0>EG_ROW)
				fill_y0 = EG_ROW;
			if(fill_y0<0)
				fill_y0 = 0; 
			fill_x1 = x0*2 - draw_x1;				
			if(fill_x1>EG_COLUMN)
				fill_x1 = EG_COLUMN;
			EG_Graphic_DrawWhiteHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
		}
		if( (draw_x2<=EG_COLUMN)&&(draw_y2<=EG_ROW) ){
				EG_Graphic_DrawWhitePoint(draw_x2, draw_y2);
		}
		if( (draw_x3>=0)&&(draw_y3<=EG_ROW) ){
				EG_Graphic_DrawWhitePoint(draw_x3, draw_y3);
		}
		if(draw_x3>=0){ 	
			fill_x0 = draw_x3;     
			fill_y0 = draw_y3;
		if(fill_y0>EG_ROW)
			fill_y0 = EG_ROW;
		if(fill_y0<0)
			fill_y0 = 0;
		fill_x1 = x0*2 - draw_x3;		
		if(fill_x1>EG_COLUMN)
			fill_x1 = EG_COLUMN;
		EG_Graphic_DrawWhiteHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	}
	if( (draw_x4<=EG_COLUMN)&&(draw_y4>=0) ){
		EG_Graphic_DrawWhitePoint(draw_x4, draw_y4);
	}
	if( (draw_x5>=0)&&(draw_y5>=0) ){
		EG_Graphic_DrawWhitePoint(draw_x5, draw_y5);
	}
	if(draw_x5>=0)	{
		fill_x0 = draw_x5;
		fill_y0 = draw_y5;	
		if(fill_y0>EG_ROW)
			fill_y0 = EG_ROW;
		if(fill_y0<0)
			fill_y0 = 0;							
		fill_x1 = x0*2 - draw_x5;		
		if(fill_x1>EG_COLUMN)
			fill_x1 = EG_COLUMN;
		EG_Graphic_DrawWhiteHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	}
	if( (draw_x6<=EG_COLUMN)&&(draw_y6<=EG_ROW) ){
			EG_Graphic_DrawWhitePoint(draw_x6, draw_y6);
	}
	if( (draw_x7>=0)&&(draw_y7<=EG_ROW) ){
		EG_Graphic_DrawWhitePoint(draw_x7, draw_y7);
	}
	if(draw_x7>=0)	{
		fill_x0 = draw_x7;
		fill_y0 = draw_y7;
		if(fill_y0>EG_ROW)
			fill_y0 = EG_ROW;
		if(fill_y0<0)
			fill_y0 = 0;	
		fill_x1 = x0*2 - draw_x7;			
		if(fill_x1>EG_COLUMN)
			fill_x1 = EG_COLUMN;
		EG_Graphic_DrawWhiteHorizonLine(fill_x0, fill_y0, fill_x1-fill_x0);
	}
	}
}

void EG_Graphic_DrawQuarterArc(unsigned int x0,unsigned int y0,unsigned int r,unsigned char angle){
	int  draw_x, draw_y;
	int  op_x, op_y;
	int  op_2rr= 2*r*r;

	if(r==0)
		return;
	switch(angle){
		case  1:
			draw_x = x0+r;
			draw_y = y0;
			op_x = r;
			op_y = 0;
			while(1){
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				/*calculate the next point*/
				op_y++;
				draw_y++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x--;
				}
				if(op_y>=op_x)
					break;
			}
            while(1){
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				/*calculate the next point*/
				op_x--;
				draw_x--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y++;
				}
				if(op_x<=0){ 
					EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
					break;
				}
			}
            break;    				
		case  2:
			draw_x = x0-r;
			draw_y = y0;
			op_x = r;
			op_y = 0;
			while(1){		
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				op_y++;
				draw_y++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x++;
				}
				if(op_y>=op_x)
					break;
			}
			while(1){				
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				op_x--;
				draw_x++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y++;
				}
				if(op_x<=0){
					EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
					break;
				}
			}
			break;
		case  3:
			draw_x = x0-r;
			draw_y = y0;
			op_x = r;
			op_y = 0;
			while(1){
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				op_y++;
				draw_y--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x++;
				}
				if(op_y>=op_x)
					break;
			}
			while(1){
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				op_x--;
				draw_x++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y--;
				}
				if(op_x<=0){ 					
					EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
					break;
				}
			}
			break;
		case  4:
			draw_x = x0+r;
			draw_y = y0;
			op_x = r;
			op_y = 0;
			while(1){
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				op_y++;
				draw_y--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x--;
				}
				if(op_y>=op_x)
					break;
			}
			while(1){
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
				op_x--;
				draw_x--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y--;
				}
				if(op_x<=0){
					EG_Graphic_DrawBlackPoint(draw_x, draw_y);				 
					break;
				}
			}
			break;
		default:
			break;
	}
}

void EG_Graphic_DrawArc(unsigned int x0,unsigned int y0,unsigned int r,unsigned int startAngle,unsigned int endAngle){
	int  draw_x, draw_y;					//draw coordinate
	int  op_x, op_y;						//operation coordinate
	int  op_2rr=2*r*r;		
	int  pno_angle= 0;				
	char  draw_on;			//on=1,  draw point

	if(r==0)
		return;					
	if(startAngle==endAngle)  //avoid the same angle,which may cause dead loop
		return;			
	if((startAngle>=360)|| (endAngle>=360))
		return;
	/*arc points of 45 degree*/       
	op_x = r;
	op_y = 0;
	while(1){
		pno_angle++; 							
		/*calculate the next point*/
		op_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
		}
		if(op_y>=op_x) 
			break;
	}
	draw_on = 0;								//do not draw the point at the beginning
	/* set the start point */
	if(endAngle>startAngle)
		draw_on = 1;
	startAngle = (360-startAngle)*pno_angle/45;
	endAngle = (360-endAngle)*pno_angle/45;
	if(startAngle==0)
		startAngle=1;
	if(endAngle==0)
		endAngle=1;

	/*draw the arc,clockwise rotation*/
	pno_angle = 0;
	draw_x = x0+r;
	draw_y = y0;         
	op_x = r;
	op_y = 0;
	while(1){ 
		op_y++;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x--;
		}
		if(draw_on==1) 
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on =1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		} 
		if(op_y>=op_x){
			if(draw_on==1) 
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	while(1){
		op_x--;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y--;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){			//toggle the draw_on,if it is the start or end angle
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		} 
		if(op_x<=0){
			if(draw_on==1) 
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	/*draw clockwise, from 269 degree*/
	draw_y = y0-r;
	draw_x = x0;         
	op_y = r;
	op_x = 0;
	while(1){
		op_x++;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if( (pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		}
		if(op_x>=op_y){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		break;
		}
	}
	while(1){
		op_y--;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x--;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		}
		if(op_y<=0){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	/*draw clockwise, from 179 degree*/
	draw_x = x0-r;
	draw_y = y0;         
	op_x = r;
	op_y = 0;
	while(1){
		op_y++;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		} 
		if(op_y>=op_x){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	while(1){
		op_x--;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		}
		if(op_x<=0){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	/*draw clockwise, from 89 degree*/
	draw_y = y0+r;
	draw_x = x0;         
	op_y = r;
	op_x = 0;
	while(1){
		op_x++;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y--;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		}
		if(op_x>=op_y){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	while(1){
		op_y--;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		} 
		if(op_y<=0){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
}

void EG_Graphic_DrawPieSlice(unsigned int x0,unsigned int y0,unsigned int r,unsigned int startAngle,unsigned int endAngle){
	int  draw_x, draw_y;				//draw coordinate		
	int  op_x, op_y;					//operation coordinate
	int  op_2rr=2*r*r;					
	int  pno_angle= 0;					
	unsigned char  draw_on;					//on=1,  draw point

	if(r==0)
		return;						
	if(startAngle==endAngle) //avoid the same angle,which may cause dead loop
		return;			
	if((startAngle>=360) || (endAngle>=360))
		return;
	/*arc points of 45 degree*/       
	op_x = r;
	op_y = 0;
	while(1){
		pno_angle++; 							
		/*calculate the next point*/
		op_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
		}
		if(op_y>=op_x) 
			break;
	}
	draw_on = 0;								//do not draw the point at the beginning
	/* set the start point */
	if(endAngle>startAngle)
		draw_on = 1;
	startAngle = (360-startAngle)*pno_angle/45;
	endAngle = (360-endAngle)*pno_angle/45;
	if(startAngle==0)
		startAngle=1;
	if(endAngle==0)
		endAngle=1;
   
	/*draw the arc,clockwise rotation*/
	pno_angle = 0;
	draw_x = x0+r;
	draw_y = y0;         
	op_x = r;
	op_y = 0;
	while(1){ 
		op_y++;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x--;
		}
		if(draw_on==1) 
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on =1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		} 
		if(op_y>=op_x){
			if(draw_on==1) 
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}   
	while(1){
		op_x--;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y--;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){			//toggle the draw_on,if it is the start or end angle
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		} 
		if(op_x<=0){
			if(draw_on==1) 
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	/*draw clockwise, from 269 degree*/
	draw_y = y0-r;
	draw_x = x0;         
	op_y = r;
	op_x = 0;
	while(1){
		op_x++;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if( (pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		}
		if(op_x>=op_y){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		break;
		}
	}
	while(1){
		op_y--;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x--;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		}
		if(op_y<=0){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	/*draw clockwise, from 179 degree*/
	draw_x = x0-r;
	draw_y = y0;         
	op_x = r;
	op_y = 0;
	while(1){
		op_y++;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		}
		if(op_y>=op_x){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	while(1){
		op_x--;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		}
		if(op_x<=0){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	/*draw clockwise, from 89 degree*/
	draw_y = y0+r;
	draw_x = x0;         
	op_y = r;
	op_x = 0;
	while(1){
		op_x++;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y--;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		}
		if(op_x>=op_y){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
	while(1){
		op_y--;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x++;
		}
		if(draw_on==1)
			EG_Graphic_DrawBlackPoint(draw_x, draw_y);
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			EG_Graphic_DrawLine(x0,y0,draw_x,draw_y,0);
		} 
		if(op_y<=0){
			if(draw_on==1)
				EG_Graphic_DrawBlackPoint(draw_x, draw_y);
			break;
		}
	}
}

void EG_Graphic_DrawEmptyEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY){
	int  draw_x0, draw_y0;		
	int  draw_x1, draw_y1;
	int  draw_x2, draw_y2;
	int  draw_x3, draw_y3;
	int  xx, yy;				// draw control variable 
	int  center_x, center_y;		//center of ellipse
	int  radius_x, radius_y;		// radius along x and y axies
	int  radius_xx, radius_yy;		
	int  radius_xx2, radius_yy2;
	int  di;						//decide variable
	
	if((leftX==rightX)||(topY==bottomY))
		return;
	/*calculate the center of ellipse*/
	center_x = (leftX + rightX) >> 1;			
	center_y = (topY + bottomY) >> 1;
	if(leftX > rightX){
		radius_x = (leftX - rightX) >> 1;
	}else{
		radius_x = (rightX - leftX) >> 1;
	}
	if(topY > bottomY){
		radius_y = (topY - bottomY) >> 1;
	}else{
		radius_y = (bottomY - topY) >> 1;
	}
	radius_xx = radius_x * radius_x;
	radius_yy = radius_y * radius_y;
	radius_xx2 = radius_xx<<1;
	radius_yy2 = radius_yy<<1;
	xx = 0;
	yy = radius_y;
	di = radius_yy2 + radius_xx - radius_xx2*radius_y ;

	/*calculate the end point of ellipse to start drawing*/
	draw_x0 = draw_x1 = draw_x2 = draw_x3 = center_x;
	draw_y0 = draw_y1 = center_y + radius_y;
	draw_y2 = draw_y3 = center_y - radius_y;

	//end point on y axie
	EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);
	EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);
	
	while((radius_yy*xx)<(radius_xx*yy)){
		if(di<0){
			di+= radius_yy2*(2*xx+3);
		}else{
			di += radius_yy2*(2*xx+3) + 4*radius_xx - 4*radius_xx*yy;
			yy--;
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;				 
		}
		xx ++;						// x axie ++
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);
		EG_Graphic_DrawBlackPoint(draw_x1,draw_y1);
		EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);
		EG_Graphic_DrawBlackPoint(draw_x3,draw_y3);
	}
	di = radius_xx2*(yy-1)*(yy-1) + radius_yy2*xx*xx + radius_yy + radius_yy2*xx - radius_xx2*radius_yy;
	while(yy>=0){
		if(di<0){
			di+= radius_xx2*3 + 4*radius_yy*xx + 4*radius_yy - 2*radius_xx2*yy;
			xx ++;							
			draw_x0++;
			draw_x1--;
			draw_x2++;
			draw_x3--;  
		}else{
			di += radius_xx2*3 - 2*radius_xx2*yy;	 	 		     			 
		}
		yy--;
		draw_y0--;
		draw_y1--;
		draw_y2++;
		draw_y3++;	
		EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);
		EG_Graphic_DrawBlackPoint(draw_x1,draw_y1);
		EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);
		EG_Graphic_DrawBlackPoint(draw_x3,draw_y3);
	}
}

void EG_Graphic_DrawFilledEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY){
	int  draw_x0, draw_y0;		
	int  draw_x1, draw_y1;
	int  draw_x2, draw_y2;
	int  draw_x3, draw_y3;
	int  xx, yy;				// draw control variable 
	int  center_x, center_y;		//center of ellipse
	int  radius_x, radius_y;		// radius along x and y axies
	int  radius_xx, radius_yy;		
	int  radius_xx2, radius_yy2;
	int  di;						//decide variable
	
	if((leftX==rightX)||(topY==bottomY))
		return;
	/*calculate the center of ellipse*/
	center_x = (leftX + rightX) >> 1;			
	center_y = (topY + bottomY) >> 1;
	if(leftX > rightX){
		radius_x = (leftX - rightX) >> 1;
	}else{
		radius_x = (rightX - leftX) >> 1;
	}
	if(topY > bottomY){
		radius_y = (topY - bottomY) >> 1;
	}else{
		radius_y = (bottomY - topY) >> 1;
	}
	radius_xx = radius_x * radius_x;
	radius_yy = radius_y * radius_y;
	radius_xx2 = radius_xx<<1;
	radius_yy2 = radius_yy<<1;
	xx = 0;
	yy = radius_y;
	di = radius_yy2 + radius_xx - radius_xx2*radius_y ;

	/*calculate the end point of ellipse to start drawing*/
	draw_x0 = draw_x1 = draw_x2 = draw_x3 = center_x;
	draw_y0 = draw_y1 = center_y + radius_y;
	draw_y2 = draw_y3 = center_y - radius_y;

	//end point on y axie
	EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);
	EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);

	while((radius_yy*xx)<(radius_xx*yy)){
		if(di<0){
			di+= radius_yy2*(2*xx+3);
		}else{
			di += radius_yy2*(2*xx+3) + 4*radius_xx - 4*radius_xx*yy;
			yy--;
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;				 
		}
		xx ++;						// x axie ++
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);
		EG_Graphic_DrawBlackPoint(draw_x1,draw_y1);
		EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);
		EG_Graphic_DrawBlackPoint(draw_x3,draw_y3);
		if(di>=0){
			if(draw_x1>draw_x0)
				EG_Graphic_DrawHorizonLine(draw_x0, draw_y0, draw_x1-draw_x0);
			else
				EG_Graphic_DrawHorizonLine(draw_x1, draw_y1, draw_x0-draw_x1);
			if(draw_x3>draw_x2)
				EG_Graphic_DrawHorizonLine(draw_x2, draw_y2, draw_x3-draw_x2);
			else
				EG_Graphic_DrawHorizonLine(draw_x3, draw_y3, draw_x2-draw_x3);
		}
	}
	di = radius_xx2*(yy-1)*(yy-1) + radius_yy2*xx*xx + radius_yy + radius_yy2*xx - radius_xx2*radius_yy;
	while(yy>=0){
		if(di<0){
			di+= radius_xx2*3 + 4*radius_yy*xx + 4*radius_yy - 2*radius_xx2*yy;
			xx ++;							
			draw_x0++;
			draw_x1--;
			draw_x2++;
			draw_x3--;  
		}else{
			di += radius_xx2*3 - 2*radius_xx2*yy;	 	 		     			 
		}
		yy--;
		draw_y0--;
		draw_y1--;
		draw_y2++;
		draw_y3++;	
		EG_Graphic_DrawBlackPoint(draw_x0,draw_y0);
		EG_Graphic_DrawBlackPoint(draw_x1,draw_y1);
		EG_Graphic_DrawBlackPoint(draw_x2,draw_y2);
		EG_Graphic_DrawBlackPoint(draw_x3,draw_y3);
		//fill it ,since y axie has already changed
		if(draw_x1>draw_x0)
			EG_Graphic_DrawHorizonLine(draw_x0, draw_y0, draw_x1-draw_x0);
		else
			EG_Graphic_DrawHorizonLine(draw_x1, draw_y1, draw_x0-draw_x1);
		if(draw_x3>draw_x2)
			EG_Graphic_DrawHorizonLine(draw_x2, draw_y2, draw_x3-draw_x2);
		else
			EG_Graphic_DrawHorizonLine(draw_x3, draw_y3, draw_x2-draw_x3);
	}
}

void EG_Graphic_DrawChar(unsigned int x,unsigned int y,char val){
    char tmp;
    int index;
    tmp=val&0xF0;
    tmp=tmp>>4;
    index=(tmp-2)*16;
    index+=val&0x0F;
    for(tmp=0;tmp<8;tmp++){
        EG_LCDSetByte(y+tmp,x,EG_SmallFont[index][tmp]);
    }
}

void EG_Graphic_DrawNotChar(unsigned int x,unsigned int y,char val){
    char tmp;
    int index;
    tmp=val&0xF0;
    tmp=tmp>>4;
    index=(tmp-2)*16;
    index+=val&0x0F;
    for(tmp=0;tmp<8;tmp++){
        EG_LCDSetByte(y+tmp,x,~EG_SmallFont[index][tmp]);
    }
}

void EG_Graphic_DrawString(unsigned int x,unsigned int y,char* string){
    unsigned int n=0;
    while(string[n]!='\0'){
        EG_Graphic_DrawChar(x,y,string[n]);
        x=x+8;
        n++;
    }
}

void EG_Graphic_DrawNotString(unsigned int x,unsigned int y,char* string){
    unsigned int n=0;
    while(string[n]!='\0'){
        EG_Graphic_DrawNotChar(x,y,string[n]);
        x=x+8;
        n++;
    }
}

void EG_Graphic_DrawConstString(unsigned int x,unsigned int y,char* string,unsigned char size){
    unsigned char n=0;
    for(;n<size;n++){
        EG_Graphic_DrawChar(x,y,string[n]);
        x=x+8;
    }
}

#ifndef EG_NO_BITMAP
void EG_Graphic_DrawBitmap(unsigned int x,unsigned int y,EBitmap* pBitmap){
	unsigned char mask;
	unsigned char count;
	unsigned char* tempp=pBitmap->m_pImageBuffer;
	if(tempp==NULL)
		return;	
	for(unsigned int m=0;m<pBitmap->m_uHeight;m++){
		for(unsigned int n=0;n<pBitmap->m_uWidth;n++){
			mask=0x80;
			for(count=0;count<8;count++){
				if(*tempp&mask){
					EG_Graphic_DrawBlackPoint(x+n,y+(m<<3)+count);
				}else{
					EG_Graphic_DrawWhitePoint(x+n,y+(m<<3)+count);
				}		
				mask=mask>>1;
			}	
			tempp++;
		}
	}		
}
#endif //EG_NO_BITMAP

#ifndef EG_NO_FONT
void EG_Graphic_DrawFontChar(unsigned int x,unsigned int y,char val,const EFont& font){
    unsigned int temp1,temp2,tmp,n,index;
	tmp=val&0xF0;
	tmp=tmp>>4;
	index=(tmp-2)*16;
	index+=val&0x0F;
    for(temp1=0;temp1<EG_FontHeight[font.m_cFontNumber];temp1++){
		for(temp2=0;temp2<EG_FontWidth[font.m_cFontNumber];temp2++){
			tmp=0x01;
			tmp=tmp<<temp2;
			if(font.m_cFontNumber==0){
				n=EG_SmallFont[index][temp1];
			}else if(font.m_cFontNumber==1){
				n=EG_NormalFont[index][temp1];
			}else if(font.m_cFontNumber==2){
				n=EG_NormalCambriaFont[index][temp1];
			}else if(font.m_cFontNumber==3){
				n=EG_NormalBoldCambriaFont[index][temp1];
			}else{
				n=EG_NormalBoldFont[index][temp1];
			}
			if(n&tmp){
				if(font.m_cFontSize==1){
					EG_LCDSetPixel(y+temp1,x+EG_FontWidth[font.m_cFontNumber]-1-temp2);
				}else if (font.m_cFontSize==2){
					EG_LCDSetPixel(y+(temp1<<1),x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1);		
					EG_LCDSetPixel(y+(temp1<<1)+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1));		
					EG_LCDSetPixel(y+(temp1<<1)+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1);		
					EG_LCDSetPixel(y+(temp1<<1),x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1));		
				}else{
					EG_LCDSetPixel(y+temp1*3,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1);
					EG_LCDSetPixel(y+temp1*3,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3));
					EG_LCDSetPixel(y+temp1*3,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1);		
					EG_LCDSetPixel(y+temp1*3+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1);
					EG_LCDSetPixel(y+temp1*3+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3));
					EG_LCDSetPixel(y+temp1*3+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1);		
					EG_LCDSetPixel(y+temp1*3+2,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1);
					EG_LCDSetPixel(y+temp1*3+2,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3));
					EG_LCDSetPixel(y+temp1*3+2,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1);		
				}
			}
		}
    }
}

void EG_Graphic_DrawNotFontChar(unsigned int x,unsigned int y,char val,const EFont& font){
    unsigned int temp1,temp2,tmp,n,index;
	tmp=val&0xF0;
	tmp=tmp>>4;
	index=(tmp-2)*16;
	index+=val&0x0F;
    for(temp1=0;temp1<EG_FontHeight[font.m_cFontNumber];temp1++){
		for(temp2=0;temp2<EG_FontWidth[font.m_cFontNumber];temp2++){
			tmp=0x01;
			tmp=tmp<<temp2;
			if(font.m_cFontNumber==0){
				n=EG_SmallFont[index][temp1];
			}else if(font.m_cFontNumber==1){
				n=EG_NormalFont[index][temp1];
			}else if(font.m_cFontNumber==2){
				n=EG_NormalCambriaFont[index][temp1];
			}else if(font.m_cFontNumber==3){
				n=EG_NormalBoldCambriaFont[index][temp1];
			}else{
				n=EG_NormalBoldFont[index][temp1];
			}
			if(!(n&tmp)){
				if(font.m_cFontSize==1){
					EG_LCDSetPixel(y+temp1,x+EG_FontWidth[font.m_cFontNumber]-1-temp2);
				}else if (font.m_cFontSize==2){
					EG_LCDSetPixel(y+(temp1<<1),x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1);		
					EG_LCDSetPixel(y+(temp1<<1)+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1));		
					EG_LCDSetPixel(y+(temp1<<1)+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1);		
					EG_LCDSetPixel(y+(temp1<<1),x+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1));		
				}else{
					EG_LCDSetPixel(y+temp1*3,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1);
					EG_LCDSetPixel(y+temp1*3,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3));
					EG_LCDSetPixel(y+temp1*3,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1);		
					EG_LCDSetPixel(y+temp1*3+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1);
					EG_LCDSetPixel(y+temp1*3+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3));
					EG_LCDSetPixel(y+temp1*3+1,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1);		
					EG_LCDSetPixel(y+temp1*3+2,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1);
					EG_LCDSetPixel(y+temp1*3+2,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3));
					EG_LCDSetPixel(y+temp1*3+2,x+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1);		
				}
			}
		}
    }
}

void EG_Graphic_DrawFontString(unsigned int x,unsigned int y,char* string,const EFont& font){
    unsigned int n=0;
    while(string[n]!='\0'){
        EG_Graphic_DrawFontChar(x,y,string[n],font);
        x=x+EG_FontWidth[font.m_cFontNumber]*font.m_cFontSize;
        n++;
    }
}

void EG_Graphic_DrawConstFontString(unsigned int x,unsigned int y,char* string,unsigned char size,const EFont& font){
    unsigned char n=0;
    for(;n<size;n++){
        EG_Graphic_DrawFontChar(x,y,string[n],font);
        x=x+EG_FontWidth[font.m_cFontNumber]*font.m_cFontSize;
    }
}

void EG_Graphic_DrawNotFontString(unsigned int x,unsigned int y,char* string,const EFont& font){
    unsigned int n=0;
    while(string[n]!='\0'){
        EG_Graphic_DrawNotFontChar(x,y,string[n],font);
        x=x+EG_FontWidth[font.m_cFontNumber]*font.m_cFontSize;
        n++;
    }
}
#endif //EG_NO_FONT

#else  //EG_RGB_COLOR

void EG_Graphic_DrawPoint(const EPosition& pos,const EColor& color){
	EG_Sim_Buffer[pos.m_uY][pos.m_uX]=color;
}

void EG_Graphic_DrawHorizonLine(const EPosition& pos,unsigned int length,const EColor& color){
    unsigned int n=0;
    for(;n<length;n++){
		EG_Sim_Buffer[pos.m_uY][pos.m_uX+n]=color;
    }
}

void EG_Graphic_DrawVerticalLine(const EPosition& pos,unsigned int length,const EColor& color){
    unsigned int n=0;
    for(;n<length;n++){
		EG_Sim_Buffer[pos.m_uY+n][pos.m_uX]=color;
    }
}

void EG_Graphic_DrawLine(const EPosition& pos0,const EPosition& pos1,const EColor& color,bool virtualLine){
	int   dx;						// line x axie delta variable
	int   dy;          			// line y axie delta variable
	char    dx_sym;					// increase direaction of x axie    -1 or 1
	char    dy_sym;					// increase direaction of y axie 
	int   dx_x2;					// dx*2  accelarate variable
	int   dy_x2;					// dy*2  accelarate variable
	int   di;						//  decide variable
	int count=0;

	dx = pos1.m_uX-pos0.m_uX;						// delta between two points.
	dy = pos1.m_uY-pos0.m_uY;
	/* whether this is a horizonal or vertical line */
	if(dx>0){
		dx_sym = 1;					// dx>0 , dx_sym=1
	}else{
		if(dx<0){
			dx_sym = -1;				// dx<0 , dx_sym=-1
		}else{  // dx==0 vertical line
			EG_Graphic_DrawVerticalLine(pos0,pos1.m_uY-pos0.m_uY,color);
			return;
		}
	}
	if(dy>0){							// direction of y axie
		dy_sym = 1;					//dy>0,dy_sym=1
	}else{
		if(dy<0){ 
			dy_sym = -1;				//dy<0,dy_sym=-1
		}else{  // dy==0, draw horizonal line
			EG_Graphic_DrawHorizonLine(pos0,pos1.m_uX-pos0.m_uX,color);
			return;
		}
	}
	/*  abs( dx and dy )  */
	dx = dx_sym * dx;
	dy = dy_sym * dy;
	dx_x2 = dx*2;
	dy_x2 = dy*2;

	EPosition pos;
	pos=pos0;
	/* using Bresenham to draw straight line */
	if(dx>=dy){						//dx>=dy  use x axie as direction.
		di = dy_x2 - dx;
		while(pos.m_uX!=pos1.m_uX){
			if (virtualLine){
				if (count==3){
					count=0;
				}else if(count==2){
					count=3;
				}else{
					count++;
					EG_Graphic_DrawPoint(pos, color);	
				}
			}else{
				EG_Graphic_DrawPoint(pos, color);	
			}
			pos.m_uX += dx_sym;
			if(di<0){
				di += dy_x2;			// dicision value of the next step
			}else{
				di += dy_x2 - dx_x2;
				pos.m_uY += dy_sym;
			}
		}
		EG_Graphic_DrawPoint(pos, color);// show the last point
	}else{								//dx<dy  use y axie as direction.
	    di = dx_x2 - dy;
		while(pos.m_uY!=pos1.m_uY){
			if (virtualLine){
				if (count==3){
					count=0;
				}else if(count==2){
					count=3;
				}else{
					count++;
					EG_Graphic_DrawPoint(pos, color);	
				}
			}else{
				EG_Graphic_DrawPoint(pos, color);	
			}
			pos.m_uY += dy_sym;
			if(di<0){
				di += dx_x2;
			}else{
				di += dx_x2 - dy_x2;
				pos.m_uX += dx_sym;
			}
		}
		EG_Graphic_DrawPoint(pos, color);		// show the last point
	} 
}

void EG_Graphic_DrawWidthLine(const EPosition& pos0,const EPosition& pos1,const EColor& color,unsigned char lineWidth){
	int   dx;						//delta value of x axie
	int   dy;          			//delta value of y axie
	char    dx_sym;					//increase direction along the x axie
	char    dy_sym;					//increase direction along the y axie
	int   dx_x2;					//equal to 2 * dx
	int   dy_x2;					//equal to 2 * dx
	int   di;						//decide variable
	int   wx, wy;					//line width
	int   draw_a, draw_b;
	EPosition pos,posA,posB;
	posA=pos0;
	posB=pos1;

	//draw nothing, if width==0
	if(lineWidth==0)
	   return;
	//well, don't tell me width>50.....  if so, write a DrawStick function by yourself  :)
	if(lineWidth>50)
		lineWidth = 50;
  
	dx = posB.m_uX-posA.m_uX;			
	dy = posB.m_uY-posA.m_uY; 
	wx = lineWidth/2;
	wy = lineWidth-wx-1;

   /* set the increase direction along x axie*/
	if(dx>0){
		dx_sym = 1;					// dx>0, set dx_sym=1
	}else{
		if(dx<0){
			dx_sym = -1;				// dx<0, set dx_sym=-1
		}else{     /* dx==0,  it is a vertical line */
			wx = posA.m_uX-wx;
			if(wx<0)
				wx = 0;
			wy = posA.m_uX+wy;
			while(1){
				posA.m_uX = wx;
				EG_Graphic_DrawVerticalLine(posA,posB.m_uY-posA.m_uY,color);
				if(wx>=wy)
					break;
				wx++;
			}
      		return;
		}
	}
   /* set the increase direction along x axie*/
	if(dy>0){
		dy_sym = 1;					// dy>0, set dy_sym=1
	}else{
		if(dy<0){
			dy_sym = -1;				// dy<0, set dy_sym=-1
		}else{
		/* dy==0  draw a horizonal line*/
			wx = posA.m_uY-wx;
			if(wx<0)
				wx = 0;
			wy = posA.m_uY+wy;         
			while(1){
				posA.m_uY = wx;
				EG_Graphic_DrawHorizonLine(posA,posB.m_uX-posA.m_uX,color);
				if(wx>=wy)
					break;
				wx++;
			}
      		return;
		}
	}
	/*dx, dy = abs(dx,dy) */
	dx = dx_sym * dx;
	dy = dy_sym * dy;
	dx_x2 = dx*2;
	dy_x2 = dy*2;
   
	if(dx>=dy){
		di = dy_x2 - dx;
		while(posA.m_uX!=posB.m_uX){  
			draw_a = posA.m_uY-wx;
			if(draw_a<0)
				draw_a = 0;
			draw_b = posA.m_uY+wy;
			pos.m_uX=posA.m_uX;
			pos.m_uY=draw_a;
			EG_Graphic_DrawVerticalLine(pos,draw_b-draw_a,color);
			posA.m_uX += dx_sym;				
			if(di<0){
				di += dy_x2;			//get decide value of the next step
			}else{
				di += dy_x2 - dx_x2;
				posA.m_uY += dy_sym;
			}
		}
		draw_a = posA.m_uY-wx;
		if(draw_a<0)
			draw_a = 0;
		draw_b = posA.m_uY+wy;
		pos.m_uX=posA.m_uX;
		pos.m_uY=draw_a;
		EG_Graphic_DrawVerticalLine(pos,draw_b-draw_a,color);
	}else{
		di = dx_x2 - dy;
		while(posA.m_uY!=posB.m_uY){  
			draw_a =posA.m_uX-wx;
			if(draw_a<0)
				draw_a = 0;
			draw_b = posA.m_uX+wy;
			pos.m_uX=draw_a;
			pos.m_uY=posA.m_uY;
			EG_Graphic_DrawHorizonLine(pos,draw_b-draw_a,color);
			posA.m_uY += dy_sym;
			if(di<0){
				di += dx_x2;
			}else{
				di += dx_x2 - dy_x2;
				posA.m_uX += dx_sym;
			}
		}
		draw_a = posA.m_uX-wx;
		if(draw_a<0)
			draw_a = 0;
		draw_b = posA.m_uX+wy;
		pos.m_uX=draw_a;
		pos.m_uY=posA.m_uY;
		EG_Graphic_DrawHorizonLine(pos,draw_b-draw_a,color);
	}
}

void EG_Graphic_DrawEmptyRectangle(const EPosition& pos,const ESize& size,const EColor& color){
    unsigned int n;	
	EPosition pos1,pos2;
	pos1.m_uX=pos.m_uX+size.m_uWidth;
	pos1.m_uY=pos.m_uY;
	pos2.m_uX=pos.m_uX;
	pos2.m_uY=pos.m_uY+size.m_uHeight;
	for (n=0;n<size.m_uWidth;n++){
		EG_Graphic_DrawVerticalLine(pos,size.m_uHeight,color);
		EG_Graphic_DrawVerticalLine(pos1,size.m_uHeight,color);
		EG_Graphic_DrawHorizonLine(pos,size.m_uWidth,color);
		EG_Graphic_DrawHorizonLine(pos2,size.m_uWidth+1,color);		
	}
}

void EG_Graphic_DrawFilledRectangle(const EPosition& pos,const ESize& size,const EColor& color){
    unsigned int n;	
	EPosition pos1;
	pos1.m_uX=pos.m_uX;
	for (n=0;n<size.m_uHeight;n++){
		pos1.m_uY=pos.m_uY+n;
		EG_Graphic_DrawHorizonLine(pos1,size.m_uWidth,color);	
	}
}

void EG_Graphic_DrawEmptyCircle(const EPosition& center,unsigned int radius,const EColor& color){
	int  draw_x0, draw_y0;			//draw points
	int  draw_x1, draw_y1;	
	int  draw_x2, draw_y5;	
	int  draw_x3, draw_y3;	
	int  draw_x4, draw_y4;	
	int  draw_x6, draw_y6;	
	int  draw_x7, draw_y7;	
	int draw_x5, draw_y2;	
	int  xx, yy;					// circle control variable
	int  di;						// decide variable
	if(0==radius)
		return;

	/* calculate 8 special point(0、45、90、135、180、225、270degree) display them */
	draw_x0 = draw_x1 = center.m_uX;
	draw_y0 = draw_y1 = center.m_uY + radius;
	if(draw_y0<EG_ROW)
		EG_Sim_Buffer[draw_y0][draw_x0]=color;// 90degree
	draw_x2 = draw_x3 = center.m_uX;
	draw_y2 = draw_y3 = center.m_uY - radius;
	if(draw_y2>=0)
		EG_Sim_Buffer[draw_y2][draw_x2]=color;// 270degree
	draw_x4 = draw_x6 = center.m_uX + radius;
	draw_y4 = draw_y6 = center.m_uY;
	if(draw_x4<EG_COLUMN)
		EG_Sim_Buffer[draw_y4][draw_x4]=color;// 0degree
	draw_x5 = draw_x7 = center.m_uX - radius;
	draw_y5 = draw_y7 = center.m_uY;
	if(draw_x5>=0)
		EG_Sim_Buffer[draw_y5][draw_x5]=color;// 180degree
	if(1==radius)   // if the radius is 1, finished.
		return;					
	/*using Bresenham */
	di = 3 - 2*radius;	
	xx = 0;
	yy = radius;	
	while(xx<yy){
		if(di<0){
			di += 4*xx + 6;	      
		}else{
			di += 4*(xx - yy) + 10;
			yy--;	  
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;
			draw_x4--;
			draw_x5++;
			draw_x6--;
			draw_x7++;	 	
		}
		xx++;   
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		draw_y4++;
		draw_y5++;
		draw_y6--;
		draw_y7--;
		/*judge current point in the avaible range*/
		if( (draw_x0<=EG_COLUMN)&&(draw_y0>=0) ){
			EG_Sim_Buffer[draw_y0][draw_x0]=color;
		}	    
		if( (draw_x1>=0)&&(draw_y1>=0) ){
			EG_Sim_Buffer[draw_y1][draw_x1]=color;
		}
		if( (draw_x2<=EG_COLUMN)&&(draw_y2<=EG_ROW) ){
			EG_Sim_Buffer[draw_y2][draw_x2]=color;
		}
		if( (draw_x3>=0)&&(draw_y3<=EG_ROW) ){ 
			EG_Sim_Buffer[draw_y3][draw_x3]=color;
		}
		if( (draw_x4<=EG_COLUMN)&&(draw_y4>=0) ){
			EG_Sim_Buffer[draw_y4][draw_x4]=color;
		}
		if( (draw_x5>=0)&&(draw_y5>=0) ){
			EG_Sim_Buffer[draw_y5][draw_x5]=color;
		}
		if( (draw_x6<=EG_COLUMN)&&(draw_y6<=EG_ROW) ){
			EG_Sim_Buffer[draw_y6][draw_x6]=color;
		}
		if( (draw_x7>=0)&&(draw_y7<=EG_ROW) ){
			EG_Sim_Buffer[draw_y7][draw_x7]=color;
		}
	}
}

void EG_Graphic_DrawFilledCircle(const EPosition& center,unsigned int radius,const EColor& color){
	int  draw_x0, draw_y0;			//draw points
	int  draw_x1, draw_y1;	
	int  draw_x2, draw_y2;	
	int  draw_x3, draw_y3;	
	int  draw_x4, draw_y4;	
	int  draw_x5, draw_y5;	
	int  draw_x6, draw_y6;	
	int  draw_x7, draw_y7;	
	int  fill_x0, fill_y0;			// variable used to fill the circle
	int  fill_x1;
	int  xx, yy;					//circle control variable
	int  di;						// decide variable
	EPosition pos;
	if(0==radius)
		return;
	/* calculate 4 special point(0、90、180、270degree) display them */
	draw_x0 = draw_x1 =center.m_uX;
	draw_y0 = draw_y1 = center.m_uY + radius;
	if(draw_y0<EG_ROW){
		EG_Sim_Buffer[draw_y0][draw_x0]=color;// 90degree
	}
	draw_x2 = draw_x3 = center.m_uX;
	draw_y2 = draw_y3 = center.m_uY - radius;
	if(draw_y2>=0){ 
		EG_Sim_Buffer[draw_y2][draw_x2]=color;// 270degree
	}
	draw_x4 = draw_x6 = center.m_uX + radius;
	draw_y4 = draw_y6 = center.m_uY;
	if(draw_x4<EG_COLUMN){
		EG_Sim_Buffer[draw_y4][draw_x4]=color;// 0degree
		fill_x1 = draw_x4;
	}else{
		fill_x1 = EG_COLUMN;
	}
	fill_y0 = center.m_uY;			// set the fill line start point fill_y0
	fill_x0 = center.m_uX - radius;						// set the fill line start point fill_x0
	if(fill_x0<0)
		fill_x0 = 0;
	pos.m_uX=fill_x0;
	pos.m_uY=fill_y0;
	EG_Graphic_DrawHorizonLine(pos, fill_x1-fill_x0, color);
	draw_x5 = draw_x7 = center.m_uX - radius;
	draw_y5 = draw_y7 = center.m_uY;
	if(draw_x5>=0){
		EG_Sim_Buffer[draw_y5][draw_x5]=color;// 180degree
	}
	if(1==radius) // if the radius is 1, finished.
		return;
	/*using Bresenham */
	di = 3 - 2*radius;		
	xx = 0;
	yy = radius;
	while(xx<yy){
			if(di<0){
				di += 4*xx + 6;
			}else{
				di += 4*(xx - yy) + 10;
				yy--;	  
				draw_y0--;
				draw_y1--;
				draw_y2++;
				draw_y3++;
				draw_x4--;
				draw_x5++;
				draw_x6--;
				draw_x7++;		 
			}
			xx++;   
			draw_x0++;
			draw_x1--;
			draw_x2++;
			draw_x3--;
			draw_y4++;
			draw_y5++;
			draw_y6--;
			draw_y7--;
			/*judge current point in the avaible range*/
			if( (draw_x0<=EG_COLUMN)&&(draw_y0>=0) ){
				EG_Sim_Buffer[draw_y0][draw_x0]=color;
			}	    
			if( (draw_x1>=0)&&(draw_y1>=0) ){
				EG_Sim_Buffer[draw_y1][draw_x1]=color;
			}
			if(draw_x1>=0){  /* set the start point of fill line fill_x0 */
				fill_x0 = draw_x1;
				fill_y0 = draw_y1;
				if(fill_y0>EG_ROW)
					fill_y0 = EG_ROW;
				if(fill_y0<0)
					fill_y0 = 0; 
				fill_x1 = center.m_uX*2 - draw_x1;		/* set the end point of fill line fill_x1 */					
				if(fill_x1>EG_COLUMN)
					fill_x1 = EG_COLUMN;
				EG_Graphic_DrawHorizonLine(EPosition(fill_x0, fill_y0), fill_x1-fill_x0, color);
			}
			if( (draw_x2<=EG_COLUMN)&&(draw_y2<=EG_ROW) ){
				EG_Sim_Buffer[draw_y2][draw_x2]=color;
			}
			if( (draw_x3>=0)&&(draw_y3<=EG_ROW)){
				EG_Sim_Buffer[draw_y3][draw_x3]=color;
			}
			if(draw_x3>=0){ 	
				fill_x0 = draw_x3;/* set the start point of fill line fill_x0 */
				fill_y0 = draw_y3;/* set the start point of fill line fill_y0 */
			if(fill_y0>EG_ROW)
				fill_y0 =EG_ROW;
			if(fill_y0<0)
				fill_y0 = 0;
			fill_x1 = center.m_uX*2 - draw_x3;		/*  set the end point of fill line fill_x1 */			
			if(fill_x1>EG_COLUMN)
				fill_x1 = EG_COLUMN;
			EG_Graphic_DrawHorizonLine(EPosition(fill_x0, fill_y0), fill_x1-fill_x0, color);
		}
		if( (draw_x4<=EG_COLUMN)&&(draw_y4>=0) ){
			EG_Sim_Buffer[draw_y4][draw_x4]=color;
		}
		if( (draw_x5>=0)&&(draw_y5>=0) ){
			EG_Sim_Buffer[draw_y5][draw_x5]=color;
		}
		if(draw_x5>=0)	{
			fill_x0 = draw_x5;/* set the start point of fill line fill_x0 */
			fill_y0 = draw_y5;	/* set the start point of fill line fill_y0 */
			if(fill_y0>EG_ROW)
				fill_y0 = EG_ROW;
			if(fill_y0<0)
				fill_y0 = 0;							
			fill_x1 = center.m_uX*2 - draw_x5;/* set the end point of fill line fill_x1 */					
			if(fill_x1>EG_COLUMN)
				fill_x1 =EG_COLUMN;
			EG_Graphic_DrawHorizonLine(EPosition(fill_x0, fill_y0), fill_x1-fill_x0, color);
		}
		if( (draw_x6<=EG_COLUMN)&&(draw_y6<=EG_ROW) ){
			EG_Sim_Buffer[draw_y6][draw_x6]=color;
		}
		if( (draw_x7>=0)&&(draw_y7<=EG_ROW) ){
			EG_Sim_Buffer[draw_y7][draw_x7]=color;
		}
		if(draw_x7>=0)	{
			fill_x0 = draw_x7;/* set the start point of fill line fill_x0 */
			fill_y0 = draw_y7;/* set the start point of fill line fill_y0 */
			if(fill_y0>EG_ROW)
				fill_y0 = EG_ROW;
			if(fill_y0<0)
				fill_y0 = 0;	
			fill_x1 = center.m_uX*2 - draw_x7;		/* set the end point of fill line fill_x1 */				
			if(fill_x1>EG_COLUMN)
				fill_x1 =EG_COLUMN;
			EG_Graphic_DrawHorizonLine(EPosition(fill_x0, fill_y0), fill_x1-fill_x0, color);
		}
	}
}

void EG_Graphic_DrawQuarterArc(const EPosition& center,unsigned int radius,const EColor& color,unsigned char angle){
	int  draw_x, draw_y;
	int  op_x, op_y;
	int  op_2rr= 2*radius*radius;
	EPosition pos;

	if(radius==0)
		return;
	switch(angle){
		case  1:
			draw_x = center.m_uX+radius;
			draw_y = center.m_uY;
			op_x = radius;
			op_y = 0;
			while(1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				/*calculate the next point*/
				op_y++;
				draw_y++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x--;
				}
				if(op_y>=op_x)
					break;
			}
            while(1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				/*calculate the next point*/
				op_x--;
				draw_x--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y++;
				}
				if(op_x<=0){ 
					pos.m_uX=draw_x;
					pos.m_uY=draw_y;
					EG_Graphic_DrawPoint(pos,color);				 
					break;
				}
			}
            break;    				
		case  2:
			draw_x = center.m_uX-radius;
			draw_y = center.m_uY;
			op_x = radius;
			op_y = 0;
			while(1){		
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				op_y++;
				draw_y++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x++;
				}
				if(op_y>=op_x)
					break;
			}
			while(1){				
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				op_x--;
				draw_x++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y++;
				}
				if(op_x<=0){
					pos.m_uX=draw_x;
					pos.m_uY=draw_y;
					EG_Graphic_DrawPoint(pos,color);				 
					break;
				}
			}
			break;
		case  3:
			draw_x = center.m_uX-radius;
			draw_y = center.m_uY;
			op_x = radius;
			op_y = 0;
			while(1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				op_y++;
				draw_y--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x++;
				}
				if(op_y>=op_x)
					break;
			}
			while(1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				op_x--;
				draw_x++;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y--;
				}
				if(op_x<=0){ 					
					pos.m_uX=draw_x;
					pos.m_uY=draw_y;
					EG_Graphic_DrawPoint(pos,color);				 
					break;
				}
			}
			break;
		case  4:
			draw_x = center.m_uX+radius;
			draw_y = center.m_uY;
			op_x = radius;
			op_y = 0;
			while(1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				op_y++;
				draw_y--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
					op_x--;
					draw_x--;
				}
				if(op_y>=op_x)
					break;
			}
			while(1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);				 
				op_x--;
				draw_x--;
				if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
					op_y++;
					draw_y--;
				}
				if(op_x<=0){
					pos.m_uX=draw_x;
					pos.m_uY=draw_y;
					EG_Graphic_DrawPoint(pos,color);				 
					break;
				}
			}
			break;
		default:
			break;
	}
}

void EG_Graphic_DrawArc(const EPosition& center,unsigned int radius,const EColor& color,unsigned int startAngle,unsigned int endAngle){
	int  draw_x, draw_y;					//draw coordinate
	int  op_x, op_y;						//operation coordinate
	int  op_2rr=2*radius*radius;		
	int  pno_angle= 0;				
	char  draw_on;			//on=1,  draw point
	EPosition pos;

	if(radius==0)
		return;					
	if(startAngle==endAngle)  //avoid the same angle,which may cause dead loop
		return;			
	if((startAngle>=360)|| (endAngle>=360))
		return;
	/*arc points of 45 degree*/       
	op_x = radius;
	op_y = 0;
	while(1){
		pno_angle++; 							
		/*calculate the next point*/
		op_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
		}
		if(op_y>=op_x) 
			break;
	}
	draw_on = 0;								//do not draw the point at the beginning
	/* set the start point */
	if(endAngle>startAngle)
		draw_on = 1;
	startAngle = (360-startAngle)*pno_angle/45;
	endAngle = (360-endAngle)*pno_angle/45;
	if(startAngle==0)
		startAngle=1;
	if(endAngle==0)
		endAngle=1;

	/*draw the arc,clockwise rotation*/
	pno_angle = 0;
	draw_x = center.m_uX+radius;
	draw_y = center.m_uY;         
	op_x = radius;
	op_y = 0;
	while(1){ 
		op_y++;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on =1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		} 
		if(op_y>=op_x){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	while(1){
		op_x--;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){			//toggle the draw_on,if it is the start or end angle
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		} 
		if(op_x<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	/*draw clockwise, from 269 degree*/
	draw_y = center.m_uY-radius;
	draw_x = center.m_uX;         
	op_y = radius;
	op_x = 0;
	while(1){
		op_x++;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if( (pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		}
		if(op_x>=op_y){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		break;
		}
	}
	while(1){
		op_y--;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		}
		if(op_y<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	/*draw clockwise, from 179 degree*/
	draw_x = center.m_uX-radius;
	draw_y = center.m_uY;         
	op_x = radius;
	op_y = 0;
	while(1){
		op_y++;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		} 
		if(op_y>=op_x){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	while(1){
		op_x--;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		}
		if(op_x<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	/*draw clockwise, from 89 degree*/
	draw_y = center.m_uY+radius;
	draw_x = center.m_uX;         
	op_y = radius;
	op_x = 0;
	while(1){
		op_x++;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		}
		if(op_x>=op_y){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	while(1){
		op_y--;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		} 
		if(op_y<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
}

void EG_Graphic_DrawPieSlice(const EPosition& center,unsigned int radius,const EColor& color,unsigned int startAngle,unsigned int endAngle){
	int  draw_x, draw_y;					//draw coordinate
	int  op_x, op_y;						//operation coordinate
	int  op_2rr=2*radius*radius;		
	int  pno_angle= 0;				
	char  draw_on;			//on=1,  draw point
	EPosition pos;

	if(radius==0)
		return;					
	if(startAngle==endAngle)  //avoid the same angle,which may cause dead loop
		return;			
	if((startAngle>=360)|| (endAngle>=360))
		return;
	/*arc points of 45 degree*/       
	op_x = radius;
	op_y = 0;
	while(1){
		pno_angle++; 							
		/*calculate the next point*/
		op_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
		}
		if(op_y>=op_x) 
			break;
	}
	draw_on = 0;								//do not draw the point at the beginning
	/* set the start point */
	if(endAngle>startAngle)
		draw_on = 1;
	startAngle = (360-startAngle)*pno_angle/45;
	endAngle = (360-endAngle)*pno_angle/45;
	if(startAngle==0)
		startAngle=1;
	if(endAngle==0)
		endAngle=1;

	/*draw the arc,clockwise rotation*/
	pno_angle = 0;
	draw_x = center.m_uX+radius;
	draw_y = center.m_uY;         
	op_x = radius;
	op_y = 0;
	while(1){ 
		op_y++;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on =1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		} 
		if(op_y>=op_x){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	while(1){
		op_x--;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){			//toggle the draw_on,if it is the start or end angle
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		} 
		if(op_x<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	/*draw clockwise, from 269 degree*/
	draw_y = center.m_uY-radius;
	draw_x = center.m_uX;         
	op_y = radius;
	op_x = 0;
	while(1){
		op_x++;
		draw_x--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if( (pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		}
		if(op_x>=op_y){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
		break;
		}
	}
	while(1){
		op_y--;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		}
		if(op_y<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	/*draw clockwise, from 179 degree*/
	draw_x = center.m_uX-radius;
	draw_y = center.m_uY;         
	op_x = radius;
	op_y = 0;
	while(1){
		op_y++;
		draw_y++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0){
			op_x--;
			draw_x++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		} 
		if(op_y>=op_x){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	while(1){
		op_x--;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0){
			op_y++;
			draw_y++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		}
		if(op_x<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	/*draw clockwise, from 89 degree*/
	draw_y = center.m_uY+radius;
	draw_x = center.m_uX;         
	op_y = radius;
	op_x = 0;
	while(1){
		op_x++;
		draw_x++;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0){
			op_y--;
			draw_y--;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		}
		if(op_x>=op_y){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
	while(1){
		op_y--;
		draw_y--;
		if((2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0){
			op_x++;
			draw_x++;
		}
		if(draw_on==1){
			pos.m_uX=draw_x;
			pos.m_uY=draw_y;
			EG_Graphic_DrawPoint(pos,color);
		}
		pno_angle++;
		if((pno_angle==startAngle)||(pno_angle==endAngle)){
			draw_on = 1-draw_on;
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			EG_Graphic_DrawLine(center,pos,color,false);
		} 
		if(op_y<=0){
			if(draw_on==1){
				pos.m_uX=draw_x;
				pos.m_uY=draw_y;
				EG_Graphic_DrawPoint(pos,color);
			}
			break;
		}
	}
}

void EG_Graphic_DrawEmptyEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY,const EColor& color){
	int  draw_x0, draw_y0;		
	int  draw_x1, draw_y1;
	int  draw_x2, draw_y2;
	int  draw_x3, draw_y3;
	int  xx, yy;				// draw control variable 
	int  center_x, center_y;		//center of ellipse
	int  radius_x, radius_y;		// radius along x and y axies
	int  radius_xx, radius_yy;		
	int  radius_xx2, radius_yy2;
	int  di;						//decide variable
	EPosition pos;
	
	if((leftX==rightX)||(topY==bottomY))
		return;
	/*calculate the center of ellipse*/
	center_x = (leftX + rightX) >> 1;			
	center_y = (topY + bottomY) >> 1;
	if(leftX > rightX){
		radius_x = (leftX - rightX) >> 1;
	}else{
		radius_x = (rightX - leftX) >> 1;
	}
	if(topY > bottomY){
		radius_y = (topY - bottomY) >> 1;
	}else{
		radius_y = (bottomY - topY) >> 1;
	}
	radius_xx = radius_x * radius_x;
	radius_yy = radius_y * radius_y;
	radius_xx2 = radius_xx<<1;
	radius_yy2 = radius_yy<<1;
	xx = 0;
	yy = radius_y;
	di = radius_yy2 + radius_xx - radius_xx2*radius_y ;

	/*calculate the end point of ellipse to start drawing*/
	draw_x0 = draw_x1 = draw_x2 = draw_x3 = center_x;
	draw_y0 = draw_y1 = center_y + radius_y;
	draw_y2 = draw_y3 = center_y - radius_y;

	//end point on y axie
	pos.m_uX=draw_x0;
	pos.m_uY=draw_y0;
	EG_Graphic_DrawPoint(pos,color);
	pos.m_uX=draw_x2;
	pos.m_uY=draw_y2;
	EG_Graphic_DrawPoint(pos,color);
	
	while((radius_yy*xx)<(radius_xx*yy)){
		if(di<0){
			di+= radius_yy2*(2*xx+3);
		}else{
			di += radius_yy2*(2*xx+3) + 4*radius_xx - 4*radius_xx*yy;
			yy--;
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;				 
		}
		xx ++;						// x axie ++
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		pos.m_uX=draw_x0;
		pos.m_uY=draw_y0;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x1;
		pos.m_uY=draw_y1;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x2;
		pos.m_uY=draw_y2;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x3;
		pos.m_uY=draw_y3;
		EG_Graphic_DrawPoint(pos,color);
	}
	di = radius_xx2*(yy-1)*(yy-1) + radius_yy2*xx*xx + radius_yy + radius_yy2*xx - radius_xx2*radius_yy;
	while(yy>=0){
		if(di<0){
			di+= radius_xx2*3 + 4*radius_yy*xx + 4*radius_yy - 2*radius_xx2*yy;
			xx ++;							
			draw_x0++;
			draw_x1--;
			draw_x2++;
			draw_x3--;  
		}else{
			di += radius_xx2*3 - 2*radius_xx2*yy;	 	 		     			 
		}
		yy--;
		draw_y0--;
		draw_y1--;
		draw_y2++;
		draw_y3++;	
		pos.m_uX=draw_x0;
		pos.m_uY=draw_y0;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x1;
		pos.m_uY=draw_y1;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x2;
		pos.m_uY=draw_y2;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x3;
		pos.m_uY=draw_y3;
		EG_Graphic_DrawPoint(pos,color);
	}
}

void EG_Graphic_DrawFilledEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY,const EColor& color){
	int  draw_x0, draw_y0;		
	int  draw_x1, draw_y1;
	int  draw_x2, draw_y2;
	int  draw_x3, draw_y3;
	int  xx, yy;				// draw control variable 
	int  center_x, center_y;		//center of ellipse
	int  radius_x, radius_y;		// radius along x and y axies
	int  radius_xx, radius_yy;		
	int  radius_xx2, radius_yy2;
	int  di;						//decide variable
	EPosition pos;
	
	if((leftX==rightX)||(topY==bottomY))
		return;
	/*calculate the center of ellipse*/
	center_x = (leftX + rightX) >> 1;			
	center_y = (topY + bottomY) >> 1;
	if(leftX > rightX){
		radius_x = (leftX - rightX) >> 1;
	}else{
		radius_x = (rightX - leftX) >> 1;
	}
	if(topY > bottomY){
		radius_y = (topY - bottomY) >> 1;
	}else{
		radius_y = (bottomY - topY) >> 1;
	}
	radius_xx = radius_x * radius_x;
	radius_yy = radius_y * radius_y;
	radius_xx2 = radius_xx<<1;
	radius_yy2 = radius_yy<<1;
	xx = 0;
	yy = radius_y;
	di = radius_yy2 + radius_xx - radius_xx2*radius_y ;

	/*calculate the end point of ellipse to start drawing*/
	draw_x0 = draw_x1 = draw_x2 = draw_x3 = center_x;
	draw_y0 = draw_y1 = center_y + radius_y;
	draw_y2 = draw_y3 = center_y - radius_y;

	//end point on y axie
	pos.m_uX=draw_x0;
	pos.m_uY=draw_y0;
	EG_Graphic_DrawPoint(pos,color);
	pos.m_uX=draw_x2;
	pos.m_uY=draw_y2;
	EG_Graphic_DrawPoint(pos,color);

	while((radius_yy*xx)<(radius_xx*yy)){
		if(di<0){
			di+= radius_yy2*(2*xx+3);
		}else{
			di += radius_yy2*(2*xx+3) + 4*radius_xx - 4*radius_xx*yy;
			yy--;
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;				 
		}
		xx ++;						// x axie ++
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		pos.m_uX=draw_x0;
		pos.m_uY=draw_y0;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x1;
		pos.m_uY=draw_y1;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x2;
		pos.m_uY=draw_y2;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x3;
		pos.m_uY=draw_y3;
		EG_Graphic_DrawPoint(pos,color);
		if(di>=0){
			if(draw_x1>draw_x0){
				pos.m_uX=draw_x0;
				pos.m_uY=draw_y0;
				EG_Graphic_DrawHorizonLine(pos, draw_x1-draw_x0,color);
			}else{
				pos.m_uX=draw_x1;
				pos.m_uY=draw_y1;
				EG_Graphic_DrawHorizonLine(pos, draw_x0-draw_x1,color);
			}
			if(draw_x3>draw_x2){
				pos.m_uX=draw_x2;
				pos.m_uY=draw_y2;
				EG_Graphic_DrawHorizonLine(pos, draw_x3-draw_x2,color);
			}else{
				pos.m_uX=draw_x3;
				pos.m_uY=draw_y3;
				EG_Graphic_DrawHorizonLine(pos, draw_x2-draw_x3,color);
			}
		}
	}
	di = radius_xx2*(yy-1)*(yy-1) + radius_yy2*xx*xx + radius_yy + radius_yy2*xx - radius_xx2*radius_yy;
	while(yy>=0){
		if(di<0){
			di+= radius_xx2*3 + 4*radius_yy*xx + 4*radius_yy - 2*radius_xx2*yy;
			xx ++;							
			draw_x0++;
			draw_x1--;
			draw_x2++;
			draw_x3--;  
		}else{
			di += radius_xx2*3 - 2*radius_xx2*yy;	 	 		     			 
		}
		yy--;
		draw_y0--;
		draw_y1--;
		draw_y2++;
		draw_y3++;	
		pos.m_uX=draw_x0;
		pos.m_uY=draw_y0;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x1;
		pos.m_uY=draw_y1;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x2;
		pos.m_uY=draw_y2;
		EG_Graphic_DrawPoint(pos,color);
		pos.m_uX=draw_x3;
		pos.m_uY=draw_y3;
		EG_Graphic_DrawPoint(pos,color);
		//fill it ,since y axie has already changed
		if(draw_x1>draw_x0){
			pos.m_uX=draw_x0;
			pos.m_uY=draw_y0;
			EG_Graphic_DrawHorizonLine(pos, draw_x1-draw_x0,color);
		}else{
			pos.m_uX=draw_x1;
			pos.m_uY=draw_y1;
			EG_Graphic_DrawHorizonLine(pos, draw_x0-draw_x1,color);
		}
		if(draw_x3>draw_x2){
			pos.m_uX=draw_x2;
			pos.m_uY=draw_y2;
			EG_Graphic_DrawHorizonLine(pos, draw_x3-draw_x2,color);
		}else{
			pos.m_uX=draw_x3;
			pos.m_uY=draw_y3;
			EG_Graphic_DrawHorizonLine(pos, draw_x2-draw_x3,color);
		}	
	}
}

void EG_Graphic_DrawChar(const EPosition& pos,char val,const EColor& color){
    char temp1,temp2,tmp,n;
    int index;
    tmp=val&0xF0;
    tmp=tmp>>4;
    index=(tmp-2)*16;
    index+=val&0x0F;
    for(temp1=0;temp1<8;temp1++){
		for(temp2=0;temp2<8;temp2++){
			tmp=0x01;
			tmp=tmp<<temp2;
			n=EG_SmallFont[index][temp1];
			if(n&tmp){
				EG_Sim_Buffer[pos.m_uY+temp1][pos.m_uX+7-temp2]=color;			
			}
		}
    }
}

void EG_Graphic_DrawNotChar(const EPosition& pos,char val,const EColor& color){
    char temp1,temp2,tmp,n;
    int index;
    tmp=val&0xF0;
    tmp=tmp>>4;
    index=(tmp-2)*16;
    index+=val&0x0F;
    for(temp1=0;temp1<8;temp1++){
		for(temp2=0;temp2<8;temp2++){
			tmp=0x01;
			tmp=tmp<<temp2;
			n=EG_SmallFont[index][temp1];
			if(!(n&tmp)){
				EG_Sim_Buffer[pos.m_uY+temp1][pos.m_uX+7-temp2]=color;			
			}
		}
    }
}

void EG_Graphic_DrawString(const EPosition& pos,char* string,const EColor& color){
    unsigned int n=0;
	EPosition pos1;
	pos1=pos;
    while(string[n]!='\0'){
		EG_Graphic_DrawChar(pos1,string[n],color);
		pos1.m_uX=pos1.m_uX+8;
        n++;
    }
}
void EG_Graphic_DrawNotString(const EPosition& pos,char* string,const EColor& color){
    unsigned int n=0;
	EPosition pos1;
	pos1=pos;
    while(string[n]!='\0'){
		EG_Graphic_DrawNotChar(pos1,string[n],color);
		pos1.m_uX=pos1.m_uX+8;
        n++;
    }
}

void EG_Graphic_DrawConstString(const EPosition& pos,char* string,unsigned char size,const EColor& color){
    unsigned char n=0;
	EPosition pos1;
	pos1=pos;
    for(;n<size;n++){
		EG_Graphic_DrawChar(pos1,string[n],color);
		pos1.m_uX=pos1.m_uX+8;
    }
}

#ifndef EG_NO_BITMAP
void EG_Graphic_DrawBitmap(const EPosition& pos,EBitmap* pBitmap){
	EPosition curpos;
	EColor temp;
	unsigned char* tempp=pBitmap->m_pImageBuffer;
	if(tempp==NULL)
		return;	
	for(unsigned int m=0;m<pBitmap->m_uHeight;m++){
		for(unsigned int n=0;n<pBitmap->m_uWidth;n++){
			curpos.m_uX=pos.m_uX+n;
			curpos.m_uY=pos.m_uY+m;
			temp.m_cRed=*tempp++;
			temp.m_cGreen=*tempp++;
			temp.m_cBlue=*tempp++;
			EG_Graphic_DrawPoint(curpos,temp);		
		}
	}		
}
#endif //EG_NO_BITMAP

#ifndef EG_NO_FONT
void EG_Graphic_DrawFontChar(const EPosition& pos,char val,const EColor& color,const EFont& font){
    unsigned int temp1,temp2,tmp,n,index;
	tmp=val&0xF0;
	tmp=tmp>>4;
	index=(tmp-2)*16;
	index+=val&0x0F;
    for(temp1=0;temp1<EG_FontHeight[font.m_cFontNumber];temp1++){
		for(temp2=0;temp2<EG_FontWidth[font.m_cFontNumber];temp2++){
			tmp=0x01;
			tmp=tmp<<temp2;
			if(font.m_cFontNumber==0){
				n=EG_SmallFont[index][temp1];
			}else if(font.m_cFontNumber==1){
				n=EG_NormalFont[index][temp1];
			}else if(font.m_cFontNumber==2){
				n=EG_NormalCambriaFont[index][temp1];
			}else if(font.m_cFontNumber==3){
				n=EG_NormalBoldCambriaFont[index][temp1];
			}else{
				n=EG_NormalBoldFont[index][temp1];
			}
			if(n&tmp){
				if(font.m_cFontSize==1){
					EG_Sim_Buffer[pos.m_uY+temp1][pos.m_uX+EG_FontWidth[font.m_cFontNumber]-1-temp2]=color;			
				}else if (font.m_cFontSize==2){
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)]=color;			
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)]=color;			
				}else{
					EG_Sim_Buffer[pos.m_uY+temp1*3][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+2][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+2][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+2][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1]=color;			
				}
			}
		}
    }
}

void EG_Graphic_DrawNotFontChar(const EPosition& pos,char val,const EColor& color,const EFont& font){
    unsigned int temp1,temp2,tmp,n,index;
	tmp=val&0xF0;
	tmp=tmp>>4;
	index=(tmp-2)*16;
	index+=val&0x0F;
    for(temp1=0;temp1<EG_FontHeight[font.m_cFontNumber];temp1++){
		for(temp2=0;temp2<EG_FontWidth[font.m_cFontNumber];temp2++){
			tmp=0x01;
			tmp=tmp<<temp2;
			if(font.m_cFontNumber==0){
				n=EG_SmallFont[index][temp1];
			}else if(font.m_cFontNumber==1){
				n=EG_NormalFont[index][temp1];
			}else if(font.m_cFontNumber==2){
				n=EG_NormalCambriaFont[index][temp1];
			}else if(font.m_cFontNumber==3){
				n=EG_NormalBoldCambriaFont[index][temp1];
			}else{
				n=EG_NormalBoldFont[index][temp1];
			}
			if(!(n&tmp)){
				if(font.m_cFontSize==1){
					EG_Sim_Buffer[pos.m_uY+temp1][pos.m_uX+EG_FontWidth[font.m_cFontNumber]-1-temp2]=color;			
				}else if (font.m_cFontSize==2){
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)]=color;			
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+(temp1<<1)][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)<<1)]=color;			
				}else{
					EG_Sim_Buffer[pos.m_uY+temp1*3][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+1][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+2][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)-1]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+2][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)]=color;			
					EG_Sim_Buffer[pos.m_uY+temp1*3+2][pos.m_uX+((EG_FontWidth[font.m_cFontNumber]-temp2)*3)+1]=color;			
				}
			}
		}
    }
}

void EG_Graphic_DrawFontString(const EPosition& pos,char* string,const EColor& color,const EFont& font){
    unsigned int n=0;
	EPosition pos1;
	pos1=pos;
    while(string[n]!='\0'){
		EG_Graphic_DrawFontChar(pos1,string[n],color,font);
		pos1.m_uX=pos1.m_uX+EG_FontWidth[font.m_cFontNumber]*font.m_cFontSize;
        n++;
    }
}

void EG_Graphic_DrawConstFontString(const EPosition& pos,char* string,unsigned char size,const EColor& color,const EFont& font){
    unsigned char n=0;
	EPosition pos1;
	pos1=pos;
    for(;n<size;n++){
		EG_Graphic_DrawFontChar(pos1,string[n],color,font);
		pos1.m_uX=pos1.m_uX+EG_FontWidth[font.m_cFontNumber]*font.m_cFontSize;
    }
}

void EG_Graphic_DrawNotFontString(const EPosition& pos,char* string,const EColor& color,const EFont& font){
    unsigned int n=0;
	EPosition pos1;
	pos1=pos;
    while(string[n]!='\0'){
		EG_Graphic_DrawNotFontChar(pos1,string[n],color,font);
		pos1.m_uX=pos1.m_uX+EG_FontWidth[font.m_cFontNumber]*font.m_cFontSize;
        n++;
    }
}
#endif //EG_NO_FONT

#endif  //EG_RGB_COLOR




