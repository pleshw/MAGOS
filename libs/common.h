#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <cstring> // memset, memcpy
#include <iostream>
#include <map>

/// Defining some common structures.
namespace canvas {

   typedef size_t coord_type;

   /// Represents a Color as a RGB entity.
   struct Color
   {
       //=== Alias
       typedef unsigned char color_t; //!< Type of a color channel.
       /// Identifies each color channel.
       enum channel_e : color_t { R=0, //!< Red channel.
                                  G=1, //!< Green channel.
                                  B=2 //!< Blue channel
       };

       //=== Members
       color_t channels[3]; //!< Stores each of the color channels, R, G, and B.
       //=== Methods
       /// Creates a color.
       Color( color_t r=0, color_t g=0, color_t b=0 ) : channels{r,g,b} {/*empty*/}
       /// Copy constructor.
       Color( const Color& clone )
       {
           std::memcpy( channels, clone.channels, sizeof(color_t)*3 );
       }
       /// Assignment operator.
       Color& operator=( const Color& rhs )
       {
           if ( &rhs != this )
               std::memcpy( channels, rhs.channels, sizeof(color_t)*3 );
           return *this;
       }
       /// Comparison operator.
       bool operator==( const Color& rhs )
       {
           return not std::memcmp( channels, rhs.channels, sizeof(color_t)*3 );
       }
   };

  typedef std::map< std::string, std::string > Scheme;
   // A basic color pallete.
   static const Color BLACK         = Color{0,0,0}      ; //!< Black.
   static const Color WHITE         = Color{255,255,255}; //!< White.
   static const Color DARK_GREEN    = Color{0,100,0}    ; //!< Dark green.
   static const Color GREEN         = Color{0,250,0}    ; //!< Green.
   static const Color GREEN_FLAG    = Color{103,178,103}; //!< Green flag.
   static const Color RED           = Color{255,0,0}    ; //!< Red.
   static const Color RED_FLAG      = Color{149,66,244} ; //!< Red flag.
   static const Color CRIMSON       = Color{220,20,60}  ; //!< Crimson (kind of red).
   static const Color LIGHT_BLUE    = Color{135,206,250}; //!< Light blue.
   static const Color LIGHT_GREY    = Color{210,210,210}; //!< Light blue.
   static const Color DEEP_SKY_BLUE = Color{0,191,255}  ; //!< Deep blue.
   static const Color DODGER_BLUE   = Color{30,144,255} ; //!< Another bluish color.
   static const Color STEEL_BLUE    = Color{70,130,180} ; //!< Yet another bluish color.
   static const Color YELLOW        = Color{255,255,0}  ; //!< Yellow.
   static const Color LIGHT_YELLOW  = Color{255,255,153}; //!< Light yellow.

}// namespace



#endif // COMMON_H
