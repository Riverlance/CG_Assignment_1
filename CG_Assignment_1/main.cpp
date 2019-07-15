#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	pixel p0, p1;



	/**
	*	Cena 1
	*/
	/*
	p0.x = 255;
	p0.y = 0;

	p0.RGBA[0] = 255;
	p0.RGBA[1] = 255;
	p0.RGBA[2] = 0;
	p0.RGBA[3] = 0;

	for (int i = 0; i < 55; i++) {
		PutPixel(p0);
		p0.y += 10;
		if (i >= 22 && i <= 32) {
			p0.RGBA[0] = 255;
			p0.RGBA[1] = 0;
			p0.RGBA[2] = 0;
			p0.RGBA[3] = 0;
		}
		else {
			p0.RGBA[0] = 255;
			p0.RGBA[1] = 255;
			p0.RGBA[2] = 0;
			p0.RGBA[3] = 0;
		}
	}

	p1.x = 0;
	p1.y = 280;

	p1.RGBA[0] = 255;
	p1.RGBA[1] = 255;
	p1.RGBA[2] = 0;
	p1.RGBA[3] = 0;

	for (int i = 0; i < 52; i++) {
		PutPixel(p1);
		p1.x += 10;
		if (i >= 22 && i <= 32) {
			p1.RGBA[0] = 255;
			p1.RGBA[1] = 0;
			p1.RGBA[2] = 0;
			p1.RGBA[3] = 0;
		}
		else {
			p1.RGBA[0] = 255;
			p1.RGBA[1] = 255;
			p1.RGBA[2] = 0;
			p1.RGBA[3] = 0;
		}
	}
	*/



	/**
	*	Cena 2
	*/
	/*
	p0.x = 0;
	p0.y = 0;

	p1.x = 511;
	p1.y = 0;

	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 0;
	p1.RGBA[1]= p0.RGBA[1]= 255;
	p1.RGBA[2]= p0.RGBA[2]= 0;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 57;
	p1.RGBA[1]= p0.RGBA[1]= 145;
	p1.RGBA[2]= p0.RGBA[2]= 65;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 145;
	p1.RGBA[1]= p0.RGBA[1]= 65;
	p1.RGBA[2]= p0.RGBA[2]= 106;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 0;
	p1.RGBA[1]= p0.RGBA[1]= 0;
	p1.RGBA[2]= p0.RGBA[2]= 255;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 205;
	p1.RGBA[1]= p0.RGBA[1]= 245;
	p1.RGBA[2]= p0.RGBA[2]= 2;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 248;
	p1.RGBA[1]= p0.RGBA[1]= 7;
	p1.RGBA[2]= p0.RGBA[2]= 211;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 252;
	p1.RGBA[1]= p0.RGBA[1]= 138;
	p1.RGBA[2]= p0.RGBA[2]= 54;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 25;
	p1.RGBA[0]= p0.RGBA[0] = 57;
	p1.RGBA[1]= p0.RGBA[1]= 145;
	p1.RGBA[2]= p0.RGBA[2]= 65;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 145;
	p1.RGBA[1]= p0.RGBA[1]= 65;
	p1.RGBA[2]= p0.RGBA[2]= 106;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 0;
	p1.RGBA[1]= p0.RGBA[1]= 0;
	p1.RGBA[2]= p0.RGBA[2]= 255;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 205;
	p1.RGBA[1]= p0.RGBA[1]= 245;
	p1.RGBA[2]= p0.RGBA[2]= 2;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 248;
	p1.RGBA[1]= p0.RGBA[1]= 7;
	p1.RGBA[2]= p0.RGBA[2]= 211;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 252;
	p1.RGBA[1]= p0.RGBA[1]= 138;
	p1.RGBA[2]= p0.RGBA[2]= 54;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 25;
	p1.RGBA[0]= p0.RGBA[0] = 57;
	p1.RGBA[1]= p0.RGBA[1]= 145;
	p1.RGBA[2]= p0.RGBA[2]= 65;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 145;
	p1.RGBA[1]= p0.RGBA[1]= 65;
	p1.RGBA[2]= p0.RGBA[2]= 106;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 0;
	p1.RGBA[1]= p0.RGBA[1]= 0;
	p1.RGBA[2]= p0.RGBA[2]= 255;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 205;
	p1.RGBA[1]= p0.RGBA[1]= 245;
	p1.RGBA[2]= p0.RGBA[2]= 2;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 248;
	p1.RGBA[1]= p0.RGBA[1]= 7;
	p1.RGBA[2]= p0.RGBA[2]= 211;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 252;
	p1.RGBA[1]= p0.RGBA[1]= 138;
	p1.RGBA[2]= p0.RGBA[2]= 54;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 25;
	p1.RGBA[0]= p0.RGBA[0] = 57;
	p1.RGBA[1]= p0.RGBA[1]= 145;
	p1.RGBA[2]= p0.RGBA[2]= 65;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 145;
	p1.RGBA[1]= p0.RGBA[1]= 65;
	p1.RGBA[2]= p0.RGBA[2]= 106;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 0;
	p1.RGBA[1]= p0.RGBA[1]= 0;
	p1.RGBA[2]= p0.RGBA[2]= 255;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 205;
	p1.RGBA[1]= p0.RGBA[1]= 245;
	p1.RGBA[2]= p0.RGBA[2]= 2;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	p1.y += 20;
	p1.RGBA[0]= p0.RGBA[0] = 248;
	p1.RGBA[1]= p0.RGBA[1]= 7;
	p1.RGBA[2]= p0.RGBA[2]= 211;
	p1.RGBA[3]= p0.RGBA[3]= 0;

	drawline(p0,p1);
	*/



	/**
	*	Cena 3
	*/
	/*
	p0.x = 0;
	p0.y = 0;

	p1.x = 511;
	p1.y = 511;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 255;
	p0.RGBA[2] = 0;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 255;

	drawline(p0,p1);

	p0.x = 0;
	p0.y = 511;

	p1.x = 511;
	p1.y = 0;

	p0.RGBA[0] = 255;
	p0.RGBA[1] = 0;
	p0.RGBA[2] = 0;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 255;

	drawline(p0,p1);

	p0.x = 255;
	p0.y = 0;

	p1.x = 255;
	p1.y = 511;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 0;
	p0.RGBA[2] = 255;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 255;

	drawline(p0,p1);

	p0.x = 0;
	p0.y = 255;

	p1.x = 511;
	p1.y = 255;

	p0.RGBA[0] = 238;
	p0.RGBA[1] = 253;
	p0.RGBA[2] = 4;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 255;

	drawline(p0,p1);
	*/



	/**
	*	Cena 4
	*/
	/*
	p0.x = 0;
	p0.y = 1;

	p1.x = 511;
	p1.y = 1;

	p0.RGBA[0] = 255;
	p0.RGBA[1] = 0;
	p0.RGBA[2] = 0;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 255;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 0;

	drawline(p0,p1);

	p0.x = 0;
	p0.y = 1;

	p1.x = 251;
	p1.y = 251;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 255;
	p0.RGBA[2] = 0;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 255;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 0;

	drawline(p0,p1);

	p0.x = 251;
	p0.y = 251;

	p1.x = 511;
	p1.y = 1;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 0;
	p0.RGBA[2] = 255;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 255;
	p1.RGBA[3]= 0;

	drawline(p0,p1);
	*/



	/**
	*	Cena 5
	*/
	p0.x = 0;
	p0.y = 1;

	p1.x = 511;
	p1.y = 1;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 0;
	p0.RGBA[2] = 255;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 255;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 0;

	drawline(p0,p1);

	p0.x = 0;
	p0.y = 1;

	p1.x = 251;
	p1.y = 251;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 0;
	p0.RGBA[2] = 255;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 0;
	p1.RGBA[1]= 255;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 0;

	drawline(p0,p1);

	p0.x = 251;
	p0.y = 251;

	p1.x = 511;
	p1.y = 1;

	p0.RGBA[0] = 0;
	p0.RGBA[1] = 255;
	p0.RGBA[2] = 0;
	p0.RGBA[3] = 0;
	p1.RGBA[0]= 255;
	p1.RGBA[1]= 0;
	p1.RGBA[2]= 0;
	p1.RGBA[3]= 0;

	drawline(p0,p1);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
