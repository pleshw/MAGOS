#ifndef PLESHW_CANVAS
#define PLESHW_CANVAS

#include <iostream>
#include <memory>
#include <cstring>
#include <stdexcept>
#include "common.h"

using namespace canvas;
 //! Provides methods for drawing on an image.
    /*!
     * This is a drawing area on which we shall draw a maze representation.
     *
     * Here some information on the canvas properties:
     *
     * 1. The drawing area has the origin set to the top left corner, with
     * positive `X` axis going to the right and positive `Y` axis going to
     * the bottom of the canvas.
     * 2. Canvas supports basic operations to draw on vertical and horizontal
     * lines, as well as filled bordeless boxes.
     * 3. It is also possible to change line thikness to improve the final
     * appearance of the maze repreentation on the output image.
     *
     * This class returns to the client a pointer to the bytes (image) that
     * represents the pixels, which might be recorded by the client as an PPM
     * or PNG image file.
     */

class Canvas
{
public:
//=== Alias
typedef unsigned char colorChannel; //!< Type of a color channel.
	public:
	    //=== Special members
	    /// Constructor
	    /*! Creates an empty canvas of the requested size.
	     * @param Width The canvas width (in pixels).
	     * @param Height The canvas height (in pixels).
	     */
		Canvas( size_t _width = 0, size_t _height = 0 )
		: Width         { _width }, 
		  Height        { _height },
		  Pixels        { new colorChannel[ Width * Height * 3 ] },
		  lineThikness  { 1 }
		{ std::memset( Pixels.get(), 255, ( Width * Height * 3 )); } //255 for all pixels

	//=== Special members
	    /// Copy constructor.
		Canvas( const Canvas & );

	    /// Assignment operator.
		Canvas & operator=( const Canvas & );

	//=== Members
	    /// Clear the canvas with the background color.
		void clear( const Color& );
	  
	    /// Change the current line thickness.
		void thickness( unsigned short _thickness )
			{ lineThikness = _thickness; }
	   
	    /// Get the current line thickness.
		unsigned short thickness( void ) const
			{ return lineThikness; }
	  
	    /// Set the color of a pixel on the canvas.
		void pixel( coord_type x, coord_type y,  const Color& );
	   
	    /// Get the pixel color from the canvas.
		Color pixel( coord_type x, coord_type y ) const;
	
	//=== Attribute accessors members.
	    /// Get the canvas width.
		size_t width( void ) const
			{ return Width; }
	  
	    /// Get the cancas height.
		size_t height( void ) const
			{ return Height; }
	  
	    /// Get the canvas pixels, as an array of `unsigned char`.
		colorChannel* buffer( void ) const
			{ return Pixels.get(); }

	    /// Draw a horizontal line with `length` pixels on the canvas, starting at a `p` location.
	    /*
	     * Example:
	     *
	     * ```
	     * (p.x, p.y), thickness = 3, length = 15.
	     *  |
	     *  v
	     *  . . . . . . . . . . . . . . .
	     *  . . . . . . . . . . . . . . .
	     *  . . . . . . . . . . . . . . .
	     *  ```
	     */
		void hLine( coord_type x, coord_type y, size_t length, const Color& c );
	    /// Draw a vertical line with `length` pixels on the canvas, starting at a `p` location.
	    /*
	     * Example:
	     *
	     * ```
	     * (p.x, p.y), thickness = 3, length = 6.
	     *  |
	     *  v
	     *  . . .
	     *  . . .
	     *  . . .
	     *  . . .
	     *  . . .
	     *  . . .
	     *  ```
	     */

		void vLine( coord_type x, coord_type y,  size_t length, const Color& c );
	    
	    /// Draw a filled box, with origin at `p` (the top-left corner).
		void box( coord_type x, coord_type y, size_t width, size_t height, const Color& c );
private:
    size_t Width; //!< The image width in pixel units.
    size_t Height; //!< The image height in pixel unitsr
    std::shared_ptr< colorChannel[] > Pixels; //!< The pixels, stored as 3 RGB components.
    unsigned short lineThikness; //!< Current line thickness.
};

#endif