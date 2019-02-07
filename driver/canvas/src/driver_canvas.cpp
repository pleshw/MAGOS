#include <iostream>
#include <cstring>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

#include "../include/canvas.h"

using namespace canvas;

int main( void )
{
    // Cria um objeto canvas de 800 por 600 pixels de dimensão.
    Canvas c( 800, 600 );

    // Definie a cor de fundo da imagem.
    c.clear( LIGHT_GREY );

    // Vamos desenhar um retângulo cujo canto superior esquerdo está em (100,100).
    coord_type orig_x{100}, orig_y{100};

    // Um retângulo pode ser formado através do desenho de 4 linhas.
    c.thickness( 3 ); //changing line thickness
    c.hLine( orig_x, orig_x, 300, RED );
    c.thickness( 7 );
    c.vLine( orig_x, orig_y, 200, STEEL_BLUE );
    c.thickness( 5 );
    c.hLine( orig_x, orig_y+200, 300, GREEN );
    c.thickness( 2 );
    c.vLine( orig_x+300, orig_y, 200, YELLOW );
    // Preencher o interior do retângulo com um quadrado de 50 x 50 pixels.
    c.box( orig_x+100, orig_y+50, 75, 75, DEEP_SKY_BLUE );

    // Recuperar as informações do Canvas (imagem) para poder gravar um arquivo PNG.
    auto width = c.width();
    auto height = c.height();
    auto pixels = c.buffer(); // Ponteiro para o vetor de bytes representando a imagem.

    // Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( 
            "teste.png",          // file name
            width, height,        // image dimensions
            3,                    // # of channels per pixel
            pixels,               // the pixels
            width*3
    );           // length of a row (in bytes), see above.

}
