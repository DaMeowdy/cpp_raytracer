#include "vec3.h"
#ifndef CSE3PSD_ASSIGNMENT3_COLOUR3
#define CSE3PSD_ASSIGNMENT3_COLOUR3
class Colour3 {
  public:
    Colour3() = default;
    Colour3(double inR, double inG, double inB):colourVector_{inR,inG,inB}{};
    int R() const {return int(this->rgbScale*colourVector_.X());}
    int G() const {return int(this->rgbScale*colourVector_.Y());};
    int B() const {return int(this->rgbScale*colourVector_.Z());};
    Colour3 operator*(double scale) const;
    friend Colour3 operator*(double scale, Colour3& colourVector);
    Colour3 operator+(const Colour3 otherColour) const;
    private:
    double rgbScale = 255.999;
    Vec3 colourVector_ {0.0,0.0,0.0};
};

#endif
