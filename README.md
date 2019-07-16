# T1
Algoritmos de rasterização


## Sumário

<!--
* [Introdução](#introdução)
* [Rasterização de pontos](#rasterização-de-pontos)
* [Rasterização de retas](#rasterização-de-retas)
* [Desenho de triângulos](#desenho-de-triângulos)
* [Referências](#referências)
-->

---

## Introdução

O projeto implementa algoritmos para a renderização de pontos e linhas na tela.

## Rasterização de pontos

Rasterização é o processo de converter um modelo matemático em um conjunto de pixels que aproxima-se do desenho desejado.
Para realizar esta operação, deve-se exibir os pixels do display com cores específicas para formar imagens.
Os pixels são representados em uma malha - **Figura 1** - ```X x Y``` onde ```X``` é a largura da tela e ```Y``` é a altura da mesma.
Por exemplo, em uma tela Full HD existem ```1920x1080 pixels``` (1920 colunas e 1080 linhas).

<p align="center">
  <br>
  <img src="./img/matrix.png"/ width=600px height=400px>
  <h5 align="center">Figura 1 - Tela formada por pixels (Fonte: slide da aula 'Rasterization')</h5>
</p>

Para identificar o local correto de desenhar o pixel, deve-se calcular o offset do mesmo com base na dimensão da janela.
A posição retornada pelo offset será o primeiro byte onde o pixel está definido.
O método que encontra tal posição pode ser visto a seguir:

``` C++
void PutPixel(pixel p)
{
  int posicao = (p.x * 4) + (p.y * IMAGE_WIDTH * 4);
  ...
}
```

Da função PutPixel pode-se verificar o seguinte:

1. x é a posição onde o pixel estará em relação a largura da tela;
2. y é a posição onde o pixel estará em relação a altura da tela;
3. IMAGE_WIDTH é a largura da tela.

O 4 define o tamanho de um pixel. Cada pixel da aplicação segue o formato RGBA, ou seja, a mesma utiliza quatro canais para representar a cor.

1. R - Canal Vermelho - Red;
2. G - Canal Verde - Green;
3. B - Canal Azul - Blue;
4. A - Canal Alpha - Transparência

Cada canal possui um byte - 256 combinações por canal -  responsável por armazenar a sua informação. Logo, podemos compreender que ```1R + 1B + 1G + 1A = 4 bytes```.

Sabendo destas informações foi implementada a primeira técnica de rasterização, desenhar um pixel na tela. A rasterização do ponto é implementada na função PutPixel, descrita abaixo:

``` C++
void PutPixel(pixel p)
{
  int posicao = (p.x * 4) + (p.y * IMAGE_WIDTH * 4);

  FBptr[posicao + 0] = p.RGBA[0];
  FBptr[posicao + 1] = p.RGBA[1];
  FBptr[posicao + 2] = p.RGBA[2];
  FBptr[posicao + 3] = p.RGBA[3];
}
```

