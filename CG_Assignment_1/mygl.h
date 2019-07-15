#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************


//*****************************************************************************
// PutPixel
//*****************************************************************************
typedef struct {
	int x;
	int y;
	int RGBA[4];
}pixel;

void PutPixel(pixel p) {

	int posicao = (p.x * 4) + (p.y * IMAGE_WIDTH * 4);

	FBptr[posicao + 0] = p.RGBA[0];
	FBptr[posicao + 1] = p.RGBA[1];
	FBptr[posicao + 2] = p.RGBA[2];
	FBptr[posicao + 3] = p.RGBA[3];
}


//*****************************************************************************
// Drawline
//*****************************************************************************

float distancia(pixel p0, pixel p1) {
	return sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
}

pixel interpolacaoCor(float p, pixel p0, pixel p1, pixel aux) {

	aux.RGBA[0] = p0.RGBA[0] * p + (1 - p)*p1.RGBA[0];
	aux.RGBA[1] = p0.RGBA[1] * p + (1 - p)*p1.RGBA[1];
	aux.RGBA[2] = p0.RGBA[2] * p + (1 - p)*p1.RGBA[2];
	aux.RGBA[3] = p0.RGBA[3] * p + (1 - p)*p1.RGBA[3];
	return aux;
}


void drawline(pixel p0, pixel p1) {

	int dx = p1.x - p0.x;
	int dy = p1.y - p0.y;

	int inclinacao;

	float distanciaParcial;
	float distanciaTotal = distancia(p0, p1);

	if (dx < 0) {
		drawline(p1, p0);
		return;
	}

	if (dy < 0) {
		inclinacao = -1;
	}
	else {
		inclinacao = 1;
	}

	int incr_e_dy, incr_e_dx, incr_ne_positivo, incr_ne_negativo, d;
	incr_e_dy = 2 * dy;
	incr_e_dx = 2 * dx;
	incr_ne_positivo = 2 * (dy + dx);
	incr_ne_negativo = 2 * (dy - dx);

	pixel aux2 = p0; //pixel auxiliar

	PutPixel(p0);

	if (dx >= inclinacao*dy) {
		if (dy < 0) {
			d = incr_e_dy + dx;
			while (aux2.x < p1.x) {
				if (d < 0) {
					d += incr_ne_positivo;
					aux2.x++;
					aux2.y--;
				}
				else {
					d += incr_e_dy;
					aux2.x++;
				}
				distanciaParcial = distancia(aux2, p1);
				aux2 = interpolacaoCor((distanciaParcial / distanciaTotal), p0, p1, aux2);
				PutPixel(aux2);
			}
		}
		else {
			d = incr_e_dy - dx;
			while (aux2.x < p1.x) {
				if (d < 0) {
					d += incr_e_dy;
					aux2.x++;
				}
				else {
					d += incr_ne_negativo;
					aux2.x++;
					aux2.y++;
				}
				distanciaParcial = distancia(aux2, p1);
				aux2 = interpolacaoCor((distanciaParcial / distanciaTotal), p0, p1, aux2);
				PutPixel(aux2);
			}
		}

	}
	else {
		if (dy < 0) {
			d = dy + incr_e_dx;
			while (aux2.y > p1.y) {
				if (d < 0) {
					d += 2 * dx;
					aux2.y--;
				}
				else {
					d += incr_ne_positivo;
					aux2.x++;
					aux2.y--;
				}
				distanciaParcial = distancia(aux2, p1);
				aux2 = interpolacaoCor((distanciaParcial / distanciaTotal), p0, p1, aux2);
				PutPixel(aux2);
			}
		}
		else {
			d = dy - incr_e_dx;
			while (aux2.y < p1.y) {
				if (d < 0) {
					d += incr_ne_negativo;
					aux2.x++;
					aux2.y++;
				}
				else {
					d += -incr_e_dx;
					aux2.y++;
				}
				distanciaParcial = distancia(aux2, p1);
				aux2 = interpolacaoCor((distanciaParcial / distanciaTotal), p0, p1, aux2);
				PutPixel(aux2);
			}
		}
	}

	PutPixel(p1);

}

//*****************************************************************************
// DrawTriangle
//*****************************************************************************

void drawTriangle(pixel p0, pixel p1, pixel p2) {
	if (p0.x < p1.x && p0.x < p2.x) {
		drawline(p0, p1);
		drawline(p0, p2);
		if (p1.x < p2.x) {
			drawline(p1, p2);
		}
		else {
			drawline(p2, p1);
		}
	}
	else {
		if (p1.x < p0.x && p1.x < p2.x) {
			drawline(p1, p0);
			drawline(p1, p2);
			if (p0.x < p2.x) {
				drawline(p0, p2);
			}
			else {
				drawline(p2, p0);
			}
		}
		else {
			if (p2.x < p0.x && p2.x < p1.x) {
				drawline(p2, p0);
				drawline(p2, p1);
				if (p0.x < p1.x) {
					drawline(p0, p1);
				}
				else {
					drawline(p1, p0);
				}
			}
		}
	}
}



#endif // _MYGL_H_
