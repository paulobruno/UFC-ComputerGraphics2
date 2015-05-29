#include "Sphere.h"


#define ZERO_THRESHOLD 0.0001


bool Sphere::interceptedWithRay(Position3d rayOrigin, Position3d rayDirection)
{
    // vector ray direction
    float v_x = rayDirection.get_x();
    float v_y = rayDirection.get_y();
    float v_z = rayDirection.get_z();

    // adjust interception equation
    float a = (v_x * v_x) + (v_y * v_y) + (v_z * v_z);

    // difference: ray initial point - sphere center point
    float d_x = rayOrigin.get_x() - transform.getPosition().get_x();
    float d_y = rayOrigin.get_y() - transform.getPosition().get_y();
    float d_z = rayOrigin.get_z() - transform.getPosition().get_z();

    // adjust interception equation
    float b = 2 * ( (v_x * d_x) + (v_y * d_y) + (v_z * d_z) );
    float c = 1;/*(d_x * d_x) + (d_y * d_y) + (d_z * d_z) - (radius * radius);*/

    float delta = b*b - (4*a*c);

    if (delta <= 0)
    {
        return NULL;
    }

    // bhaskara
    float t1 = (- b + sqrt(delta)) / (2*a);
    float t2 = (- b - sqrt(delta)) / (2*a);

    //LOG("t1 = " << t1 << "\tt2 = " << t2);

    if (t1 <= ZERO_THRESHOLD)
    {
        if (t2 <= ZERO_THRESHOLD)
        {
            return NULL;
        }
        else
        {
            return ( new Position3d(rayOrigin + (rayDirection * t2)) );
        }
    }
    else
    {
        if (t2 <= ZERO_THRESHOLD)
        {
            return ( new Position3d(rayOrigin + (rayDirection * t1)) );
        }
        else
        {
            if (t1 < t2)
            {
                return ( new Position3d(rayOrigin + (rayDirection * t1)) );
            }
            else
            {
                return ( new Position3d(rayOrigin + (rayDirection * t2)) );
            }
        }
    }
}