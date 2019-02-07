#include "../include/canvas.h"

    /*!
     * Deep copy of the canvas.
     * @param clone The object we are copying from.
     */
    Canvas::Canvas( const Canvas &clone )
    {
        Width  = clone.width();
        Height = clone.height();
        Pixels.reset( new colorChannel[Width * Height * 3]  );
        std::memcpy( Pixels.get(), clone.Pixels.get(), sizeof( colorChannel )*Width*Height*3);   
    }



    /*!
     * @param source The object we are copying information from.
     * @return A reference to the `this` object.
     */
    Canvas& Canvas::operator=( const Canvas & source )
    {
        if ( &source != this )
            std::memcpy( Pixels.get(), source.Pixels.get(), sizeof( colorChannel )*Width*Height*3);
        return *this;
    }



    void Canvas::clear( const Color& color )
    {
        std::memset( Pixels.get(), *color.channels, ( Width * Height * 3 ));
        // for(size_t y(0); y < Height; y++)
        //     for(size_t x; x < Width; x++)
        //         pixel(x, y, color);
    }



    /*!
     * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to know the color of.
     * @return The pixel color.
     */
    Color Canvas::pixel( coord_type x, coord_type y ) const
    {
        if(x > Width )  std::invalid_argument( "X: " + x );
        if(y > Height ) std::invalid_argument( "Y: " + y );
        return Color( Pixels[(y * Width * 3) + (x * 3)] );
    }



    /*!
     * @note Nothing is done if the  pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to change the color.
     * @param c The color.
     */
    void Canvas::pixel( coord_type x, coord_type y, const Color& color )
    {
        if(x > Width )  return;
        if(y > Height ) return;
        std::memcpy( &Pixels[(y * Width * 3) + x*3], &color.channels, sizeof(colorChannel)*3 );
    }



    /*!
     * Draws on the canvas a horizontal line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The horizontal length of the line in pixels.
     */
    void Canvas::hLine( coord_type x, coord_type y, size_t length, const Color& color )
    {
        for( size_t i(0); i < length; i++ )
            for( size_t t(0); t < thickness(); t++ )
                pixel( x+i, y+t, color );
    }



    /*!
     * Draws on the canvas a vertical line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The vertical length of the line in pixels.
     */
    void Canvas::vLine( coord_type x, coord_type y, size_t length, const Color& color )
    {
        for( size_t i(0); i < length; i++ )
            for( size_t t(0); t < thickness(); t++ )
                pixel( x+t, y+i, color );
    }



    /*!
     * Draws on the canvas a filled box. The origin of the box is the top-left corner.
     * The box is compose of horizontal lines, drawn top to bottom.
     * @param p The 2D coordinate of the initial pixel of the box (top-left corner).
     * @param width The box's width in pixels.
     * @param height The box's height in pixels.
     */
    void Canvas::box( coord_type x, coord_type y, size_t width, size_t height , const Color& color)
    {
        for( size_t h(0); h < height; h++ )
            hLine( x, y+h, width, color );
    }